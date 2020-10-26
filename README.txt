                     BIOS Implementation Test Suite (BITS)
                               and reference code
                                 Burt Triplett

Build ID: @@BUILDID@@
Build number: @@BUILDNUM@@

Based on GRUB bzr snapshot, revno 2587.

Please send any bug reports to <burton.w.triplett@intel.com>, and please
include the build ID for reference.

You can find the BITS homepage at http://biosbits.org/

Disclaimer
==========

None of the menu options provided by this toolkit should affect your system
permanently, only for the current boot.  If you *ever* find that this toolkit
affects your system in any permanent way, that represents a serious bug.
However, poking around at the GRUB command line may turn up some commands
provided by GRUB that can affect your system; if it breaks, you get to keep
both pieces.


Other sources of information
============================

This README.txt file documents how to use BITS.  For instructions to build a
bootable USB disk from a BITS binary distribution, refer to INSTALL.txt
included in the top-level directory of that that binary distribution.  If you
want to do BITS development, start with the BITS source code; on a BITS USB
disk built from this version of BITS, you can find the source code under
/boot/src/bits-@@BUILDNUM@@.tar.gz; for more information, see
README.Developers.txt in the BITS source.


Getting Started
===============

When a BITS USB drive boots, it will display a menu of available functionality.

BITS will detect your processor signature and enable appropriate menu options
for your CPU and general CPU family.  For instance, if you have a Westmere
processor, you will see menu options specific to the Westmere processor, menu
options for the Nehalem family of processors, and menu options for all Intel
processors.

The available options in BITS fall into several broad categories:

- "Test Menu" contains various test suites designed to test your system and
  its BIOS configuration.  When run normally, these test suites will produce
  a list of all test failures, and a summary of the tests run.  Tests that
  pass will generate no output, and if the entire test suite passes, you will
  see only the summary at the end.  If you want to see more verbose failure
  information from each test, you can set the verbosity level via the
  "test_options" command from the GRUB command line.  If you turn it up high
  enough it will show tests that pass, but that will quickly drown out the
  useful information about test failures; apart from the novelty of seeing how
  many tests BITS includes, this serves little useful purpose.  Turn it back
  off and get back to fixing bugs. :)

- "Configure Menu" contains options to temporarily reconfigure your system.
  For example, you can re-run the power management reference code normally run
  by your BIOS.  None of these options will touch your BIOS or permanently
  change your system configuration, but they will override that configuration
  for the current boot only.  These options can help you quickly explore
  alterative configurations, or override an incorrect BIOS configuration with
  one that follows Intel's recommendations.

- "Explore Menu" contains options that let you explore your system's existing
  configuration and behavior, as well as experimental tests which produce
  results beyond just PASS/FAIL.  For example, you can find out how much
  latency your BIOS's SMI handler (or other mysterious background processing)
  introduces in your system, or explore the latency incurred to wake CPUs from
  deeper C-states.

- "Boot first drive MBR" and "Boot second drive MBR" allow you to boot your
  existing operating system from the first or second hard disk on your system.
  You can use these options to boot your existing OS after running options
  from the Configure menu to change your system's configuration; for instance,
  after running Intel's power management reference code to overwrite your
  BIOS's power management configuration, you could boot Linux and run
  powertop, or boot your own test workload and run benchmarks.


Reference code
==============

This toolkit includes the processor power management (PPM) reference code
normally run by your BIOS (assuming your BIOS did the right thing and used
Intel's reference code; accept no substitutes).  If you boot this toolkit on a
processor that the reference code knows how to handle (currently
Nehalem/Westmere family processors only), then you will have a menu option to
run the reference code and override the ACPI tables written by your BIOS.  You
can then use the menu item to boot your OS from your disk, and you should find
that your processor power management works better (or perhaps that it works at
all).

If this reference code produces better results on your system than your existing
BIOS configuration, or if it produces identical results, then you may want to
incoporate this official Intel reference code into your BIOS as a replacement
for your existing power management configuration code.


Microcode
=========

BITS can load CPU microcode for you, or check your current microcode version
and compare it to available microcodes.  You can find these options under the
Configure menu.

To check your current microcode version, you can run mcu_status with no
arguments.

To load microcode, or compare your current microcode version to available
microcodes, you need a microcode data file.  You can get one from
http://downloadcenter.intel.com/ , under "Processors".  You can then run
mcu_status with that file to check for a newer microcode, or run mcu_load with
that file to load it.

mcu_status and mcu_load can also take one or more directories as well as files;
given a directory, they will attempt to load *every* file in the directory as a
microcode database.  (They will not recurse into subdirectories, however.)  The
menu options for checking and loading microcode default to checking
/boot/mcu.first and /boot/mcu, in that order.  If you download a microcode data
file, you can put it in /boot/mcu and the menu options will find it.
/boot/mcu.first exists in case you have a processor-specific microcode you want
to load instead of one from the full standard microcode database.

mcu_status and mcu_load support both binary microcode files and text-based
microcode files.  Note, though, that any file other than a microcode database
will probably get parsed as one anyway, with unhelpful (though not dangerous)
results; in particular, don't give mcu_status or mcu_load a directory
containing any files other than a microcode database.


Credits
=======

Author: Burt Triplett <burton.w.triplett@intel.com>

Based on the GNU GRUB2 bootloader.
http://www.gnu.org/software/grub/


Command help
============

This toolkit adds the following commands to GRUB.  You can get more help on
each command by running it with the --help option.

