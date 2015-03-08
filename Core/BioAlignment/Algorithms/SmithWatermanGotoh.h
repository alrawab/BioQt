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

#ifndef SMITHWATERMANGOTOH_H
#define SMITHWATERMANGOTOH_H

#include <BioQt_global.h>
#include <QtCore>
#include <BioAlignment/Alignment.h>
#include <BioAlignment/SubstMatrix/SMatrix.h>
#include <BioAlignment/SubstMatrix/Cell.h>
#include <Sequence/QSequence.h>



namespace BioQt {
/**
 * Smith and Waterman developed an efficient dynamic programming algorithm to
 * perform local sequence alignments, which returns the most conserved region of
 * two sequences (longest common substring with modifications). It
 * uses affine gap penalties if and only if the expenses of a delete or insert
 * operation are unequal to the expenses of gap extension. This uses
 * significantly more memory (four times as much) and increases the runtime if
 * swapping is performed.
 *
 * @author Usama S Erawab

 */
class BIOQTSHARED_EXPORT SmithWatermanGotoh
{
public:
    /**
     * @brief align
     * @param seq1
     * @param seq2
     * @param matrix
     * @param _OpenGapPenalty
     * @param _ExtendGapPenalty
     * @return
     */
    static Alignment align(const QSequence& seq1, const QSequence& seq2, SMatrix matrix, float _OpenGapPenalty, float _ExtendGapPenalty);
private:
    /**
     * @brief construct
     * @param seq1
     * @param seq2
     * @param matrix
     * @param _OpenGapPenalty
     * @param _ExtendGapPenalty
     * @param pointers
     * @param sizesOfVerticalGaps
     * @param sizesOfHorizontalGaps
     * @return
     */
    static Cell * construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float _OpenGapPenalty,
                          float _ExtendGapPenalty, QVector<int> pointers,QVector<short> sizesOfVerticalGaps,QVector<short> sizesOfHorizontalGaps);

    /**
    * @brief traceback
    * @param s1
    * @param s2
    * @param m
    * @param pointers
    * @param cell
    * @param sizesOfVerticalGaps
    * @param sizesOfHorizontalGaps
    * @return
    */
   static Alignment traceback(QSequence s1, QSequence s2, SMatrix m, QVector<int> pointers, Cell* cell, QVector<short> sizesOfVerticalGaps,
                              QVector<short> sizesOfHorizontalGaps);
   /**
    * @brief SmithWatermanGotoh::maximum
    * @param a
    * @param b
    * @param c
    * @param d
    * @return
    */
   static float SmithWatermanGotoh::maximum(float a, float b, float c, float d);
   static QByteArray SmithWatermanGotoh::reverse(QByteArray a, int len);
};

} // namespace BioQt

#endif // BIOQT_SMITHWATERMANGOTOH_H
