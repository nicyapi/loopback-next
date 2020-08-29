// copyright (c) 2017-2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef DIALOGSTATICSCAN_H
#define DIALOGSTATICSCAN_H

#include <QDialog>
#include <QThread>
#include <QDateTime>
#include <QFileDialog>
#include <QStandardItemModel>
#include "staticscanitemmodel.h"

namespace Ui
{
class DialogStaticScan;
}

class DialogStaticScan : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStaticScan(QWidget *parent=nullptr);
    ~DialogStaticScan();

    void setData(QString sFileName,SpecAbstract::SCAN_OPTIONS *pOptions,SpecAbstract::SCAN_RESULT *pScanResult);
    void setData(QIODevice *pDevice,SpecAbstract::SCAN_OPTIONS *pOptions,SpecAbstract::SCAN_RESULT *pScanResult);
    void setData(QString sDirectoryName,SpecAbstract::SCAN_OPTIONS *pOptions);

    static bool saveResult(QWidget *pParent, StaticScanItemModel *pModel, QString sResultFileName);

private slots:
    void on_pushButtonCancel_clicked();
    void onCompleted(qint64 nElapsed);
    void onSetProgressMaximum(int nValue);
    void onSetProgressValue(int nValue);
    void timerSlot();

signals:
    void scanFileStarted(QString sFileName);
    void scanResult(SpecAbstract::SCAN_RESULT scanResult);

private:
    Ui::DialogStaticScan *ui;
    StaticScan *pScan;
    QThread *pThread;
    bool bIsRun;
    QTimer *pTimer;
};

#endif // DIALOGSTATICSCAN_H
