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



#ifndef LOCALFILEADAPTER_H
#define LOCALFILEADAPTER_H
#include <BioQt_global.h>
#include <QtCore>
#include "IOAdapter.h"


namespace BioQt {
/**
*BioQt::LocalFileAdapter
*@author Usama S Erawab
*
*/



class BIOQTSHARED_EXPORT LocalFileAdapter: public IOAdapter {
    Q_OBJECT
public:
    LocalFileAdapter(QObject* o = NULL, bool bufferOptimization = false);
    ~LocalFileAdapter() {if (isOpen()) close();}

    virtual bool open(const Url& url, IOAdapterMode m);

    virtual bool isOpen() const {return f!=NULL;}

    virtual void close();

    virtual qint64 readBlock(char* data, qint64 maxSize);

    virtual qint64 writeBlock(const char* data, qint64 size);

    virtual bool skip(qint64 nBytes);

    virtual qint64 left() const;
    virtual int getProgress() const;

    virtual qint64 bytesRead() const;

    virtual Url getURL() const;

private:
    QFile* f;

    bool bufferOptimization;
    QByteArray buffer;
    char *bufData;
    qint64 bufLen;
    qint64 currentPos;
    static const quint64 BUF_SIZE;
};

} // namespace BioQt

#endif // BIOQT_LOCALFILEADAPTER_H
