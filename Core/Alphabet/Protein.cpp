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

#include <Alphabet/Protein.h>
#include <assert.h>

namespace BioQt {

Protein::Protein(Qt::CaseSensitivity CMode):
    caseMode(CMode)
{
     cmptb=QIUPACData::AminoTable();
}



QString Protein::GetFullName(int Base) const  throw (UnCompatibleIntException)
{
    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
    foreach(ProteinTable c,QIUPACData::AminoTable())
    {
        if(c.id()==Base)
            return c.fname();
    }

}

//******************************************************************************************************************//
QString Protein::GetFullName(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base.toUpper()))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
    foreach(ProteinTable c,QIUPACData::AminoTable())
    {
        if(QString::compare(c.sname(),Base,caseMode)==0)
            return c.fname();
    }
}

//********************************************************************************************************************************//
bool Protein::isIntInAlphabet(int Base) const
{
    if(Base <-1 ||Base >22)
        return false;
    return true;
}
//----------------------------------------------------------------------------------------------------------//
bool Protein::isCharInAlphabet(const QString& Base) const
{
    assert(Base.size()==1);
    return getSupportedChars().contains(Base,caseMode);
}
//--------------------------------------------------------------------------------------------------------
QString Protein::intToChar(int Base) const throw (UnCompatibleIntException)
{


    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
    foreach(ProteinTable c,QIUPACData::AminoTable())
    {
        if(c.id()==Base)
            return c.sname();
    }



}

//*******************************************************************************************************///
int Protein::charToInt(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base.toUpper()))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
    foreach(ProteinTable c,QIUPACData::AminoTable())
    {
        if(QString::compare(c.sname(),Base,caseMode)==0)
            return c.id();
    }


}

//-----------------------------------------------------------------------------------------------------------------------//
unsigned int Protein::GetNumberOfChars() const
{
    return 28;
}
//*************************************************************************************************//
unsigned int Protein::GetNumberOfTypes() const
{
    return 23;
}
//************************************************************************************************************//
unsigned int Protein::GetSize() const
{
    return 20;
}
//***********************************************************************************************************************
QList<int> Protein::getAlias(int Base) const throw (UnCompatibleIntException)
{
    if(!isIntInAlphabet(Base))
        throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");

        QList<int> tmp;
         if(Base== 20) {// N or D
             tmp<<2<<3;
          } else if(Base == 21) {// Q or E
             tmp<<5<<6;
             } else if(Base == 22) {// all!

             for(unsigned int i = 0; i < 20; i++) tmp<< i;
             } else {
                 tmp<<Base;
    }
    return tmp;
}

//********************************************************************************************************
QList<QString> Protein::getAlias(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base.toUpper()))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");

    QList<QString> tmp;
       //--------------------------------
       if(QString::compare(Base,"B",caseMode)==0)// N or D
       {
           tmp<<"N"<<"D";
       qDebug()<<1;
       }
       else if(QString::compare(Base,"Z",caseMode)==0)// Q or E
        {   tmp<<"Q"<<"E";
        qDebug()<<2;
       }
       else if(QString::compare(Base,"X",caseMode)==0
               ||QString::compare(Base,"0",caseMode)==0
               ||QString::compare(Base,"O",caseMode)==0
               ||QString::compare(Base,"?",caseMode)==0)
       {// all!
            for(unsigned int i = 0; i < 20; i++)
                tmp<<intToChar(i);
       }
       else
           tmp<<Base;


       //------------------------------
   return tmp;
}

//**********************************************************************///
QList<int> Protein::getSupportedInts() const
{
    QList<int> tmp;

    Q_FOREACH(ProteinTable c,cmptb)
    {

        tmp<<c.id();
    }

    return tmp;
}
//*****************************************************************************************///
QStringList Protein::getSupportedChars() const
{
    QStringList tmp;

    Q_FOREACH(ProteinTable c,cmptb)
    {

        tmp<<c.sname();
    }

    return tmp;

}
//*****************************************************************************///
int Protein::getGapCharacterCode() const
{
    return -1;
}
//*************************************************************************///
bool Protein::isGap(int Base) const
{
    return Base == -1;
}
//*********************************************************************************///
bool Protein::isGap(const QString& Base) const
{

    return charToInt(Base) == -1;
}
//**************************************************************************************///
bool Protein::isUnresolved(int Base) const
{
    return Base == 19;
}
//******************************************************************************************************///
bool Protein::isUnresolved(const QString& Base) const
{

    return   charToInt(Base) == 19;
}
//***********************************************************************************************///
QString Protein::getAlphabetType() const
{
    return "Protein alphabet";
}
/////////////////////////////\\\\\\\\\\\\\\\\\\\\\\|||||||||||||||||||||||||||||||||||||||||||||||\

unsigned int Protein::GetBinary(const QString& Base) const throw (UnCompatibleCharException)
{
    if(!isCharInAlphabet(Base.toUpper()))
        throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
    foreach(ProteinTable c,QIUPACData::AminoTable())
    {
       // if(QString::compare(c.sname(),Base,caseMode)==0)
            //return c.BinaryVal();

    }

}
    unsigned int Protein::GetBinary(int Base) const  throw (UnCompatibleIntException)
    {
        if(!isIntInAlphabet(Base))
            throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
        foreach(ProteinTable c,QIUPACData::AminoTable())
        {
          //  if(c.id()==Base)
             //   return c.BinaryVal();
        }

    }
    //***********************
    QString Protein::Get1to3L(int Base) const throw(UnCompatibleIntException)
    {
         if(!isIntInAlphabet(Base))
            throw UnCompatibleIntException("BioQt::AlphabetException UnHandled integer ");
        foreach(ProteinTable c,QIUPACData::AminoTable())
        {
            if(c.id()==Base)
                return c.Iletter_code();
        }
    }

    QString Protein::Get1to3L(const QString& Base) const throw(UnCompatibleCharException)
    {
        if(!isCharInAlphabet(Base.toUpper()))
            throw UnCompatibleCharException("BioQt::AlphabetException Uncompatible letter");
        foreach(ProteinTable c,QIUPACData::AminoTable())
        {
            if(QString::compare(c.sname(),Base,caseMode)==0)
                return c.Iletter_code();

        }
    }

} // namespace BioQt
