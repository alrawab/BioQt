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

#include "ORFFinder.h"

namespace BioQt {



QVector<QPair<int,int>>  ORFFinder::ForwordORFs(const QSequence &seq, int min_length, int TransTable, bool Alternative_Starts)
{
    int min_length_bp=min_length;
    bool longest_orfs=true;
    int from, to;
    QMap<QString, QStringList> gamma=GeneticCodeQuery::GetRoles(TransTable);
    QVector<QPair<int,int>> ranges;
    QStringList allowable_starts ;
    allowable_starts.append(gamma.value("StartCodon"));
    if(Alternative_Starts)
        allowable_starts.append(gamma.value("StartAlteranative"));
    QStringList allowable_stops;
    allowable_stops.append(gamma.value("StopCodon"));
    qDebug()<<allowable_stops;

    QVector<QVector<int> > stops;
    for (int pos = 0;  pos < 3;  pos++) {
        stops.push_back(FindStops(seq,pos,seq.size(),allowable_stops));

    }

    // for each reading frame, calculate the orfs
    for (int frame = 0;  frame < 3;  frame++) {


        if (stops[frame].empty()) {
            // no stops in this frame;
            from = frame;



            to = ((seq.size() - from) / 3) * 3 + from - 1;
            if (!allowable_starts.empty()) {
                from = FindFirstStart(seq, from, to, allowable_starts);
            }
            if (to - from + 1 >= min_length_bp) {
                ranges.push_back(qMakePair(from, to));

                if (!longest_orfs && !allowable_starts.empty()) {
                    for (from += 3; from < to; from += 3) {
                        from = FindFirstStart(seq, from, to, allowable_starts);
                        if (to - from + 1 < min_length_bp)
                            break;
                        ranges.push_back(qMakePair(from, to));
                    }
                }
            }
            continue;
        }



        // deal specially with first ORF
        from = frame;
        to = stops[frame].front() ;//- 1;

        if (to - from + 1 >= min_length_bp) {
            if (!allowable_starts.empty()) {
                from = FindFirstStart(seq, from, to, allowable_starts);
            }
            if (from < to && to - from + 1 >= min_length_bp) {
                ranges.push_back(qMakePair(from, to+2));

                if (!longest_orfs && !allowable_starts.empty()) {
                    for (from += 3; from < to; from += 3) {
                        from = FindFirstStart(seq, from, to, allowable_starts);
                        if (to - from + 1 < min_length_bp)
                            break;
                        ranges.push_back(qMakePair(from, to));
                    }
                }
            }
        }




        for (unsigned int i = 0;  i < stops[frame].size() - 1;  i++) {
            from = stops[frame][i] + 3;
            to = stops[frame][i + 1];// - 1;

            if (to - from + 1 >= min_length_bp) {
                if (!allowable_starts.empty()) {
                    from = FindFirstStart(seq, from, to, allowable_starts);
                    if (from >= to || to - from + 1 < min_length_bp) {
                        continue;
                    }
                }
                ranges.push_back(qMakePair(from, to));

                if (!longest_orfs && !allowable_starts.empty()) {
                    for (from += 3; from < to; from += 3) {
                        from = FindFirstStart(seq, from, to, allowable_starts);
                        if (to - from + 1 < min_length_bp)
                            break;
                        ranges.push_back(qMakePair(from, to));
                    }
                }
            }
        }




        // deal specially with last ORF
        from = stops[frame].back() + 3;

        to = ((seq.size() - from) / 3) * 3 + from;// - 1;

        if (to - from + 1 >= min_length_bp) {
            if (!allowable_starts.empty()) {
                from = FindFirstStart(seq, from, to, allowable_starts);
                if (from >= to || to - from + 1 < min_length_bp) {
                    continue;
                }
            }
            ranges.push_back(qMakePair(from, to));

            if (!longest_orfs && !allowable_starts.empty()) {
                for (from += 3; from < to; from += 3) {
                    from = FindFirstStart(seq, from, to, allowable_starts);
                    if (to - from + 1 < min_length_bp)
                        break;
                    ranges.push_back(qMakePair(from, to));
                }
            }
        }


    }


    return ranges;
}
/*
QVector<QPair<int, int> > ORFFinder::BackwordORFs(const QSequence& seq, int min_length, int TransTable, bool Alternative_Starts)
{
    QSequence _seq=( SequenceTools::GetComplement( SequenceTools::Reverse( seq)));

return ForwordORFs(_seq,min_length,TransTable,Alternative_Starts);
}
*/



int ORFFinder::FindFirstStart(const QString &_seq, int from, int to, const QStringList &allowable_starts)
{

    for(from;from<to;from+=3){
        QString tmp=_seq.mid(from,3);
        if(tmp.size()>2)
        {

            QStringList::const_iterator  it;
            for (it = allowable_starts.begin(); it != allowable_starts.end(); ++it)
            {
                if(tmp==*it)
                    return from+1;

            }
        }
    }
}

QVector<int> ORFFinder::FindStops(const QString &_seq, int from, int to, const QStringList &allowable_stops)
{
    QVector<int> tmpvec;

    for(from;from <to;from+=3)
    {
        QString tmp=_seq.mid(from,3);

        if(tmp.size()>2)
        {
            ;
            QStringList::const_iterator  it;
            for (it = allowable_stops.begin(); it != allowable_stops.end(); ++it)
            {
                if(tmp==*it)
                    tmpvec.push_back(from+3);
            }

        }

    }

    return tmpvec;
}

} // namespace BioQt

