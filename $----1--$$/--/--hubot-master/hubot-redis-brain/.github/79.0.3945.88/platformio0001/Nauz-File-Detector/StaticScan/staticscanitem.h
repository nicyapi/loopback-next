// copyright (c) 2017-2020 hors<horsicq@gmail.com>
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
#ifndef STATICSCANITEM_H
#define STATICSCANITEM_H

#include <QList>
#include <QVariant>
#include "staticscan.h"

class StaticScanItem
{
public:
    StaticScanItem(const QString &_sString, StaticScanItem *pParentItem=nullptr,int nColumnCount=1);
    ~StaticScanItem();

    void appendChild(StaticScanItem *pChild);
    StaticScanItem *child(int nRow);
    int childCount() const;
    int columnCount() const;
    QVariant data(int nColumn) const;
    void setScanStruct(const SpecAbstract::SCAN_STRUCT &_ss);
    SpecAbstract::SCAN_STRUCT scanStruct() const;
    int row() const;
    StaticScanItem *parentItem();

private:
    QList<StaticScanItem *> listChildItems;
    QString _sString;
    StaticScanItem *_parentItem;
    int nColumnCount;

    SpecAbstract::SCAN_STRUCT _ss;
};

#endif // STATICSCANITEM_H
