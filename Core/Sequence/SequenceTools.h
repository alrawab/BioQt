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

#ifndef SEQUENCETOOLS_H
#define SEQUENCETOOLS_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceException.h>
#include <Data/QIUPACData.h>
#include <Data/QIUPACData.h>
#include <Alphabet/Alphabet.h>
#include <Alphabet/DNA.h>
#include <Alphabet/Protein.h>
#include <Alphabet/RNA.h>
#include <Alphabet/AlphabetException.h>
#include <windef.h>
#include <cmath>
namespace BioQt {


#define nucleotide_A 0x41//hex value
#define nucleotide_C 0x43
#define nucleotide_G 0x47
#define nucleotide_T 0x54
#define nucleotide_N 0x4E

#define ADENINE 65 //Ascii code value
#define THYMINE 84
#define GUANINE 71
#define CYTOSINE 67
#define URACIL 85
#define ANYNUCLEOTIDE 78



/**
 * @brief The SequenceTools class
 *@author Usama S Erawab
 */
typedef struct BaseCount{
    int A;
    int C;
    int G;
    int T;
    int U;
    //-------
    int M;
    int R;
    int W;
    int S;
    int Y;
    int K;
    int V;
    int H;
    int D;
    int B;
    //**********
    int N;
    int X;
    int gap;
}BaseCount;
class BIOQTSHARED_EXPORT SequenceTools
{
public:
    /**
     * @brief IsOdd
     * @param num
     * @return
     */
    static  bool IsOdd(int num);
    /**
     * @brief IsEven
     * @param num
     * @return
     */
    static bool IsEven(int num);
    /**
     * @brief SubSequence
     * @param seq
     * @param pos
     * @param len
     * @return
     */
    static QSequence SubSequence(const QSequence& seq,int pos, int len=0 );
    /**
         * @brief HalfSequence
         * @param seq
         * @param len
         * @return
         */
        static  QSequence HalfSequence( QSequence seq,int len);
        /**
         * @brief IsMirror
         * @param seq
         * @return
         */
        static bool IsMirror( QString  seq);

    //**********************************
        /**
         * @brief ContainsBlank
         * @param seq
         * @param pos
         * @return
         */
    static bool ContainsBlank(const QSequence& seq,size_t pos=0) throw (EmptySequenceException);
    /**
     * @brief ContainsBlank
     * @param seq
     * @param start
     * @param end
     * @return
     */
    static bool ContainsBlank(const QSequence& seq,size_t start,size_t end) throw (EmptySequenceException);
    /**
 * @brief ContainsAmbiguous
 * @param seq
 * @param CaseMod
 * @return
 */
    static bool ContainsAmbiguous(const QSequence& seq,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive) throw (EmptySequenceException,InvalidDNASequence);//okay
    /**
 * @brief IsAmbiguous checks if given base is valide ambigous nucleotoid char as described by iupac
 * @param base subjected
 * @param CaseMod case sensitivity status (Qt::CaseInsensitive or Qt::CaseSensitive).
 *set by default to Case Insenstive .
 * @return
 *see http://www.dnabaser.com/articles/IUPAC%20ambiguity%20codes.html
 */
    static bool IsAmbiguous(const QChar& base,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive) throw (EmptySequenceException);

    /**
     * @brief IsValidDnaSequence
     * @param seq
     * @return
     */
    static bool IsValidDnaSequence(const QSequence& seq,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive)throw (EmptySequenceException);
    /**
     * @brief IsValidDnaBase
     * @param base
     * @return
     */
    static bool IsValidDnaBase(const QChar &base,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive);
    /**
     * @brief IsValidRnaSequence
     * @param seq
     * @param CaseMod
     * @return
     */
    static bool IsValidRnaSequence(const QSequence& seq,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive)throw (EmptySequenceException);
    /**
     * @brief IsValidRnaBase
     * @param base
     * @param CaseMod
     * @return
     */
    static bool IsValidRnaBase(const QChar &base,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive);
    /**
     * @brief SequenceWithGap
     * @param seq
     * @param CaseMod
     * @return
     */
    static bool SequenceWithGap(const QSequence& seq,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive)throw (EmptySequenceException);
    /**
     * @brief IsGap
     * @param base
     * @return
     */
    static bool IsGap(const QChar& base);
    /**
     * @brief SequenceWithUnresolved
     * @param seq
     * @param CaseMod
     * @return
     */
    static bool SequenceWithUnresolved(const QSequence& seq,Qt::CaseSensitivity CaseMod=Qt::CaseInsensitive)throw (EmptySequenceException);
    /**
     * @brief IsUnresolved
     * @param base
     * @return
     */
    static bool IsUnresolved(const QChar& base);

    /**
        * @brief NumberOfNmers Encode an n-mer as an integer(eg. there are 4^n n-mers)
        * @param n
        *
        */
    static int NumberOfNmers(int n);
    /**
         * @brief NmerToInt  Encode an n-mer as an integer.
         * convert nmer of length n, pointed to by seq,
         * to an integer representation
         * if there's a character other than AGCT, return -1
         * n better be small enough that the result fits into an int
         *
         * @param seq sequence
         * @param n n-mer legth.
         *
         */
    static int NmerToInt(const QSequence &seq, int n)throw (EmptySequenceException);

    /**
         * @brief Nuc2Nibble nibble is 4-bit chunks of a char.
         * see http://en.wikipedia.org/wiki/Nibble
         * @param nuc
         */
    static int NucToNibble(char nuc);
    /**
         * @brief NibbleToNuc
         * @param n
         * @return
         */
    static char NibbleToNuc(int n);
    /**
         * @brief GetPercentGC
         * @param seq
         * @return
         */
    static int GetPercentGC(const QSequence& seq)throw (EmptySequenceException);
    /**
     * @brief GetPercentAT
     * @param seq
     * @return
     */
    static int GetPercentAT(const QSequence& seq)throw (EmptySequenceException);
    /**
 * @brief IsComplement
 * @param base1
 * @param base2
 * @return
 */
    static bool IsComplement(const QChar& base1,const QChar& base2);
    /**
 * @brief GetComplement
 *<h2>IUPAC Degeneracies:</h2>
 *<TABLE BORDER="1">
 * <TR ALIGN="CENTER"><TH>Base</TH><TH>Name</TH><TH>Bases Represented</TH><TH>Complementary Base</TH>      </TR>
 * <TR ALIGN="CENTER"><TH>A</TH><TD>Adenine</TD><TD>A</TD><TD>T</TD>       </TR>
 * <TR ALIGN="CENTER"><TH>T</TH><TD>Thymidine</TD><TD>T</TD><TD>A</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>U</TH><TD>Uridine(RNA only)</TD><TD>U</TD> <TD>A</TD>    </TR>
 * <TR ALIGN="CENTER"><TH>G</TH><TD>Guanidine</TD><TD>G</TD><TD>C</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>C</TH><TD>Cytidine</TD><TD>C</TD><TD>G</TD>      </TR>
 * <TR ALIGN="CENTER"><TH>Y</TH><TD>pYrimidine</TD><TD>C T</TD><TD>R</TD>  </TR>
 * <TR ALIGN="CENTER"><TH>R</TH><TD>puRine</TD><TD>A G</TD><TD>Y</TD>      </TR>
 * <TR ALIGN="CENTER"><TH>S</TH><TD>Strong(3Hbonds)</TD><TD>G C</TD><TD>S*</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>W</TH><TD>Weak(2Hbonds)</TD><TD>A T</TD><TD>W*</TD>       </TR>
 * <TR ALIGN="CENTER"><TH>K</TH><TD>Keto</TD><TD>T/U G</TD><TD>M</TD>      </TR>
 * <TR ALIGN="CENTER"><TH>M</TH><TD>aMino</TD><TD>A C</TD><TD>K</TD>       </TR>
 * <TR ALIGN="CENTER"><TH>B</TH><TD>not A</TD><TD>C G T</TD><TD>V</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>D</TH><TD>not C</TD><TD>A G T</TD><TD>H</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>H</TH><TD>not G</TD><TD>A C T</TD><TD>D</TD>     </TR>
 * <TR ALIGN="CENTER"><TH>V</TH><TD>not T/U</TD><TD>A C G</TD><TD>B</TD>   </TR>
 * <TR ALIGN="CENTER"><TH>N</TH><TD>Unknown</TD><TD>A C G T</TD><TD>N</TD> </TR>
 *</TABLE>
 *see http://www.fr33.net/seqedit.php<br>
 * http://arep.med.harvard.edu/labgc/adnan/projects/Utilities/revcomp.html
 * @param seq
 * @return
 */
    static QSequence GetComplement(const QSequence&  seq) throw (EmptySequenceException,NonIupacBase);//okay
    /**
 * @brief reverseInParallel
 * @param seq
 * @return
 */
    static QSequence reverseInParallel(const QSequence& seq);//thanks wysota okay
    /**
 * @brief randInt
 * @param Low
 * @param High
 * @return
 */
    static int randInt(int Low, int High);
    /**
 * @brief RandomSequence
 *Formula
 * gcTotal * lengthTotal = gcDone * lengthDone + gcToSet * lengthToSet<br>
 * => gcToSet = (gcTotal * lengtTotal - gcActual *lengthActual)/lengthToSet<br>
 *orginal code in C# (BioCSharp by Dr. Robert Kofler.)<br>
 * @param Length
 * @param gcContent
 * @return  Returns a randomly created sequence, having the specified properties.
 */
    static QSequence RandomSequence(int Length,int gcContent);
    /**
 * @brief GetMutatedCharacter
  *orginal code in C# (BioCSharp by Dr. Robert Kofler.)
 * @param toMutate
 * @return
 */
    static QChar GetMutatedCharacter(QChar toMutate)throw(BioQtException);

    /**
 * @brief LightUnAmbiguity replace all Ambigous Bases with lightest base possible
 * @param seq
 * @return
 */
    static QSequence LightUnAmbiguity( QSequence seq)throw (EmptySequenceException);//okay
    /**
 * @brief HeavyUnAmbiguity replace all Ambigous Bases with heaviest base possible
 * @param seq
 * @return
 */
    static QSequence HeavyUnAmbiguity(QSequence seq)throw (EmptySequenceException);//okay
    /**
 * @brief ExpandNuclicAcids
 * @param seq
 * @return returns the expansion of a nucleic acid sequence, replacing special<br>
 * wildcard symbols  with the proper  QRegExp.
 */
    static QSequence ExpandNuclicAcids(QSequence& seq);
    /**
 * @brief RemoveNonCodingBases
 * @param seq
 * @return sequence with out any non IUPAC valid bases
 */
    static QSequence RemoveNonCodingBases(QSequence& seq);
    /**
 * @brief RemoveNonUnAmbigousCodingBases
 * @param seq
 * @return
 */
    static QSequence RemoveNonUnAmbigousCodingBases(QSequence& seq);
    /**
 * @brief GetInvalidUnambigousBases
 * @param seq
 * @return
 */
    static QMap<int,QChar> GetInvalidUnambigousBases(QSequence & seq);
    /**
 * @brief GetInvalidAmbigousBases
 * @param seq
 * @return
 */
    static QMap<int,QChar> GetInvalidAmbigousBases(QSequence & seq);

    static QSequence Reverse( const QSequence& seq);//okay
    /**
 * @brief GetReverseComplement
 * @param seq
 * @return the reverse complement for a sequence .
 */
    static QSequence GetReverseComplement(const QSequence& seq)throw (EmptySequenceException,NonIupacBase);//okay
    /**
 * @brief Antiparallel Create the antiparallel DNA or RNA strand. For example, the sequence "ATGC" is converted to "GCAT".
 *"Antiparallel" combines the two functions @GetComplement and @Reverse.
 * @param seq
 * @return
 */
    static QSequence Antiparallel(const QSequence& seq);//okay
    /**
 * @brief ConvertToDNA
 * @param seq
 * @return
 */

    static QSequence ConvertToDNA(const QSequence & seq)throw (EmptySequenceException);//okay
    /**
 * @brief ConvertToRNA
 * @param seq
 * @return
 */
    static QSequence ConvertToRNA(const QSequence & seq)throw (EmptySequenceException);//okay
    /**
 * @brief IsOnlyAT
 * @param seq
 * @return true if the sequence contains only A or T
 */
    static bool IsOnlyAT(QSequence& seq)throw (EmptySequenceException);
    /**
 * @brief IsOnlyGC
 * @param seq
 * @return true if the sequence contains only G or C
 */
    static bool IsOnlyGC(QSequence& seq)throw (EmptySequenceException);
    /**
 * @brief IsSymmetry
 * @param seq
 * @return True if the sequence is reverse complement to itself.
 */
    static bool IsSymmetry(QSequence& seq)throw (EmptySequenceException);
    /**
 * @brief CalculateBases
 * @param seq
 * @return
 */
    static BaseCount CalculateBases(const QSequence& seq)throw (EmptySequenceException,NonIupacBase);//okay tested
    /**
 * @brief GetSimilarity
 * @param oriseq
 * @param seq
 * @return
 */
    static double GetSimilarity (const QSequence& oriseq,const QSequence & seq)throw (EmptySequenceException);//okay tested

    /**
 * @brief CountNeighbors_indeces
 * @param seek_pattren
 * @param seq
 * @return
 */
    static QList<int> CountNeighbors(const QSequence& seek_pattren,const QSequence& seq)throw (EmptySequenceException);
    /**
     * @brief BinaryToNucleo
     * @param in
     * @return
     */

    static char BinaryToNucleo(int in) throw(NonIupacBase);
    /**
     * @brief NucleoToBinary
     * @param in
     * @return
     */
    static int NucleoToBinary(char in)throw(NonIupacBase);//to convert QChar to std::char use to QChar.toAscii()
    /**
     * @brief SequenceToBinary
     * @param seq
     * @return
     */
    static QList<int> SequenceToBinary(const QSequence& seq)throw(EmptySequenceException,NonIupacBase);
    /**
     * @brief BinarySeqToQSequence
     * @param lst
     * @return
     */
    static QSequence BinarySeqToQSequence(QList<int> lst)throw(InvalidIntValue);
    /**
     * @brief NucleoToByte
     * @param c
     * @return
     */
    static BYTE NucleoToByte( char c);
    /**
     * @brief SequenceToByteList
     * @param seq
     * @return
     */

    static QList<int> SequenceToByteList(const QSequence& seq)throw(EmptySequenceException,BadChar);
    /**
     * @brief NucleoCountNeighbors
     * @param seq
     * @return
     */
    static QMap<QString,int> NucleoCountNeighbors(const QSequence& seq)throw(EmptySequenceException);
    /**
     * @brief GC_skew
     * @param seq
     * @return
     */
    static double GC_skew(const QSequence& seq)throw(EmptySequenceException);
    /**
     * @brief GmC_skew
     * @param seq
     * @return
     */
    static double GmC_skew(const QSequence& seq)throw(EmptySequenceException);
    /**
     * @brief AT_skew
     * @param seq
     * @return
     */
    static double AT_skew(const QSequence& seq)throw(EmptySequenceException);
    /**
     * @brief KETO_skew
     * @param seq
     * @return
     */
    static double KETO_skew(const QSequence& seq)throw(EmptySequenceException);
    /**
     * @brief GuessAlphabet
     * @param seq
     * @return
     */
    static AlphaBet * GuessAlphabet(const QSequence &seq);
    static int nucleotide_complement(int nucleotide);
        static int nucleotide_complement(const QChar &nucleotide);
private:
     static char complement[22];

};//class end

//-------------------------------------------------------------------


} // namespace BioQt

#endif // BIOQT_SEQUENETOCOLS_H
