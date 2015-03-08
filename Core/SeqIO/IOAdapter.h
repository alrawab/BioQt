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



#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <BioQt_global.h>
#include <QtCore>
#include "Url.h"
namespace BioQt {

/**
*BioQt::IOAdapter
*@author Usama S Erawab
*
*/
//#define BUFF_SIZE 8196
//#define CHECK_MB 1024*1024
typedef QString IOAdapterId;
static const QBitArray LINE_BREAKS;
enum TriState {
    TriState_Unknown,
    TriState_Yes,
    TriState_No
};

enum IOAdapterMode {
    IOAdapterMode_Read,
    IOAdapterMode_Write,
    IOAdapterMode_Append
};

class IOAdapter;


class BIOQTSHARED_EXPORT IOAdapter : public QObject {
    Q_OBJECT
public:
    IOAdapter( QObject* o = NULL) : QObject(o){}
    virtual ~IOAdapter(){}



    virtual bool open(const Url& url, IOAdapterMode m) = 0;

    virtual bool isOpen() const = 0;

    virtual void close() = 0;

    enum TerminatorHandling {
        Term_Exclude,   // stop before terminators
        Term_Include,   // include all terminators into result
        Term_Skip       // do not include terminators to the result, but skip to after last terminator
    };

    //return 0 if at the end of file, -1 if error
    virtual qint64 readUntil(char* buff, qint64 maxSize, const QBitArray& readTerminators,
        TerminatorHandling th, bool* terminatorFound = 0);

    virtual bool getChar(char* buff) {return 1 == readBlock(buff, 1);}

    //If an error occurs, this function returns -1
    virtual qint64 readBlock(char* buff, qint64 maxSize) = 0;

    //read a single line of text and skips one EOL, returns length of line w/o terminator or -1
    virtual qint64 readLine(char* buff, qint64 maxSize, bool* terminatorFound = 0);

    virtual qint64 writeBlock(const char* buff, qint64 size) = 0;

    qint64 writeBlock(const QByteArray& a) {return writeBlock(a.data(), a.size());}


    virtual bool skip(qint64 nBytes) = 0;

    //returns -1 if not supported
    virtual qint64 left() const = 0;

    /* Percent values in range 0..100, negative if unknown. */
    virtual int getProgress() const = 0;

    bool isEof();

    virtual qint64 bytesRead() const { return -1; }

    virtual Url getURL() const = 0;

    virtual QString toString() const {return getURL().getURLString();}


};


//-------------------------------------------------------------------
class BIOQTSHARED_EXPORT BaseIOAdapters {
public:
    static const IOAdapterId LOCAL_FILE;
    static const IOAdapterId GZIPPED_LOCAL_FILE;
    static const IOAdapterId STRING;
};

} // namespace BioQt

#endif // BIOQT_IOADAPTER_H
