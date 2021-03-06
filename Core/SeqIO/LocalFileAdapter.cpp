/*****************************************************************************************
                        BioQt - Integrated Bioinformatics Library
Copyright (C) 2013-2014 Usama S Erawab <alrawab@hotmail.com> Libya
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
************************************************************************************************/



#include "LocalFileAdapter.h"
#include "ZlibAdapter.h"
#include "SafePoints.h"

namespace BioQt {


const quint64 LocalFileAdapter::BUF_SIZE = 1024*1024;

LocalFileAdapter::LocalFileAdapter(/*LocalFileAdapterFactory* factory,*/ QObject* o, bool b)
: IOAdapter(/*factory,*/ o), f(NULL), bufferOptimization(b)
{
    bufferOptimization = true;
    if (bufferOptimization) {
        buffer = QByteArray(BUF_SIZE, '\0');
        bufData = buffer.data();
    } else {
        bufData = NULL;
    }
    bufLen = 0;
    currentPos = 0;
}


bool LocalFileAdapter::open(const Url& url, IOAdapterMode m) {
    SAFE_POINT(!isOpen(), "Adapter is already opened!", false);
    SAFE_POINT(f == NULL, "QFile is not null!", false);

    if (url.isEmpty()) {
        return false;
    }
    f = new QFile(url.getURLString());
    QIODevice::OpenMode iomode;
    switch (m) {
        case IOAdapterMode_Read: iomode = QIODevice::ReadOnly; break;
        case IOAdapterMode_Write: iomode = QIODevice::WriteOnly | QIODevice::Truncate; break;
        case IOAdapterMode_Append: iomode = QIODevice::WriteOnly | QIODevice::Append; break;
    }
    bool res = f->open(iomode);
    if (!res) {
        delete f;
        f = NULL;
        return false;
    }
    return true;
}

void LocalFileAdapter::close() {
    SAFE_POINT(isOpen(), "Adapter is not opened!",);
    f->close();
    delete f;
    f = NULL;
}

qint64 LocalFileAdapter::readBlock(char* data, qint64 size) {
    SAFE_POINT(isOpen(), "Adapter is not opened!",-1);
    qint64 l = 0;
    if (bufferOptimization) {
        qint64 copySize = 0;
        while (l < size) {
            if (currentPos == bufLen) {
                bufLen = f->read(bufData, BUF_SIZE);
                currentPos = 0;
            }
            copySize = qMin(bufLen - currentPos, size - l);
            if (0 == copySize) {
                break;
            }
            memcpy(data + l, bufData + currentPos, copySize);
            l += copySize;
            currentPos += copySize;
        }
    } else {
        l = f->read(data, size);
    }
    return l;
}

qint64 LocalFileAdapter::writeBlock(const char* data, qint64 size) {
    SAFE_POINT(isOpen(), "Adapter is not opened!",-1);
    qint64 l = f->write(data, size);
    return l;
}

bool LocalFileAdapter::skip(qint64 nBytes) {
    SAFE_POINT(isOpen(), "Adapter is not opened!",false);
    if (bufferOptimization) {
        qint64 newPos = currentPos + nBytes;
        if (newPos < 0 || newPos >= bufLen) {
            qint64 p = f->pos();
            bool res = f->seek((p - bufLen + currentPos) + nBytes);

            bufLen = 0;
            currentPos = 0;
            return res;
        } else {
            currentPos = newPos;
            return true;
        }
    } else {
        qint64 p = f->pos();
        return f->seek(p+nBytes);
    }
}

qint64 LocalFileAdapter::left() const {
    SAFE_POINT(isOpen(), "Adapter is not opened!",-1);
    qint64 p = f->pos();
    qint64 len = f->size();
    if (bufferOptimization) {
        p -= bufLen - currentPos;
    }
    return len - p;
}

int LocalFileAdapter::getProgress() const {
    SAFE_POINT(isOpen(), "Adapter is not opened!",false);
    return int(100 * float(bytesRead()) / f->size());
}

qint64 LocalFileAdapter::bytesRead() const {
    qint64 p = f->pos();
    if (bufferOptimization) {
        p -= bufLen - currentPos;
    }
    return p;
}

Url LocalFileAdapter::getURL() const {
    return Url(f->fileName(), Url_File);
}


} // namespace BioQt
