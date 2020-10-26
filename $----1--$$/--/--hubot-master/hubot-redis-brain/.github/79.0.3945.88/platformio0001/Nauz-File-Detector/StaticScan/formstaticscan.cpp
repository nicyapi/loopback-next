// copyright (c) 2019 hors<horsicq@gmail.com>
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
#include "formstaticscan.h"
#include "ui_formstaticscan.h"

FormStaticScan::FormStaticScan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStaticScan)
{
    ui->setupUi(this);

    ui->checkBoxDeepScan->setChecked(true);
    ui->checkBoxRecursive->setChecked(true);
}

FormStaticScan::~FormStaticScan()
{
    delete ui;
}

void FormStaticScan::setData(QIODevice *pDevice, FormStaticScan::OPTIONS *pOptions)
{
    this->pDevice=pDevice;
    this->pOptions=pOptions;

    if(pOptions->bHideRecursive)
    {
        ui->checkBoxRecursive->setChecked(false);
        ui->checkBoxRecursive->hide();
    }

    if(pOptions->bScanAfterOpen)
    {
        scan();
    }
}

void FormStaticScan::on_pushButtonScan_clicked()
{
    scan();
}

void FormStaticScan::scan()
{
    SpecAbstract::SCAN_RESULT scanResult;

    SpecAbstract::SCAN_OPTIONS options= {0};
    options.bRecursive=ui->checkBoxRecursive->isChecked();
    options.bDeepScan=ui->checkBoxDeepScan->isChecked();
    options.bIsImage=pOptions->bIsImage;

    DialogStaticScan ds(this);
    ds.setData(pDevice,&options,&scanResult);
    ds.exec();

    ui->widgetResult->setData(scanResult,"");
}
