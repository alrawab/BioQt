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

#ifndef SEQIOEXCEPTION_H
#define SEQIOEXCEPTION_H
#include <BioQt_global.h>
#include <Utils/Exceptions/BioQtException.h>
#include <QtCore>

namespace BioQt {

class  FileNotFoundException : public BioQtException
{
public:
    FileNotFoundException(const QString& text):BioQtException(QString("BioQtException::FileNotFoundException: %1").arg(text)){};
};

class  IllegalFormatException : public BioQtException
{
public:
    IllegalFormatException(const QString& text):BioQtException(QString("BioQtException::IllegalFormatException: %1").arg(text)){};
};

class  EmptyURLException : public BioQtException
{
public:
    EmptyURLException(const QString& text):BioQtException(QString("BioQtException::EmptyURLException: %1").arg(text)){};
};

class  LineOutOfRangeException : public BioQtException
{
public:
    LineOutOfRangeException(const QString& text):BioQtException(QString("BioQtException::LineOutOfRangeException: %1").arg(text)){};
};

class  SequenceFormatException : public BioQtException
{
public:
    SequenceFormatException(const QString& text):BioQtException(QString("BioQtException::SequenceFormatException: %1").arg(text)){};
};


class  IOErrorException : public BioQtException
{
public:
    IOErrorException(const QString& text):BioQtException(QString("BioQtException::IOErrorException: %1").arg(text)){};
};

class ParseException : public BioQtException
{
public:
    ParseException(const QString& text):BioQtException(QString("BioQtException::ParseException: %1").arg(text)){};
};
/*
class InvalidFastaRecordException : public BioQtException
{
public:
    InvalidFastaRecordException(const QString& text):BioQtException(QString("BioQtException::SeqIOException: %1").arg(text)){};
};


class UnreadableStreamException : public BioQtException
{
public:
    UnreadableStreamException(const QString& text):BioQtException(QString("BioQtException::SeqIOException: %1").arg(text)){};
};

class ParserException : public BioQtException
{
public:
    ParserException(const QString& text):BioQtException(QString("BioQtException::SeqIOException: %1").arg(text)){};
};

*/


} // namespace BioQt

#endif // BIOQT_SEQIOEXCEPTION_H
