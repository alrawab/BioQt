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

#ifndef QSEQUENCE_H
#define QSEQUENCE_H
#include <BioQt_global.h>
#include <QtCore>
#include <windef.h>
#include <Alphabet/Alphabet.h>
#include <Alphabet/DNA.h>
#include <Alphabet/RNA.h>
#include <Alphabet/Protein.h>
#include <Alphabet/AlphabetException.h>
#include "SeqInfo.h"
namespace BioQt {
/*
typedef enum SeqAlphabetType {
    DNAAlphabet,
    RNAAlphabet,
    AMINOAlphabet
}SeqAlphabetType;
*/

class BIOQTSHARED_EXPORT QSequence :public QString,public SeqInfo
{

public:
    QSequence(AlphaBet *_alpha=NULL,const QString &_name="generic_sequence")
    {
    //    this->replace(QRegExp("[\\n|\\s|\\t]"),"");
        SetID(_name);
     //   SetMol(eMol_not_set);
      //  SetTopology(eTopology_linear);
        replace(QRegExp("[\\r]\[\\d]|[\\n|\\s|\\t]"),"");


    }

    QSequence(const QString & other,AlphaBet *_alpha=NULL,const QString &_name="generic_sequence"):QString(other)
    {
    //    this->replace(QRegExp("[\\n|\\s|\\t]"),"");
        SetID(_name);
      //  SetMol(eMol_not_set);
     //   SetTopology(eTopology_linear);
        replace(QRegExp("[\\r]\[\\d]|[\\n|\\s|\\t]"),"");

    }

    QSequence(const char * str,AlphaBet *_alpha=NULL,const QString &_name="generic_sequence" ):QString(str)
    {
    //    this->replace(QRegExp("[\\n|\\s|\\t]"),"");
        SetID(_name);
      //  SetMol(eMol_not_set);
     //   SetTopology(eTopology_linear);
        replace(QRegExp("[\\r]\[\\d]|[\\n|\\s|\\t]"),"");


    }


    void SetName(const QString & name) {SetID(name);}
    QString GetName()const {return GetID();}
    void SetAlpha(AlphaBet * _alpha){alpha=_alpha;}
    AlphaBet * GetAlpha(){return alpha;}



private :
   // SeqAlphabetType seqalphatype;
    AlphaBet * alpha;
        QString name;
   // Q_DECLARE_METATYPE(QSequence *);
};

class BIOQTSHARED_EXPORT Triplet
{
public:
       Triplet(const QSequence& seq){Base[0]=seq[0];Base[1]=seq[1];Base[2]=seq[2];}
       QSequence ToSequnce( ){return QString("%1%2%3").arg(Base[0]).arg(Base[1]).arg(Base[2]);}
       QChar Base[3];
};



} // namespace BioQt
Q_DECLARE_METATYPE(BioQt::QSequence);
//Q_DECLARE_METATYPE(BioQt::Triplet);
#endif // BIOQT_QSEQUENCE_H
