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

#ifndef DIGESTTOOLS_H
#define DIGESTTOOLS_H
#include <BioQt_global.h>
#include <Sequence/QSequence.h>
#include <QtCore>

namespace BioQt {

class BIOQTSHARED_EXPORT DigestTools
{
public:


    static QList<int> SearchMatches(const QSequence &seq,QString pattern);
private:
    static QString PatternToRegExp(QString PatSeq);




};

} // namespace BioQt

#endif // BIOQT_DIGESTTOOLS_H
