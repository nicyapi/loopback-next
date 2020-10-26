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
#include "xne.h"

XNE::XNE(QIODevice *__pDevice, bool bIsImage, qint64 nImageBase) : XMSDOS(__pDevice,bIsImage,nImageBase)
{

}

bool XNE::isValid()
{
    bool bResult=false;

    quint16 magic=get_magic();

    if(magic==(quint16)XMSDOS_DEF::S_IMAGE_DOS_SIGNATURE)
    {
        qint32 lfanew=get_lfanew();

        if(lfanew>0)
        {
            quint32 signature=read_uint16(lfanew);

            if(signature==XNE_DEF::S_IMAGE_OS2_SIGNATURE)
            {
                bResult=true;
            }
        }
    }

    return bResult;
}

qint64 XNE::getImageOS2HeaderOffset()
{
    qint64 nResult=get_lfanew();

    if(!isOffsetValid(nResult))
    {
        nResult=-1;
    }

    return nResult;
}

qint64 XNE::getImageOS2HeaderSize()
{
    return sizeof(XNE_DEF::IMAGE_OS2_HEADER);
}

XNE_DEF::IMAGE_OS2_HEADER XNE::getImageOS2Header()
{
    XNE_DEF::IMAGE_OS2_HEADER result={};

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        result.ne_magic=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_magic));
        result.ne_ver=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_ver));
        result.ne_rev=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rev));
        result.ne_enttab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_enttab));
        result.ne_cbenttab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbenttab));
        result.ne_crc=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_crc));
        result.ne_flags=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flags));
        result.ne_autodata=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_autodata));
        result.ne_heap=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_heap));
        result.ne_stack=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_stack));
        result.ne_csip=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_csip));
        result.ne_sssp=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_sssp));
        result.ne_cseg=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cseg));
        result.ne_cmod=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmod));
        result.ne_cbnrestab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbnrestab));
        result.ne_segtab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_segtab));
        result.ne_rsrctab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rsrctab));
        result.ne_restab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_restab));
        result.ne_modtab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_modtab));
        result.ne_imptab=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_imptab));
        result.ne_nrestab=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_nrestab));
        result.ne_cmovent=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmovent));
        result.ne_align=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_align));
        result.ne_cres=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cres));
        result.ne_exetyp=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_exetyp));
        result.ne_flagsothers=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flagsothers));
        result.ne_pretthunks=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_pretthunks));
        result.ne_psegrefbytes=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_psegrefbytes));
        result.ne_swaparea=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_swaparea));
        result.ne_expver=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_expver));
    }

    return result;
}

quint16 XNE::getImageOS2Header_magic()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_magic));
    }

    return nResult;
}

quint8 XNE::getImageOS2Header_ver()
{
    quint8 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_ver));
    }

    return nResult;
}

quint8 XNE::getImageOS2Header_rev()
{
    quint8 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rev));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_enttab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_enttab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cbenttab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbenttab));
    }

    return nResult;
}

quint32 XNE::getImageOS2Header_crc()
{
    quint32 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_crc));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_flags()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flags));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_autodata()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_autodata));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_heap()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_heap));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_stack()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_stack));
    }

    return nResult;
}

quint32 XNE::getImageOS2Header_csip()
{
    quint32 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_csip));
    }

    return nResult;
}

quint32 XNE::getImageOS2Header_sssp()
{
    quint32 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_sssp));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cseg()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cseg));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cmod()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmod));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cbnrestab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbnrestab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_segtab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_segtab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_rsrctab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rsrctab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_restab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_restab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_modtab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_modtab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_imptab()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_imptab));
    }

    return nResult;
}

quint32 XNE::getImageOS2Header_nrestab()
{
    quint32 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_nrestab));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cmovent()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmovent));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_align()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_align));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_cres()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cres));
    }

    return nResult;
}

quint8 XNE::getImageOS2Header_exetyp()
{
    quint8 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_exetyp));
    }

    return nResult;
}

quint8 XNE::getImageOS2Header_flagsothers()
{
    quint8 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flagsothers));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_pretthunks()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_pretthunks));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_psegrefbytes()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_psegrefbytes));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_swaparea()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_swaparea));
    }

    return nResult;
}

quint16 XNE::getImageOS2Header_expver()
{
    quint16 nResult=0;

    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        nResult=read_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_expver));
    }

    return nResult;
}

void XNE::setImageOS2Header_magic(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_magic),value);
    }
}

void XNE::setImageOS2Header_ver(quint8 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_ver),value);
    }
}

void XNE::setImageOS2Header_rev(quint8 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rev),value);
    }
}

void XNE::setImageOS2Header_enttab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_enttab),value);
    }
}

void XNE::setImageOS2Header_cbenttab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbenttab),value);
    }
}

void XNE::setImageOS2Header_crc(quint32 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_crc),value);
    }
}

void XNE::setImageOS2Header_flags(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flags),value);
    }
}

void XNE::setImageOS2Header_autodata(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_autodata),value);
    }
}

void XNE::setImageOS2Header_heap(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_heap),value);
    }
}

void XNE::setImageOS2Header_stack(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_stack),value);
    }
}

void XNE::setImageOS2Header_csip(quint32 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_csip),value);
    }
}

void XNE::setImageOS2Header_sssp(quint32 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_sssp),value);
    }
}

void XNE::setImageOS2Header_cseg(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cseg),value);
    }
}

void XNE::setImageOS2Header_cmod(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmod),value);
    }
}

void XNE::setImageOS2Header_cbnrestab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cbnrestab),value);
    }
}

void XNE::setImageOS2Header_segtab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_segtab),value);
    }
}

void XNE::setImageOS2Header_rsrctab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_rsrctab),value);
    }
}

void XNE::setImageOS2Header_restab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_restab),value);
    }
}

void XNE::setImageOS2Header_modtab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_modtab),value);
    }
}

void XNE::setImageOS2Header_imptab(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_imptab),value);
    }
}

void XNE::setImageOS2Header_nrestab(quint32 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint32(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_nrestab),value);
    }
}

void XNE::setImageOS2Header_cmovent(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cmovent),value);
    }
}

void XNE::setImageOS2Header_align(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_align),value);
    }
}

void XNE::setImageOS2Header_cres(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_cres),value);
    }
}

void XNE::setImageOS2Header_exetyp(quint8 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_exetyp),value);
    }
}

void XNE::setImageOS2Header_flagsothers(quint8 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint8(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_flagsothers),value);
    }
}

void XNE::setImageOS2Header_pretthunks(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_pretthunks),value);
    }
}

void XNE::setImageOS2Header_psegrefbytes(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_psegrefbytes),value);
    }
}

void XNE::setImageOS2Header_swaparea(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_swaparea),value);
    }
}

void XNE::setImageOS2Header_expver(quint16 value)
{
    qint64 nOffset=getImageOS2HeaderOffset();

    if(nOffset!=-1)
    {
        write_uint16(nOffset+offsetof(XNE_DEF::IMAGE_OS2_HEADER,ne_expver),value);
    }
}

QMap<quint64, QString> XNE::getImageNEMagics()
{
    QMap<quint64, QString> mapResult;

    mapResult.insert(0x454E,"IMAGE_OS2_SIGNATURE");

    return mapResult;
}

QMap<quint64, QString> XNE::getImageNEMagicsS()
{
    QMap<quint64, QString> mapResult;

    mapResult.insert(0x454E,"OS2_SIGNATURE");

    return mapResult;
}
