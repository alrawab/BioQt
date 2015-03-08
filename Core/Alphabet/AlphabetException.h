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

#ifndef ALPHABETEXCEPTION_H
#define ALPHABETEXCEPTION_H
#include <BioQt_global.h>
#include <Utils/Exceptions/BioQtException.h>
class Alphabet;
namespace BioQt {

//------------------------------------------------------------------------------------------------//
/**
 * @brief An alphabet exception thrown when trying to specify a UnCompatible char to the alphabet.
 */
class  UnCompatibleCharException:
  public BioQtException
{
    public:
    UnCompatibleCharException(const QString& text):BioQtException(QString("BioQtException::UnCompatibleCharException: %1").arg(text)){};
};

//--------------------------------------------------------------------------------
/**
 * @brief An alphabet exception thrown when trying to specify a UnCompatible int to the alphabet.
 */
class  UnCompatibleIntException:
  public BioQtException
{
    public:
   UnCompatibleIntException(const QString& text):BioQtException(QString("BioQtException::UnCompatibleIntException: %1").arg(text)){};
};

} // namespace BioQt

#endif // BIOQT_ALPHABETEXCEPTION_H
