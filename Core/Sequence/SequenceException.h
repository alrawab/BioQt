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

#ifndef SEQUENCEEXCEPTION_H
#define SEQUENCEEXCEPTION_H

#include <BioQt_global.h>
#include <Utils/Exceptions/BioQtException.h>

namespace BioQt {

class EmptySequenceException : public BioQtException
{
public:
    EmptySequenceException(const QString& text):BioQtException(QString("BioQtException::EmptySequenceException: %1").arg(text)){};
};
//==================================================================================
class NonIupacBase : public BioQtException
{
public:
    NonIupacBase(const QString& text):BioQtException(QString("BioQtException::NonIupacBase: %1").arg(text)){};
};
//==================================================================================
//-----------------------------
class InvalidDNASequence : public BioQtException
{
public:
    InvalidDNASequence(const QString& text):BioQtException(QString("BioQtException::InvalidDNASequence: %1").arg(text)){};
};
//==================================================================================
class InvalidIupacSequence : public BioQtException
{
public:
    InvalidIupacSequence(const QString& text):BioQtException(QString("BioQtException::InvalidIupacSequence: %1").arg(text)){};
};
//==================================================================================
class InvalidIntValue : public BioQtException
{
public:
    InvalidIntValue(const QString& text):BioQtException(QString("BioQtException::InvalidIntValue: %1").arg(text)){};
};

class BadChar : public BioQtException
{
public:
    BadChar(const QString& text):BioQtException(QString("BioQtException::BadChar: %1").arg(text)){};
};

class ArgumentOutOfRangeException : public BioQtException
{
public:
    ArgumentOutOfRangeException(const QString& text):BioQtException(QString("BioQtException::ArgumentOutOfRangeException: %1").arg(text)){};
};


} // namespace BioQt

#endif // BIOQT_SEQUENCEEXCEPTION_H
