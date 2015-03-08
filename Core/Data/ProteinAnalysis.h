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

#ifndef PROTEINANALYSIS_H
#define PROTEINANALYSIS_H


#include <BioQt_global.h>
#include <QtCore>
#include <Data/AminoAcidQuery.h>
#include <Sequence/QSequence.h>
#include <Data/QIUPACData.h>

namespace BioQt {
typedef struct SecondaryStructure {
  double helix,turn,sheet;
} SecondaryStructure;

class BIOQTSHARED_EXPORT ProteinAnalysis
{
public:
    ProteinAnalysis(const QSequence& _seq):seq(_seq){}
    QMap<QString,int> CountAminoAcids();
    QMap<QString,double> GetAminoAcidsPercent();
    double MolecularWeight();
    /**
     * @brief Aromaticity Calculates the aromaticity value of a protein according to Lobry, 1994.
     *   It is simply the relative frequency of Phe+Trp+Tyr.
     * @return
     */
    double Aromaticity();
    /**
     * @brief InstabilityIndex Calculate the instability index according to Guruprasad et al 1990.
     *Implementation of the method of Guruprasad et al. 1990 to test a
     * protein for stability. Any value above 40 means the protein is unstable
     *(has a short half life).
     *See: Guruprasad K., Reddy B.V.B., Pandit M.W.
     * Protein Engineering 4:155-161(1990).
     * @return
     */
    double InstabilityIndex();
    /**
     * @brief FlexiBility Calculate the flexibility according to Vihinen, 1994.
     * No argument to change window size because parameters are specific for a
     * window=9. The parameters used are optimized for determining the flexibility.
     * @return
     */
    QList<double> FlexiBility();
    /**
     * @brief SecondaryStructureFraction Calculate fraction of helix, turn and sheet.
     * @return Returns a list of the fraction of amino acids which tend
     *   to be in Helix, Turn or Sheet.
     *   Amino acids in helix: V, I, Y, F, W, L.
     *   Amino acids in Turn: N, P, G, S.
     *   Amino acids in sheet: E, M, A, L.
     *   Returns a tuple of three integers (Helix, Turn, Sheet)
     */
    SecondaryStructure SecondaryStructureFraction();


private:
    QSequence seq;
    QMap<QString,int> AminoAcidsContent;
    QMap<QString,double> AminoAcidsPercent;
};

} // namespace BioQt

#endif // BIOQT_PROTEINANALYSIS_H
