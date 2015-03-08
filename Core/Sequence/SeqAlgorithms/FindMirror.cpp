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

#include "FindMirror.h"

namespace BioQt {

QMap<QString,int> FindMirror::find_mirror(const QString & haystack,int pallen1, int pallen2, QString options)
{
   QMap<QString,int> tmp;
    int haylen = haystack.size();
    if(haylen==0)return tmp;
    if(pallen1<2)return tmp;
    if(pallen1>haylen)return tmp;
    if(pallen2==0)pallen2=pallen1;
    if(pallen2<pallen1)return tmp;
    QString _options=options.toUpper();

    if((_options !="E")&&(_options!="O")&&(_options!="A"))return tmp;

    for(int x =pallen1;x<=pallen2;x++)
    {
        if ((_options == "E") && (SequenceTools::IsOdd(x) == TRUE)) continue;
        if ((_options == "O") && (SequenceTools::IsEven(x) == TRUE)) continue;

        int _count = haylen - x + 1;
        for(int j = 0; j < _count; j++)
        {
            QString mirr= haystack.mid(j,x);     //SequenceTools::SubSequence(haystack,j,x);

            if(SequenceTools::IsMirror(mirr))
            {

                tmp.insert(mirr,j);
            }
        }
    }

    return tmp;

}


} // namespace BioQt
