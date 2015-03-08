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

#ifndef NEEDLEMANWUNSCHGOTOH_H
#define NEEDLEMANWUNSCHGOTOH_H
#include <BioQt_global.h>
#include <QtCore>
#include <BioAlignment/Alignment.h>
#include <BioAlignment/SubstMatrix/SMatrix.h>
#include <BioAlignment/SubstMatrix/Cell.h>
#include <Sequence/QSequence.h>
#include <memory>


namespace BioQt {

class BIOQTSHARED_EXPORT  NeedlemanWunschGotoh
{
public:
    /**
     * @brief NeedlemanWunschGotoh
     */
    NeedlemanWunschGotoh();
    ~NeedlemanWunschGotoh();
    /**
     * @brief align
     * @param seq1
     * @param seq2
     * @param matrix
     * @param o
     * @param e
     * @return
     */
    static Alignment align(QSequence seq1, QSequence seq2, SMatrix matrix, float o, float e);
    /**
     * @brief construct
     * @param seq1
     * @param seq2
     * @param matrix
     * @param o
     * @param e
     * @param pointers
     * @param lengths
     * @return
     */
    static Cell* construct(QSequence seq1, QSequence seq2, QVector<QVector<float>> matrix, float o, float e, QVector<int> pointers, QVector<short> lengths);
    /**
     * @brief traceback
     * @param seq1
     * @param seq2
     * @param m
     * @param pointers
     * @param cell
     * @param lengths
     * @return
     */
    static Alignment traceback(QSequence s1, QSequence s2, SMatrix m,  QVector<int> pointers , Cell *cell, QVector<short> lengths);
    /**
     * @brief SmithWatermanGotoh::maximum
     * @param a
     * @param b
     * @param c
     * @param d
     * @return
     */
    static float maximum(float a, float b, float c);
    static QByteArray reverse(QByteArray a, int len);
};

} // namespace BioQt

#endif // BIOQT_NEEDLEMANWUNSCHGOTOH_H
