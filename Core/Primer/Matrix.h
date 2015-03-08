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

#ifndef MATRIX_H
#define MATRIX_H

#include <BioQt_global.h>
#include <QtCore>
namespace BioQt {

class BIOQTSHARED_EXPORT Matrix
{
public:
    /**
   * @brief Toeplitz   Toeplitz matrix, a non-symmetric Toeplitz matrix having C as its
   * first column and R as its first row.
   * @param c
   * @param r
   * @return
   */
  static  QVector<QVector<int> > Toeplitz(QVector<int> c, QVector<int> r);
  static  QVector<QVector<int> > Filter( QVector<QVector<bool> > W, int window);
};

} // namespace BioQt

#endif // BIOQT_MATRIX_H
