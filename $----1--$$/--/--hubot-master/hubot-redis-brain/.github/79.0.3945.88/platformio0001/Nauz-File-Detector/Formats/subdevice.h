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
#ifndef SUBDEVICE_H
#define SUBDEVICE_H

#include <QObject>
#include <QIODevice>

class SubDevice : public QIODevice
{
public:
    SubDevice(QIODevice *pDevice,qint64 nOffset=0,qint64 nSize=-1,QObject *parent=nullptr);
    ~SubDevice();

    virtual qint64 size() const;
    //    virtual qint64 bytesAvailable() const;
    virtual bool isSequential() const;
    virtual bool seek(qint64 pos);
    virtual bool reset();
    virtual bool open(OpenMode mode);
    virtual bool atEnd() const;
    virtual void close();
    virtual qint64 pos() const;

protected:
    virtual qint64 readData(char *data, qint64 maxSize);
    virtual qint64 writeData(const char *data, qint64 maxSize);
    virtual void setErrorString(const QString &str); // TODO

private:
    QIODevice *pDevice;
    qint64 nOffset;
    qint64 nSize;
};

#endif // SUBDEVICE_H
