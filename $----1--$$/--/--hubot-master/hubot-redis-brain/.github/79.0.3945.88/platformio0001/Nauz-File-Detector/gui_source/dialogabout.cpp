// Copyright (c) 2018-2019 hors<horsicq@gmail.com>
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
#include "dialogabout.h"
#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

    ui->labelInfo->setText(QString("<html><head/><body><p align=\"center\">"
                                   "<span style=\" font-weight:600;\">Copyright(C) 2017-2019 hors</span></p>"
                                   "<p align=\"center\"><span style=\" font-weight:600;\">"
                                   "Version: </span>%1 (%2)</p><p align=\"center\">"
                                   "<span style=\" font-weight:600;\">Website: </span><a href=\"http://ntinfo.biz\">"
                                   "<span style=\" text-decoration: underline; color:#0000ff;\">http://ntinfo.biz</span>"
                                   "</a></p><p align=\"center\"><span style=\" font-weight:600;\">Bugerports: </span>"
                                   "<a href=\"mailto:horsicq@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">"
                                   "horsicq@gmail.com</span></a></p></body></html>").arg(X_APPLICATIONVERSION).arg(__DATE__));
}

DialogAbout::~DialogAbout()
{
    delete ui;
}

void DialogAbout::on_pushButtonOK_clicked()
{
    this->close();
}
