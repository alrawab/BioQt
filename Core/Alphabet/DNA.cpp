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

#include <Alphabet/DNA.h>
#include <Alphabet/AlphabetException.h>
#include <assert.h>
namespace BioQt {

DNA::DNA(Qt::CaseSensitivity CMode):
    caseMode(CMode)

{
    cmptb=QIUPACData::DnaTable();

}


QString DNA::GetFullName(int Base) const  throw (UnCompatibleIntException)
{
    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
    foreach(CompoundTable c,QIUPACData::DnaTable())
    {
        if(c.id()==Base)
            return c.fname();
    }

}

//******************************************************************************************************************//
QString DNA::GetFullName(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base))
        throw UnCompatibleCharException("BioQt::AlphabetException  Uncompatible letter");
    foreach(CompoundTable c,QIUPACData::DnaTable())
    {
        if(QString::compare(c.sname(),Base,caseMode)==0)
            return c.fname();
    }
}

//********************************************************************************************************************************//
bool DNA::isIntInAlphabet(int Base) const
{
    if(Base <-1 ||Base >14)
        return false;
    return true;
}
//----------------------------------------------------------------------------------------------------------//
bool DNA::isCharInAlphabet(const QString& Base) const
{
    assert(Base.size()==1);
    return getSupportedChars().contains(Base,caseMode);
}
//--------------------------------------------------------------------------------------------------------
QString DNA::intToChar(int Base) const throw (UnCompatibleIntException)
{


    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
    foreach(CompoundTable c,QIUPACData::DnaTable())
    {
        if(c.id()==Base)
            return c.sname();
    }



}

//*******************************************************************************************************///
int DNA::charToInt(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
    foreach(CompoundTable c,QIUPACData::DnaTable())
    {
        if(QString::compare(c.sname(),Base,caseMode)==0)
            return c.id();
    }


}

//-----------------------------------------------------------------------------------------------------------------------//
unsigned int DNA::GetNumberOfChars() const
{
    return 20;
}
//*************************************************************************************************//
unsigned int DNA::GetNumberOfTypes() const
{
    return 15;
}
//************************************************************************************************************//
unsigned int DNA::GetSize() const
{
    return 4;
}
//***********************************************************************************************************************
QList<int> DNA::getAlias(int Base) const throw (UnCompatibleIntException)
{
    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
    QList<int> tmp;
    if (GetBinary(Base) & 1)
        tmp<<0;
    if (GetBinary(Base) & 2)
        tmp<<1;
    if (GetBinary(Base) & 4)
        tmp<<2;
    if (GetBinary(Base) & 8)
        tmp<<3;
    return tmp;
}

//********************************************************************************************************
QList<QString> DNA::getAlias(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");

    int x=charToInt(Base);
    QList<QString> tmp;
    if (GetBinary(x) & 1)
        tmp<<intToChar(0);
      if (GetBinary(x) & 2)
       tmp<<intToChar(1);
      if (GetBinary(x) & 4)
        tmp<<intToChar(2);
      if (GetBinary(x) & 8)
      tmp<<intToChar(3);
return tmp;
}

//**********************************************************************///
QList<int> DNA::getSupportedInts() const
{
    QList<int> tmp;

    Q_FOREACH(CompoundTable c,cmptb)
    {

        tmp<<c.id();
    }

    return tmp;
}
//*****************************************************************************************///
QStringList DNA::getSupportedChars() const
{
    QStringList tmp;

    Q_FOREACH(CompoundTable c,cmptb)
    {

        tmp<<c.sname();
    }

    return tmp;

}
//*****************************************************************************///
int DNA::getGapCharacterCode() const
{
    return -1;
}
//*************************************************************************///
bool DNA::isGap(int Base) const
{
    return Base == -1;
}
//*********************************************************************************///
bool DNA::isGap(const QString& Base) const
{

    return charToInt(Base) == -1;
}
//**************************************************************************************///
bool DNA::isUnresolved(int Base) const
{
    return Base == 15;
}
//******************************************************************************************************///
bool DNA::isUnresolved(const QString& Base) const
{

    return   charToInt(Base) == 15;
}
//***********************************************************************************************///
QString DNA::getAlphabetType() const
{
    return "DNA alphabet";
}
/////////////////////////////\\\\\\\\\\\\\\\\\\\\\\|||||||||||||||||||||||||||||||||||||||||||||||\

unsigned int DNA::GetBinary(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
    foreach(CompoundTable c,QIUPACData::DnaTable())
    {
        if(QString::compare(c.sname(),Base,caseMode)==0)
            return c.BinaryVal();

    }

}
    unsigned int DNA::GetBinary(int Base) const  throw (UnCompatibleIntException)
    {
        if(!isIntInAlphabet(Base))
            throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
        foreach(CompoundTable c,QIUPACData::DnaTable())
        {
            if(c.id()==Base)
                return c.BinaryVal();
        }

    }

} // namespace BioQt
