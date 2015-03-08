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

#include "MoleculeType.h"

namespace BioQt {

QString MoleculeType::GuessAlphabet(const QSequence& seq,double threshold,int index,int length)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::MoleculeType the Sequence Is empty");


    int SeqCount = 1;
    int ColCount = seq.size();
    int DNACount = 0;
    int RNACount = 0;
    int amino_count=0;
    int Total = 0;
    int i = 0;
    Q_FOREACH(QChar base,seq)
    {
        int SeqIndex = i / ColCount;
        if (SeqIndex >= SeqCount)
            break;
        int ColIndex = i % ColCount;
        ++i;
        if(QIUPACData::GapChars.contains(base,Qt::CaseInsensitive))
            continue;
        if(QIUPACData::Ambiguous_DNA_Chars.contains(base,Qt::CaseInsensitive))
            DNACount++;
        if (QIUPACData::Ambiguous_RNA_Chars.contains(base,Qt::CaseInsensitive))
            RNACount++;
        if (QIUPACData::Protein_Chars.contains(base,Qt::CaseInsensitive))
            amino_count++;
        Total++;
        if (Total >= length)
            break;
    }
  //  qDebug()<<RNACount<<" dna "<<DNACount<<" pro "<<amino_count<<" total "<<Total;
    if (Total != 0 && ((RNACount * 100) / Total) >= (threshold *100))
        return "RNA alphabet";
    if (Total != 0 && ((DNACount * 100) / Total) >= (threshold *100))
        return "DNA alphabet";
    if (Total != 0 && ((amino_count * 100) / Total) >= (threshold *100))
        return "Protein alphabet";
    return "unknown alphabet" ;

}
//-----
QString MoleculeType::Guess(const QSequence& seq,double threshold,int index,int length)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::MoleculeType the Sequence Is empty");

    int bases=0;
    int n_base=0;
    Q_FOREACH(QChar b,seq)
    {

        if(b=='N'||b=='n')
            n_base++;
         if(QIUPACData::NucleotideChars.contains(b,Qt::CaseInsensitive))
             bases++;

    }
    int total = seq.length() - n_base;

    if((double)bases/total >threshold)

        return "Nucleotide Sequence";
        else
                return "Protein Sequence";


}

} // namespace BioQt
