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

#include "SequenceTools.h"
#include <QtConcurrentMap>

namespace BioQt {

#include <QtConcurrentMap>


char  SequenceTools::complement[22] = {"T G   C      N     A"};

struct Chunk {
    char *ba;
    int size;
    int from;
    int cnt;
};
//-------------------------------------------------------------------------------------------
void swapChunk(const Chunk &ch) {
    const int size = ch.size;
    char *baRef = ch.ba;
    for(int i=0;i<ch.cnt;++i) {
        int i1 = ch.from+i;
        int i2 = size-1-ch.from-i;
        qSwap(baRef[i1], baRef[i2]);
    }
}

//-------------------------------------------------------------------------------------------

bool SequenceTools::ContainsBlank(const QSequence& seq,size_t pos)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    size_t len = seq.size();
    for (size_t idx = pos; idx < len; ++idx) {
        if ( seq[idx].isSpace()) {
            return true;
        }

    }
    return false;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::ContainsBlank(const QSequence& seq,size_t start,size_t end)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");


    for (size_t idx = start; idx < end; ++idx) {
        if ( seq[idx].isSpace()) {
            return true;
        }

    }
    return false;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::ContainsAmbiguous(const QSequence& seq,Qt::CaseSensitivity CaseMod) throw (EmptySequenceException,InvalidDNASequence)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    if(!IsValidDnaSequence(seq))
        throw InvalidDNASequence("BioQt::SequenceTools the sequence is not avalid DNA Sequence");
    Q_FOREACH(QChar c,seq)
    {

        if(QIUPACData::Ambiguous_DNA_Chars.mid(4).contains(c,CaseMod))

            return true;

    }
    return false;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsAmbiguous(const QChar& base,Qt::CaseSensitivity CaseMod) throw (EmptySequenceException)
{

    return QIUPACData::Ambiguous_DNA_Chars.indexOf(base,0,CaseMod) >3;
}
//---------------------------------------------------------------------------------------
bool SequenceTools::IsValidDnaSequence(const QSequence &seq,Qt::CaseSensitivity CaseMod) throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    Q_FOREACH(QChar c,seq)
    {
        if( QIUPACData::Ambiguous_DNA_Chars.indexOf(c,0,CaseMod) ==-1)
            return FALSE;
    }
    return true;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsValidDnaBase(const QChar &base,Qt::CaseSensitivity CaseMod)
{
    return QIUPACData::Ambiguous_DNA_Chars.indexOf(base,0,CaseMod)!=-1;
}
//-----------------------------------------------------------------------------

bool SequenceTools::IsValidRnaSequence(const QSequence &seq,Qt::CaseSensitivity CaseMod) throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    Q_FOREACH(QChar c,seq)
    {
        if( QIUPACData::Ambiguous_RNA_Chars.indexOf(c,0,CaseMod) ==-1)
            return FALSE;
    }
    return true;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsValidRnaBase(const QChar &base,Qt::CaseSensitivity CaseMod)
{
    return QIUPACData::Ambiguous_RNA_Chars.indexOf(base,0,CaseMod)!=-1;
}
//--------------------------------------------------------------------------------------------
bool SequenceTools::SequenceWithGap(const QSequence& seq,Qt::CaseSensitivity CaseMod)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    return seq.indexOf('-',CaseMod) !=-1;

}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsGap(const QChar& base)
{
    return base=='-';
}
//******************************************************
bool SequenceTools::SequenceWithUnresolved(const QSequence& seq,Qt::CaseSensitivity CaseMod)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    foreach(QChar c,seq)
    {
        if(QIUPACData::NucleoUnresolvedChars.indexOf(c)!=-1)
            return true;
    }
    return false;
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsUnresolved(const QChar& base)
{
    return QIUPACData::NucleoUnresolvedChars.indexOf(base)!=-1;
}
//========================================================================

int SequenceTools::NumberOfNmers(int n)
{
    return 1 << (2*n);
}
//-------------------------------------------------------------------------------------------
int SequenceTools::NmerToInt(const QSequence &seq, int n)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    int rv = 0;

    for (int i = 0;  i<n;  i++) {
        rv <<= 2;
        int nucint = NucToNibble(seq[i].toAscii());
        //  qDebug()<<nucint;
        if(nucint < 0) {
            return -1;
        }
        rv |= nucint;
    }
    return rv;
}
//-------------------------------------------------------------------------------------------
int SequenceTools::NucToNibble(char nuc)
{
    switch (nuc) {
    case 'G':case 'g':
        return 0;
    case 'A':case 'a':
        return 1;
    case 'T':case 't':
        return 2;
    case 'C':case 'c':
        return 3;
    default:     // other than GATC
        return -1;
    }
}
//-------------------------------------------------------------------------------------------
char SequenceTools::NibbleToNuc(int n)
{
    switch (n) {
    case 0:
        return 'G';
    case 1:
        return 'A';
    case 2:
        return 'T';
    case 3:
        return 'C';
    default:
        // this should never happen
        return '?';
    }
}
//-------------------------------------------------------
int SequenceTools::GetPercentGC(const QSequence& seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    int gc_count = 0;
    int len=seq.size();
    for (int i = 0;  i < len;  ++i) {
        switch(seq[i].toAscii())
        {

        case 'C':case 'c':
        case 'G':case 'g':
        case 'S':case 's':
            ++gc_count;
            break;
        default:
            break;
        }
    }
    return (int) ((gc_count * 100.0) / len );
}

int SequenceTools::GetPercentAT(const QSequence& seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    int at_count = 0;
    int len=seq.size();
    for (int i = 0;  i < len;  ++i) {
        switch(seq[i].toAscii())
        {

        case 'A':case 'a':
        case 'T':case 't':

            ++at_count;
            break;
        default:
            break;
        }
    }
    return (int) ((at_count * 100.0) / len );
}
//-------------------------------------------------------------------------------------------
bool SequenceTools::IsComplement(const QChar& base1,const QChar& base2)
{
    if ((base1.toLower()  == 'a' & base2.toLower ()  == 't') |
            (base1.toLower()   == 't' & base2.toLower ()  == 'a') |
            (base1.toLower()   == 'g' & base2.toLower ()  == 'c') |
            (base1.toLower()   == 'c' & base2.toLower ()  == 'g'))
        return true;
    else
        return false;
}

//-------------------------------------------------------------------------------------------
QSequence SequenceTools::reverseInParallel(const QSequence& seq)
{
    QByteArray zx;//FIXME you have to avoid this osama!!!!!!!!!!!!!
    zx.append(seq);
    char *dat = zx.data();
    int threads = QThread::idealThreadCount();
    int bytesPerThread = seq.size()/2/threads; // if size not even, the middle doesn't change anyway
    // prepare work
    QList<Chunk> chunks;
    for(int i=0;i<threads;++i) {
        Chunk ch;
        ch.ba = dat;
        ch.size = seq.size();
        ch.from = bytesPerThread*i;
        ch.cnt = bytesPerThread;
        chunks << ch;
    }
    // execute
    QtConcurrent::blockingMap(chunks, swapChunk);
    return zx.data();
}
//=========================================================
int SequenceTools::randInt(int Low, int High)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    return qrand() % ((High + 1) - Low)+Low ;
}
//-------------------------------------------------------------------------------------------
QSequence SequenceTools::RandomSequence(int Length,int gcContent)
{
    //Formula
    // gcTotal * lengthTotal = gcDone * lengthDone + gcToSet * lengthToSet
    // => gcToSet = (gcTotal * lengtTotal - gcActual *lengthActual)/lengthToSet
    double gcActual = 0.0;
    int gcCount = 0;
    double gcTotal = (double)gcContent;
    int gcToSet = (int)gcTotal;
    QSequence newSeq;
    for (int i = 0; i < Length; i++)
    {
        if (randInt(1, 101) <= gcToSet)
        {
            //New G or C
            if (randInt(1, 3) == 1)
            {
                newSeq.append('C');

            }
            else
            {
                newSeq.append('G');

            }
            //Updated gcActual
            gcCount++;
            gcActual = ((double)gcCount) * 100.0 / (double)newSeq.length();
        }//if
        else
        {
            //new A or T
            if (randInt(1, 3) == 1)
            {
                newSeq.append('A');

            }
            else
            {
                newSeq.append('T');

            }

            //update gcActual
            gcActual = ((double)gcCount) * 100.0 / (double)newSeq.length();

        }//else
        gcToSet = (int)(((gcTotal * (double)Length) - (gcActual * (double)newSeq.length())) / ((double)(Length - newSeq.length())));

    }//for

    return newSeq;
}
//-------------------------------------------------------------------------------------------
QChar SequenceTools::GetMutatedCharacter(QChar toMutate)throw(BioQtException)
{
    int character = randInt(1, 4);
    switch (toMutate.toAscii())
    {
    case 'A':
        switch (character)
        {
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'G';
        default:throw BioQtException("this should not happen");

        }
    case 'T':
        switch (character)
        {
        case 1: return 'A';
        case 2: return 'C';
        case 3: return 'G';
        default:throw BioQtException("this should not happen");
        }

    case 'C':
        switch (character)
        {
        case 1: return 'T';
        case 2: return 'A';
        case 3: return 'G';
        default: throw BioQtException("this should not happen");
        }

    case 'G':
        switch (character)
        {
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'A';
        default:throw BioQtException("this should not happen");
        }
    default:
        character = randInt(1, 4);
        switch (character)
        {
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'G';
        case 4: return 'A';
        default: throw BioQtException("this should not happen");
        }

    }
}
//--------------------------------------------------------------------------

QSequence SequenceTools::LightUnAmbiguity( QSequence seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    seq.replace(QRegExp("[Y|S|M|B|H|V|N]"),"C");
    seq.replace(QRegExp("[W|K|D]"),"T");
    seq.replace(QRegExp("[R]"),"A");
    return seq;
}
//-------------------------------------------------------------------------------------------

QSequence SequenceTools::HeavyUnAmbiguity( QSequence seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    seq.replace(QRegExp("[R|S|K|B|D|V|N]"),"G");
    seq.replace(QRegExp("[W|M|H]"),"A");
    seq.replace(QRegExp("[Y]"),"T");
    return seq;
}
//-------------------------------------------------------------------------------------------
QSequence SequenceTools::ExpandNuclicAcids(QSequence& seq)
{
    seq.replace(QRegExp("[N|X]"),".");
    seq.replace(QRegExp("[R]"), "[AG]");
    seq.replace(QRegExp("[Y]"), "[CT]");
    seq.replace(QRegExp("[S]"), "[GC]");
    seq.replace(QRegExp("[W]"), "[AT]");
    seq.replace(QRegExp("[M]"), "[AC]");
    seq.replace(QRegExp("[K]"), "[TG]");
    seq.replace(QRegExp("[B]"), "[CGT]");
    seq.replace(QRegExp("[D]"), "[AGT]");
    seq.replace(QRegExp("[H]"), "[ACT]");
    seq.replace(QRegExp("[R]"), "[ACG]");
    return seq;
}
//-------------------------------------------------------------------------------------------
QSequence SequenceTools::RemoveNonCodingBases(QSequence& seq)
{
    seq.replace(QRegExp("\\W|[^ATGCYRWSKMDVHBN]|\\d"),"");
    return seq;
}
//-------------------------------------------------------------------------------------------
QSequence SequenceTools::RemoveNonUnAmbigousCodingBases(QSequence& seq)
{
    seq.replace(QRegExp("\\W|[^ACGTN]|\\d"),"");
    return seq;
}
//-------------------------------------------------------------------------------------------
QMap<int,QChar> SequenceTools::GetInvalidUnambigousBases(QSequence & seq)
{
    QMap<int,QChar> tmp;
    int x=0;
    for(QSequence::Iterator it=seq.begin();it !=seq.end();it++)
    {


        switch(it->toAscii())
        {
        case 'A':
        case 'a':
        case 'T':
        case 't':
        case 'C':
        case 'c':
        case 'G':
        case 'g':
            break;
        default: tmp.insert(x ,*it);

            break;
        }
        x++;
    }
    return tmp;
}
//-------------------------------------------------------------------------------------------
QMap<int,QChar> SequenceTools::GetInvalidAmbigousBases(QSequence & seq)
{
    QMap<int,QChar> tmp;
    int x=0;
    for(QSequence::Iterator it=seq.begin();it !=seq.end();it++)
    {


        switch(it->toAscii())
        {
        case 'A':
        case 'a':
        case 'T':
        case 't':
        case 'C':
        case 'c':
        case 'G':
        case 'g':
        case 'n':
        case 'N':

            //Ambigous bases
        case 'Y':
        case 'y':
        case 'r':
        case 'R':
        case 'w':
        case 'W':
        case 'S':
        case 's':
        case 'k':
        case 'K':
        case 'm':
        case 'M':
        case 'B':
        case 'b':
        case 'd':
        case 'D':
        case 'h':
        case 'H':
        case 'v':
        case 'V':
            break;
        default: tmp.insert(x ,*it);
            break;
        }
        x++;
    }
    return tmp;
}
//-------------------------------------------------------------------------------------------
QSequence SequenceTools::Reverse(const QSequence& seq)
{

    QSequence tmp;

    for (int i = seq.length() - 1; i >= 0; i--)
    {
        tmp +=seq[i];
    }

    return tmp;
}

//-------------------------------------------

QSequence SequenceTools::Antiparallel(const QSequence& seq)
{
    return  GetReverseComplement(seq);
}

//http://www.fr33.net/seqedit.php
//http://arep.med.harvard.edu/labgc/adnan/projects/Utilities/revcomp.html
QSequence SequenceTools::GetComplement( const QSequence&  seq) throw (EmptySequenceException,NonIupacBase)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QSequence tmp;
    for (int i =0;i< seq.length() ;  i++)
    {
        switch (seq[i].toAscii())
        {
        case 'a':
        case 'A': tmp.append('T');
            break;
        case 't':
        case 'T': tmp.append('A');
            break;
        case 'c':
        case 'C': tmp.append('G');
            break;
        case 'g':
        case 'G': tmp.append('C');
            break;
        case 'n':
        case 'N': tmp.append('N');
        case 'Y':
        case 'y': tmp.append('R');
            break;
        case 'r':
        case 'R': tmp.append('Y');
            break;
        case 'w':
        case 'W': tmp.append('W');
            break;
        case 'S':
        case 's': tmp.append('S');
            break;
        case 'k':
        case 'K': tmp.append('M');
            break;
        case 'm':
        case 'M': tmp.append('K');
            break;
        case 'B':
        case 'b': tmp.append('V');
            break;
        case 'd':
        case 'D': tmp.append('H');
            break;
        case 'h':
        case 'H': tmp.append('D');
            break;
        case 'v':
        case 'V': tmp.append('B');
            break;
        default: throw NonIupacBase("Sequence contains invalid IUPAC Base, in reverse complement");

        }
    }
    return tmp;
}
//*********************************************************************
QSequence SequenceTools::GetReverseComplement(const QSequence& seq)throw (EmptySequenceException,NonIupacBase)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QSequence tmp;
    for (int i = seq.length() - 1; i >= 0; i--)
    {
        switch (seq[i].toAscii())
        {
        case 'a':
        case 'A': tmp.append('T');
            break;
        case 't':
        case 'T': tmp.append('A');
            break;
        case 'c':
        case 'C': tmp.append('G');
            break;
        case 'g':
        case 'G': tmp.append('C');
            break;
        case 'n':
        case 'N': tmp.append('N');
            break;
        case 'Y':
        case 'y': tmp.append('R');
            break;
        case 'r':
        case 'R': tmp.append('Y');
            break;
        case 'w':
        case 'W': tmp.append('W');
            break;
        case 'S':
        case 's': tmp.append('S');
            break;
        case 'k':
        case 'K': tmp.append('M');
            break;
        case 'm':
        case 'M': tmp.append('K');
            break;
        case 'B':
        case 'b': tmp.append('V');
            break;
        case 'd':
        case 'D': tmp.append('H');
            break;
        case 'h':
        case 'H': tmp.append('D');
            break;
        case 'v':
        case 'V': tmp.append('B');
            break;
        default:throw NonIupacBase("tmpuence contains invalid IUPAC Base, in reverse complement");

        }
    }
    return tmp;

}

QSequence SequenceTools::ConvertToDNA(const QSequence & seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QSequence tmp;
    for(int x=0;x<seq.length();x++)
    {
        switch(seq[x].toAscii())
        {
        case 'u': tmp.append('t');
            break;
        case 'U': tmp.append('T');
            break;
        default: tmp.append(seq[x]);
            break;
        }
    }
    return tmp;
}

QSequence SequenceTools::ConvertToRNA(const QSequence & seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QSequence tmp;
    for(int x=0;x<seq.length();x++)
    {
        switch(seq[x].toAscii())
        {
        case 't': tmp.append('u');
            break;
        case 'T': tmp.append('U');
            break;
        default: tmp.append(seq[x]);
            break;
        }
    }
    return tmp;
}

bool SequenceTools::IsOnlyAT(QSequence& seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    for (int i = 0; i < seq.size(); ++i)
    {
        if (seq[i].toLower().toAscii() != 'a' | seq[i].toLower().toAscii() != 't' | seq[i].toLower().toAscii() != 'n')
        {
            return false;

        }
    }
    return true;
}

bool SequenceTools::IsOnlyGC(QSequence& seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    for (int i = 0; i < seq.size(); ++i)
    {
        if (seq[i].toLower().toAscii() != 'c' | seq[i].toLower().toAscii() != 'g' | seq[i].toLower().toAscii() != 'n')
        {
            return false;

        }
    }
    return true;
}

bool SequenceTools::IsSymmetry(QSequence& seq)throw (EmptySequenceException)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    for(int x=0;x<seq.size();x++)
    {
        if(!IsComplement(seq[x].toLower(),seq[seq.length()-x-1].toLower()))
        {
            return FALSE;
        }
    }
    return TRUE;
}

BaseCount SequenceTools::CalculateBases(const QSequence& seq)throw (EmptySequenceException,NonIupacBase)
{
    if(seq.isEmpty()||seq.isNull())
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    BaseCount tmp={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int j=0;j<seq.length();j++)
    {
        switch(seq[j].toUpper().toAscii())
        {
        case 'A':
            tmp.A++;
            break;
        case 'C':
            tmp.C++;
            break;
        case 'G':
            tmp.G++;
            break;
        case 'T':
            tmp.T++;
            break;
        case 'U':
            tmp.U++;
            break;
            //------------------------
        case 'M':
            tmp.M++;
            break;
        case 'R':
            tmp.R++;
            break;
        case 'W':
            tmp.W++;
            break;
        case 'S':
            tmp.S++;
            break;
        case 'Y':
            tmp.Y++;
            break;
        case 'K':
            tmp.K++;
            break;
        case 'V':
            tmp.V++;
            break;
        case 'H':
            tmp.H++;
            break;
        case 'D':
            tmp.D++;
            break;
        case 'B':
            tmp.B++;
            break;
            //---------
        case 'X':
            tmp.X++;
            break;
        case 'N':
            tmp.N++;
            break;
        case '-':
            tmp.gap++;
            break;
        default:throw NonIupacBase("sequence contains invalid IUPAC Base, in reverse complement");


        }
    }

    return tmp;
}

double SequenceTools::GetSimilarity (const QSequence& oriseq,const QSequence & seq)throw (EmptySequenceException)
{
    if((seq.isEmpty()||seq.isNull())||(oriseq.isEmpty()||oriseq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    int len=oriseq.length();
    int c=0;
    for(int i =0;i<len;i++)
    {
        if(oriseq.mid(i,1)==seq.mid(i,1))
            c++;
    }
    return (100 * (double)c/len);
}

//*************************************************************

QList<int> SequenceTools::CountNeighbors(const QSequence& seek_pattren,const QSequence& seq)throw (EmptySequenceException)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QList<int>  indices;
    int x=0;
    while(x>=0 &&x <seq.size())
    {
        x=seq.indexOf(QRegExp(seek_pattren,Qt::CaseInsensitive) ,x);
        if(x>=0){
            indices<<x;
            x++;
        }
    }
    return indices;
}
//*********************************************************************************

//===========================================================
//   BINARY SEQUENCE CONVERSION
//===========================================================
char SequenceTools::BinaryToNucleo(int in)throw(NonIupacBase)
{


    static const char char_table[16] = {
        ' ','A','C','M','G','R','S','V','T',
        'W','Y',' ','K','D','B','N'};

    char out;
    if(in ==-1)
    {
        return out='-';
    }


    switch(in)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:
        out=char_table[in]  ;
        break;

    default:
        throw NonIupacBase("BioQt::SequenceTools invalid IUPAC code ");
        break;

    }
    return out;
}

int SequenceTools::NucleoToBinary(char in)throw(NonIupacBase)//to convert QChar to std::char use to QChar.toAscii()
{
    in=toupper(in);
    char A = 1, C = 2, G = 4, T = 8;

    int out;
    switch (in) {
    case 'A':
        out = A;
        break;
    case 'G':
        out = G;
        break;
    case 'C':
        out = C;
        break;
    case 'T':
        out = T;
        break;
    case 'R':
        out = A | G;
        break;
    case 'Y':
        out = T | C;
        break;
    case 'S':
        out = G | C;
        break;
    case 'W':
        out = A | T;
        break;
    case 'M':
        out = A | C;
        break;
    case 'K':
        out = G | T;
        break;
    case 'B':
        out = G | C | T;
        break;
    case 'D':
        out = A | G | T;
        break;
    case 'H':
        out = A | C | T;
        break;
    case 'V':
        out = A | G | C;
        break;
    case 'N':
        out = A | G | C | T;
    case 'X':
        out = A | G | C | T;
        break;
    case '-':
        out = A -C ;
        break;
    default:
        throw NonIupacBase("BioQt::SequenceTools invalid IUPAC code ");

        break;
    }
    return out;
}

QList<int> SequenceTools::SequenceToBinary(const QSequence& seq)throw(EmptySequenceException,NonIupacBase)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");

    QList<int> tmp;
    Q_FOREACH(QChar c,seq){
        if(QIUPACData::Ambiguous_DNA_Chars.contains(c,Qt::CaseInsensitive))
            throw NonIupacBase("BioQt::SequenceTools invalid IUPAC code ");
        tmp<<NucleoToBinary(c.toAscii());
    }
    return tmp;
}

QSequence SequenceTools::BinarySeqToQSequence(QList<int> lst)throw(InvalidIntValue)
{
    QSequence tmp;
    for(int j=0;j<lst.size();j++ )
    {
        if(lst[j]>15 ||lst[j]==0||lst[j]<-2||lst[j]==11)
            throw InvalidIntValue("BioQt::SequenceTools invalid int vlaue");
        tmp.append(BinaryToNucleo(lst[j]));
    }
    return tmp;
}
//=======================================================================================
//================================================================================
//             BYTE SEQUENCE Conversion
//===============================================================================

BYTE SequenceTools::NucleoToByte( char c)
{
    c=tolower(c);
    if (c == 'a')
        return 1;
    else if (c == 'b')
        return 11;
    else if (c == 'c')
        return 2;
    else if (c == 'd')
        return 12;
    else if (c == 'e')
        return 0;
    else if (c == 'f')
        return 0;
    else if (c == 'g')
        return 3;
    else if (c == 'h')
        return 13;
    else if (c == 'i')
        return 0;
    else if (c == 'j')
        return 0;
    else if (c == 'k')
        return 7;
    else if (c == 'l')
        return 7;
    else if (c == 'm')
        return 0;
    else if (c == 'n')
        return 15;
    else if (c == 'o')
        return 0;
    else if (c == 'p')
        return 0;
    else if (c == 'q')
        return 0;
    else if (c == 'r')
        return 5;
    else if (c == 's')
        return 9;
    else if (c == 't')
        return 4;
    else if (c == 'u')
        return 4;
    else if (c == 'v')
        return 14;
    else if (c == 'w')
        return 10;
    else if (c == 'x')
        return 15;
    else if (c == 'y')
        return 6;
    else if (c == 'z')
        return 0;
    else
        return 16;

}

QList<int> SequenceTools::SequenceToByteList(const QSequence& seq)throw(EmptySequenceException,BadChar)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    QList<int> tmp;
    Q_FOREACH(QChar c,seq)
    {
        if(!c.isLetter())
        {
            if(c !='-')
                throw BadChar("BioQt::SequenceTools the Sequence Contains non char charcter");

        }
        tmp<<NucleoToByte(c.toAscii());
    }
    return tmp;
}

//====================================================================================
bool SequenceTools::IsOdd(int num)
{
    // return (num%2==0);
    if ((num/2) != ((int) (num/2))) return TRUE;
    else return FALSE;
}

bool   SequenceTools::IsEven(int num)
{
    if ((num/2) == ((int) (num/2))) return TRUE;
    else return FALSE;
}

QSequence SequenceTools::SubSequence( const QSequence& seq,int pos, int len )
{

    QSequence tmp(seq.mid(pos,len));


    return tmp;
}

QSequence SequenceTools::HalfSequence(QSequence seq,int len)
{
    int comp_len=int(seq.size()/2);
    if(IsOdd(seq.size()))
    {

        if(len==0)
            return SubSequence(seq,0,comp_len);
        else
            return SubSequence(seq,comp_len+1);
    }
    else
    {


        if(len==0)
        {

            return SubSequence(seq,0,comp_len);
        }
        else
            return SubSequence(seq,comp_len);
    }
}


bool SequenceTools::IsMirror( QString  seq)
{

    if (QString::compare(seq,Reverse(seq))==0) return true;
    else return false;
}

//*********************

QMap<QString,int> SequenceTools::NucleoCountNeighbors(const QSequence& seq)throw(EmptySequenceException)
{
    QMap<QString,int> tmp;
    tmp["AA"]=CountNeighbors("AA",seq).size();
    tmp["AT"]=CountNeighbors("AT",seq).size();
    tmp["TA"]=CountNeighbors("TA",seq).size();
    tmp["CA"]=CountNeighbors("CA",seq).size();
    tmp["GT"]=CountNeighbors("GT",seq).size();
    tmp["CT"]=CountNeighbors("CT",seq).size();
    tmp["GA"]=CountNeighbors("GA",seq).size();
    tmp["CG"]=CountNeighbors("CG",seq).size();
    tmp["GC"]=CountNeighbors("GC",seq).size();
    tmp["GG"]=CountNeighbors("GG",seq).size();
    tmp["TT"]=CountNeighbors("TT",seq).size();
    tmp["AU"]=CountNeighbors("AU",seq).size();
    tmp["UA"]=CountNeighbors("UA",seq).size();
    tmp["TG"]=CountNeighbors("TG",seq).size();
    tmp["AC"]=CountNeighbors("AC",seq).size();
    tmp["AG"]=CountNeighbors("AG",seq).size();
    tmp["TC"]=CountNeighbors("TC",seq).size();
    tmp["UU"]=CountNeighbors("UU",seq).size();
    tmp["UG"]=CountNeighbors("UG",seq).size();
    tmp["GU"]=CountNeighbors("GU",seq).size();
    tmp["CU"]=CountNeighbors("CU",seq).size();
    tmp["UC"]=CountNeighbors("UC",seq).size();
    return tmp;


}

double SequenceTools::GC_skew(const QSequence& seq)throw(EmptySequenceException)
{

    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    BaseCount bsct=CalculateBases(seq);
    double skew=(bsct.G-bsct.C)/double(bsct.G+bsct.C);
    return skew;
}

double SequenceTools::GmC_skew(const QSequence& seq)throw(EmptySequenceException)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    BaseCount bsct=CalculateBases(seq);
    double skew=(bsct.G+bsct.C)/double(bsct.A+bsct.G+bsct.C+bsct.T);
    return skew;
}

double SequenceTools::AT_skew(const QSequence& seq)throw(EmptySequenceException)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    BaseCount bsct=CalculateBases(seq);
    double skew=(bsct.A-bsct.T)/double(bsct.A+bsct.T);
    return skew;
}

double SequenceTools::KETO_skew(const QSequence& seq)throw(EmptySequenceException)
{
    if((seq.isEmpty()||seq.isNull()))
        throw EmptySequenceException("BioQt::SequenceTools the Sequence Is empty");
    BaseCount bsct=CalculateBases(seq);
    double skew=(bsct.G+bsct.C-bsct.A-bsct.T)/double(bsct.A+bsct.G+bsct.C+bsct.T);
    return ( skew);
}

AlphaBet *SequenceTools::GuessAlphabet(const QSequence &seq)
{
    const int BASE_COUNT = 100;
    const int MIN_NUCLEO_PCT = 95;
    int DNACount = 0;
    int RNACount = 0;
    int Total = 0;
    AlphaBet * alpha;

    BaseCount tmp;
    try
    {
        if(seq.size()<BASE_COUNT)
            tmp=  SequenceTools::CalculateBases(seq);
        else
            tmp=  SequenceTools::CalculateBases(seq.mid(0,BASE_COUNT));

        DNACount=tmp.A+tmp.C+tmp.G+tmp.T+tmp.N;
        RNACount=tmp.A+tmp.C+tmp.G+tmp.U+tmp.N;
        Total=seq.size() <BASE_COUNT ? seq.size() : 100;



        if (Total != 0 && ((RNACount * 100) / Total) >= MIN_NUCLEO_PCT)
            return (new RNA());
        if (Total != 0 && ((DNACount * 100) / Total) >= MIN_NUCLEO_PCT)
            return (new DNA());
    }
    catch(BioQtException ex)
    {
    }
    return (new Protein());

}


int SequenceTools::nucleotide_complement(int nucleotide)
{
    return(*(complement - 65 + nucleotide));
}

int SequenceTools::nucleotide_complement(const QChar &nucleotide)
{
    return(*(complement - 65 + nucleotide.toUpper().unicode()));
}

//===============================================
} // namespace BioQt
