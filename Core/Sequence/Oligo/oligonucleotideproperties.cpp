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

#include "oligonucleotideproperties.h"
#include <cmath>

namespace BioQt {

OligonucleotideProperties::OligonucleotideProperties(const QSequence &seq):Seq(seq)
{
    Length=Seq.size();
    IsSymmetry=SequenceTools::IsSymmetry(Seq);
    IsOnlyAT=SequenceTools::IsOnlyAT(Seq);
    basecount=SequenceTools::CalculateBases(Seq) ;
    DNAChars = "acgt";
    HasAmbiguous=SequenceTools::ContainsAmbiguous(Seq);
    Bres86_H=NearestNeighborMatrices::Bres86_H();
    Bres86_S=NearestNeighborMatrices::Bres86_S();
    Sant96_H=NearestNeighborMatrices::Sant96_H();
    Sant96_S=NearestNeighborMatrices::Sant96_S();
    Sant98_H=NearestNeighborMatrices::Sant98_H();
    Sant98_S=NearestNeighborMatrices::Sant98_S();
    Sugi96_H=NearestNeighborMatrices::Sugi96_H();
    Sugi96_S=NearestNeighborMatrices::Sugi96_S();
    //==================================================//
    Bres86_H_N==NearestNeighborMatrices::Bres86_H_N();
    Bres86_S_N==NearestNeighborMatrices::Bres86_S_N();
    Sant96_H_N==NearestNeighborMatrices::Sant96_H_N();
    Sant96_S_N==NearestNeighborMatrices::Sant96_S_N();
    Sant98_H_N==NearestNeighborMatrices::Sant98_H_N();
    Sant98_S_N==NearestNeighborMatrices::Sant98_S_N();
    Sugi96_H_N==NearestNeighborMatrices::Sugi96_H_N();
    Sugi96_S_N==NearestNeighborMatrices::Sugi96_S_N();
}

double OligonucleotideProperties::BasicMeltingTemp()
{
    double basic;

    if (!HasAmbiguous)
    {

        if (Length < 14)
        {
            basic = 2.0 * (basecount.A +basecount.T) + 4.0 * (basecount.G +basecount.C);
        }
        else
        {
            basic = 64.9 + (41.0 * ((basecount.C + basecount.G - 16.4) / Length));
        }
    }
    else
    {
        if (Length < 14)
        {
            basic = 2.0 * (basecount.A + basecount.T) + 4 * (basecount.G + basecount.C) + 3 * basecount.N;
        }
        else
        {
            basic = 64.9 + (41.0 * (basecount.C + basecount.G - 16.4 + basecount.N / 2.0) / Length);
        }
    }
    return basic;

}

double OligonucleotideProperties::SaltAdjustTm(double salt)
{
    double saltadj;
    double basic = BasicMeltingTemp();

    if (!HasAmbiguous)
    {

        if (Length < 14)
        {
            saltadj = basic - 16.6 * log10(0.05) + 16.6 * log10(salt);
        }
        else
        {
            saltadj = 100.5 + ((41.0 * (basecount.C + basecount.G)) / Length) -
                    (820.0 / Length) + (16.6 * log10(salt)); // TM SALT ADJUSTED [9]
        }
    }
    else
    {
        if (Length < 14)
        {

            saltadj = basic - 16.6 * log10(0.05) + 16.6 * log10(salt);

        }
        else
        {
            saltadj = 100.5 - (820.0 / Length) + (16.6 * log10(salt))
                    + 41.0 * ((basecount.G + basecount.C + basecount.N / 2.0) / Length);
        }
    }
    return saltadj;

}

double OligonucleotideProperties::LinearRegression()
{

    //Tm = 81.5 + 16.6(log10([Na+])) + .41*(%GC) – 600/length


    double linearreg=81.5+ 16.6*(log10(0.05))+
            ((double)(basecount.G+basecount.C)/  Length*100)*.041-(double)600/Length;




    return linearreg;
}

double OligonucleotideProperties::MeltingTemp( QVector<double> NN,double salt, double primerConc)
{
    double b = 4.0;
    if (IsSymmetry)
        b = 1.0; // correction value for nearest neighbor melting temperature calculation

    double saltadj = SaltAdjustTm(salt);
    double tmdeltaH;
    double tmdeltaS;
    double tm;
    if (NN.isEmpty() ) NN = ThermoProp(Sant98);

    if (!HasAmbiguous)
    {

        tm = (NN[0] * 1000.0 / (NN[1] + (1.9872 * log(primerConc / b)))) + (16.6 * log10(salt)) - 273.15; // TM NEAREST NEIGHBOR
    }
    else
    {
        if (Length < 14)
        {
            tmdeltaH = basecount.N;
            tmdeltaS = 3.0 * basecount.N;
        }
        else
        {
            tmdeltaH = 1.0 / 2.0 * 41.0 * (basecount.N / Length);
            tmdeltaS = 41.0 * 1.0 / 2.0 * (basecount.N / Length);
        }

        tm = (((NN[0] + NN[2]) * 1000.0 / ((NN[1] + NN[3]) + (1.9872 * log(primerConc / b)))) + (16.6 * log10(salt)) - 273.15 +
                ((NN[0] - NN[2]) * 1000.0 / ((NN[1] - NN[3]) + (1.9872 * log(primerConc / b)))) + (16.6 * log10(salt)) - 273.15) * 1.0 / 2.0; // NEAREST NEIGHBOR

    }



    return tm;


}

QVector<double> OligonucleotideProperties::ThermoProp(OligonucleotideProperties::NearestNeighborMethod method)
{

    QVector<double> NN(4) ;
    if (!HasAmbiguous)
    {
        for (int k = 0; k < Length - 1; ++k)
        {


            int i = DNAChars.indexOf(Seq[k],0,Qt::CaseInsensitive);
            int j = DNAChars.indexOf(Seq[k + 1],0,Qt::CaseInsensitive);
            if (method == Bres86)
            {

                NN[0] += Bres86_H[i][j];
                NN[1] += Bres86_S[i][j];
            }
            else if (method == Sant96)
            {
                NN[0] += Sant96_H[i][j];
                NN[1] += Sant96_S[i][j];
            }
            else if (method == Sant98)
            {

                NN[0] += Sant98_H[i][j];
                NN[1] += Sant98_S[i][j];

            }
            else
            {
                NN[0] += Sugi96_H[i][j];
                NN[1] += Sugi96_S[i][j];
            }
        }

        if (IsOnlyAT)
        {
            if (method == Bres86)
                NN[1] += -20.13;
            else if (method == Sant96)
                NN[1] += -9.0;
            else if (method == Sugi96)
            {
                NN[0] += 0.6;
                NN[1] += -9.0;
            }
        }
        else
        {
            if (method == Bres86)
                NN[1] += -16.77;
            else if (method == Sant96)
                NN[1] += -5.9;
            else if (method == Sugi96)
            {
                NN[0] += 0.6;
                NN[1] += -9.0;
            }
        }

        if (IsSymmetry)
        {
            if (method ==Bres86)
                NN[1] += -1.34;
            else if (method ==Sant96)
                NN[1] += -1.4;
            else if (method ==Sant98)
                NN[1] += -1.4;
            else if (method ==Sugi96)
                NN[1] += -1.4;
        }

        // initiation with terminal  5'
        if (Seq[0] == 'c' | Seq[0] == 'g')
        {
            if (method == Sant98)
            {
                NN[0] += 0.1;
                NN[1] += -2.8;
            }
        }
        else if (Seq[Length - 1] == 'a' | Seq[Length - 1] == 't')
        {
            if (method == Sant98)
            {
                NN[0] += 2.3;
                NN[1] += 4.1;
            }
        }

        // initiation with terminal  3'
        if (Seq[Length - 1] == 'g' | Seq[Length - 1] == 'c')
        {
            if (method == Sant98)
            {
                NN[0] += 0.1;
                NN[1] += -2.8;
            }
        }
        else if (Seq[Length - 1] == 'a' | Seq[Length - 1] == 't')
        {
            if (method ==Sant98)
            {
                NN[0] += 2.3;
                NN[1] += 4.1;
            }
        }
    }
    else
    {
        QString DNAnChars = "acgtn";
        for (int k = 0; k < Length - 1; ++k)
        {
            int i = DNAnChars.indexOf(Seq[k],0,Qt::CaseInsensitive);
            int j = DNAnChars.indexOf(Seq[k + 1],0,Qt::CaseInsensitive);
            if (method == Bres86)
            {
                NN[0] += Bres86_H_N[i][j];
                NN[1] += Bres86_S_N[i][j];
            }
            else if (method == Sant96)
            {
                NN[0] += Sant96_H_N[i][j];
                NN[1] += Sant96_S_N[i][j];
            }
            else if (method == Sant98)
            {
                NN[0] += Sant98_H_N[i][j];
                NN[1] += Sant98_S_N[i][j];
            }
            else
            {
                NN[0] += Sugi96_H_N[i][j];
                NN[1] += Sugi96_S_N[i][j];
            }
        }

        if (IsSymmetry)
        {
            if (method == Bres86)
                NN[1] += -16.77;
            else if (method == Sant96)
                NN[1] += -5.9;
            else if (method == Sant98)
                NN[1] += -1.4;
            else if (method == Sugi96)
                NN[1] += -1.4;
        }

        QVector<double> NN1(4); // case when all Ns are G/C
        for (int i = 0; i < NN.size(); ++i) NN1[i] = NN[i];
        QVector<double> NN2(4); // case when all Ns are A/T
        for (int i = 0; i < NN.size(); ++i) NN2[i] = NN[i];

        if (IsOnlyAT)
        {
            if (method == Bres86)
                NN1[1] += -20.13;
            else if (method ==Sant96)
                NN1[1] += -9.0;
            else if (method ==Sugi96)
            {
                NN1[0] += 0.6;
                NN1[1] += -9.0;
            }
        }
        else
        {
            if (method ==Bres86)
                NN2[1] += -16.77;
            else if (method ==Sant96)
                NN2[1] += -5.9;
            else if (method == Sugi96)
            {
                NN2[0] += 0.6;
                NN2[1] += -9.0;
            }
        }


        // initiation with terminal 5'(only Sant98)
        if (method == Sant98)
        {
            if (Seq[0] == 'g' | Seq[0] == 'c' | Seq[0] == 'n')
            {
                NN2[0] += 0.1;
                NN2[1] += -2.8;
            }
            else if (Seq[0] == 'a' | Seq[0] == 't' | Seq[0] == 'n')
            {
                NN1[0] += 2.3;
                NN1[1] += 4.1;

            }


            // initiation with terminal  3'
            if (Seq[Length - 1] == 'g' | Seq[Length - 1] == 'c')
            {
                NN2[0] += 0.1;
                NN2[1] += -2.8;
            }
            else if (Seq[Length - 1] == 'a' | Seq[Length - 1] == 't' | Seq[Length - 1] == 'n')
            {
                NN1[0] += 2.3;
                NN1[1] += 4.1;

            }
        }

        // average
        NN[0] = (NN1[0] + NN2[0]) * 0.5;
        NN[1] = (NN1[1] + NN2[1]) * 0.5;
        NN[2] = (qMax(NN1[0], NN2[0]) - qMin(NN1[0], NN2[0])) / 2.0; // delta level
        NN[3] = (qMax(NN1[1], NN2[1]) - qMin(NN1[1], NN2[1])) / 2.0; // delta level
    }
    return NN;

}//----------->



} // namespace BioQt
