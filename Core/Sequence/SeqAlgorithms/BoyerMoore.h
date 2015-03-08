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
*BoyerMoore
*@author Usama S Erawab
*
*/

#ifndef BOYERMOORE_H
#define BOYERMOORE_H


#include <QtCore>
#include <BioQt_global.h>

namespace BioQt {


class BIOQTSHARED_EXPORT BoyerMoore
{
public:
/**
*@brief implementation of Boyer-Moore string search algorithm.
*/
    BoyerMoore(const QString& pattren);
 QVector<int> BoyerMooreMatch(const QString& text, int startingIndex=0);
 /**
  * @brief TurboBoyerMooreMatch using the Turbo Boyer-Moore algorithm
  * @param text
  * @param startingIndex
  * @return
  */
 QVector<int> TurboBoyerMooreMatch(const QString& text, int startingIndex=0);
 /**
 * @brief ApostolicoGiancarloMatch  using the Apostolico-GiancarloMatch algorithm
 * @param text
 * @param startingIndex
 * @return
 */
QVector<int> ApostolicoGiancarloMatch(const QString& text, int startingIndex=0);
private:
    /**
  * @brief BuildBadCharacterShift  Build the bad character shift vector.
  * @param pattern
  * @return
  */
 QVector<int> BuildBadCharacterShift(const QString& pattern);
 /**
  * @brief FindSuffixes Find suffixes in the pattern
  * @param pattern
  * @return
  */
 QVector<int> FindSuffixes(const QString& pattern);
  QVector<int>  BuildGoodSuffixShift(const QString& pattern, QVector<int> suff);
private:
    QVector<int> m_badCharacterShift;
    QVector<int> m_goodSuffixShift;
    QVector<int> m_suffixes;
    QString m_pattern;
};
}
#endif // BOYERMOORE_H
