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
*BioQt::ProteinAnalysis
*@author Usama S Erawab
*
*/

#include "ProteinAnalysis.h"
#include <QtCore>
#include <memory>
namespace BioQt {

QMap<QString, int> ProteinAnalysis::CountAminoAcids()
{
    QMap<QString, int> tmp;
    foreach (QString c, QIUPACData::Protein_Chars) {
        tmp[c]=seq.count(c);
    }

    return tmp;
}

QMap<QString, double> ProteinAnalysis::GetAminoAcidsPercent()
{
    QMap<QString, double> tmp;

    foreach (QString c, CountAminoAcids().keys()) {
        tmp[c]=CountAminoAcids()[c]/(double)seq.size();

    }
    return tmp;
}

double ProteinAnalysis::MolecularWeight()
{
     double TotalWeight;
       for(int i=0;i <seq.size();++i)
       {
TotalWeight += QIUPACData::Amino_MW()[seq[i]];
       }

    return TotalWeight-(seq.size()-1)*18.010565;;
}

double ProteinAnalysis::Aromaticity()
{
    QString AromaticAAs = "YWF";
    double aromaticity=0.0;
    foreach (QString c, AromaticAAs) {
        aromaticity +=GetAminoAcidsPercent()[c];
    }
    return aromaticity;
}

double ProteinAnalysis::InstabilityIndex()
{
    double score = 0.0;
    double DipeptideValue;

    for(int i=0;i<seq.length()-1;++i)
    {


        DipeptideValue=QIUPACData::InstabilityIndex()[seq[i].toAscii()][seq[i+1].toAscii()];
        score += DipeptideValue;

    }

    return (10.0/seq.size())*score;
}

QList<double> ProteinAnalysis::FlexiBility()
{
    double flexibilities;
    //  std::auto_ptr<AminoAcidQuery> kk(new AminoAcidQuery);
    //std::auto_ptr<AminoAcidQuery>dd;


    int window_size = 9;
    QList<double> weights ;
    weights<<0.25<< 0.4375<< 0.625<< 0.8125<< 1;
    QList<double> scores;

    for(int i=0;i<seq.length()-window_size;++i)
    {
        // dd=new AminoAcidQuery();
        QString sq=seq.mid(i,window_size);
        double score=0.0;
        for(int j=0;j<window_size/2;++j)
        {

            QString front = sq[j];
            QString back = sq[window_size - j - 1];
            score += (QIUPACData::Flex()[front]+QIUPACData::Flex()[back])* weights[j];


        }
        QString middle = sq[window_size / 2 + 1];

        score += QIUPACData::Flex()[middle];
        scores.append(score / 5.25);

    }



    return scores;
}

SecondaryStructure ProteinAnalysis::SecondaryStructureFraction()
{
    SecondaryStructure tmp;
    QString H,T,S;
    T="NPGS";H="VIYFWL";S="EMAL";
    Q_FOREACH(QString c,T)
       tmp.turn +=GetAminoAcidsPercent()[c];
    Q_FOREACH(QString c,H)
       tmp.helix +=GetAminoAcidsPercent()[c];
    Q_FOREACH(QString c,S)
       tmp.sheet +=GetAminoAcidsPercent()[c];


        return tmp;

}








} // namespace BioQt
