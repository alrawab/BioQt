/*****************************************************************************************
                        BioQt - Integrated Bioinformatics Library
Copyright (C) 2012-2013 Usama S Erawab <alrawab@hotmail.com> Libya
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

#ifndef BIOQT_DNA_H
#define BIOQT_DNA_H
#include <BioQt_global.h>
#include <Alphabet/Alphabet.h>
#include <QtCore>
#include <Compound/CompoundTable.h>
#include <Data/QIUPACData.h>
namespace BioQt {

class BIOQTSHARED_EXPORT DNA : public AlphaBet
{
public:
    DNA(Qt::CaseSensitivity CMode=Qt::CaseInsensitive);
 virtual    ~DNA(){};

    unsigned int GetBinary(const QString& Base)const throw (UnCompatibleCharException) ;
    unsigned int GetBinary(int Base) const  throw (UnCompatibleIntException);
    unsigned int getBaseCodingSize() const {return 1;};
//*********************************************************************************

public:


 QString GetFullName(int Base) const  throw (UnCompatibleIntException)  ;
//******************************************************************************************************************//
 QString GetFullName(const QString& Base) const throw (UnCompatibleCharException) ;
//********************************************************************************************************************************//
 bool isIntInAlphabet(int Base) const ;
//----------------------------------------------------------------------------------------------------------//
 bool isCharInAlphabet(const QString& Base) const ;
 //--------------------------------------------------------------------------------------------------------
 QString intToChar(int Base) const throw (UnCompatibleIntException) ;
//*******************************************************************************************************
 int charToInt(const QString& Base) const throw (UnCompatibleCharException) ;
//-----------------------------------------------------------------------------------------------------------------------
 unsigned int GetNumberOfChars() const ;
//*************************************************************************************************
 unsigned int GetNumberOfTypes() const ;
//************************************************************************************************************
 unsigned int GetSize() const ;
//***********************************************************************************************************************
 QList<int> getAlias(int Base) const throw (UnCompatibleIntException) ;
//********************************************************************************************************
 QList<QString> getAlias(const QString& Base) const throw (UnCompatibleCharException) ;
//**********************************************************************
  QList<int> getSupportedInts() const ;
//*****************************************************************************************
  QStringList getSupportedChars() const ;
//*****************************************************************************
 int getGapCharacterCode() const ;
//*************************************************************************
 bool isGap(int Base) const ;
//*********************************************************************************
 bool isGap(const QString& Base) const ;
//**************************************************************************************
 bool isUnresolved(int Base) const ;
//******************************************************************************************************
 bool isUnresolved(const QString& Base) const ;
//***********************************************************************************************
 QString getAlphabetType() const ;

//***********************************************************************************************
private :

 Qt::CaseSensitivity     caseMode;
 QList<CompoundTable> cmptb;
};

} // namespace BioQt

#endif // BIOQT_DNA_H
