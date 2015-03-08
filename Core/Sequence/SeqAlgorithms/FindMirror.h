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

#ifndef FINDMIRROR_H
#define FINDMIRROR_H
#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/SequenceTools.h>
namespace BioQt {

class BIOQTSHARED_EXPORT FindMirror
{
public:
static QMap<QString,int> find_mirror(const QString & haystack,int pallen1, int pallen2=0 , QString options = "E");
};

} // namespace BioQt

#endif // BIOQT_FINDMIRROR_H
