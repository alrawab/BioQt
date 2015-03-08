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
*BioQt::DigestTools
*@author Usama S Erawab
*
*/

#include "DigestTools.h"

namespace BioQt {

QString DigestTools::PatternToRegExp(QString PatSeq)
{
    if (PatSeq.contains('R')) PatSeq = PatSeq.replace("R", "[AG]");
    if (PatSeq.contains('Y')) PatSeq = PatSeq.replace("Y", "[CT]");
    if (PatSeq.contains('M')) PatSeq = PatSeq.replace("M", "[AC]");
    if (PatSeq.contains('K')) PatSeq = PatSeq.replace("K", "[GT]");
    if (PatSeq.contains('S')) PatSeq = PatSeq.replace("S", "[CG]");
    if (PatSeq.contains('W')) PatSeq = PatSeq.replace("W", "[AT]");
    if (PatSeq.contains('B')) PatSeq = PatSeq.replace("B", "[CGT]");
    if (PatSeq.contains('D')) PatSeq = PatSeq.replace("D", "[AGT]");
    if (PatSeq.contains('H')) PatSeq = PatSeq.replace("H", "[ACT]");
    if (PatSeq.contains('V')) PatSeq = PatSeq.replace("V", "[ACG]");
    if (PatSeq.contains('N')) PatSeq = PatSeq.replace("N", "[ACGT]");
    return PatSeq;
}

QList<int> DigestTools::SearchMatches(const QSequence &seq, QString pattern)
{
    QList<int> tmp;
    QRegExp rx(DigestTools::PatternToRegExp(pattern));
    int pos = 0;
    while ((pos = rx.indexIn(seq, pos)) != -1) {
        tmp<<pos;
        pos += rx.matchedLength();
    }


    return tmp;
}



} // namespace BioQt
