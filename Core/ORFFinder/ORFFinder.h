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

#ifndef BIOQT_ORFFINDER_H
#define BIOQT_ORFFINDER_H

#include <QtCore>
#include <BioQt_global.h>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceTools.h>
#include <Sequence/SequenceException.h>
#include <Sequence/DNATranslation/GeneticCodeData.h>
#include <Sequence/DNATranslation/GeneticCodeQuery.h>

namespace BioQt {

class BIOQTSHARED_EXPORT ORFFinder
{
public:

static QVector<QPair<int,int>>  ForwordORFs(const QSequence& seq,int min_length=100,int TransTable=1,bool Alternative_Starts =false);
//static QVector<QPair<int,int>> BackwordORFs(const QSequence &seq,int min_length=100,int TransTable=1,bool Alternative_Starts =false);
private:
    static int FindFirstStart(const QString &_seq,int from,int to ,const QStringList &allowable_starts/*const QRegExp &allowable_starts */);
    static QVector<int> FindStops(const QString &_seq,int from,int to ,const QStringList &allowable_stops);
};

} // namespace BioQt

#endif // BIOQT_ORFFINDER_H
