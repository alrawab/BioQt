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

#ifndef LEVENSHTEINDISTANCE_H
#define LEVENSHTEINDISTANCE_H
#include <BioQt_global.h>
#include <QtCore>
namespace BioQt {
/**
 * @brief The LevenshteinDistance class
 *In information theory and computer science, the Levenshtein distance is a string metric for measuring
 *the difference between two sequences. Informally, the Levenshtein distance between two words is the
 * minimum number of single-character edits (i.e. insertions, deletions or substitutions) required
 *to change one word into the other. It is named after Vladimir Levenshtein,
 * who considered this distance in 1965.
 *see http://en.wikipedia.org/wiki/Levenshtein_distance
 */
class BIOQTSHARED_EXPORT LevenshteinDistance
{
public:
    /**
    * @brief GetLevenshteinDistance
    * @param s1
    * @param s2
    * @return
    */
   static int GetLevenshteinDistance(const QString& s1,const QString& s2);
};

} // namespace BioQt

#endif // BIOQT_LEVENSHTEINDISTANCE_H
