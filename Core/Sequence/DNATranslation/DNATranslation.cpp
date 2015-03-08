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

#include "DNATranslation.h"

namespace BioQt {




DNATranslation::DNATranslation(const QSequence &_seq, Frames _fram, Strand _starns)
    :Seq(_seq),frame(_fram),strans(_starns)
{

}

DNATranslation::~DNATranslation()
{

}
/*
QSequence DNATranslation::GetTranslation(const QString &_Tbn)throw(EmptySequenceException)
{
    if(Seq.isEmpty()|| Seq.isNull())
    {
        throw EmptySequenceException("BioQt::DNATranslation the Sequence Is empty");
    }
    GeneticCode alpha= GeneticCodeQuery::recod(_Tbn);

    QSequence Tmp;
    for (int i =frame-1; i < Seq.size() - 2; i+=3)
    {
        for(int j=frame-1;j <alpha.AMS().size();++j)
        {
            if(Seq[i]==alpha.Base1()[j]&&Seq[i+1]==alpha.Base2()[j]&&Seq[i+2]==alpha.Base3()[j])
            Tmp.append(alpha.Starts()[j]);
        }

    }


    return Tmp;
}
*/
QSequence DNATranslation::GetTranslation(int _Tbn)
{

    if(Seq.isEmpty()|| Seq.isNull())
    {
        throw EmptySequenceException("BioQt::DNATranslation the Sequence Is empty");
    }
    GeneticCode alpha= GeneticCodeQuery::recod(_Tbn);

    QSequence Tmp;
    QSequence fi;
    if(strans==Forward)
        fi=Seq;
    else
        fi=GetRevComp();

    for (int i =frame-1; i < fi.size() ; i+=3)
    {

        for(int j=0;j <alpha.AMS().size();++j)
        {
            if(fi[i]==alpha.Base1()[j]&&
                    fi[i+1]==alpha.Base2()[j]&&
                    fi[i+2]==alpha.Base3()[j])
            Tmp.append(alpha.AMS()[j]);

        }

    }
if(strans==Backward)
    return SequenceTools::Reverse(Tmp);

    return Tmp;
}

} // namespace BioQt

