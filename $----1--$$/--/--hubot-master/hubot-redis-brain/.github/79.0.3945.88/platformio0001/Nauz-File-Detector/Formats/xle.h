// copyright (c) 2020 hors<horsicq@gmail.com>
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
#ifndef XLE_H
#define XLE_H

#include "xmsdos.h"
#include "xle_def.h"

class XLE : public XMSDOS
{
    Q_OBJECT

public:
    explicit XLE(QIODevice *__pDevice=nullptr,bool bIsImage=false,qint64 nImageBase=-1);
    virtual bool isValid();

    qint64 getImageVxdHeaderOffset();
    qint64 getImageVxdHeaderSize();
    XLE_DEF::IMAGE_VXD_HEADER getImageVxdHeader();

    quint16 getImageVxdHeader_magic();
    quint8 getImageVxdHeader_border();
    quint8 getImageVxdHeader_worder();
    quint32 getImageVxdHeader_level();
    quint16 getImageVxdHeader_cpu();
    quint16 getImageVxdHeader_os();
    quint32 getImageVxdHeader_ver();
    quint32 getImageVxdHeader_mflags();
    quint32 getImageVxdHeader_mpages();
    quint32 getImageVxdHeader_startobj();
    quint32 getImageVxdHeader_eip();
    quint32 getImageVxdHeader_stackobj();
    quint32 getImageVxdHeader_esp();
    quint32 getImageVxdHeader_pagesize();
    quint32 getImageVxdHeader_lastpagesize();
    quint32 getImageVxdHeader_fixupsize();
    quint32 getImageVxdHeader_fixupsum();
    quint32 getImageVxdHeader_ldrsize();
    quint32 getImageVxdHeader_ldrsum();
    quint32 getImageVxdHeader_objtab();
    quint32 getImageVxdHeader_objcnt();
    quint32 getImageVxdHeader_objmap();
    quint32 getImageVxdHeader_itermap();
    quint32 getImageVxdHeader_rsrctab();
    quint32 getImageVxdHeader_rsrccnt();
    quint32 getImageVxdHeader_restab();
    quint32 getImageVxdHeader_enttab();
    quint32 getImageVxdHeader_dirtab();
    quint32 getImageVxdHeader_dircnt();
    quint32 getImageVxdHeader_fpagetab();
    quint32 getImageVxdHeader_frectab();
    quint32 getImageVxdHeader_impmod();
    quint32 getImageVxdHeader_impmodcnt();
    quint32 getImageVxdHeader_impproc();
    quint32 getImageVxdHeader_pagesum();
    quint32 getImageVxdHeader_datapage();
    quint32 getImageVxdHeader_preload();
    quint32 getImageVxdHeader_nrestab();
    quint32 getImageVxdHeader_cbnrestab();
    quint32 getImageVxdHeader_nressum();
    quint32 getImageVxdHeader_autodata();
    quint32 getImageVxdHeader_debuginfo();
    quint32 getImageVxdHeader_debuglen();
    quint32 getImageVxdHeader_instpreload();
    quint32 getImageVxdHeader_instdemand();
    quint32 getImageVxdHeader_heapsize();

    void setImageVxdHeader_magic(quint16 value);
    void setImageVxdHeader_border(quint8 value);
    void setImageVxdHeader_worder(quint8 value);
    void setImageVxdHeader_level(quint32 value);
    void setImageVxdHeader_cpu(quint16 value);
    void setImageVxdHeader_os(quint16 value);
    void setImageVxdHeader_ver(quint32 value);
    void setImageVxdHeader_mflags(quint32 value);
    void setImageVxdHeader_mpages(quint32 value);
    void setImageVxdHeader_startobj(quint32 value);
    void setImageVxdHeader_eip(quint32 value);
    void setImageVxdHeader_stackobj(quint32 value);
    void setImageVxdHeader_esp(quint32 value);
    void setImageVxdHeader_pagesize(quint32 value);
    void setImageVxdHeader_lastpagesize(quint32 value);
    void setImageVxdHeader_fixupsize(quint32 value);
    void setImageVxdHeader_fixupsum(quint32 value);
    void setImageVxdHeader_ldrsize(quint32 value);
    void setImageVxdHeader_ldrsum(quint32 value);
    void setImageVxdHeader_objtab(quint32 value);
    void setImageVxdHeader_objcnt(quint32 value);
    void setImageVxdHeader_objmap(quint32 value);
    void setImageVxdHeader_itermap(quint32 value);
    void setImageVxdHeader_rsrctab(quint32 value);
    void setImageVxdHeader_rsrccnt(quint32 value);
    void setImageVxdHeader_restab(quint32 value);
    void setImageVxdHeader_enttab(quint32 value);
    void setImageVxdHeader_dirtab(quint32 value);
    void setImageVxdHeader_dircnt(quint32 value);
    void setImageVxdHeader_fpagetab(quint32 value);
    void setImageVxdHeader_frectab(quint32 value);
    void setImageVxdHeader_impmod(quint32 value);
    void setImageVxdHeader_impmodcnt(quint32 value);
    void setImageVxdHeader_impproc(quint32 value);
    void setImageVxdHeader_pagesum(quint32 value);
    void setImageVxdHeader_datapage(quint32 value);
    void setImageVxdHeader_preload(quint32 value);
    void setImageVxdHeader_nrestab(quint32 value);
    void setImageVxdHeader_cbnrestab(quint32 value);
    void setImageVxdHeader_nressum(quint32 value);
    void setImageVxdHeader_autodata(quint32 value);
    void setImageVxdHeader_debuginfo(quint32 value);
    void setImageVxdHeader_debuglen(quint32 value);
    void setImageVxdHeader_instpreload(quint32 value);
    void setImageVxdHeader_instdemand(quint32 value);
    void setImageVxdHeader_heapsize(quint32 value);

    static QMap<quint64, QString> getImageLEMagics();
    static QMap<quint64, QString> getImageLEMagicsS();
};

#endif // XLE_H
