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

#ifndef HAMMINGDISTANCE_H
#define HAMMINGDISTANCE_H
#include <BioQt_global.h>
#include <QtCore>
namespace BioQt {
/**
 * @brief The HammingDistance class
 *In information theory, the Hamming distance between two strings of equal length
 *is the number of positions at which the corresponding symbols are different.
 * In another way, it measures the minimum number of substitutions required to change one string into the other,
 * or the minimum number of errors that could have transformed one string into the other.
 *see www.en.wikipedia.org/wiki/Hamming_distance
 *
 */
class BIOQTSHARED_EXPORT HammingDistance
{
public:
    static int GetHammingDistance(const QString& s1,const QString& s2);
};

} // namespace BioQt

#endif // BIOQT_HAMMINGDISTANCE_H
