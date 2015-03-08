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
*BioQt::Primer
*@author Usama S Erawab
*
*/

#ifndef PRIMER_H
#define PRIMER_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceTools.h>
#include "Matrix.h"

namespace  BioQt {

class BIOQTSHARED_EXPORT Primer
{
public:
    enum Form
        {
            Numeric,
            Simple,
            Camel,
            Pretty
        };
    Primer(const QSequence& _seq);
 static   QVector<QVector<bool> > ComplementMatrix(const QSequence& seq);
 /**
  * @brief searchSelfDimers find positions that forms self dimer and possible hairpins.
  * @param W
  * @param minDimerLength  number of total complementary base count.
  * @param minDimerCount minimum number of bases for dimers.
  * @return
  */
 static QVector<int> searchSelfDimers(QVector<QVector<bool> > W, int minDimerLength, int minDimerCount);
 /**
  * @brief searchHairPins
  * @param W
  * @param minHpinBases minHpinBases.
  * @param minHpinLoop  minHpinLoop.
  * @return
  */
 static QVector<float> searchHairPins(QVector<QVector<bool> > W,int minHpinBases, int minHpinLoop);

 QByteArray DumpSelfDimers(Form form);
 QByteArray DumpHairPins(Form form);

 static QString PrintDimer(const QSequence& seq, int revOffset, Form form);
 static QString PrintHairPin(const QSequence &seq, float pin, Form form);





 QSequence seq;
 QVector<int>   selfDimers;
 QVector<float>  hairPins;
private:




};

} // namespace BioQt

#endif // BIOQT_PRIMER_H
