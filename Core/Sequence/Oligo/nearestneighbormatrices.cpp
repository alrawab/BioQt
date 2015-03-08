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
*BioQt::NearestNeighborMatrices
*@author Usama S Erawab
*
*/

#include "nearestneighbormatrices.h"

namespace BioQt {

QVector<QVector<double> > NearestNeighborMatrices::Bres86_H()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -9.1, -6.5, -7.8, -8.6 }, { -5.8, -11, -11.9, -7.8 }, { -5.6, -11.1, -11, -6.5 }, { -6, -5.6, -5.8, -9.1 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];


    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Bres86_S()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -24, -17.3, -20.8, -23.9 }, { -12.9, -26.6, -27.8, -20.8 }, { -13.5, -26.7, -26.6, -17.3 }, { -16.9, -13.5, -12.9, -24 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant96_H()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]= { { -8.4, -8.6, -6.1, -6.5 }, { -7.4, -6.7, -10.1, -6.1 }, { -7.7, -11.1, -6.7, -8.6 }, { -6.3, -7.7, -7.4, -8.4 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;

}

QVector<QVector<double> > NearestNeighborMatrices::Sant96_S()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -23.6, -23, -16.1, -18.8 }, { -19.3, -15.6, -25.5, -16.1 }, { -20.3, -28.4, -15.6, -23 }, { -18.5, -20.3, -19.3, -23.6 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;

}

QVector<QVector<double> > NearestNeighborMatrices::Sant98_H()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -7.9, -8.4, -7.8, -7.2 }, { -8.5, -8, -10.6, -7.8 }, { -8.2, -9.8, -8, -8.4 }, { -7.2, -8.2, -8.5, -7.9 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant98_S()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -22.2, -22.4, -21, -20.4 }, { -22.7, -19.9, -27.2, -21 }, { -22.2, -24.4, -19.9, -22.4 }, { -21.3, -22.2, -22.7, -22.2 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sugi96_H()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -8, -9.4, -6.6, -5.6 }, { -8.2, -10.9, -11.8, -6.6 }, { -8.8, -10.5, -10.9, -9.4 }, { -6.6, -8.8, -8.2, -8 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sugi96_S()
{
    QVector<QVector<double> > tmp(4,QVector<double>(4));
    double ab[4][4]={ { -21.9, -25.5, -16.4, -15.2 }, { -21, -28.4, -29, -16.4 }, { -23.5, -26.4, -28.4, -25.5 }, { -18.4, -23.5, -21, -21.9 } };
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Bres86_H_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -9.1, -6.5, -7.8, -8.6, -8 }, { -5.8, -11, -11.9, -7.8, -9.125 }, { -5.6, -11.1, -11, -6.5, -8.55 }, { -6, -5.6, -5.8, -9.1, -6.625 }, { -6.625, -8.55, -9.125, -8, -8.075 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Bres86_S_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -24, -17.3, -20.8, -23.9, -21.5 }, { -12.9, -26.6, -27.8, -20.8, -22.025 }, { -13.5, -26.7, -26.6, -17.3, -21.025 }, { -16.9, -13.5, -12.9, -24, -16.825 }, { -16.825, -21.025, -22.025, -21.5, -20.3438 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant96_H_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -8.4, -8.6, -6.1, -6.5, -7.4 }, { -7.4, -6.7, -10.1, -6.1, -7.575 }, { -7.7, -11.1, -6.7, -8.6, -8.525 }, { -6.3, -7.7, -7.4, -8.4, -7.45 }, { -7.45, -8.525, -7.575, -7.4, -7.7375 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant96_S_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -23.6, -23, -16.1, -18.8, -20.375 }, { -19.3, -15.6, -25.5, -16.1, -19.125 }, { -20.3, -28.4, -15.6, -23, -21.825 }, { -18.5, -20.3, -19.3, -23.6, -20.425 }, { -20.425, -21.825, -19.125, -20.375, -20.4375 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant98_H_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -7.9, -8.4, -7.8, -7.2, -7.825 }, { -8.5, -8, -10.6, -7.8, -8.725 }, { -8.2, -9.8, -8, -8.4, -8.6 }, { -7.2, -8.2, -8.5, -7.9, -7.95 }, { -7.95, -8.6, -8.725, -7.825, -8.275 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sant98_S_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -22.2, -22.4, -21, -20.4, -21.5 }, { -22.7, -19.9, -27.2, -21, -22.7 }, { -22.2, -24.4, -19.9, -22.4, -22.225 }, { -21.3, -22.2, -22.7, -22.2, -22.1 }, { -22.1, -22.225, -22.7, -21.5, -22.1313 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sugi96_H_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -8, -9.4, -6.6, -5.6, -7.4 }, { -8.2, -10.9, -11.8, -6.6, -9.375 }, { -8.8, -10.5, -10.9, -9.4, -9.9 }, { -6.6, -8.8, -8.2, -8, -7.9 }, { -7.9, -9.9, -9.375, -7.4, -8.6437 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}

QVector<QVector<double> > NearestNeighborMatrices::Sugi96_S_N()
{
    QVector<QVector<double> > tmp(5,QVector<double>(5));
    double ab[5][5]={ { -21.9, -25.5, -16.4, -15.2, -19.75 }, { -21, -28.4, -29, -16.4, -23.7 }, { -23.5, -26.4, -28.4, -25.5, -25.95 }, { -18.4, -23.5, -21, -21.9, -21.2 }, { -21.2, -25.95, -23.7, -19.75, -22.65 } };
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j < 5; j++ )
            tmp[i][j]=ab[i][j];

    return tmp;
}



} // namespace BioQt
