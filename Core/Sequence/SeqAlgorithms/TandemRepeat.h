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

#ifndef TANDEMREPEAT_H
#define TANDEMREPEAT_H
#include <BioQt_global.h>
#include <QtCore>

namespace BioQt {

class BIOQTSHARED_EXPORT TandemRepeatRecord
{
public:
    TandemRepeatRecord(int StartPos_,QString Pattren_,int Frequency_,QString TandemRepeatSequence_):
            StartPos(StartPos_),
            Pattren(Pattren_),
            Frequency(Frequency_),
            TandemRepeatSequence(TandemRepeatSequence_){}
        int StartPos;
        QString Pattren;
        int Frequency;
        QString TandemRepeatSequence;

};
class BIOQTSHARED_EXPORT TandemRepeat
{
public:

    static   QList<TandemRepeatRecord> find_tandem_repeats(const QString & sequence,int min_length,int max_length,int min_repeats,int min_length_of_TR);
};

} // namespace BioQt

#endif // BIOQT_TANDEMREPEAT_H
