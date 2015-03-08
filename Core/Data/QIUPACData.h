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

#ifndef BIOQT_QIUPACDATA_H
#define BIOQT_QIUPACDATA_H

#include <QObject>
#include <BioQt_global.h>
#include <Compound/CompoundTable.h>
#include <Compound/ProteinTable.h>
#include <Compound/AminInfoTable.h>
#include <QtCore>
namespace BioQt {
/**
*@brief  QIUPACData Class
*@details   Declare Standard elements and it's property which used by sequences Object as defined by  IUPAC
*@author    Usama S Erawab <alrawab@hotmail.com>
*@version   1.0.0 Beta
*@date      21-01-2013
*/
class BIOQTSHARED_EXPORT QIUPACData : public QObject
{
    Q_OBJECT
public:
    /**

      // \verbatim
       Uppercase IUPAC protein single letter alphabet of the 20 standard amino acids
             Amino Acid alphabet:
             ------------------------------------------
             Symbol           Meaning
              ------------------------------------------
              A        Alanine
              B        Aspartic Acid, Asparagine
              C        Cystine
              D        Aspartic Acid
              E        Glutamic Acid
              F        Phenylalanine
              G        Glycine
              H        Histidine
              I        Isoleucine
              J        Isoleucine/Leucine
              K        Lysine
              L        Leucine
              M        Methionine
              N        Asparagine
              O        Pyrrolysine
              P        Proline
              Q        Glutamine
              R        Arginine
              S        Serine
              T        Threonine
              U        Selenocysteine
              V        Valine
              W        Tryptophan
              X        Unknown
              Y        Tyrosine
              Z        Glutamic Acid, Glutamine
              *        Terminator(stop codon)



              IUPAC-IUP AMINO ACID SYMBOLS:
                Biochem J. 1984 Apr 15; 219(2): 345-373
                Eur J Biochem. 1993 Apr 1; 213(1): 2
       \endverbatim
       http://www.chem.qmw.ac.uk/iupac/AminoAcid/A2021.html#AA21
      */
  static const QString Protein_Chars;
  /**

      Extended uppercase IUPAC protein single letter alphabet including X etc\n
       In addition to the standard 20 single letter protein codes, this includes:\n

        B = "Asx";  Aspartic acid (R) or Asparagine (N)
        X = "Xxx";  Unknown or 'other' amino acid
        Z = "Glx";  Glutamic acid (E) or Glutamine (Q)

        http://www.chem.qmul.ac.uk/iupac/AminoAcid/A2021.html#AA212 \n


        J = "Xle";  Leucine (L) or Isoleucine (I), used in mass-spec (NMR) \n
         Mentioned in :\n

         http://www.chem.qmul.ac.uk/iubmb/newsletter/1999/item3.html \n

        Also the International Nucleotide Sequence Database Collaboration (INSDC)
        (i.e. GenBank, EMBL, DDBJ) adopted this in 2006\n
        http://www.ddbj.nig.ac.jp/insdc/icm2006-e.html \n

       Xle (J); Leucine or Isoleucine \n
         The residue abbreviations, Xle (the three-letter abbreviation) and J
         (the one-letter abbreviation) are reserved for the case that cannot
         experimentally distinguish leucine from isoleucine.\n

        U = "Sec";  Selenocysteine \n
        http://www.chem.qmul.ac.uk/iubmb/newsletter/1999/item3.html \n

       O = "Pyl";  Pyrrolysine \n
       http://www.chem.qmul.ac.uk/iubmb/newsletter/2009.html#item35 \n

        This alphabet is not intended to be used with X for Selenocysteine  \n
        (an ad-hoc standard prior to the IUPAC adoption of U instead). \n


  */

  static const QString Extended_Protein_Chars;
  /**
   Uppercase IUPAC ambiguous DNA letters  \n
   http://www.chem.qmw.ac.uk/iubmb/misc/naseq.html
  */
  static const QString Ambiguous_DNA_Chars;
  /**
   Uppercase IUPAC unambiguous DNA (letters GATC only) \n
   http://www.chem.qmw.ac.uk/iubmb/misc/naseq.html
  */
  static const QString Unambiguous_DNA_Chars;
  /**
  Uppercase IUPAC ambiguous RNA letters
  */
  static const QString Ambiguous_RNA_Chars;
  /**
  Uppercase IUPAC unambiguous RNA (letters GAUC only)
  */
  static const QString Unambiguous_RNA_Chars;
  /**
  Extended IUPAC RNA alphabet:\n
     In addition to the standard letter codes GAUC, this includes:  \n

        B = 5-bromouridine \n
        D = 5,6-dihydrouridine \n
        S = thiouridine \n
        W = wyosine \n
  \verbatim
          Extended DNA / RNA alphabet :
          (includes symbols for nucleotide ambiguity)
          ------------------------------------------
          Symbol       Meaning      Nucleic Acid
          ------------------------------------------
           A            A           Adenine
           C            C           Cytosine
           G            G           Guanine
           T            T           Thymine
           U            U           Uracil
           M          A or C
           R          A or G
           W          A or T
           S          C or G
           Y          C or T
           K          G or T
           V        A or C or G
           H        A or C or T
           D        A or G or T
           B        C or G or T
           X      G or A or T or C
           N      G or A or T or C
           \endverbatim
          IUPAC-IUB SYMBOLS FOR NUCLEOTIDE NOMENCLATURE:
            Cornish-Bowden (1985) Nucl. Acids Res. 13: 3021-3030.

  */
  static const QString Extended_DNA_Chars;

  /**
   gap char in DNA sequence "-"
   */
  static const QString GapChar;
  /**
   gap chars in DNA sequence ".-"
   */
  static const QString GapChars;
  /**
   * @brief NucleoUnresolvedChars Unresolved charcter for nucleotoid (0 ,O,?,N,X)
   */
  static const QString NucleoUnresolvedChars;

  static const QString NucleotideChars;
    /**
     * @brief Atoms_MW
     * @return molecular weight of Known elements \n
      Taken from http://www.chem.qmul.ac.uk/iupac/AtWt/ & PyMol
     */
    static const QHash<QString,double> Atoms_MW();
    /**
     * @brief DnaTable
     *  <table>
     * <tr><th>ID</th><th>Letter</th><th>Name</th><th>Binary code</th><th>int value</th></tr>
     * <tr><td align=center>-1</td><td align=center>-</td><td align=center>Gap</td><td align=center>00000000</td><td align=center>0</td></tr>
     *<tr><td align=center>0</td><td align=center>A</td><td align=center>Adenine</td><td align=center>00000001</td><td align=center>1</td></tr>
     *<tr><td align=center>1</td><td align=center>C</td><td align=center>Cytosine</td><td align=center>00000010</td><td align=center>2</td></tr>
     *<tr><td align=center>2</td><td align=center>G</td><td align=center>Guanine</td><td align=center>00000100</td><td align=center>4</td></tr>
     *<tr><td align=center>3</td><td align=center>T</td><td align=center>Thymine</td><td align=center>00001000</td><td align=center>8</td></tr>
     *<tr><td align=center>4</td><td align=center>M</td><td align=center>Adenine or Cytosine</td><td align=center>00000011</td><td align=center>3</td></tr>
     *<tr><td align=center>5</td><td align=center>R</td><td align=center>Purine (Adenine or Guanine)</td><td align=center>00000101</td><td align=center>5</td></tr>
     *<tr><td align=center>6</td><td align=center>W</td><td align=center>Adenine or Thymine</td><td align=center>00001001</td><td align=center>9</td></tr>
     *<tr><td align=center>7</td><td align=center>S</td><td align=center>Cytosine or Guanine</td><td align=center>00000110</td><td align=center>6</td></tr>
     *<tr><td align=center>8</td><td align=center>Y</td><td align=center>Pyrimidine (Cytosine or Thymine)</td><td align=center>00001010</td><td align=center>10</td></tr>
     *<tr><td align=center>9</td><td align=center>K</td><td align=center>Guanine or Thymine</td><td align=center>00001100</td><td align=center>12</td></tr>
     *<tr><td align=center>10</td><td align=center>V</td><td align=center>Adenine or Cytosine or Guanine</td><td align=center>00000111</td><td align=center>7</td></tr>
     *<tr><td align=center>11</td><td align=center>H</td><td align=center>Adenine or Cytosine or Thymine</td><td align=center>00001011</td><td align=center>11</td></tr>
     *<tr><td align=center>12</td><td align=center>D</td><td align=center>Adenine or Guanine or Thymine</td><td align=center>00001101</td><td align=center>13</td></tr>
     *<tr><td align=center>13</td><td align=center>B</td><td align=center>Cytosine or Guanine or Thymine</td><td align=center>00001110</td><td align=center>14</td></tr>
     *<tr><td align=center>14</td><td align=center>N</td><td align=center>Unresolved base</td><td align=center>00001111</td><td align=center>15</td></tr>
     * </table>
     */
    static QList<CompoundTable> DnaTable() ;
    /**
      * @brief RnaTable
     *  <table>
     * <tr>
     *<th>ID</th><th>Letter</th><th>Name</th><th>Binary code</th><th>int value</th></tr>
     * <tr><td align=center>-1</td><td align=center>-</td><td align=center>Gap</td><td align=center>00000000</td><td align=center>0</td></tr>
     *<tr><td align=center>0</td><td align=center>A</td><td align=center>Adenine</td><td align=center>00000001</td><td align=center>1</td></tr>
     *<tr><td align=center>1</td><td align=center>C</td><td align=center>Cytosine</td><td align=center>00000010</td><td align=center>2</td></tr>
     *<tr><td align=center>2</td><td align=center>G</td><td align=center>Guanine</td><td align=center>00000100</td><td align=center>4</td></tr>
     *<tr><td align=center>3</td><td align=center>U</td><td align=center>Uracile</td><td align=center>00001000</td><td align=center>8</td></tr>
     *<tr><td align=center>4</td><td align=center>M</td><td align=center>Adenine or Cytosine</td><td align=center>00000011</td><td align=center>3</td></tr>
     *<tr><td align=center>5</td><td align=center>R</td><td align=center>Purine (Adenine or Guanine)</td><td align=center>00000101</td><td align=center>5</td></tr>
     *<tr><td align=center>6</td><td align=center>W</td><td align=center>Adenine or Uracile</td><td align=center>00001001</td><td align=center>9</td></tr>
     *<tr><td align=center>7</td><td align=center>S</td><td align=center>Cytosine or Guanine</td><td align=center>00000110</td><td align=center>6</td></tr>
     *<tr><td align=center>8</td><td align=center>Y</td><td align=center>Pyrimidine (Cytosine or Uracile)</td><td align=center>00001010</td><td align=center>10</td></tr>
     *<tr><td align=center>9</td><td align=center>K</td><td align=center>Guanine or Uracile</td><td align=center>00001100</td><td align=center>12</td></tr>
     *<tr><td align=center>10</td><td align=center>V</td><td align=center>Adenine or Cytosine or Guanine</td><td align=center>00000111</td><td align=center>7</td></tr>
     *<tr><td align=center>11</td><td align=center>H</td><td align=center>Adenine or Cytosine or Uracile</td><td align=center>00001011</td><td align=center>11</td></tr>
     *<tr><td align=center>12</td><td align=center>D</td><td align=center>Adenine or Guanine or Uracile</td><td align=center>00001101</td><td align=center>13</td></tr>
     *<tr><td align=center>13</td><td align=center>B</td><td align=center>Cytosine or Guanine or Uracile</td><td align=center>00001110</td><td align=center>14</td></tr>
     *<tr><td align=center>14</td><td align=center>N</td><td align=center>Unresolved base</td><td align=center>00001111</td><td align=center>15</td></tr>
     * </table>
     */
     static QList<CompoundTable> RnaTable() ;
     /**
      * @brief AminoTable
      * @return
      */
     static QList<ProteinTable> AminoTable();
     /**
      * @brief AminAcidPropertiesTable
      * @return
      */
     static QList<AminInfoTable> AminAcidPropertiesTable();
     //----------------------------------------------------------------
     /**
      * @brief Ambiguous_DNA_Values
      * @return dict with possible Ambiguous DNA Chars and associated keys
      */
     static const QHash<QChar,QString> Ambiguous_DNA_Values();
     /**
      * @brief Ambiguous_RNA_Values
      * @return dict with possible Ambiguous RNA Chars and associated keys
      */
     static const QHash<QChar,QString> Ambiguous_RNA_Values();
     /**
      * @brief Ambiguous_DNA_Complement
      * @return
      */
     static const QHash<QChar,QChar> Ambiguous_DNA_Complement();
     /**
      * @brief Ambiguous_RNA_Complement
      * @return
      */
     static const QHash<QChar,QChar> Ambiguous_RNA_Complement();
     /**
      * @brief Extended_Amino_Values
      * @return
      */
     static const QHash<QChar,QString> Extended_Amino_Values();
     /**
      * @brief Amino_Names
      * http://en.wikipedia.org/wiki/Amino_acid
      * @return
      */
     static const QHash<QString,QString> Amino_Names_1Lto3L();
     /**
      * @brief Nucleo_Names
      *
      * @return
      */
     /**
      * @brief Amino_Names
      * @return
      */
     static const QHash<QString,QString> Amino_Names();
     /**
      * @brief Nucleo_Names
      * @return Returns dict with possible nucleotids letters
      */
     static const QHash<QString,QString> Nucleo_Names();
     /**
      //	\verbatim
     ---------------------------------------------------------------
     Aminoacid	   Chemical formula	       Molecular weight,g/mol
     ---------------------------------------------------------------
     Isoleucine	      C6H13NO2	                 131.1736
     Leucine	          C6H13NO2	                 131.1736
     Lysine	          C6H14N2O2	                 146.1882
     Methionine	      C5H11NO2S	                 149.2124
     Phenylalanine	  C9H11NO2	                 165.19
     Threonine	      C4H9NO3	                 119.1197
     Tryptophan	      C11H12N2O2	             204.2262
     Valine	          C5H11NO2	                 117.1469
     Arginine	      C6H14N4O2	                 174.2017
     Histidine	      C6H9N3O2	                 155.1552
     Alanine	          C3H7NO2	                 89.0935
     Asparagine	      C4H8N2O3	                 132.1184
     Aspartate	      C4H7NO4	                 133.1032
     Cysteine	      C3H7NO2S	                 121.159
     Glutamate	      C5H9NO4	                 147.1299
     Glutamine	      C5H10N2O3	                 146.1451
     Glycine	          C2H5NO2	                 75.0669
     Proline	          C5H9NO2	                 115.131
     Serine	          C3H7NO3	                 105.093
     Tyrosine	      C9H11NO3	                 181.1894
     ---------------------------------------------------------------
     \endverbatim
      * @brief Amino_MW
      * @return Molecular Masses of each of the 20 Amino Acids

      */
     static const QMap<QChar,double>  Amino_MW();
     /**
     //	\verbatim
            Amino Acid          Acidic/Neutral/Basic    Hydropathy Index
     --------------------------------------------------------------------
     Arginine	   Arg	R       	Acidic	               10.76
     Lysine	       Lys	K	        Basic	               9.74
     Aspartic	   Asp	D	        Acidic	               2.77
     Asparagine	   Asn	N	        Neutral	               5.41
     Glutamic	   Glu	E	        Acidic	               3.22
     Glutamine	   Gln	Q	        Neutral	               5.65
     Histidine	   His	H	        Basic	               7.59
     Proline	       Pro	P	        Neutral	               6.3
     Tyrosine	   Tyr	Y	        Neutral	               5.66
     Tryptophan	   Trp	W	        Neutral	               5.89
     Serine	       Ser	S	        Neutral	               5.68
     Threonine	   Thr	T	        Neutral	               6.16
     Glycine	       Gly	G	        Neutral	               5.97
     Alanine	       Ala	A	        Neutral	                6
     Methionine	   Met	M	        Neutral	               5.74
     Cysteine	   Cys	C	        Neutral	               5.07
     Phenylalanine  Phe	F	        Neutral	               5.48
     Leucine	       Leu	L	        Neutral	               5.98
     Valine	       Val	V	        Neutral	               5.96
     Isoleucine	   Ile	I	        Neutral	               6.02
     -----------------------------------------------------------------------
     /**
     \endverbatim

     http://www2d.biglobe.ne.jp/~chem_env/amino/amino2j_e.html




      * @brief Amino_Hydrophobicity
      * @return  Hydrophobicity values of Amino
     <TABLE border>
     <tr><th align="center">Residue Type</th>
     <th align="center">kdHydrophobicity<a href="#anote"><sup>a</sup></a></th>
     <th align="center">wwHydrophobicity<a href="#bnote"><sup>b</sup></a></th>
     <th align="center">hhHydrophobicity<a href="#cnote"><sup>c</sup></a></th>
     </tr>
     <tr><td align=center>Ile</td> <td align=center>4.5</td>
     <td align=center>0.31</td> <td align=center>-0.60</td></tr>
     <tr><td align=center>Val</td> <td align=center>4.2</td>
     <td align=center>-0.07</td> <td align=center>-0.31</td></tr>
     <tr><td align=center>Leu</td> <td align=center>3.8</td>
     <td align=center>0.56</td> <td align=center>-0.55</td></tr>
     <tr><td align=center>Phe</td> <td align=center>2.8</td>
     <td align=center>1.13</td> <td align=center>-0.32</td></tr>
     <tr><td align=center>Cys</td> <td align=center>2.5</td>
     <td align=center>0.24</td> <td align=center>-0.13</td></tr>
     <tr><td align=center>Met</td> <td align=center>1.9</td>
     <td align=center>0.23</td> <td align=center>-0.10</td></tr>
     <tr><td align=center>Ala</td> <td align=center>1.8</td>
     <td align=center>-0.17</td> <td align=center>0.11</td></tr>
     <tr><td align=center>Gly</td> <td align=center>-0.4</td>
     <td align=center>-0.01</td> <td align=center>0.74</td></tr>
     <tr><td align=center>Thr</td> <td align=center>-0.7</td>
     <td align=center>-0.14</td> <td align=center>0.52</td></tr>
     <tr><td align=center>Ser</td> <td align=center>-0.8</td>
     <td align=center>-0.13</td> <td align=center>0.84</td></tr>
     <tr><td align=center>Trp</td> <td align=center>-0.9</td>
     <td align=center>1.85</td> <td align=center>0.30</td></tr>
     <tr><td align=center>Tyr</td> <td align=center>-1.3</td>
     <td align=center>0.94</td> <td align=center>0.68</td></tr>
     <tr><td align=center>Pro</td> <td align=center>-1.6</td>
     <td align=center>-0.45</td> <td align=center>2.23</td></tr>
     <tr><td align=center>His</td> <td align=center>-3.2</td>
     <td align=center>-0.96</td> <td align=center>2.06</td></tr>
     <tr><td align=center>Glu</td> <td align=center>-3.5</td>
     <td align=center>-2.02</td> <td align=center>2.68</td></tr>
     <tr><td align=center>Gln</td> <td align=center>-3.5</td>
     <td align=center>-0.58</td> <td align=center>2.36</td></tr>
     <tr><td align=center>Asp</td> <td align=center>-3.5</td>
     <td align=center>-1.23</td> <td align=center>3.49</td></tr>
     <tr><td align=center>Asn</td> <td align=center>-3.5</td>
     <td align=center>-0.42</td> <td align=center>2.05</td></tr>
     <tr><td align=center>Lys</td> <td align=center>-3.9</td>
     <td align=center>-0.99</td> <td align=center>2.71</td></tr>
     <tr><td align=center>Arg</td> <td align=center>-4.5</td>
     <td align=center>-0.81</td> <td align=center>2.58</td></tr>
     </TABLE>
      */
     static const 	 QMap<QChar,double> Amino_Hydrophobicity();


     /**
      * @brief AMINO_Weights
      * @return  Molecular weight of Amino Acids
      */
     static const QMap<QChar,QPair<double, double> > AMINO_Weights();
     /**
      * @brief DNAMolWeight
      *see http://www.lifetechnologies.com/ly/en/home/references/ambion-tech-support/rna-tools-and-calculators/dna-and-rna-molecular-weights-and-conversions.html
      * @return list with molecular weights of a,c,g,t;
      */
     static const QList<double> DNAMolWeight();
     /**
      * @brief RNAMolWeight
      *see http://www.lifetechnologies.com/ly/en/home/references/ambion-tech-support/rna-tools-and-calculators/dna-and-rna-molecular-weights-and-conversions.html
      * @return
      */
     static const QList<double> RNAMolWeight();
     /**
      * @brief WaterMW
      * @return molecualr weight of water
      */
     inline static const double OHMW(){return 17.01;}
     /**
      * @brief H2OMW
      * @return
      */
     inline static const double H2OMW(){return 18;}
     /**
      * @brief IsBase
      * @param base
      * @return
      */
     static bool IsBase(char base);
     /**
      * @brief IsIUpacBase
      * @param base
      * @return
      */
     static bool IsIUpacBase(char base);
     /**
 * @brief createPKAMap
 * @return
 */
static QMap<QChar,double> PKAMap();
/**
 * @brief createChargeMap
 * @return
 */
static QMap<QChar,int> ChargeMap() ;
/**
  * @brief InstabilityIndex
  * @return
  */
 static const QMap<char,QMap<char,double>>  InstabilityIndex();


 static const QMap<QString,double> PositivePks();
 static const QMap<QString,double> NegativePks();
 static const QMap<QString,double> pKcterminal();
 static const QMap<QString,double> pKnterminal();
 static const QMap<QString,double> Flex();
 static const QStringList chargedAAs();


signals:
    
public slots:
    
};

} // namespace BioQt

#endif // BIOQT_QIUPACDATA_H
