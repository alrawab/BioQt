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

#ifndef BIOQT_BIOQTMATH_H
#define BIOQT_BIOQTMATH_H

#include <WinDef.h>
#include <BioQt_global.h>
#include <QtCore>
#include <limits>
#if __GNUC__
#include <cmath>
#define NANDOUBLE NAN
#define INTMAX std::numeric_limits<int>::max()
#else
#include <float.h>
#define NANDOUBLE std::numeric_limits<float>::quiet_NaN()
#undef max
#define INTMAX std::numeric_limits<int>::max()

#endif

#define DOUBELEPSILON 4.94065645841247e-324
namespace BioQt {

/**
 * @brief The BioQTMath class
 *@author Usama S Erawab
 */

typedef QVector<QVector<int> > MDAINT;
typedef QVector<QVector<bool> > MDABOL;
typedef QVector<QVector<float> > MDAFLOT;
typedef QVector<QVector<double> > MDADOU;


class BIOQTSHARED_EXPORT BioQTMath
{
public:
    /**
     * @brief Toeplitz  matrix, a non-symmetric Toeplitz matrix having C as its
     *first column and R as its first row.
     *see http://en.wikipedia.org/wiki/Toeplitz_matrix
     * @param c
     * @param r
     * @return
     */




    static MDAINT Toeplitz(QVector<int> c,QVector<int> r);

    static MDAINT Filter(MDABOL W, int window);

    static bool IS_NAN_DOUBLE(double s);
};

} // namespace BioQt

#endif // BIOQT_BIOQTMATH_H
