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

#include "Alignment.h"

namespace BioQt {

Alignment::Alignment()
{

}

Alignment::~Alignment()
{

}

QByteArray Alignment::format()
{

    QByteArray sequence1 = getSequence1();
    QByteArray sequence2 = getSequence2();
    QByteArray markup = getMarkupLine();

   sequence1.replace(" ","-");

    int length = sequence1.length() > sequence2.length() ? sequence2.length() : sequence1.length();

    QString name1 = adjustName(getName1());
    QString name2 = adjustName(getName2());

    QByteArray buffer ;

    QByteArray preMarkup;

    for (int j = 0; j < 21; j++) {
     preMarkup.append(" ");
    }
     int position1 = 1 + getStart1();
     int position2 = 1 + getStart2();
     for (int i = 0; i * 50 < length; i++)
          {
            int oldPosition1 = position1;
            int oldPosition2 = position2;

           int line = (i + 1) * 50 < length ? (i + 1) * 50 : length;

            QByteArray subsequence1(line - i * 50,' ');
            QByteArray subsequence2(line - i * 50,' ');
            QByteArray submarkup(line - i * 50,' ');

            int j = i * 50;
            for (int k = 0; j < line; k++)
            {
              subsequence1[k] = sequence1[j];
              subsequence2[k] = sequence2[j];
              submarkup[k] = markup[j];
              char c1 = subsequence1[k];
              char c2 = subsequence2[k];
             if (c1 == c2)
             {
                position1++;
               position2++;
              }
             else if (c1 == '-')
             {
                position2++;
              }
              else if (c2 == '-')
              {
                position1++;
              }
              else
           {
                position1++;
                position2++;
              }
               j++;
            }
            buffer.append("\r\n");

            buffer.append(name1);
            buffer.append(" ");
            buffer.append(adjustPosition(QString::number(oldPosition1)));
            buffer.append(" ");
            buffer.append(subsequence1);
            buffer.append(" ");
            buffer.append(adjustPosition(QString::number(position1 - 1)));
            buffer.append("\r\n");

            buffer.append(preMarkup);
            buffer.append(submarkup);
            buffer.append("\r\n");

            buffer.append(name2);
            buffer.append(" ");
           buffer.append(adjustPosition(QString::number(oldPosition2)));
           buffer.append(" ");
           buffer.append(subsequence2);
           buffer.append(" ");
           buffer.append(adjustPosition(QString::number(position2 - 1)));
           buffer.append("\r\n");

           buffer.append("\r\n");
          }
         return buffer;





}

QByteArray Alignment::getSummary()
{
    qDebug()<<sequence1;

    QByteArray Tmp;
    int length = getSequence1().size();
    //  qDebug()<<getSequence1();
    QString _DEFAULT_LINE_SEPARATOR="\r\n";
    Tmp.append(QString("Sequence #1: %1").arg( getName1()));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Sequence #2: %1").arg(getName2()));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Length #1: %1").arg( getOriginalSequence1().size()));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Length #2: %1").arg( getOriginalSequence2().size() ));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    //Tmp.append(QString("Matrix: %1").arg( (matrix.getId().isEmpty() ? "" : matrix.getId())));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Gap open: %1").arg(open));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Gap extend: %1").arg( extend));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Length: %1").arg( getLength()));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);

    Tmp.append(QString("Identity: %1%2%3(%4%)").arg(identity).arg(QDir::separator()).arg(length).arg(QString::number((identity / (float) length*100),'f',2)));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Similarity: %1%2%3(%4%)").arg(similarity).arg(QDir::separator()).arg(length).arg(QString::number((similarity / (float) length *100),'f',2)));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);
    Tmp.append(QString("Gaps: %1%2%3(%4 %)").arg(gaps).arg(QDir::separator()).arg(length).arg(QString::number((((gaps /(float)  length*100))))));
    Tmp.append(QString("Score: %1").arg( QString::number(score,'f',2)));
    Tmp.append(_DEFAULT_LINE_SEPARATOR);


qDebug()<<Tmp;


    return Tmp;

}

float Alignment::calculateScore()
{
    float calcScore = 0.0F;

    bool previous1wasGap = false;

    bool previous2wasGap = false;

    int start = 0;
    int end = sequence1.size() - 1;
    for (int i = start; i <= end; i++)
    {
        char c1 = sequence1.at(i);
        char c2 = sequence2.at(i);
        if (c1 == '-')
        {
            if (previous1wasGap) {
                calcScore -= extend;
            } else {
                calcScore -= open;
            }
            previous1wasGap = true;
            previous2wasGap = false;
        }
        else if (c2 == '-')
        {
            if (previous2wasGap) {
                calcScore -= extend;
            } else {
                calcScore -= open;
            }
            previous1wasGap = false;
            previous2wasGap = true;
        }
        else
        {
            calcScore += matrix.getScore(c1, c2);
            previous1wasGap = false;
            previous2wasGap = false;
        }

    }

    return calcScore;




}

float Alignment::getScoreWithNoTerminalGaps()
{
    float calcScore = 0.0F;

    bool previous1wasGap = false;

    bool previous2wasGap = false;

    int start = 0;

    int end = sequence1.size() - 1;

    if (sequence1[start] == '-') {
        while (sequence1[start] == '-') {
            start++;
        }
    }
    if (sequence2[start] == '-') {
        while (sequence2[start] == '-') {
            start++;
        }
    }
    if (sequence1[end] == '-') {
        while (sequence1[end] == '-') {
            end--;
        }
    }
    if (sequence2[end] == '-') {
        while (sequence2[end] == '-') {
            end--;
        }
    }

    for (int i = start; i <= end; i++)
    {
        char c1 = sequence1[i];
        char c2 = sequence2[i];
        if (c1 == '-')
        {
            if (previous1wasGap) {
                calcScore -= extend;
            } else {
                calcScore -= open;
            }
            previous1wasGap = true;
            previous2wasGap = false;
        }
        else if (c2 == '-')
        {
            if (previous2wasGap) {
                calcScore -= extend;
            } else {
                calcScore -= open;
            }
            previous1wasGap = false;
            previous2wasGap = true;
        }
        else
        {
            calcScore += matrix.getScore(c1, c2);
            previous1wasGap = false;
            previous2wasGap = false;
        }
    }
    return calcScore;





}

bool Alignment::checkScore()
{
    if (calculateScore() == score) {
        return true;
    }
    return false;
}

QString Alignment::adjustName(QString name)
{
    QString buffer;//
    if (name.length() > 13)
    {
        buffer.append(name.mid(0, 13));
    }
    else
    {
        buffer.append(name);
        for (int j = buffer.length(); j < 13; j++) {
            buffer.append(" ");
        }
    }
    return buffer;
}

QString Alignment::adjustPosition(QString position)
{
    QByteArray buffer1 ;
    QByteArray buffer2;
    if (position.length() > 6) {
        buffer1.append(position.mid(position.length() - 6, position.length()));
    } else {
        buffer1.append(position);
    }
    int j = 0;
    for (int n = 6 - buffer1.length(); j < n; j++) {
        buffer2.append(" ");
    }
    buffer2.append(buffer1);
    return QString(buffer2);
}

} // namespace BioQt

