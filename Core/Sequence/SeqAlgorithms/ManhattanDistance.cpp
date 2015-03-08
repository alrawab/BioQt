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

#include "ManhattanDistance.h"
/**
 *The distance between two points in a grid based on a strictly horizontal and/or
 *vertical path (that is, along the grid lines), as opposed to the diagonal or "as the crow flies" distance.
 *The Manhattan distance is the simple sum of the horizontal and vertical components, whereas the diagonal
 *distance might be computed by applying the Pythagorean theorem.
 *See http://en.wiktionary.org/wiki/Manhattan_distance and http://heuristicswiki.wikispaces.com/Manhattan+Distance
 */
namespace BioQt {
/**
 * @brief ManhattanDistance::GetManhattanDistance
 * @param a
 * @param b
 * @return
 */
int ManhattanDistance::GetManhattanDistance(QList<int> a,QList<int> b)
{
    if(a.size() !=b.size())
    {
        //exception length mismatched //FIXME OSama!!
    }
 int distance =0;
    for(int x=0;x<a.size();x++)
    {
        distance +=abs(a[x]-b[x]);
    }

    return distance;
}

} // namespace BioQt
