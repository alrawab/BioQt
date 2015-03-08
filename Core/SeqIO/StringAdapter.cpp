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


#include "StringAdapter.h"

namespace BioQt {





StringAdapter::StringAdapter( QObject *o)
: opened(false)
{

}

bool StringAdapter::open(const Url &, IOAdapterMode) {
    buffer.clear();
    opened = true;

    return true;
}

void StringAdapter::close() {
    buffer.clear();
    opened = false;
}

qint64 StringAdapter::readBlock(char * /*data*/, qint64 /*maxSize*/) {
    // todo
    return -1;
}

qint64 StringAdapter::writeBlock(const char* data, qint64 size) {
    QByteArray ar(data, size);
    buffer += ar;
    return size;
}

bool StringAdapter::skip(qint64 /*nBytes*/) {
    // todo
    return false;
}

qint64 StringAdapter::left() const {
    // todo
    return -1;
}

int StringAdapter::getProgress() const {
    // todo
    return -1;
}

qint64 StringAdapter::bytesRead() const {
    // todo
    return -1;
}


} // namespace BioQt
