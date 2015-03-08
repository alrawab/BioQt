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
*BioQt::Matrix
*@author Usama S Erawab
*
*/

#include "Matrix.h"

namespace BioQt {

QVector<QVector<int> > Matrix::Toeplitz(QVector<int> c, QVector<int> r)
{
    if(r.isEmpty())//Hermitian Toeplitz
        r=c;
    int p = r.size();
    int m = c.size();
    QVector<int> x(p - 1 + m);
    int k = 0;

    for (int i = p - 1; i >= 1; --i)
        x[k++] = r[i];

    for (int i = 0; i < c.size(); ++i)
        x[p - 1 + i] = c[i];

    QVector<int> cidx (m);

    for (int i = 0; i < m; ++i)
        cidx[i] = i;

    QVector<int> ridx(p);
    k = 0;

    for (int i = p; i > 0; --i)
        ridx[k++] = i;
    QVector<QVector<int> >y(m,QVector<int>(p));


    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            y[i][j] = x[cidx[i] + ridx[j] - 1];

        }

    }


    return y;



}

QVector<QVector<int> > Matrix::Filter(QVector<QVector<bool> > W, int window)
{
    QVector<QVector<int> > filter(W.size(),QVector<int>(W[0].size()));


    for (int i = 0; i < W.size(); ++i)
    {
        for (int j = 0; j < W[0].size(); ++j)
        {

            if (W[i][j])
            {
                for (int k = 0; k < window; ++k)
                {
                    int idx = i + k;
                    if (idx < filter.size())
                        filter[idx][j] += 1;
                    else
                        break;

                }
            }
        }
    }
    return filter;



}



} // namespace BioQt
