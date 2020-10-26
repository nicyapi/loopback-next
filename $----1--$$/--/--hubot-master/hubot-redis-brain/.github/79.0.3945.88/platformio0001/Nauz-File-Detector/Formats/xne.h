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
#ifndef XNE_H
#define XNE_H

#include "xmsdos.h"
#include "xne_def.h"

class XNE : public XMSDOS
{
    Q_OBJECT

public:
    explicit XNE(QIODevice *__pDevice=nullptr,bool bIsImage=false,qint64 nImageBase=-1);
    virtual bool isValid();

    qint64 getImageOS2HeaderOffset();
    qint64 getImageOS2HeaderSize();

    XNE_DEF::IMAGE_OS2_HEADER getImageOS2Header();

    quint16 getImageOS2Header_magic();
    quint8 getImageOS2Header_ver();
    quint8 getImageOS2Header_rev();
    quint16 getImageOS2Header_enttab();
    quint16 getImageOS2Header_cbenttab();
    quint32 getImageOS2Header_crc();
    quint16 getImageOS2Header_flags();
    quint16 getImageOS2Header_autodata();
    quint16 getImageOS2Header_heap();
    quint16 getImageOS2Header_stack();
    quint32 getImageOS2Header_csip();
    quint32 getImageOS2Header_sssp();
    quint16 getImageOS2Header_cseg();
    quint16 getImageOS2Header_cmod();
    quint16 getImageOS2Header_cbnrestab();
    quint16 getImageOS2Header_segtab();
    quint16 getImageOS2Header_rsrctab();
    quint16 getImageOS2Header_restab();
    quint16 getImageOS2Header_modtab();
    quint16 getImageOS2Header_imptab();
    quint32 getImageOS2Header_nrestab();
    quint16 getImageOS2Header_cmovent();
    quint16 getImageOS2Header_align();
    quint16 getImageOS2Header_cres();
    quint8 getImageOS2Header_exetyp();
    quint8 getImageOS2Header_flagsothers();
    quint16 getImageOS2Header_pretthunks();
    quint16 getImageOS2Header_psegrefbytes();
    quint16 getImageOS2Header_swaparea();
    quint16 getImageOS2Header_expver();

    void setImageOS2Header_magic(quint16 value);
    void setImageOS2Header_ver(quint8 value);
    void setImageOS2Header_rev(quint8 value);
    void setImageOS2Header_enttab(quint16 value);
    void setImageOS2Header_cbenttab(quint16 value);
    void setImageOS2Header_crc(quint32 value);
    void setImageOS2Header_flags(quint16 value);
    void setImageOS2Header_autodata(quint16 value);
    void setImageOS2Header_heap(quint16 value);
    void setImageOS2Header_stack(quint16 value);
    void setImageOS2Header_csip(quint32 value);
    void setImageOS2Header_sssp(quint32 value);
    void setImageOS2Header_cseg(quint16 value);
    void setImageOS2Header_cmod(quint16 value);
    void setImageOS2Header_cbnrestab(quint16 value);
    void setImageOS2Header_segtab(quint16 value);
    void setImageOS2Header_rsrctab(quint16 value);
    void setImageOS2Header_restab(quint16 value);
    void setImageOS2Header_modtab(quint16 value);
    void setImageOS2Header_imptab(quint16 value);
    void setImageOS2Header_nrestab(quint32 value);
    void setImageOS2Header_cmovent(quint16 value);
    void setImageOS2Header_align(quint16 value);
    void setImageOS2Header_cres(quint16 value);
    void setImageOS2Header_exetyp(quint8 value);
    void setImageOS2Header_flagsothers(quint8 value);
    void setImageOS2Header_pretthunks(quint16 value);
    void setImageOS2Header_psegrefbytes(quint16 value);
    void setImageOS2Header_swaparea(quint16 value);
    void setImageOS2Header_expver(quint16 value);

    static QMap<quint64, QString> getImageNEMagics();
    static QMap<quint64, QString> getImageNEMagicsS();
};

#endif // XNE_H
