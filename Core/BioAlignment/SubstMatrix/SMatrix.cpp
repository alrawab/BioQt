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

#include "SMatrix.h"
namespace BioQt {
#define DEFAULT_FILL_VALUE -1000000.0f

SMatrix::SMatrix(const QString& _name,  const QList<SScore>& rawMatrix, const QString& _description,const QByteArray& vchars)
    : name(_name), description(_description)
{
    validCharacters ="ABCDEFGHIKLMNPQRSTVWXYZ*X-" ;//vchars;
//Scores=rawMatrix;
    SMatrix::charBounds(validCharacters.constData(), validCharacters.size(), minChar, maxChar);
    charsInRow  = maxChar - minChar + 1;

    scores.resize(charsInRow*charsInRow);
    qFill(scores.data(), scores.data() + scores.size(), -1000000);

    minScore = 1000000;
    maxScore = -1000000;
    foreach(const SScore& s, rawMatrix) {
        int idx = getScoreIdx(s.c1, s.c2);
        scores[idx] = s.score;
        minScore = qMin(minScore, s.score);
        maxScore = qMax(maxScore, s.score);
    }

    //now for all symbols in alphabet without score set the minimal score
       foreach(char c1, validCharacters) {
           foreach(char c2, validCharacters) {
               float score = getScore(c1, c2);
               if (score == DEFAULT_FILL_VALUE) {
                   setScore(c1, c2, minScore);
               }
           }
       }

}

SMatrix::~SMatrix()
{

}

void SMatrix::charBounds(const char *data, int dataSize, char &minChar, char &maxChar)
{
    assert(dataSize > 0);
    maxChar = minChar = data[0];
    for (int i=1; i < dataSize; i++) {
        char c = data[i];
        minChar = qMin(minChar, c);
        maxChar = qMax(maxChar, c);
    }

}

QVector<QVector<float> > SMatrix::Matrix()
{
     QVector<QVector<float> >  scores(127,QVector<float>(127));
     for(int x=0;x<getAlphabetChars().size();++x)
     {

         for(int j=0;j<getAlphabetChars().size();++j)
         {
             scores[getAlphabetChars().at(x)][getAlphabetChars().at(j)]=getScore(x,j);
         }


     }
     return scores;
}



void SMatrix::copyCharValues(char srcChar, char dstChar) {
    for (int i=0; i < validCharacters.size(); i++) {
        char c = validCharacters.at(i);
        float scoreSrc1 = getScore(srcChar, c);
        setScore(dstChar, c, scoreSrc1);
        float scoreSrc2 = getScore(c, srcChar);
        setScore(c, dstChar, scoreSrc2);
    }
}

QVariant SMatrix::toQVariant() const {
    QList<QVariant> res;
    res.append(name);
    res.append(description);
    res.append(QChar(minChar));
    res.append(QChar(maxChar));
    res.append(charsInRow);
    res.append(validCharacters);
    res.append(double(minScore));
    res.append(double(maxScore));

    res.append(scores.size());
    for (int i=0; i< scores.size(); i++) {
        res.append(double(scores[i]));
    }

    return res;

}

SMatrix SMatrix::fromQVariant(const QVariant& v) {
    QList<QVariant> list = v.toList();
    SMatrix m;

    int n = 0;
    m.name = list.at(n++).toString();
    m.description = list.at(n++).toString();
    QString alphabetId = list.at(n++).toString();
    m.minChar = list.at(n++).toChar().toAscii();
    m.maxChar = list.at(n++).toChar().toAscii();
    m.charsInRow = list.at(n++).toInt();
    m.validCharacters = list.at(n++).toByteArray();
    m.minScore = (float)list.at(n++).toDouble();
    m.maxScore = (float)list.at(n++).toDouble();

    int nScores = list.at(n++).toInt();
    m.scores.resize(nScores);
    for(int i = 0; i< nScores; i++) {
        m.scores[i] = float(list.at(n++).toDouble());
    }

    if (m.name.isEmpty() ||  m.validCharacters.isEmpty()
            || !m.validCharacters.contains(m.minChar) || !m.validCharacters.contains(m.maxChar)
            || m.maxChar - m.minChar + 1 != m.charsInRow)
    {
        qDebug("Error during substitution matrix deserialization!");
        return SMatrix();
    }
    return m;
}

}
