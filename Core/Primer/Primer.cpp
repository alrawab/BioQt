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
*BioQt::Primer
*@author Usama S Erawab
*
*/

#include "Primer.h"
#include <climits>
#include <limits>

namespace BioQt {

Primer::Primer(const QSequence &_seq)
    :seq(_seq)
{
    QVector<QVector<bool> > W=ComplementMatrix(seq);
    selfDimers = searchSelfDimers(W, 3, -1);

    hairPins = searchHairPins(W,  4, 2);
}

QVector<QVector<bool> > Primer::ComplementMatrix(const QSequence &seq)
{
    QList<int> B=SequenceTools::SequenceToByteList(seq);

    int n = seq.length() - 1;

    QVector<int> c(seq.size());

    c[0] = B[0];

    QVector<int> r(2*seq.length()-1);

    for (int i = 0; i < seq.length(); ++i)
        r[i] = B[i];

    QVector<QVector<int> > T = Matrix::Toeplitz(c,r);

    QVector<QVector<int> > R(B.size(),QVector<int>(n + n + 1));

    for (int i = 0; i < R.size(); ++i)
        for (int j = 0; j < R[i].size(); ++j)
            R[i][j] = 5 - B[i];

    QVector<QVector<bool> > W(T.size(),QVector<bool>(T[0].size())) ;

    // W = (T==R) | (R~=0 & T==15) | (R==-10 & T~=0);
    for (int i = 0; i < T.size(); ++i)
        for (int j = 0; j < T[i].size(); ++j)
            W[i][j] = T[i][j] == R[i][j] |
                    (R[i][j] != 0 & T[i][j] == 15) |
                    (R[i][j] == -10 & T[i][j] != 0);

    return W;

}

QVector<int> Primer::searchSelfDimers(QVector<QVector<bool> > W, int minDimerLength, int minDimerCount)
{
    // column indeces with at least dBases matches and/or Ns
    QVector<QVector<int> > filter = Matrix::Filter(W,minDimerLength);

    QVector<int> selfComp;

    for (int k1 = 0; k1 < W[0].size(); ++k1)//C
    {

        for (int k2 = 0; k2 < W.size(); ++k2)//R K1
        {

            if (filter[k2][k1] == minDimerLength)
            {

                if (minDimerCount > 0)
                {
                    int dimerCount = 0;
                    for (int k3 = 0; k3 < W.size(); ++k3)//R K2
                        if (W[k3][k1]) ++dimerCount;
                    if (dimerCount < minDimerCount) continue;
                }
                if (!selfComp.contains(k1))
                {

                    selfComp.append(k1);
                }
                break;
            }
        }
    }

    if (selfComp.size() == 0)
        return QVector<int>();
    else
        return selfComp;

}

QVector<float> Primer::searchHairPins(QVector<QVector<bool> > W, int minHpinBases, int minHpinLoop)
{
    QVector<QVector<int> > filter = Matrix::Filter(W,minHpinBases);
    QVector<QVector<double> > index(W.size(),QVector<double>(W[0].size()));

    for (int i = 0; i < W.size(); ++i)
    {
        for (int j = 0; j < W[0].size(); ++j)
            index[i][j] = i + 1;
    }



    for (int i = 0; i < filter.size(); ++i)
        for (int j = 0; j < filter[0].size(); ++j)
            if (filter[i][j] != minHpinBases)
                index[i][j] =qQNaN();
    //------------------------------
    QVector<int> hpins ;
    for (int i = 0; i < index[0].size(); ++i)
    {

        double max = 0.0;
        double min =  INT_MAX;
        for (int j = 0; j < index.size(); ++j)
        {
            if (!qIsNaN(index[j][i]))
            {
                if (index[j][i] > max)
                    max = index[j][i];
                if (index[j][i] < min)
                    min = index[j][i];
            }
        }

        if (max - min >= minHpinBases + minHpinLoop)
            hpins.append(i);

    }


    //---------------------------------
    QVector<float> hairPins(hpins.count());
    for (int i = 0; i < hpins.count(); ++i)
    {
        int s = W[0].size();
        int e = 0;
        for (int j = 0; j < W.size(); ++j)
        {
            if (W[j][hpins[i]])
            {
                if (j < s)
                    s = j;
                if (j > e)
                    e = j;
            }

        }
        float pin = (s + e) / 2.0f;
        hairPins[i] = pin;

    }


    return hairPins;

}

QByteArray Primer::DumpSelfDimers(Primer::Form form)
{
    QByteArray tmp;
    if(selfDimers.isEmpty())
        return tmp.append("No self dimmer");
    for (int i = 0; i < selfDimers.size(); ++i)
    {

         tmp.append(PrintDimer(seq,selfDimers[i],form));

    }

    return tmp;
}

QByteArray Primer::DumpHairPins(Primer::Form form)
{
    QByteArray tmp;
    if(hairPins.isEmpty()) return tmp.append("No hairpins");
    for (int i = 0; i < hairPins.size(); ++i)
    {
        tmp.append(PrintHairPin(seq,hairPins[i],form));

    }
    return tmp;

}




QString Primer::PrintDimer(const QSequence &seq, int revOffset, Primer::Form form)
{


    if (form == Pretty)
    {

        QString revSeq =SequenceTools::Reverse(seq);
        QString sb2;
        for (int j = 0; j < seq.length(); ++j)
        {
            int rj = seq.length() - revOffset + j - 1;


          if(rj >= 0 && rj < revSeq.length() &&SequenceTools::IsComplement(seq[j],revSeq[rj]))
            {



               sb2.append("|");
            }
            else
            {
              sb2.append(" ");

            }
        }
        return seq.rightJustified(seq.size()*2-1) + "\n"+sb2.rightJustified(seq.length() * 2) +"\n"+
                revSeq.rightJustified(revOffset + seq.length()+1);

    }
    else // numeric format assumed
    {
        return     QString("%1 in %2").arg(revOffset).arg(seq.size());
    }

}

QString Primer::PrintHairPin(const QSequence &seq, float pin, Primer::Form form)
{
    int L = seq.length();
    int iPin = (int)pin;
    QString s = seq;
    int half = iPin == pin ? 1 : 2;

    if (form == Pretty)
    {
        QString sb;
        if (half == 1) sb.append(s[iPin]);
        QString s1 = s.mid(iPin+half);
        if (half == 1) s1 = " " + s1;
        QString sb2;
        if (half == 1) sb2.append(" ");

        for (int i = 0; i < iPin; ++i)
        {
            sb2.append(s[iPin - i - 1]);
            if ((iPin + half + i) < L &&
                    SequenceTools::IsComplement(s[iPin - i - 1], s[iPin + i + half]))

            {
                sb.append('|');
            }
            else
            {
                sb.append(' ');
            }
        }

        return s1 + "\n" + sb + "\n" + sb2;
    }
    //*****************************
    else if (form == Camel)
    {
        QString sb ;
        half = half == 1 ? 0 : 1;
        for (int i = 0; i < seq.length(); ++i)
        {
            bool pair = false;
            if ((i <= iPin && ((iPin + 1) * 2 - i) < seq.length()) &&
                    SequenceTools::IsComplement(seq[i], seq[(iPin + 1) * 2 - i - 1]))

            {
                pair = true;
            }
            if (pair)
            {
                sb.append(seq[i].toUpper());
            }
            else
            {
                sb.append(seq[i]);
            }
        }
        return sb;
    }
    else if (form == Simple)
    {
        if (half == 1)
        {

            return s.mid(0, iPin) + "]" + s.mid(iPin, 1) + "[" + s.mid(iPin + 1);
        }
        else
        {

            return s.mid(0, iPin) + "|" + s.mid(iPin);
        }
    }
    else
    {
        return QString("%1 of %2").arg(pin).arg(seq.size());

    }


}


} // namespace BioQt
