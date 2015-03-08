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

#ifndef NEEDLEMANWUNSCH_H
#define NEEDLEMANWUNSCH_H
#include <BioAlignment/Algorithms/AlignmentAlgorithm.h>
#include <BioQt_global.h>
#include <QtCore>
#include <BioAlignment/SubstMatrix/SMatrix.h>
#include <BioAlignment/SubstMatrix/Cell.h>
#include <Sequence/QSequence.h>


namespace BioQt {

class BIOQTSHARED_EXPORT NeedlemanWunsch /*:public AlignmentAlgorithm*/
{
public:
    NeedlemanWunsch();
    ~NeedlemanWunsch();
  static   Alignment align(const QSequence& seq1, const QSequence& seq2, SMatrix matrix, float _Penalty);
private:
  static   Cell * construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float _Gap,
                  QVector<QVector<float> > pointers);

   static  Alignment traceback(QSequence seq1, QSequence seq2, SMatrix m, QVector<QVector<float> > pointers, Cell* cell);

static float maximum(float a, float b, float c);
static QByteArray reverse(QByteArray a, int len);


};

} // namespace BioQt

#endif // BIOQT_NEEDLEMANWUNSCH_H
