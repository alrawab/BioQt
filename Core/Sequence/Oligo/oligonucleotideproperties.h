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
*BioQt::OligonucleotideProperties
*@author Usama S Erawab
*
*/

#ifndef OLIGONUCLEOTIDEPROPERTIES_H
#define OLIGONUCLEOTIDEPROPERTIES_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceTools.h>
#include "nearestneighbormatrices.h"

namespace BioQt {

class BIOQTSHARED_EXPORT OligonucleotideProperties
{
public:
    enum NearestNeighborMethod
    {
      //("Breslauer et. al. 1986")]
        Bres86 = 0,
     //("SantaLucia et. al. 1996")]
        Sant96 = 1,
       //("SantaLucia et. al. 1998")]
        Sant98 = 2,
       //("Sugimoto et. al. 1996")]
        Sugi96 = 3
    };
    OligonucleotideProperties(const QSequence&seq);

    /**
     * @brief BasicMeltingTemp
     * Get melting temperature using basic formula. 4 * (#AT) + 2 * (#GC)
     * @return
     */
    double BasicMeltingTemp();
    /**
     * @brief SaltAdjustTm Adjustment melting temperature at default salt concentration of 0.05 M
     * @param salt
     * @return
     */
    double SaltAdjustTm(double salt=0.05);
    /**
     * @brief LinearRegression
     * A more sophisticated method is the linear regression based on the length of the DNA molecule and
     * the GC ratio. the GC ratio is the number of G or C nucleotides divided by the total length of the
     *  DNA. Based on empirical data, a number of linear regression terms for the Tm have been proposed.
     *  Tm = 81.5 + 0.41(%GC) - 600/N + 16.6 x log[Na+]
     *  Used by Primer3Plus to calculate the product Tm. Default set.
     * @return
     */
    double LinearRegression();
    /**
     * @brief MeltingTemp
     * @param salt
     * @param primerConc
     * @param NN
     * @return
     */
    double MeltingTemp( QVector<double> NN=QVector<double>(),double salt=0.05, double primerConc=50e-6);
    /**
     * @brief ThermoProp compute thermo values using Nearest Neighbor methods.
     * defaule value is Sant98.
     * @param method
     * @return Columns are H, S, DeltaH and DeltaS
     */
    QVector<double> ThermoProp(NearestNeighborMethod method=Sant98);

private:
    QSequence Seq;
    BaseCount basecount;
    bool HasAmbiguous;
    bool IsSymmetry;
    bool IsOnlyAT;
    int Length;
    QString DNAChars ;

    QVector<QVector<double> > Bres86_H;
    QVector<QVector<double> > Bres86_S;

    QVector<QVector<double> > Sant96_H;
    QVector<QVector<double> > Sant96_S;

    QVector<QVector<double> > Sant98_H;
    QVector<QVector<double> > Sant98_S;

    QVector<QVector<double> > Sugi96_H;
    QVector<QVector<double> > Sugi96_S;
    //-----------------------------------------------/
    QVector<QVector<double> > Bres86_H_N;
    QVector<QVector<double> > Bres86_S_N;

    QVector<QVector<double> > Sant96_H_N;
    QVector<QVector<double> > Sant96_S_N;

    QVector<QVector<double> > Sant98_H_N;
    QVector<QVector<double> > Sant98_S_N;

    QVector<QVector<double> > Sugi96_H_N;
    QVector<QVector<double> > Sugi96_S_N;
};

} // namespace BioQt

#endif // BIOQT_OLIGONUCLEOTIDEPROPERTIES_H
