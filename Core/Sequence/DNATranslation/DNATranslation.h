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

#ifndef BIOQT_DNATRANSLATION_H
#define BIOQT_DNATRANSLATION_H

#include <QtCore>
#include <BioQt_global.h>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceTools.h>
#include <Sequence/SequenceException.h>
#include <Sequence/DNATranslation/GeneticCodeData.h>
#include <Sequence/DNATranslation/GeneticCodeQuery.h>


namespace BioQt {

typedef BIOQTSHARED_EXPORT enum Frames
{

    Frame1 = 1,
    Frame2 = 2,
    Frame3 = 3
}Frames;
//***********************************
typedef enum Strand
{
    Forward=1,
    Backward=-1
}Strand;
//**********************************************


class BIOQTSHARED_EXPORT DNATranslation
{
public:
   // DNATranslation(){}
    /**
     * @brief DNATranslation
     * @param _seq
     * @param _fram
     * @param _starns
     */
    DNATranslation(const QSequence &_seq,Frames _fram=Frame1,Strand _starns=Forward);

    ~DNATranslation();
    /**
     * @brief GetRevComp
     * @return
     */
    QSequence GetRevComp(){return SequenceTools::Reverse( SequenceTools::GetComplement(Seq));};
    /**
     * @brief SetFrame
     * @param _frame
     */
    inline void SetFrame(Frames _frame){frame=_frame;}
    /**
     * @brief SetStran
     * @param _strans
     */
    inline void SetStrand(Strand _strans){strans=_strans;}
    /**
     * @brief GetFrames
     * @return
     */
    inline Frames GetFrames(){return frame;}
    /**
     * @brief GetStrands
     * @return
     */
    inline Strand GetStrands(){return strans;}
    /**
     * @brief GetTranslation
     * @return
     */
  //  QSequence GetTranslation(const QString &_Tbn="Standard") throw(EmptySequenceException);

    QSequence GetTranslation(int _Tbn=1) throw(EmptySequenceException);
    inline QSequence GetSequence(){return Seq;}
private :
    QSequence Seq;
    QSequence RevComp;
    Frames frame;
    Strand strans;
    GeneticCode * geneticcode;

};

} // namespace BioQt

#endif // BIOQT_DNATRANSLATION_H
