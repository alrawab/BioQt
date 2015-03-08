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

#ifndef MOLECULETYPE_H
#define MOLECULETYPE_H
#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceException.h>
#include <Data/QIUPACData.h>
namespace BioQt {
/**
 * @brief The MoleculeType class
 *@author Usama S Erawab
 */
class BIOQTSHARED_EXPORT MoleculeType
{
public:
    /**
     * @brief GuessAlphabet
     * @param seq
     * @param threshold
     * @param index
     * @param length
     * @return
     */
    static QString GuessAlphabet(const QSequence& seq,double threshold=0.95,int index=0,int length=100)throw (EmptySequenceException);
    /**
     * @brief Guess
     *this method imported from bioruby ( bio/sequence.rb).
     * @param seq
     * @param threshold (defaults set to 0.9) is the frequency of nucleic acid bases [AGCTUagctu] required in the sequence for this method
     *to produce a Nucleotide Sequence.
     *In the default case, if less than 90% of the bases (after excluding [Nn]) are in the set [AGCTUagctu],
     * then the guess is Protein Sequence.
     *ex :
     * Guess("atgcatgcqq")      #=> Protein Sequence.
     *Guess("atgcatgcqq", 0.8) #=> Protein Sequence.
     *Guess("atgcatgcqq", 0.7) #=> Nucleotide Sequence.
     * @param index not implemented in this version.
     * @param length not implemented in this version.
     * @return
     */
    static QString Guess(const QSequence& seq,double threshold=0.9,int index=0,int length=100)throw (EmptySequenceException);

};

} // namespace BioQt

#endif // BIOQT_MOLECULETYPE_H
