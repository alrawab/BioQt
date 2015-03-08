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

/**
*BioQt::GenBankLocusInfo
*@author Usama S Erawab
*
*/

#ifndef GENBANKLOCUSINFO_H
#define GENBANKLOCUSINFO_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/SeqInfo.h>
namespace BioQt {
/**
 * @brief The GenBankLocusInfo class Locus provides a short mnemonic name for the sequence entry in gen bank
 * database, chosen to suggest the sequence's definition.
 * It also contains information like Sequence type, Strand type division code etc.
 */
class BIOQTSHARED_EXPORT GenBankLocusInfo
{
public:
    GenBankLocusInfo(){}

    /**
     * @brief Name name for the sequence entry.
     */
    QString Name;

    /**
     * @brief SequenceLength length of the sequence
     */
    int SequenceLength ;

    /**
     * @brief SequenceType Sequence type specifies whether the sequence is a DNA ,RNA or AMino Acid etc..
     */
    QString SequenceType ;

    /**
     * @brief Strand A StrandType specifies whether sequence occurs as a single stranded,
     * double stranded or mixed stranded.
     */
   /* SequenceStrandType*/QString Strand;

    /**
      * @brief MoleType  Specifies type of the biological sequence.
      */
    /*MoleculesType*/QString MoleType ;

    /**
     * @brief StrandTopology A StrandTopology specifies whether the strand is linear or circular.
     */
    /*SequenceStrandTopology*/QString StrandTopology;


    /**
     * @brief DivisionCode A DivisionCode specifies which family a sequence belongs to.
     */
    /*SequenceDivisionCode*/ QString DivisionCode ;

    QString LocusDate;


};

} // namespace BioQt

#endif // BIOQT_GENBANKLOCUSINFO_H
