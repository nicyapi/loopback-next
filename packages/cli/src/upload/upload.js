/**
 * @license Copyright 2019 Google Inc. All Rights Reserved.
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
 */
'use strict';

const URL = require('url').URL;
const crypto = require('crypto');
const fetch = require('isomorphic-fetch');
const childProcess = require('child_process');
const _ = require('@lhci/utils/src/lodash.js');
const ApiClient = require('@lhci/utils/src/api-client.js');
const {computeRepresentativeRuns} = require('@lhci/utils/src/representative-runs.js');
const {
  getSavedLHRs,
  replaceUrlPatterns,
  getHTMLReportForLHR,
} = require('@lhci/utils/src/saved-reports.js');

const envVars = process.env;

const TEMPORARY_PUBLIC_STORAGE_URL =
  'https://us-central1-lighthouse-infrastructure.cloudfunctions.net/saveHtmlReport';

/**
 * @param {import('yargs').Argv} yargs
 */
function buildCommand(yargs) {
  return yargs.options({
    target: {
      type: 'string',
      default: 'lhci',
      choices: ['lhci', 'temporary-public-storage'],
      description:
        'The type of target to upload the data to. If set to anything other than "lhci", ' +
        'some of the options will not apply.',
    },
    token: {type: 'string'},
    serverBaseUrl: {
      description: 'The base URL of the server where results will be saved.',
      default: 'http://localhost:9001/',
    },
    urlReplacementPatterns: {
      type: 'array',
      description: 'sed-like replacement patterns to mask non-deterministic URL substrings.',
      default: [
        's#:[0-9]{3,5}/#:PORT/#', // replace ports
        's/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/UUID/ig', // replace UUIDs
      ],
    },
  });
}

/**
 * @return {string}
 */
function getCurrentHash() {
  if (envVars.TRAVIS_PULL_REQUEST_SHA) return envVars.TRAVIS_PULL_REQUEST_SHA;
  if (envVars.TRAVIS_COMMIT) return envVars.TRAVIS_COMMIT;

  const result = childProcess.spawnSync('git', ['rev-list', '--no-merges', '-n', '1', 'HEAD'], {
    encoding: 'utf8',
  });
  if (result.status !== 0) {
    throw new Error('Unable to determine current hash with `git rev-parse HEAD`');
  }

  return result.stdout.trim();
}

/**
 * @return {string}
 */
function getCurrentBranch() {
  if (envVars.TRAVIS_PULL_REQUEST_BRANCH) return envVars.TRAVIS_PULL_REQUEST_BRANCH.slice(0, 40);
  if (envVars.TRAVIS_BRANCH) return envVars.TRAVIS_BRANCH.slice(0, 40);

  const result = childProcess.spawnSync('git', ['rev-parse', '--abbrev-ref', 'HEAD'], {
    encoding: 'utf8',
  });
  if (result.status !== 0) {
    throw new Error('Unable to determine current branch with `git rev-parse --abbrev-ref HEAD`');
  }

  return result.stdout.trim().slice(0, 40);
}

/**
 * @return {string}
 */
function getExternalBuildUrl() {
  return envVars.TRAVIS_BUILD_WEB_URL || '';
}

/**
 * @param {string} hash
 * @return {string}
 */
function getCommitMessage(hash = 'HEAD') {
  const result = childProcess.spawnSync('git', ['log', '--format=%s', '-n', '1', hash], {
    encoding: 'utf8',
  });
  if (result.status !== 0) {
    throw new Error('Unable to determine commit message with `git log --format=%s -n 1`');
  }

  return result.stdout.trim().slice(0, 80);
}

/**
 * @param {string} hash
 * @return {string}
 */
function getAuthor(hash = 'HEAD') {
  const result = childProcess.spawnSync('git', ['log', '--format=%aN <%aE>', '-n', '1', hash], {
    encoding: 'utf8',
  });
  if (result.status !== 0) {
    throw new Error('Unable to determine commit author with `git log --format=%aN <%aE> -n 1`');
  }

  return result.stdout.trim().slice(0, 256);
}

/**
 * @param {string} hash
 * @return {string}
 */
function getAvatarUrl(hash = 'HEAD') {
  const result = childProcess.spawnSync('git', ['log', '--format=%aE', '-n', '1', hash], {
    encoding: 'utf8',
  });
  if (result.status !== 0) {
    throw new Error('Unable to determine commit email with `git log --format=%aE -n 1`');
  }

  // Use default gravatar image, see https://en.gravatar.com/site/implement/images/.
  const md5 = crypto.createHash('md5');
  md5.update(result.stdout.trim().toLowerCase());
  return `https://www.gravatar.com/avatar/${md5.digest('hex')}.jpg?d=identicon`;
}

/**
 * @return {string}
 */
function getAncestorHashForMaster() {
  const result = childProcess.spawnSync('git', ['rev-parse', 'HEAD^'], {encoding: 'utf8'});
  if (result.status !== 0) {
    throw new Error('Unable to determine previous hash with `git rev-parse HEAD^`');
  }

  return result.stdout.trim();
}

/**
 * @return {string}
 */
function getAncestorHashForBranch() {
  const result = childProcess.spawnSync('git', ['merge-base', 'HEAD', 'master'], {
    encoding: 'utf8',
  });

  if (result.status !== 0) {
    throw new Error('Unable to determine current hash with `git merge-base HEAD master`');
  }

  return result.stdout.trim();
}

/**
 * @param {LHCI.UploadCommand.Options} options
 * @return {Promise<void>}
 */
async function runLHCITarget(options) {
  if (!options.token) throw new Error('Must provide token for LHCI target');

  const api = new ApiClient({rootURL: options.serverBaseUrl});

  const project = await api.findProjectByToken(options.token);
  if (!project) {
    throw new Error('Could not find active project with provided token');
  }

  const hash = getCurrentHash();
  const branch = getCurrentBranch();

  const build = await api.createBuild({
    projectId: project.id,
    lifecycle: 'unsealed',
    hash,
    branch,
    commitMessage: getCommitMessage(hash),
    author: getAuthor(hash),
    avatarUrl: getAvatarUrl(hash),
    ancestorHash: branch === 'master' ? getAncestorHashForMaster() : getAncestorHashForBranch(),
    externalBuildUrl: getExternalBuildUrl(),
    runAt: new Date().toISOString(),
  });

  process.stdout.write(`Saving CI project ${project.name} (${project.id})\n`);
  process.stdout.write(`Saving CI build (${build.id})\n`);

  const lhrs = getSavedLHRs();
  const urlReplacementPatterns = options.urlReplacementPatterns.filter(Boolean);

  for (const lhr of lhrs) {
    const parsedLHR = JSON.parse(lhr);
    const url = replaceUrlPatterns(parsedLHR.finalUrl, urlReplacementPatterns);
    const run = await api.createRun({
      projectId: project.id,
      buildId: build.id,
      representative: false,
      url,
      lhr,
    });

    process.stdout.write(`Saved LHR to ${options.serverBaseUrl} (${run.id})\n`);
  }

  const buildViewUrl = new URL(
    `/app/projects/${build.projectId}/builds/${build.id}`,
    options.serverBaseUrl
  );

  await api.sealBuild(build.projectId, build.id);
  process.stdout.write(`Done saving build results to Lighthouse CI\n`);
  process.stdout.write(`View build diff at ${buildViewUrl.href}\n`);
}

async function runTemporaryPublicStorageTarget() {
  /** @type {Array<LH.Result>} */
  const lhrs = getSavedLHRs().map(lhr => JSON.parse(lhr));
  /** @type {Array<Array<[LH.Result, LH.Result]>>} */
  const lhrsByUrl = _.groupBy(lhrs, lhr => lhr.finalUrl).map(lhrs => lhrs.map(lhr => [lhr, lhr]));
  const representativeLhrs = computeRepresentativeRuns(lhrsByUrl);

  for (const lhr of representativeLhrs) {
    const urlAudited = lhr.finalUrl;
    process.stdout.write(`Uploading median LHR of ${urlAudited}...`);

    try {
      const response = await fetch(TEMPORARY_PUBLIC_STORAGE_URL, {
        method: 'POST',
        headers: {'content-type': 'text/html'},
        body: getHTMLReportForLHR(lhr),
      });

      const {success, url} = await response.json();
      if (success && url) {
        process.stdout.write(`success!\nOpen the report at ${url}\n`);
      } else {
        process.stdout.write(`failed!\n`);
      }
    } catch (err) {
      process.stdout.write(`failed!\n`);
      process.stderr.write(err.stack + '\n');
    }
  }
}

/**
 * @param {LHCI.UploadCommand.Options} options
 * @return {Promise<void>}
 */
async function runCommand(options) {
  switch (options.target) {
    case 'lhci':
      return runLHCITarget(options);
    case 'temporary-public-storage':
      return runTemporaryPublicStorageTarget();
    default:
      throw new Error(`Unrecognized target "${options.target}"`);
  }
}

module.exports = {buildCommand, runCommand};
