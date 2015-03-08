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

#ifndef KNUTHMORRISPRATTSEARCH_H
#define KNUTHMORRISPRATTSEARCH_H
#include <BioQt_global.h>
#include <QtCore>

namespace BioQt {
/**
 * An object to find exact subsequences within a sequence.
 *
 * <p>
 * Reference: KNUTH D.E., MORRIS (Jr) J.H., PRATT V.R., 1977,
 * Fast pattern matching in strings, SIAM Journal on Computing 6(1):323-350.
 * </P.
 *
 * <p><b>USAGE:</b></p>
 * When the object is constructed the <code>findMatches()</code>
 * method would be called. This will return an int[] giving the offsets
 * (ie the location of the first symbol of each match in the text).
 * The <code>getKMPNextTable()</code> returns the table of border lengths
 * used in the algorithm. This method is protected as it is unlikely it
 * will be needed except for debugging.</p>
 *
 * <p>
 * The algorithm finds exact matches therefore ambiguity symbols will match
 * only themselves. The class cannot perform regular expressions. The class
 * operates on all alphabets thus if searching for a DNA pattern you should
 * compile both the pattern and its reverse complement.</p>
 *
 * <p><b>WARNING the behaviour of a pattern containing gaps is undefined.
 *  It's not recommended that you try it.</b></p>
 *
 * <p>Copyright:    Copyright (c) 2002</p>
 * <p>Company:      AgResearch</p>
 *
 *@author Usama S Erawab
 *
 */

class BIOQTSHARED_EXPORT KnuthMorrisPrattSearch
{
public:
    KnuthMorrisPrattSearch(){};
    void compilePattern();
    QList<int> findMatches(const QString& text);
private:
    /**
     * @brief kmpNext the table that defines the border lengths.
     */
    QList<int> kmpNext;
    QString pattern;
};

} // namespace BioQt

#endif // BIOQT_KNUTHMORRISPRATTSEARCH_H
