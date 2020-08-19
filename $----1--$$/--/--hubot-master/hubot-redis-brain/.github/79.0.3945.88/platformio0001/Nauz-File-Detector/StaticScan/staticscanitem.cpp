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
#include "staticscanitem.h"

StaticScanItem::StaticScanItem(const QString &_sString, StaticScanItem *pParentItem, int nColumnCount)
{
    this->_parentItem=pParentItem;
    this->_sString=_sString;
    this->nColumnCount=nColumnCount;
}

StaticScanItem::~StaticScanItem()
{
    qDeleteAll(listChildItems);
}

void StaticScanItem::appendChild(StaticScanItem *pChild)
{
    listChildItems.append(pChild);
}

StaticScanItem *StaticScanItem::child(int nRow)
{
    return listChildItems.value(nRow);
}

int StaticScanItem::childCount() const
{
    return listChildItems.count();
}

int StaticScanItem::columnCount() const
{
    return nColumnCount;
}

QVariant StaticScanItem::data(int nColumn) const
{
    QVariant result;

    if(nColumn==0)
    {
        result=_sString;
    }

    return result;
}

void StaticScanItem::setScanStruct(const SpecAbstract::SCAN_STRUCT &_ss)
{
    this->_ss=_ss;
}

SpecAbstract::SCAN_STRUCT StaticScanItem::scanStruct() const
{
    return _ss;
}

int StaticScanItem::row() const
{
    int nResult=0;

    if(_parentItem)
    {
        nResult=_parentItem->listChildItems.indexOf(const_cast<StaticScanItem*>(this));
    }

    return nResult;
}

StaticScanItem *StaticScanItem::parentItem()
{
    return _parentItem;
}
