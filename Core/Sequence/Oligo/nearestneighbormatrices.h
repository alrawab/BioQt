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

#ifndef NEARESTNEIGHBORMATRICES_H
#define NEARESTNEIGHBORMATRICES_H

#include <BioQt_global.h>
#include <QtCore>


namespace BioQt {

class BIOQTSHARED_EXPORT NearestNeighborMatrices
{
public:
    //nearest neighbor parameters from: Panjkovich and Melo, Bioinformatics  Vol 21 no 6 pp 711-722 2004 [1]
   // rows corresponds to A,C,G,T respectively; columns correspond to A,C,G,T respectively
  static QVector<QVector<double> > Bres86_H();
  static QVector<QVector<double> > Bres86_S();

  static QVector<QVector<double> > Sant96_H();
  static QVector<QVector<double> > Sant96_S();

  static QVector<QVector<double> > Sant98_H();
  static QVector<QVector<double> > Sant98_S();

  static QVector<QVector<double> > Sugi96_H();
  static QVector<QVector<double> > Sugi96_S();
   //nearest neighbor parameters as Above with added average values for
   // all possible combinations involving 'N'
   //rows corresponds to A,C,G,T,N respectively; columns correspond to
   // A,C,G,T,N respectively
  static QVector<QVector<double> > Bres86_H_N();
  static QVector<QVector<double> > Bres86_S_N();

  static QVector<QVector<double> > Sant96_H_N();
  static QVector<QVector<double> > Sant96_S_N();

  static QVector<QVector<double> > Sant98_H_N();
  static QVector<QVector<double> > Sant98_S_N();

  static QVector<QVector<double> > Sugi96_H_N();
  static QVector<QVector<double> > Sugi96_S_N();

};

} // namespace BioQt

#endif // BIOQT_NEARESTNEIGHBORMATRICES_H
