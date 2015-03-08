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
*BioQt::Primers
*@author Usama S Erawab
*
*/

#ifndef PRIMERS_H
#define PRIMERS_H

#include <BioQt_global.h>
#include <QtCore>
#include "Primer.h"
#include <Utils/Exceptions/BioQtException.h>


namespace BioQt {
class Primers;
class BIOQTSHARED_EXPORT PrimerRegion
{
public:
    //     PrimerRegion(){}

    PrimerRegion(const QSequence& _seq, int _start, int _end);
    void Validate();
    inline void Invalidate() { isInvalid = true; }
    Primers PrimersAt(int primerLength)throw(BioQtException);
    inline int Length (){return seqNum.size();}
    void setMaxLength(int _maxlen)throw(BioQtException);
    inline int getMaxLength(){return maxLength;}


     void setMinLength(int _minlen)   throw(BioQtException);

    QList<Primers> getPrimers(){return primers;}
    inline int getMinDimerLength(){return minDimerLength;}
    void setMinDimerLength(int val)throw(BioQtException);
    inline int getMinHpinBases(){return minHpinBases;}
    void setMinHpinBases(int val)throw(BioQtException);
    void setMinHpinLoop(int val)throw(BioQtException);
    int getMinHpinLoop(){return minHpinLoop;}

    QSequence seq;
    int start;
    int end;
    int minLength;
    int maxLength;
    int targetLength;

    static int maxLengthMax;
    bool isForward;

    int minHpinBases;
    int minHpinLoop;
    int minDimerLength;
    int minDimerCount;
    bool isInvalid ;
    QList<Primers> primers;
    QList<int> seqNum;


};
//-----------------------------------------------------------------------
class BIOQTSHARED_EXPORT Primers
{
public:
    //Primers(){}
    Primers(PrimerRegion _parent, int _primerLength);
    //Return string of most stable self-dimer at given location
    QString SelfDimer(int location, Primer::Form form);
    //Return pretty string of all dimers at given location
    QStringList SelfDimers(int location, Primer::Form form)throw (BioQtException);
    QStringList HairPins(int location, Primer::Form form)throw (BioQtException);
    inline int PrimerLength (){return primerLength;}
    inline int RegionLength(){return parent.seq.length();}


    //protected:
    void Validate();
    int primerLength;
    PrimerRegion parent;
    QVector<QVector<int> > selfDimers;
    QVector<QVector<float> > hairPins;

};

} // namespace BioQt

#endif // BIOQT_PRIMERS_H
