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


#ifndef SEQRECORD_H
#define SEQRECORD_H

#include <BioQt_global.h>
#include <QtCore>
#include "SequenceException.h"
namespace BioQt {




/**
*BioQt::SeqRecord
*@author Usama S Erawab
*
*/

/**********************SequenceStrandType*****************************************/
typedef enum SequenceStrandType /* EStrand*/ {
    /** strandType is unspecified        */
    Strand_not_set =   0,
    Strand_ss      =   1,  ///< single strand(ss)
    Strand_ds      =   2,  ///< double strand(ds)
    Strand_mixed   =   3, ///< Mixed-stranded (ms).
    Strand_other   = 255  ///< default ds for DNA, ss for RNA, pept
}SequenceStrandType;
//*************************************************************************************

//********************************MoleculeType******************************************/
/**molecule class in living organism**/
typedef   enum MoleculesType {
    Mol_not_set =   0,  /// same as 3 rna
    Mol_dna     =   1,  ///Deoxyrobonucleic acid.
    Mol_rna     =   2, ///Ribonucleic acid of an unspecified type.
    Mol_aa      =   3, /// Amino Acid chain.
    Mol_na      =   4,  ///< just a nucleic acid.
    Mol_trna    =   5,  ///Transfer RNA.
    Mol_rrna    =   6,  ///Ribosomal RNA.
    Mol_mrna    =   7, ///Small nuclear RNA.
    Mol_urna    =   8,///Small nuclear RNA.
    Mol_snrna   =   9,///Small nuclear RNA.
    Mol_snorna  =   10,///Small nucleolar RNA (often referred to as guide RNA).
    Mol_other   = 255
}MoleculesType;

//****************************************************************************************/

//**************************SequenceStrandTopology***************************************/
//*A StrandTopology specifies whether the strand is linear or circular.*/
typedef enum SequenceStrandTopology {
    Topology_not_set  =   0,
    Topology_linear   =   1,
    Topology_circular =   2,
    Topology_tandem   =   3,  ///< some part of tandem repeat
    Topology_other    = 255
}SequenceStrandTopology;

//****************************************************************************************/

//*************************TranslationFrame**************************//


typedef   enum TranslationFrame {
    FramePlus1  =  1,
    FramePlus2  =  2,
    FramePlus3  =  3,
    FrameMinus1 = -1,
    FrameMinus2 = -2,
    FrameMinus3 = -3,
    FrameNotSet = 0
}TranslationFrame;

//**************************************************************************************//
//************************SequenceDivisionCode*********************************************//
typedef   enum SequenceDivisionCode {
    DivisionCode_Notset=0,///None - Division code is unspecified.
    DivisionCode_PRI=1,///Primate sequences
    DivisionCode_ROD=2,///Rodent sequences.
    DivisionCode_MAM=3,///Other mammalian sequences.
    DivisionCode_VRT=4,///Other vertebrate sequences.
    DivisionCode_INV=5,///Invertebrate sequences.
    DivisionCode_PLN=6,///Plant, fungal, and algal sequences.
    DivisionCode_BCT=7,///Bacterial sequences.
    DivisionCode_VRL=8,///Viral sequences.
    DivisionCode_PHG=9,///Bacteriophage sequences.
    DivisionCode_SYN=10,///Synthetic sequences.
    DivisionCode_UNA=11,///Unannotated sequences.
    DivisionCode_EST=12,///EST sequences (expressed sequence tags).
    DivisionCode_PAT=13,///Patent sequences.
    DivisionCode_STS=14,///STS sequences (sequence tagged sites).
    DivisionCode_GSS=15,///GSS sequences (genome survey sequences).
    DivisionCode_HTG=16,///HTGS sequences (high throughput genomic sequences).
    DivisionCode_HTC=17,///HTC sequences (high throughput cDNA sequences).
    DivisionCode_ENV=18,///Environmental sampling sequences.
    DivisionCode_CON=19///Constructed sequences


}SequenceDivisionCode;



typedef enum StrandDirection
{
    StrandDirection_Unkown=0,
    StrandDirection_Forward=1,
    StrandDirection_Reverced=2

}StrandDirection;

/**
 * Trace Assembly Archive.  The Description specifies the actual string
 * with spaces that appears in the genbank file.
 */
typedef enum CrossReferenceType
{
   CrossReference_Unkown=0,///CrossReferenceType is unspecified.
    CrossReference_Project=1,///Project.
    CrossReference_BioProject=2///BioProject Type.

}CrossReferenceType;


//****************************************************************************//

class BIOQTSHARED_EXPORT SeqInfo
{
public:
    SeqInfo(){}
    TranslationFrame GetFrame() const { return  m_Frame; }
    void SetFrame(TranslationFrame frame){m_Frame=frame;}

    QString GetID()const {return ID;}
    void SetID(const QString &_id){ID=_id;}

    SequenceStrandType GetStrand()const {return  m_Strand;}
    void SetStrand (SequenceStrandType strand){m_Strand=strand;}

    MoleculesType GetMol()const {return  m_Mol;}
    void SetMol(MoleculesType mol){m_Mol=mol;}

    SequenceStrandTopology GetTopology()const {return  m_Topology;}
    void SetTopology(SequenceStrandTopology topology){m_Topology=topology;}

    SequenceDivisionCode GetDivisionCode()const {return  m_DivisionCode;}
    void SetMolDivisionCode(SequenceDivisionCode div){m_DivisionCode=div;}

    StrandDirection GetStrandDirection()const {return  m_direction;}
    void SetStrandDirection(StrandDirection dirct){m_direction=dirct;}

private:
    QString ID;
    SequenceStrandType m_Strand;
    SequenceStrandTopology m_Topology;
    MoleculesType m_Mol;
    TranslationFrame m_Frame;
    SequenceDivisionCode m_DivisionCode;
    StrandDirection m_direction;
};

} // namespace BioQt

#endif // BIOQT_SEQRECORD_H
