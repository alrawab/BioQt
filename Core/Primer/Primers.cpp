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

#include "Primers.h"

namespace BioQt {

int PrimerRegion::maxLengthMax=30;


PrimerRegion::PrimerRegion(const QSequence &_seq, int _start, int _end):minLength(15),
    maxLength(24),targetLength(20),minHpinBases(3),minHpinLoop(2),minDimerLength(2),
    minDimerCount(4),isInvalid(true)
{

    start=_start;
    end=_end;
     seq=_seq.mid(start,end);
    isForward=start <= end;
    seqNum =SequenceTools::SequenceToByteList(seq);

    int len =qAbs(start-end);
    if (minLength > len)
        minLength = len;
    if (maxLength > len)
        maxLength = len;
    if (targetLength > len)
        targetLength = len;
}

void PrimerRegion::Validate()
{
    int increasingLength = targetLength;
    int decreasingLength = targetLength;
    bool direction = true;  // direction of increasing, we go alternative
    do
    {
        if (direction) // go increase
        {
            Primers p(*this, increasingLength);

            p.Validate();
            primers.append(p);
        }
        else
        {
            Primers p (*this, decreasingLength);
            p.Validate();
            primers.append(p);
        }

        if (direction) // go increase
        {
            if (increasingLength + 1 > maxLength)
            {
                if (decreasingLength - 1 < minLength)
                {
                    break;
                }
                else
                {
                    direction = !direction;
                    decreasingLength--;
                }
            }
            increasingLength++;
        }
        else
        {
            if (decreasingLength - 1 < minLength)
            {
                if (increasingLength + 1 > maxLength)
                {
                    break;
                }
                else
                {
                    direction = !direction;
                    increasingLength++;
                }
            }
            increasingLength--;
        }

    } while (true);

    isInvalid = false;
}

Primers PrimerRegion::PrimersAt(int primerLength)throw(BioQtException)
{
    if (isInvalid) Validate();
    if (primerLength >= minLength & primerLength <= maxLength)
    {

        Q_FOREACH(Primers c,primers)
        {
            if(c.primerLength==primerLength)
                return c;
        }

    }
    else
    {
        throw BioQtException("primer length: " + QString::number(primerLength));
    }

}

void PrimerRegion::setMaxLength(int _maxlen)throw(BioQtException)
{
    if (_maxlen > Length())
        throw BioQtException("value must be less than sequence length");
    maxLength = _maxlen;
    if (minLength > maxLength)
        minLength = maxLength;
    isInvalid = true;

}

void PrimerRegion::setMinLength(int _minlen)throw(BioQtException)
{
    if (_minlen > Length())
        throw BioQtException("value must be less than sequence length");
    minLength = _minlen;
    if (minLength > maxLength)
        maxLength = minLength;
    isInvalid = true;

}

void PrimerRegion::setMinDimerLength(int val)throw(BioQtException)
{
    if (val < 2 | val > maxLengthMax)
    {
        throw BioQtException("value must be larger than 2 and less than primer length");
    }
    minDimerLength = val;

}

void PrimerRegion::setMinHpinBases(int val)throw(BioQtException)
{
    minHpinBases = val;
    if (minHpinLoop > minHpinBases)
        minHpinLoop = minHpinBases;
    isInvalid = true;

}

void PrimerRegion::setMinHpinLoop(int val)throw(BioQtException)
{
    minHpinLoop = val;
    if (minHpinBases < minHpinLoop)
        minHpinBases = minHpinLoop;
    isInvalid = true;

}












//------------------------------------------------------------------------

Primers::Primers(PrimerRegion _parent, int _primerLength):parent(_parent),primerLength(_primerLength)
{


}

QString Primers::SelfDimer(int location, Primer::Form form)
{
    if (selfDimers[location].isEmpty())
        return QString();

    return  Primer::PrintDimer(parent.seq, selfDimers[location][0], form);

}

QStringList Primers::SelfDimers(int location, Primer::Form form)throw (BioQtException)
{
    if (location > (parent.seq.length() - primerLength))
    {
        throw BioQtException("location must be less than (sequence length - primer length)");
    }
    if (selfDimers[location].isEmpty())
    {
       return QStringList();
    }
    else
    {
        QStringList ss;
        for (int i = 0; i < selfDimers[location].size(); ++i)
        {


            ss<< Primer::PrintDimer(parent.seq.mid(parent.start + location, primerLength),
                                   selfDimers[location][i], form);
        }
        return ss;
    }

}

QStringList Primers::HairPins(int location, Primer::Form form)throw (BioQtException)
{
    if (location > (parent.seq.length() - primerLength))
    {
        throw BioQtException("location must be less than (sequence length - primer length)");
    }
    if (hairPins[location].isEmpty())
    {
        return QStringList();
    }
    else
    {
        QStringList ss ;
        for (int i = 0; i < hairPins[location].size(); ++i)
        {
            ss << Primer::PrintHairPin(parent.seq.mid(parent.start + location, primerLength),
                                       hairPins[location][i], form);
        }
        return ss;
    }

}

void Primers::Validate()
{
    int n=parent.seq.length()-primerLength+1;
    selfDimers.resize(n);
    hairPins.resize(n);
    for (int i = 0; i < n; ++i)
    {
        Primer primer(parent.seq.mid(i,primerLength));
        selfDimers[i]=   primer.selfDimers;
        hairPins[i] = primer.hairPins;
    }

}



} // namespace BioQt
