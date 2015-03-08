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

#include "HammingDistance.h"

namespace BioQt {


int HammingDistance::GetHammingDistance(const QString& s1,const QString& s2)
{
    if(s1.size()!=s2.size())
    {
        //exception length mismatched exit //FIXME
    }
    int tmp;
    for(int x=0;x<s1.size();x++)
    {
        if(s1[x] !=s2[x])
            ++tmp;
    }
return tmp;
}
} // namespace BioQt
