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

#ifndef ALIGNMENTALGORITHM_H
#define ALIGNMENTALGORITHM_H
#include <BioQt_global.h>
#include <QtCore>>
#include <BioAlignment/Alignment.h>
#include <BioAlignment/SubstMatrix/SMatrix.h>
#include <BioAlignment/SubstMatrix/Cell.h>
#include <Sequence/QSequence.h>


namespace BioQt {
/**
 * @brief The AlignmentAlgorithm class
 * It's an Interface provides methods for the alignment of bio-sequences
 * @author Usama S Erawab
 */
class BIOQTSHARED_EXPORT AlignmentAlgorithm
{
public:
    AlignmentAlgorithm();
    ~AlignmentAlgorithm();
    virtual Alignment align(const QSequence& seq1, const QSequence& seq2, SMatrix matrix, float _OpenGapPenalty, float _ExtendGapPenalty)=0;
private:
    virtual Cell * construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float _OpenGapPenalty,
                            float _ExtendGapPenalty, QVector<int> pointers,QVector<short> sizesOfVerticalGaps,QVector<short> sizesOfHorizontalGaps)=0;

    virtual Alignment traceback(QSequence s1, QSequence s2, SMatrix m, QVector<int> pointers, Cell* cell, QVector<short> sizesOfVerticalGaps,
                               QVector<short> sizesOfHorizontalGaps)=0;
    /**
         * This just computes the maximum of four integers.
         *
         * @param a
         * @param b
         * @param c
         * @param d
         * @return the maximum of four <code>int</code>s.
         */
  static  float maximum(float a, float b, float c, float d);

};

} // namespace BioQt

#endif // BIOQT_ALIGNMENTALGORITHM_H
