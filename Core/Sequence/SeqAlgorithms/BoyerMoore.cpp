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

#include "BoyerMoore.h"

namespace BioQt {


BoyerMoore::BoyerMoore(const QString &pattern):m_pattern(pattern)
{
    m_badCharacterShift = BuildBadCharacterShift(pattern);
    m_suffixes = FindSuffixes(pattern);
    m_goodSuffixShift = BuildGoodSuffixShift(pattern, m_suffixes);
}

QVector<int> BoyerMoore::BoyerMooreMatch(const QString &text, int startingIndex)
{
    QVector<int> resault;
    int patternLength = m_pattern.length();
    int textLength = text.length();

    /* Searching */
    int index = startingIndex;
    while (index <= textLength - patternLength)
    {
        int unmatched;
        for (unmatched = patternLength - 1;
             unmatched >= 0 && (m_pattern[unmatched] == text[unmatched + index]);
             --unmatched
             )
            ; // empty

        if (unmatched < 0)
        {

            resault.push_back(index);
            index += m_goodSuffixShift[0];
        }
        else
            index += qMax(m_goodSuffixShift[unmatched],
                          m_badCharacterShift[text[unmatched + index].toAscii()] - patternLength + 1 + unmatched);
    }
    return resault;
}

QVector<int> BoyerMoore::TurboBoyerMooreMatch(const QString &text, int startingIndex)
{
    QVector<int> resault;
    int patternLength = m_pattern.length();
    int textLength = text.length();

    /* Searching */
    int index = startingIndex;
    int overlap = 0;
    int shift = patternLength;
    while (index <= textLength - patternLength)
    {
        int unmatched = patternLength - 1;

        while (unmatched >= 0 && (m_pattern[unmatched] == text[unmatched + index]))
        {
            --unmatched;
            if (overlap != 0 && unmatched == patternLength - 1 - shift)
                unmatched -= overlap;
        }

        if (unmatched < 0)
        {

            resault.push_back(index);
            shift = m_goodSuffixShift[0];
            overlap = patternLength - shift;
        }
        else
        {
            int matched = patternLength - 1 - unmatched;
            int turboShift = overlap - matched;
            int bcShift = m_badCharacterShift[text[unmatched + index].toAscii()] - patternLength + 1 + unmatched;
            shift = qMax(turboShift, bcShift);
            shift = qMax(shift, m_goodSuffixShift[unmatched]);
            if (shift == m_goodSuffixShift[unmatched])
                overlap = qMin(patternLength - shift, matched);
            else
            {
                if (turboShift < bcShift)
                    shift = qMax(shift, overlap + 1);
                overlap = 0;
            }
        }

        index += shift;
    }
    return resault;
}

QVector<int> BoyerMoore::ApostolicoGiancarloMatch(const QString &text, int startingIndex)
{
     QVector<int> resault;
    int patternLength = m_pattern.length();
    int textLength = text.length();
    QVector<int> skip(patternLength);
    int shift;

    /* Searching */
    int index = startingIndex;
    while (index <= textLength - patternLength)
    {
        int unmatched = patternLength - 1;
        while (unmatched >= 0)
        {
            int skipLength = skip[unmatched];
            int suffixLength = m_suffixes[unmatched];
            if (skipLength > 0)
                if (skipLength > suffixLength)
                {
                    if (unmatched + 1 == suffixLength)
                        unmatched = (-1);
                    else
                        unmatched -= suffixLength;
                    break;
                }
                else
                {
                    unmatched -= skipLength;
                    if (skipLength < suffixLength)
                        break;
                }
            else
            {
                if (m_pattern[unmatched] == text[unmatched + index])
                    --unmatched;
                else
                    break;
            }
        }
        if (unmatched < 0)
        {

            resault.push_back(index);
            skip[patternLength - 1] = patternLength;
            shift = m_goodSuffixShift[0];
        }
        else
        {
            skip[patternLength - 1] = patternLength - 1 - unmatched;
            shift =qMax(m_goodSuffixShift[unmatched],
                             m_badCharacterShift[text[unmatched + index].toAscii()] - patternLength + 1 + unmatched
                    );
        }
        index += shift;

        for (int copy = 0; copy < patternLength - shift; ++copy)
            skip[copy] = skip[copy + shift];

        for (int clear = 0; clear < shift; ++clear)
            skip[patternLength - shift + clear] = 0;
    }
    return resault;
}




QVector<int> BoyerMoore::BuildBadCharacterShift(const QString &pattern)
{
    QVector<int> badCharacterShift(256);

    for (int c = 0; c < badCharacterShift.size(); ++c)
        badCharacterShift[c] = pattern.length();
    for (int i = 0; i < pattern.length() - 1; ++i)
        badCharacterShift[pattern[i].toAscii()] = pattern.length() - i - 1;

    return badCharacterShift;
}

QVector<int> BoyerMoore::FindSuffixes(const QString &pattern)
{
    int f = 0, g;

    int patternLength = pattern.length() ;
    QVector<int> suffixes (pattern.length()+1);
    //        suffixes[0]=0;
    //        int k=0;
    //        for ( std::size_t i = 1; i < patternLength; ++i )
    //        {
    //            while ( k > 0 && ( pattern[k] != pattern[i] )) {

    //                k = suffixes [ k - 1 ];
    //            }
    //            if ( pattern[k] == pattern[i] )
    //                                k++;
    //                            suffixes [ i ] = k;
    //        }

    suffixes[patternLength - 1] = patternLength;
    g = patternLength - 1;
    for (int i = patternLength - 2; i >= 0; --i)
    {
        if (i > g &&(suffixes[i + patternLength - 1 - f] < i - g))
            suffixes[i] = suffixes[i + patternLength - 1 - f];
        else
        {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && (pattern[g] == pattern[g + patternLength - 1 - f]))
                --g;
            suffixes[i] = f - g;
        }
    }



    return suffixes;

}

QVector<int> BoyerMoore::BuildGoodSuffixShift(const QString &pattern, QVector<int> suff)
{
    int patternLength = pattern.length();
    QVector<int> goodSuffixShift(pattern.length() + 1);

    for (int i = 0; i < patternLength; ++i)
        goodSuffixShift[i] = patternLength;
    int j = 0;
    for (int i = patternLength - 1; i >= -1; --i)
        if (i == -1 || suff[i] == i + 1)
            for (; j < patternLength - 1 - i; ++j)
                if (goodSuffixShift[j] == patternLength)
                    goodSuffixShift[j] = patternLength - 1 - i;
    for (int i = 0; i <= patternLength - 2; ++i)
        goodSuffixShift[patternLength - 1 - suff[i]] = patternLength - 1 - i;

    return goodSuffixShift;
}









}
