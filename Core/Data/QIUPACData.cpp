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

#include "QIUPACData.h"

namespace BioQt {

const QString  QIUPACData::Protein_Chars("ACDEFGHIKLMNPQRSTVWY");

const QString QIUPACData::Extended_Protein_Chars("ACDEFGHIKLMNPQRSTVWYBXZJUO");

const QString QIUPACData::Ambiguous_DNA_Chars("ACGTMRWSYKVHDBN");//OKAY

const QString QIUPACData::Unambiguous_DNA_Chars("GATCN");

const QString QIUPACData::Ambiguous_RNA_Chars("ACGUMRWSYKVHDBN");//OKAY

const QString QIUPACData::Unambiguous_RNA_Chars("GAUCN");

const QString QIUPACData::Extended_DNA_Chars("GATCBDSWN");
const QString QIUPACData::NucleotideChars("ACGTU");

const QString QIUPACData::GapChar("-");
const QString QIUPACData::GapChars(".-");
const QString QIUPACData::NucleoUnresolvedChars("NXO0?");

const   QHash<QString,double> QIUPACData::Atoms_MW()
{
    QHash<QString,double> tmp;
    tmp["H"]=  1.00794;
    tmp["He"]=   4.002602;
    tmp["Li"]=   6.941;
    tmp["Be"]=   9.012182;
    tmp["B"]= 10.811;
    tmp["C"]= 12.0107;
    tmp["N"]= 14.0067;
    tmp["O"]= 15.9994;
    tmp["F"]= 18.9984032;
    tmp["Ne"]=  20.1797;
    tmp["Na"]=  22.989770;
    tmp["Mg"]=  24.3050;
    tmp["Al"]=  26.981538;
    tmp["Si"]=  28.0855;
    tmp["P"]= 30.973761;
    tmp["S"]= 32.065;
    tmp["Cl"]=  35.453;
    tmp["Ar"]=  39.948;
    tmp["K"]= 39.0983;
    tmp["Ca"]=  40.078;
    tmp["Sc"]=  44.955910;
    tmp["Ti"]=  47.867;
    tmp["V"]= 50.9415;
    tmp["Cr"]=  51.9961;
    tmp["Mn"]=  54.938049;
    tmp["Fe"]=  55.845;
    tmp["Co"]=  58.933200;
    tmp["Ni"]=  58.6934;
    tmp["Cu"]=  63.546;
    tmp["Zn"]=  65.39;
    tmp["Ga"]=  69.723;
    tmp["Ge"]=  72.64;
    tmp["As"]=  74.92160;
    tmp["Se"]=  78.96;
    tmp["Br"]=  79.904;
    tmp["Kr"]=  83.80;
    tmp["Rb"]=  85.4678;
    tmp["Sr"]=  87.62;
    tmp["Y"]= 88.90585;
    tmp["Zr"]=  91.224;
    tmp["Nb"]=  92.90638;
    tmp["Mo"]=  95.94;
    tmp["Tc"]=  98.0;
    tmp["Ru"]= 101.07;
    tmp["Rh"]= 102.90550;
    tmp["Pd"]= 106.42;
    tmp["Ag"]= 107.8682;
    tmp["Cd"]= 112.411;
    tmp["In"]= 114.818;
    tmp["Sn"]= 118.710;
    tmp["Sb"]= 121.760;
    tmp["Te"]= 127.60;
    tmp["I"]=126.90447;
    tmp["Xe"]= 131.293;
    tmp["Cs"]= 132.90545;
    tmp["Ba"]= 137.327;
    tmp["La"]= 138.9055;
    tmp["Ce"]= 140.116;
    tmp["Pr"]= 140.90765;
    tmp["Nd"]= 144.24;
    tmp["Pm"]= 145.0;
    tmp["Sm"]= 150.36;
    tmp["Eu"]= 151.964;
    tmp["Gd"]= 157.25;
    tmp["Tb"]= 158.92534;
    tmp["Dy"]= 162.50;
    tmp["Ho"]= 164.93032;
    tmp["Er"]= 167.259;
    tmp["Tm"]= 168.93421;
    tmp["Yb"]= 173.04;
    tmp["Lu"]= 174.967;
    tmp["Hf"]= 178.49;
    tmp["Ta"]= 180.9479;
    tmp["W"]=183.84;
    tmp["Re"]= 186.207;
    tmp["Os"]= 190.23;
    tmp["Ir"]= 192.217;
    tmp["Pt"]= 195.078;
    tmp["Au"]= 196.96655;
    tmp["Hg"]= 200.59;
    tmp["Tl"]= 204.3833;
    tmp["Pb"]= 207.2;
    tmp["Bi"]= 208.98038;
    tmp["Po"]= 208.98;
    tmp["At"]= 209.99;
    tmp["Rn"]= 222.02;
    tmp["Fr"]= 223.02;
    tmp["Ra"]= 226.03;
    tmp["Ac"]= 227.03;
    tmp["Th"]= 232.0381;
    tmp["Pa"]= 231.03588;
    tmp["U"]=238.02891;
    tmp["Np"]= 237.05;
    tmp["Pu"]= 244.06;
    tmp["Am"]= 243.06;
    tmp["Cm"]= 247.07;
    tmp["Bk"]= 247.07;
    tmp["Cf"]= 251.08;
    tmp["Es"]= 252.08;
    tmp["Fm"]= 257.10;
    tmp["Md"]= 258.10;
    tmp["No"]= 259.10;
    tmp["Lr"]= 262.11;
    tmp["Rf"]= 261.11;
    tmp["Db"]= 262.11;
    tmp["Sg"]= 266.12;
    tmp["Bh"]= 264.12;
    tmp["Hs"]= 269.13;
    tmp["Mt"]= 268.14;
    return tmp;

}
//*****************************************************************************************
//=============================================================================
//                              QIUPACData::DnaTable
//==============================================================================

QList<CompoundTable> QIUPACData::DnaTable()
{
    QList<CompoundTable> tmp;
    tmp<<CompoundTable(-1, "-",  0, "Gap");// 0x00==> 00000000
    tmp<<CompoundTable( 0, "A",  1, "Adenine"); // 0x01==> 00000001
    tmp<<CompoundTable( 1, "C",  2, "Cytosine");//0x02==> 00000010
    tmp<<CompoundTable( 2, "G",  4, "Guanine");//0x04==> 00000100
    tmp<<CompoundTable( 3, "T",  8, "Thymine"); //0x08==> 00001000
    tmp<<CompoundTable( 4, "M",  3, "Adenine or Cytosine");//0x03==> 00000011
    tmp<<CompoundTable( 5, "R",  5, "Purine (Adenine or Guanine)");//0x05==> 00000101
    tmp<<CompoundTable( 6, "W",  9, "Adenine or Thymine");//0x09==> 00001001
    tmp<<CompoundTable( 7, "S",  6, "Cytosine or Guanine");// 0x06==> 00000110
    tmp<<CompoundTable( 8, "Y", 10, "Pyrimidine (Cytosine or Thymine)");//0x0A==> 00001010
    tmp<<CompoundTable( 9, "K", 12, "Guanine or Thymine");//0x0C==> 00001100
    tmp<<CompoundTable(10, "V",  7, "Adenine or Cytosine or Guanine");//0x07==> 00000111
    tmp<<CompoundTable(11, "H", 11, "Adenine or Cytosine or Thymine");//0x0B==> 00001011
    tmp<<CompoundTable(12, "D", 13, "Adenine or Guanine or Thymine");//0x0D==> 00001101
    tmp<<CompoundTable(13, "B", 14, "Cytosine or Guanine or Thymine");//0x0E==> 00001110
    tmp<<CompoundTable(14, "N", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "X", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "O", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "0", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "?", 15, "Unresolved base");//0x0F==> 00001111
    return tmp;
}
//=============================================================================
//                              QIUPACData::RnaTable
//==============================================================================
QList<CompoundTable> QIUPACData::RnaTable()
{
    QList<CompoundTable> tmp;
    tmp<<CompoundTable(-1, "-",  0, "Gap");// 0x00==> 00000000
    tmp<<CompoundTable( 0, "A",  1, "Adenine"); // 0x01==> 00000001
    tmp<<CompoundTable( 1, "C",  2, "Cytosine");//0x02==> 00000010
    tmp<<CompoundTable( 2, "G",  4, "Guanine");//0x04==> 00000100
    tmp<<CompoundTable( 3, "U",  8, "Uracile"); //0x08==> 00001000
    tmp<<CompoundTable( 4, "M",  3, "Adenine or Cytosine");//0x03==> 00000011
    tmp<<CompoundTable( 5, "R",  5, "Purine (Adenine or Guanine)");//0x05==> 00000101
    tmp<<CompoundTable( 6, "W",  9, "Adenine or Uracile");//0x09==> 00001001
    tmp<<CompoundTable( 7, "S",  6, "Cytosine or Guanine");// 0x06==> 00000110
    tmp<<CompoundTable( 8, "Y", 10, "Pyrimidine (Cytosine or Uracile)");//0x0A==> 00001010
    tmp<<CompoundTable( 9, "K", 12, "Guanine or Uracile");//0x0C==> 00001100
    tmp<<CompoundTable(10, "V",  7, "Adenine or Cytosine or Guanine");//0x07==> 00000111
    tmp<<CompoundTable(11, "H", 11, "Adenine or Cytosine or Uracile");//0x0B==> 00001011
    tmp<<CompoundTable(12, "D", 13, "Adenine or Guanine or Uracile");//0x0D==> 00001101
    tmp<<CompoundTable(13, "B", 14, "Cytosine or Guanine or Thymine");//0x0E==> 00001110
    tmp<<CompoundTable(14, "N", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "X", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "O", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "0", 15, "Unresolved base");//0x0F==> 00001111
    tmp<<CompoundTable(14, "?", 15, "Unresolved base");//0x0F==> 00001111
    return tmp;
}
//==============================================================================================
//
//===============================================================================================

QList<ProteinTable> QIUPACData::AminoTable()
{
    QList<ProteinTable> tmp;
    tmp<<ProteinTable(-1, "-", "GAP", "Gap");
    tmp<<ProteinTable( 0, "A", "ALA", "Alanine");
    tmp<<ProteinTable( 1, "R", "ARG", "Arginine");
    tmp<<ProteinTable( 2, "N", "ASN", "Asparagine");
    tmp<<ProteinTable( 3, "D", "ASP", "Asparatic Acid");
    tmp<<ProteinTable( 4, "C", "CYS", "Cysteine");
    tmp<<ProteinTable( 5, "Q", "GLN", "Glutamine");
    tmp<<ProteinTable( 6, "E", "GLU", "Glutamic acid");
    tmp<<ProteinTable( 7, "G", "GLY", "Glycine");
    tmp<<ProteinTable( 8, "H", "HIS", "Histidine");
    tmp<<ProteinTable( 9, "I", "ILE", "Isoleucine");
    tmp<<ProteinTable(10, "L", "LEU", "Leucine");
    tmp<<ProteinTable(11, "K", "LYS", "Lysine");
    tmp<<ProteinTable(12, "M", "MET", "Methionine");
    tmp<<ProteinTable(13, "F", "PHE", "Phenylalanine");
    tmp<<ProteinTable(14, "P", "PRO", "Proline");
    tmp<<ProteinTable(15, "S", "SER", "Serine");
    tmp<<ProteinTable(16, "T", "THR", "Threonine");
    tmp<<ProteinTable(17, "W", "TRP", "Tryptophan");
    tmp<<ProteinTable(18, "Y", "TYR", "Tyrosine");
    tmp<<ProteinTable(19, "V", "VAL", "Valine");
    tmp<<ProteinTable(20, "B", "B", "N or D");
    tmp<<ProteinTable(21, "Z", "Z", "Q or E");
    tmp<<ProteinTable(22, "X", "X", "Unresolved amino acid");
    tmp<<ProteinTable(22, "O", "O", "Unresolved amino acid");
    tmp<<ProteinTable(22, "0", "0", "Unresolved amino acid");
    tmp<<ProteinTable(22, "?", "?", "Unresolved amino acid");
    return tmp;

}
//=======================================================================================================
//
//=======================================================================================================

QList<AminInfoTable> QIUPACData::AminAcidPropertiesTable()
{
    QList<AminInfoTable> tmp;
    tmp<<AminInfoTable("A", "Ala", "Alanine",
                       "C3H7NO2",
                       89.090000,
                       8.300000,
                       11.500000,
                       8.100000,
                       78.000000,
                       0.620000,
                       1.800000,
                       4.340000,
                       4.000000,
                       11.200000,
                       6.600000,
                       86.600000,
                       0.360000,
                       0.984,
                       -0.5,
                       0.815,
                       0.28,
                       HalfLife(4.4, 20, 10)
                       );

    tmp<<AminInfoTable("C", "Cys",
                       "Cysteine", "C3H7NO2S",
                       121.150000,
                       1.700000,
                       13.460000,
                       15.500000,
                       89.000000,
                       0.290000,
                       2.500000,
                       35.770000,
                       1.000000,
                       4.100000,
                       0.900000,
                       132.300000,
                       0.350000,
                       0.906,
                       -1.0,
                       0.394,
                       0.97,
                       HalfLife(1.2, 20, 10)
                       );
    tmp<<AminInfoTable("D", "Asp",
                       "AsparticAcid", "C4H7NO4",
                       133.100000,
                       5.300000,
                       11.680000,
                       13.000000,
                       81.000000,
                       -0.900000,
                       -3.500000,
                       13.280000,
                       2.000000,
                       2.900000,
                       7.700000,
                       97.800000,
                       0.510000,
                       1.068,
                       3.0,
                       1.283,
                       -0.52,
                       HalfLife(1.1, 2, 10)
                       );

    tmp<<AminInfoTable("E", "Glu",
                       "GlutamicAcid", "C5H9NO4",
                       147.130000,
                       6.200000,
                       13.570000,
                       12.300000,
                       78.000000,
                       -0.740000,
                       -3.500000,
                       17.560000,
                       2.000000,
                       1.800000,
                       5.700000,
                       113.900000,
                       0.500000,
                       1.094,
                       3.0,
                       1.445,
                       -1.01,
                       HalfLife(1, 30, 10)
                       );

    tmp<<AminInfoTable("F", "Phe",
                       "Phenylalanine", "C9H11NO2",
                       165.190000,
                       3.900000,
                       19.800000,
                       5.200000,
                       81.000000,
                       1.190000,
                       2.800000,
                       29.400000,
                       2.000000,
                       5.100000,
                       2.400000,
                       194.100000,
                       0.310000,
                       0.915,
                       -2.5,
                       0.695,
                       0.46,
                       HalfLife(1.1, 3, 2)
                       );

    tmp<<AminInfoTable("G", "Gly",
                       "Glycine", "C2H5NO2",
                       75.070000,
                       7.200000,
                       3.400000,
                       9.000000,
                       84.000000,
                       0.480000,
                       -0.400000,
                       0.000000,
                       4.000000,
                       11.800000,
                       6.700000,
                       62.900000,
                       0.540000,
                       1.031,
                       0.0,
                       0.714,
                       0.43,
                       HalfLife(30, 20, 10)
                       );

    tmp<<AminInfoTable("H", "His",
                       "Histidine", "C6H9N3O2",
                       155.160000,
                       2.200000,
                       13.690000,
                       10.400000,
                       84.000000,
                       -0.400000,
                       -3.200000,
                       21.810000,
                       2.000000,
                       2.000000,
                       2.500000,
                       155.800000,
                       0.320000,
                       0.950,
                       -0.05,
                       1.180,
                       -0.31,
                       HalfLife(3.5, 10, 10)
                       );

    tmp<<AminInfoTable("I", "Ile",
                       "Isoleucine", "C6H13NO2",
                       131.170000,
                       5.200000,
                       21.400000,
                       5.200000,
                       88.000000,
                       1.380000,
                       4.500000,
                       18.780000,
                       3.000000,
                       8.600000,
                       2.800000,
                       158.000000,
                       0.460000,
                       0.927,
                       -1.8,
                       0.603,
                       0.60,
                       HalfLife(20, 30, 10)
                       );

    tmp<<AminInfoTable("K", "Lys",
                       "Lysine", "C6H14N2O2",
                       146.190000,
                       5.700000,
                       15.710000,
                       11.300000,
                       87.000000,
                       -1.500000,
                       -3.900000,
                       21.290000,
                       2.000000,
                       0.500000,
                       10.300000,
                       115.500000,
                       0.470000,
                       1.102,
                       3.0,
                       1.545,
                       -1.62,
                       HalfLife(1.3, 3.0 / 60, 2.0 / 60)
                       );

    tmp<<AminInfoTable("L", "Leu",
                       "Leucine", "C6H13NO2",
                       131.170000,
                       9.000000,
                       21.400000,
                       4.900000,
                       85.000000,
                       1.060000,
                       3.800000,
                       19.060000,
                       6.000000,
                       11.700000,
                       4.800000,
                       164.100000,
                       0.370000,
                       0.935,
                       -1.8,
                       0.603,
                       0.60,
                       HalfLife(5.5, 3.0 / 60, 2.0 / 60)
                       );

    tmp<<AminInfoTable("M", "Met",
                       "Methionine", "C5H11NO2S",
                       149.210000,
                       2.400000,
                       16.250000,
                       5.700000,
                       80.000000,
                       0.640000,
                       1.900000,
                       21.640000,
                       1.000000,
                       1.900000,
                       1.000000,
                       172.900000,
                       0.300000,
                       0.952,
                       -1.3,
                       0.714,
                       0.43,
                       HalfLife(30, 20, 10)
                       );

    tmp<<AminInfoTable("N", "Asn",
                       "Asparagine", "C4H8N2O3",
                       132.120000,
                       4.400000,
                       12.820000,
                       11.600000,
                       94.000000,
                       -0.780000,
                       -3.500000,
                       12.000000,
                       2.000000,
                       2.900000,
                       6.700000,
                       103.300000,
                       0.460000,
                       1.048,
                       0.2,
                       1.296,
                       -0.55,
                       HalfLife(1.4, 3, 10)
                       );

    tmp<<AminInfoTable("P", "Pro",
                       "Proline", "C5H9NO2",
                       115.130000,
                       5.100000,
                       17.430000,
                       8.000000,
                       91.000000,
                       0.120000,
                       -1.600000,
                       10.930000,
                       4.000000,
                       2.700000,
                       4.800000,
                       92.900000,
                       0.510000,
                       1.049,
                       0.0,
                       1.236,
                       -.042,
                       HalfLife(20, 20, 0)
                       );

    tmp<<AminInfoTable("Q", "Gln",
                       "Glutamine", "C5H10N2O3",
                       146.150000,
                       4.000000,
                       14.450000,
                       10.500000,
                       87.000000,
                       -0.850000,
                       -3.500000,
                       17.260000,
                       2.000000,
                       1.600000,
                       5.200000,
                       119.200000,
                       0.490000,
                       1.037,
                       0.2,
                       1.348,
                       -.096,
                       HalfLife(0.8, 10, 10)
                       );

    tmp<<AminInfoTable("R", "Arg",
                       "Arginine", "C6H14N4O2",
                       174.200000,
                       5.700000,
                       14.280000,
                       10.500000,
                       95.000000,
                       -2.530000,
                       -4.500000,
                       26.660000,
                       6.000000,
                       0.500000,
                       4.500000,
                       162.200000,
                       0.530000,
                       1.008,
                       3.0,
                       1.475,
                       -1.14,
                       HalfLife(1.0, 2.0 / 60, 2.0 / 60)
                       );

    tmp<<AminInfoTable("S", "Ser",
                       "Serine", "C3H7NO3",
                       105.090000,
                       6.900000,
                       9.470000,
                       9.200000,
                       107.000000,
                       -0.180000,
                       -0.800000,
                       6.350000,
                       6.000000,
                       8.000000,
                       9.400000,
                       85.600000,
                       0.510000,
                       1.046,
                       0.3,
                       1.115,
                       -.019,
                       HalfLife(1.9, 20.0, 10.0)
                       );

    tmp<<AminInfoTable("T", "Thr",
                       "Threonine", "C4H9NO3",
                       119.120000,
                       5.800000,
                       15.770000,
                       8.600000,
                       93.000000,
                       -0.050000,
                       -0.700000,
                       11.010000,
                       4.000000,
                       4.900000,
                       7.000000,
                       106.500000,
                       0.440000,
                       0.997,
                       -0.4,
                       1.184,
                       -0.32,
                       HalfLife(7.2, 20.0, 10.0)
                       );

    tmp<<AminInfoTable("V", "Val",
                       "Valine", "C5H11NO2",
                       117.150000,
                       6.600000,
                       21.570000,
                       5.900000,
                       89.000000,
                       1.080000,
                       4.200000,
                       13.920000,
                       4.000000,
                       12.900000,
                       4.500000,
                       141.000000,
                       0.390000,
                       0.931,
                       -1.5,
                       0.606,
                       0.60,
                       HalfLife(100.0, 20.0, 10.0)
                       );

    tmp<<AminInfoTable("W", "Trp",
                       "Tryptophan", "C11H12N2O2",
                       204.230000,
                       1.300000,
                       21.670000,
                       5.400000,
                       104.000000,
                       0.810000,
                       -0.900000,
                       42.530000,
                       1.000000,
                       2.200000,
                       1.400000,
                       224.600000,
                       0.310000,
                       0.904,
                       -3.4,
                       0.808,
                       0.29,
                       HalfLife(2.8, 3.0 / 60, 2.0 / 60)
                       );

    tmp<<AminInfoTable("Y", "Tyr",
                       "Tyrosine", "C9H11NO3",
                       181.190000,
                       3.200000,
                       18.030000,
                       6.200000,
                       84.000000,
                       0.260000,
                       -1.300000,
                       31.530000,
                       2.000000,
                       2.600000,
                       5.100000,
                       177.700000,
                       0.420000,
                       0.929,
                       -2.3,
                       1.089,
                       -0.15,
                       HalfLife(2.8, 10, 2)
                       );
    return tmp;

}
//----------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
const QHash<QChar,QString> QIUPACData::Ambiguous_DNA_Values()
{
    QHash<QChar,QString> tmp;
    tmp['A']= "A";
    tmp['C']= "C";
    tmp['G']= "G";
    tmp['T']= "T";
    tmp['M']= "AC";
    tmp['R']= "AG";
    tmp['W']= "AT";
    tmp['S']= "CG";
    tmp['Y']= "CT";
    tmp['K']= "GT";
    tmp['V']= "ACG";
    tmp['H']= "ACT";
    tmp['D']= "AGT";
    tmp['B']= "CGT";
    tmp['X']= "GATC";
    tmp['N']= "GATC";
    return tmp;
}

const QHash<QChar,QString> QIUPACData::Ambiguous_RNA_Values()
{
    QHash<QChar,QString> tmp;
    tmp['A']= "A";
    tmp['C']= "C";
    tmp['G']= "G";
    tmp['U']= "U";
    tmp['M']= "AC";
    tmp['R']= "AG";
    tmp['W']= "AU";
    tmp['S']= "CG";
    tmp['Y']= "CU";
    tmp['K']= "GU";
    tmp['V']= "ACG";
    tmp['H']= "ACU";
    tmp['D']= "AGU";
    tmp['B']= "CGU";
    tmp['X']= "GAUC";
    tmp['N']= "GAUC";
    return tmp;

}

const QHash<QChar,QChar> QIUPACData::Ambiguous_DNA_Complement()
{
    QHash<QChar,QChar> tmp;
    tmp['A']= 'T';
    tmp['C']= 'G';
    tmp['G']= 'C';
    tmp['T']= 'A';
    tmp['M']= 'K';
    tmp['R']= 'Y';
    tmp['W']= 'W';
    tmp['S']= 'S';
    tmp['Y']= 'R';
    tmp['K']= 'M';
    tmp['V']= 'B';
    tmp['H']= 'D';
    tmp['D']= 'H';
    tmp['B']= 'V';
    tmp['X']= 'X';
    tmp['N']= 'N';
    return tmp;


}


const QHash<QChar,QChar> QIUPACData::Ambiguous_RNA_Complement()
{
    QHash<QChar,QChar> tmp;
    tmp['A']= 'U';
    tmp['C']= 'G';
    tmp['G']= 'C';
    tmp['U']= 'A';
    tmp['M']= 'K';
    tmp['R']= 'Y';
    tmp['W']= 'W';
    tmp['S']= 'S';
    tmp['Y']= 'R';
    tmp['K']= 'M';
    tmp['V']= 'B';
    tmp['H']= 'D';
    tmp['D']= 'H';
    tmp['B']= 'V';
    tmp['X']= 'X';
    tmp['N']= 'N';
    return tmp;



}


const QHash<QChar,QString> QIUPACData::Extended_Amino_Values()
{
    QHash<QChar,QString> tmp;
    tmp['A']= "A";
    tmp['B']= "ND";
    tmp['C']= "C";
    tmp['D']= "D";
    tmp['E']= "E";
    tmp['F']= "F";
    tmp['G']= "G";
    tmp['H']= "H";
    tmp['I']= "I";
    tmp['J']= "IL";
    tmp['K']= "K";
    tmp['L']= "L";
    tmp['M']= "M";
    tmp['N']= "N";
    tmp['O']= "O";
    tmp['P']= "P";
    tmp['Q']= "Q";
    tmp['R']= "R";
    tmp['S']= "S";
    tmp['T']= "T";
    tmp['U']= "U";
    tmp['V']= "V";
    tmp['W']= "W";
    tmp['X']= "ACDEFGHIKLMNPQRSTVWY";
    tmp['Y']= "Y";
    tmp['Z']= "QE";
    return tmp;




}
//=====================================================================
const QHash<QString,QString> QIUPACData::Amino_Names_1Lto3L()
{
    QHash<QString,QString> tmp;
    tmp["A"]= "Ala";
    tmp["C"]= "Cys";
    tmp["D"]= "Asp";
    tmp["E"]= "Glu";
    tmp["F"]= "Phe";
    tmp["G"]= "Gly";
    tmp["H"]= "His";
    tmp["I"]= "Ile";
    tmp["K"]= "Lys";
    tmp["L"]= "Leu";
    tmp["M"]= "Met";
    tmp["N"]= "Asn";
    tmp["P"]= "Pro";
    tmp["Q"]= "Gln";
    tmp["R"]= "Arg";
    tmp["S"]= "Ser";
    tmp["T"]= "Thr";
    tmp["V"]= "Val";
    tmp["W"]= "Trp";
    tmp["Y"]= "Tyr";
    tmp["B"]= "Asx";	// D/N
    tmp["Z"]= "Glx";	// E/Q
    tmp["J"]= "Xle";	// I/L
    tmp["U"]= "Sec";	// "uga" (stop)
    tmp["O"]= "Pyl";	// "uag" (stop)
    tmp["X"]= "Xaa";	// (unknown)
    return tmp;
}

const QHash<QString,QString> QIUPACData::Amino_Names()
{
    QHash<QString,QString> tmp;
    tmp["Ala"]= "alanine";
    tmp["Cys"]= "cysteine";
    tmp["Asp"]= "aspartic acid";
    tmp["Glu"]= "glutamic acid";
    tmp["Phe"]= "phenylalanine";
    tmp["Gly"]= "glycine";
    tmp["His"]= "histidine";
    tmp["Ile"]= "isoleucine";
    tmp["Lys"]= "lysine";
    tmp["Leu"]= "leucine";
    tmp["Met"]= "methionine";
    tmp["Asn"]= "asparagine";
    tmp["Pro"]= "proline";
    tmp["Gln"]= "glutamine";
    tmp["Arg"]= "arginine";
    tmp["Ser"]= "serine";
    tmp["Thr"]= "threonine";
    tmp["Val"]= "valine";
    tmp["Trp"]= "tryptophan";
    tmp["Tyr"]= "tyrosine";
    tmp["Asx"]= "asparagine/aspartic acid [DN]";
    tmp["Glx"]= "glutamine/glutamic acid [EQ]";
    tmp["Xle"]= "isoleucine/leucine [IL]";
    tmp["Sec"]= "selenocysteine";
    tmp["Pyl"]= "pyrrolysine";
    tmp["Xaa"]= "unknown [A-Z]";
    return tmp;


}

const QHash<QString,QString> QIUPACData::Nucleo_Names()
{
    QHash<QString,QString> tmp;
    tmp["y"]= "tc";
    tmp["r"]= "ag";
    tmp["w"]= "at";
    tmp["s"]= "gc";
    tmp["k"]= "tg";
    tmp["m"]= "ac";
    tmp["b"]= "tgc";
    tmp["d"]= "atg";
    tmp["h"]= "atc";
    tmp["v"]= "agc";
    tmp["n"]= "atgc";
    tmp["a"]= "a";
    tmp["t"]= "t";
    tmp["g"]= "g";
    tmp["c"]= "c";
    tmp["u"]= "u";
    tmp["A"]= "Adenine";
    tmp["T"]= "Thymine";
    tmp["G"]= "Guanine";
    tmp["C"]= "Cytosine";
    tmp["U"]= "Uracil";
    tmp["Y"]= "pYrimidine";
    tmp["R"]= "puRine";
    tmp["W"]= "Weak";
    tmp["S"]= "Strong";
    tmp["K"]= "Keto";
    tmp["M"]= "aroMatic";
    tmp["B"]= "not A";
    tmp["D"]= "not C";
    tmp["H"]= "not G";
    tmp["V"]= "not T";
    return tmp;



}
const QMap<QChar,double>  QIUPACData::Amino_MW()
{
    QMap<QChar,double> tmp;
    tmp['A']= 89.09;
    tmp['C']= 121.15;
    tmp['D']= 133.1;
    tmp['E']= 147.13;
    tmp['F']= 165.19;
    tmp['G']= 75.07;
    tmp['H']= 155.16;
    tmp['I']= 131.17;
    tmp['K']= 146.19;
    tmp['L']= 131.17;
    tmp['M']= 149.21;
    tmp['N']= 132.12;
    tmp['O']= 255.31;
    tmp['P']= 115.13;
    tmp['Q']= 146.15;
    tmp['R']= 174.20;
    tmp['S']= 105.09;
    tmp['T']= 119.12;
    tmp['U']= 168.06;
    tmp['V']= 117.15;
    tmp['W']= 204.23;
    tmp['Y']= 181.19;
    return tmp;

}
const QMap<QChar,double> QIUPACData::Amino_Hydrophobicity()
{
    QMap<QChar,double> tmp;
    tmp['A'] =  1.800;
    tmp['R'] = -4.500;
    tmp['N'] = -3.500;
    tmp['D'] = -3.500;
    tmp['C'] =  2.500;
    tmp['Q'] = -3.500;
    tmp['E'] = -3.500;
    tmp['G'] = -0.400;
    tmp['H'] = -3.200;
    tmp['I'] =  4.500;
    tmp['L'] =  3.800;
    tmp['K'] = -3.900;
    tmp['M'] =  1.900;
    tmp['F'] =  2.800;
    tmp['P'] = -1.600;
    tmp['S'] = -0.800;
    tmp['T'] = -0.700;
    tmp['W'] = -0.900;
    tmp['Y'] = -1.300;
    tmp['V'] =  4.200;
    return tmp;

}

const QList<double> QIUPACData::DNAMolWeight()
{
    QList<double> tmp;
    tmp<<313.21<< 289.18<< 329.21<< 304.2;//A=>C=>G=>T from heavy to light
    return tmp;
}


const QList<double> QIUPACData::RNAMolWeight()
{
    QList<double> tmp;
    tmp<<329.21<< 305.18<< 345.21<< 306.17;//A=>C=>G=>U
    return tmp;
}


bool QIUPACData::IsBase(char base)
{
    base=toupper(base) ;
    if ((base == 'A')  ||
            (base  == 'G')  ||
            (base  == 'C')  ||
            (base  == 'U')  ||
            (base  == 'T')) {return true;	}
    return false;
}

bool QIUPACData::IsIUpacBase(char base)
{
    base=toupper(base) ;
    if ((base == 'M') ||
            (base == 'R') ||
            (base == 'W') ||
            (base == 'S') ||
            (base == 'Y') ||
            (base == 'K') ||
            (base == 'V') ||
            (base == 'H') ||
            (base == 'D') ||
            (base == 'B') ||
            (base == 'N'))
    {
        return true;
    }
    return false;
}

QMap<QChar,double> QIUPACData::PKAMap() {
    QMap<QChar,double> tmp;

    tmp.insert('D', 4.0);
    tmp.insert('C', 8.5);
    tmp.insert('E', 4.4);
    tmp.insert('Y', 10.0);
    tmp.insert('c', 3.1); // CTERM
    tmp.insert('R', 12.0);
    tmp.insert('H', 6.5);
    tmp.insert('K', 10.4);
    tmp.insert('n',8.0); // NTERM

    return tmp;
}

QMap<QChar,int> QIUPACData::ChargeMap() {
    QMap<QChar,int> tmp;

    tmp.insert('D', -1);
    tmp.insert('C', -1);
    tmp.insert('E', -1);
    tmp.insert('Y', -1);
    tmp.insert('c', -1); // CTERM
    tmp.insert('R', 1);
    tmp.insert('H', 1);
    tmp.insert('K', 1);
    tmp.insert('n', 1); // NTERM

    return tmp;
}

const QMap<char, QMap<char, double> > QIUPACData::InstabilityIndex()
{
    QMap<char,QMap<char,double>> _tmp;
    QMap<char,double> tmp;
    //===============A==========================//
    tmp['A']= 1.0 ;tmp['C']= 44.94;tmp['E']= 1.0;
    tmp['D']= -7.49;tmp['G']= 1.0;tmp['F']= 1.0;
    tmp['I']= 1.0; tmp['H']= -7.49;tmp['K']= 1.0;
    tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= 20.26; tmp['S']= 1.0 ;
    tmp['R']= 1.0;tmp['T']= 1.0;tmp['W']= 1.0 ;
    tmp['V']= 1.0 ;
    tmp['Y']= 1.0;
    _tmp['A']=tmp;
    tmp.clear();
    //================C===============================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;
    tmp['D']= 20.26;tmp['G']= 1.0;tmp['F']= 1.0;
    tmp['I']= 1.0;tmp['H']= 33.60;tmp['K']= 1.0;
    tmp['M']= 33.60;tmp['L']= 20.26;tmp['N']= 1.0;
    tmp['Q']= -6.54;tmp['P']= 20.26;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= 33.60;tmp['W']= 24.68;tmp['V']= -6.54;
    tmp['Y']= 1.0;
    _tmp['C']=tmp;
    tmp.clear();
    //================E=====================================//
    tmp['A']= 1.0;tmp['C']= 44.94;tmp['E']= 33.60;
    tmp['D']= 20.26;tmp['G']= 1.0;tmp['F']= 1.0;
    tmp['I']= 20.26;tmp['H']= -6.54;tmp['K']= 1.0;
    tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 20.26;tmp['P']= 20.26;tmp['S']= 20.26;
    tmp['R']= 1.0;
    _tmp['E']=tmp;
    tmp.clear();
    //================D=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= 1.0;tmp['F']= -6.54;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= -7.49;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= 1.0;tmp['S']= 20.26;tmp['R']= -6.54;
    tmp['T']= -14.03;tmp['W']= 1.0;tmp['V']= 1.0;tmp['Y']= 1.0;
    _tmp['D']=tmp;
    tmp.clear();
    //================G=====================================//
    tmp['A']= -7.49;tmp['C']= 1.0;tmp['E']= -6.54;tmp['D']= 1.0;
    tmp['G']= 13.34;tmp['F']= 1.0;tmp['I']= -7.49;tmp['H']= 1.0;
    tmp['K']= -7.49;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= -7.49;
    tmp['Q']= 1.0;tmp['P']= 1.0;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= -7.49;tmp['W']= 13.34;tmp['V']= 1.0;tmp['Y']= -7.49;
    _tmp['G']=tmp;
    tmp.clear();
    //================F=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 13.34;
    tmp['G']= 1.0;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= -14.03;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= 20.26;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= 1.0;tmp['W']= 1.0;tmp['V']= 1.0;tmp['Y']= 33.601;
    _tmp['F']=tmp;
    tmp.clear();
    //================I=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 44.94;tmp['D']= 1.0;
    tmp['G']= 1.0;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 13.34;
    tmp['K']= -7.49;tmp['M']= 1.0;tmp['L']= 20.26;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= -1.88;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= 1.0;tmp['W']= 1.0;tmp['V']= -7.49;tmp['Y']= 1.0;
    _tmp['I']=tmp;
    tmp.clear();
    //================H=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= -9.37;tmp['F']= -9.37;tmp['I']= 44.94;tmp['H']= 1.0;
    tmp['K']= 24.68;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 24.68;
    tmp['Q']= 1.0;tmp['P']= -1.88;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= -6.54;tmp['W']= -1.88;tmp['V']= 1.0;tmp['Y']= 44.94;
    _tmp['H']=tmp;
    tmp.clear();
    //================K=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= -7.49;tmp['F']= 1.0;tmp['I']= -7.49;tmp['H']= 1.0;
    tmp['K']= 1.0;tmp['M']= 33.60;tmp['L']= -7.49;tmp['N']= 1.0;
    tmp['Q']= 24.64;tmp['P']= -6.54;tmp['S']= 1.0;tmp['R']= 33.60;
    tmp['T']= 1.0;tmp['W']= 1.0;tmp['V']= -7.49;tmp['Y']= 1.0;
    _tmp['K']=tmp;
    tmp.clear();
    //================M=====================================//
    tmp['A']= 13.34;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= 1.0;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 58.28;
    tmp['K']= 1.0;tmp['M']= -1.88;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= -6.54;tmp['P']= 44.94;tmp['S']= 44.94;tmp['R']= -6.54;
    tmp['T']= -1.88;tmp['W']= 1.0;tmp['V']= 1.0;tmp['Y']= 24.68;
    _tmp['M']=tmp;
    tmp.clear();
    //================L=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= 1.0;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= -7.49;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 33.60;tmp['P']= 20.26;tmp['S']= 1.0;tmp['R']= 20.26;
    tmp['T']= 1.0;tmp['W']= 24.68;tmp['V']= 1.0;tmp['Y']= 1.0;
    _tmp['L']=tmp;
    tmp.clear();
    //================N=====================================//
    tmp['A']= 1.0;tmp['C']= -1.88;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= -14.03;tmp['F']= -14.03;tmp['I']= 44.94;tmp['H']= 1.0;
    tmp['K']= 24.68;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= -6.54;tmp['P']= -1.88;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= -7.49;tmp['W']= -9.37;tmp['V']= 1.0;tmp['Y']= 1.0;
    _tmp['N']=tmp;
    tmp.clear();
    //================Q=====================================//
    tmp['A']= 1.0;tmp['C']= -6.54;tmp['E']= 20.26;tmp['D']= 20.26;
    tmp['G']= 1.0;tmp['F']= -6.54;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= 1.0;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 20.26;tmp['P']= 20.26;tmp['S']= 44.94;tmp['R']= 1.0;
    tmp['T']= 1.0;tmp['W']= 1.0;tmp['V']= -6.54;tmp['Y']= -6.54;
    _tmp['Q']=tmp;
    tmp.clear();
    //================P=====================================//
    tmp['A']= 20.26;tmp['C']= -6.54;tmp['E']= 18.38;tmp['D']= -6.54;
    tmp['G']= 1.0;tmp['F']= 20.26;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= 1.0;tmp['M']= -6.54;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 20.26;tmp['P']= 20.26;tmp['S']= 20.26;tmp['R']= -6.54;
    tmp['T']= 1.0;tmp['W']= -1.88;tmp['V']= 20.26;tmp['Y']= 1.0;
    _tmp['P']=tmp;
    tmp.clear();
    //================S=====================================//
    tmp['A']= 1.0;tmp['C']= 33.60;tmp['E']= 20.26;tmp['D']= 1.0;
    tmp['G']= 1.0;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= 1.0;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 20.26;tmp['P']= 44.94;tmp['S']= 20.26;tmp['R']= 20.26;
    tmp['T']= 1.0;tmp['W']= 1.0;tmp['V']= 1.0;tmp['Y']= 1.0;
    _tmp['S']=tmp;
    tmp.clear();
    //================R=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= -7.49;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 20.26;
    tmp['K']= 1.0;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 13.34;
    tmp['Q']= 20.26;tmp['P']= 20.26;tmp['S']= 44.94;tmp['R']= 58.28;
    tmp['T']= 1.0;tmp['W']= 58.28;tmp['V']= 1.0;tmp['Y']= -6.54;
    _tmp['R']=tmp;
    tmp.clear();
    //================T=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 20.26;tmp['D']= 1.0;
    tmp['G']= -7.49;tmp['F']= 13.34;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= 1.0;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= -14.03;
    tmp['Q']= -6.54;tmp['P']= 1.0;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= 1.0;tmp['W']= -14.03;tmp['V']= 1.0;tmp['Y']= 1.0;
    _tmp['T']=tmp;
    tmp.clear();
    //================W=====================================//
    tmp['A']= -14.03;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= 1.0;
    tmp['G']= -9.37;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 24.68;
    tmp['K']= 1.0;tmp['M']= 24.68;tmp['L']= 13.34;tmp['N']= 13.34;
    tmp['Q']= 1.0;tmp['P']= 1.0;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= -14.03;tmp['W']= 1.0;tmp['V']= -7.49;tmp['Y']= 1.0;
    _tmp['W']=tmp;
    tmp.clear();
    //================V=====================================//
    tmp['A']= 1.0;tmp['C']= 1.0;tmp['E']= 1.0;tmp['D']= -14.03;
    tmp['G']= -7.49;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 1.0;
    tmp['K']= -1.88;tmp['M']= 1.0;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= 20.26;tmp['S']= 1.0;tmp['R']= 1.0;
    tmp['T']= -7.49;tmp['W']= 1.0;tmp['V']= 1.0;tmp['Y']= -6.54;
    _tmp['V']=tmp;
    tmp.clear();
    //================Y=====================================//
    tmp['A']= 24.68;tmp['C']= 1.0;tmp['E']= -6.54;tmp['D']= 24.68;
    tmp['G']= -7.49;tmp['F']= 1.0;tmp['I']= 1.0;tmp['H']= 13.34;
    tmp['K']= 1.0;tmp['M']= 44.94;tmp['L']= 1.0;tmp['N']= 1.0;
    tmp['Q']= 1.0;tmp['P']= 13.34;tmp['S']= 1.0;tmp['R']= -15.91;
    tmp['T']= -7.49;tmp['W']= -9.37;tmp['V']= 1.0;tmp['Y']= 13.34;
    _tmp['Y']=tmp;
    tmp.clear();
    //======================================================//
    return _tmp;

}

const QMap<QString, double> QIUPACData::PositivePks()
{
    QMap<QString,double> tmp;
    tmp["Nterm"]= 7.5;
    tmp["K"]= 10.0;
    tmp["R"]= 12.0;
    tmp["H"]=5.98;
    return tmp;

}

const QMap<QString, double> QIUPACData::NegativePks()
{
    QMap<QString,double> tmp;
    tmp["Cterm"]= 3.55;
    tmp["D"]= 4.05;
    tmp["E"]= 4.45;
    tmp["C"]=9.0;
    tmp["Y"]=10.0;
    return tmp;

}

const QMap<QString, double> QIUPACData::pKcterminal()
{
    QMap<QString,double> tmp;
    tmp["E"]= 4.75;
    tmp["D"]= 4.55;
    return tmp;

}

const QMap<QString, double> QIUPACData::pKnterminal()
{
    QMap<QString,double> tmp;
    tmp["A"]=7.59;
    tmp["M"]=7.0;
    tmp["S"]=6.93;
    tmp["P"]=8.36;
    tmp["T"]=6.82;
    tmp["V"]=7.44;
    tmp["E"]=7.7;
    return tmp;


}
//Flexibility
// Normalized flexibility parameters (B-values), average (Vihinen et al., 1994)
const QMap<QString, double> QIUPACData::Flex()
{
    QMap<QString, double> tmp;
    tmp["A"]= 0.984;tmp["C"]= 0.906;tmp["E"]= 1.094;tmp["D"]= 1.068;
    tmp["G"]= 1.031;tmp["F"]= 0.915;tmp["I"]= 0.927;tmp["H"]= 0.950;
    tmp["K"]= 1.102;tmp["M"]= 0.952;tmp["L"]= 0.935;tmp["N"]= 1.048;
    tmp["Q"]= 1.037;tmp["P"]= 1.049;tmp["S"]= 1.046;tmp["R"]= 1.008;
    tmp["T"]= 0.997;tmp["W"]= 0.904;tmp["V"]= 0.931;tmp["Y"]= 0.929;
    return tmp;
}

const QStringList QIUPACData::chargedAAs()
{
    QStringList tmp;
    tmp<<"k"<<"R"<<"H"<<"D"<<"E"<<"C"<<"Y";
    return tmp;

}


//-----------------------------------------------------------------------------------------

} // namespace BioQt
