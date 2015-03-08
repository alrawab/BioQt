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

#include "NeedlemanWunsch.h"

namespace BioQt {

NeedlemanWunsch::NeedlemanWunsch()
{

}

NeedlemanWunsch::~NeedlemanWunsch()
{

}

Alignment NeedlemanWunsch::align(const QSequence &seq1, const QSequence &seq2, SMatrix matrix, float _GapPenalty)
{

    QVector<QVector<float>> scores =matrix.Matrix();

       int m = seq1.length() + 1;
       int n = seq2.length() + 1;

      QVector<QVector<float>>  pointers(m,QVector<float>(n));
      pointers[0][0] = 0;


       for (int i = 1; i < m; i++) {
         pointers[i][0] = 3;
       }
       for (int j = 1; j < n; j++) {
         pointers[0][j] = 1;
       }


       Cell * cell = construct(seq1, seq2, scores, _GapPenalty, pointers);
       Alignment alignment = traceback(seq1, seq2, matrix, pointers, cell);

       alignment.setOriginalSequence1(seq1);
       alignment.setOriginalSequence2(seq2);
       alignment.setMatrix(matrix);
       alignment.setOpen(_GapPenalty);
       alignment.setExtend(_GapPenalty);
       /*if (s1.getId() != null) {
         alignment.setName1(s1.getId());
       }
       if (s2.getId() != null) {
         alignment.setName2(s2.getId());
       }*/
       return alignment;
}

Cell * NeedlemanWunsch::construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float _Gap, QVector<QVector<float> > pointers)
{
    Cell *cell = new Cell();

    QByteArray a1 = seq1.toLocal8Bit();

    QByteArray a2 = seq2.toLocal8Bit();

        int m = seq1.length() + 1;
        int n = seq2.length() + 1;


       QVector<float> v(n);
        for (int j = 1; j < n; j++) {
          v[j] = (j * -_Gap);
        }
        v[0] = 0.0F;


        float vOld = 0.0F;
        for (int i = 1; i < m; i++)
        {
          v[0] = (i * -_Gap);
          for (int j = 1; j < n; j++)
          {
            float x = v[j] - _Gap;
            float y = v[(j - 1)] - _Gap;
            float z = vOld + matrix[a1[(i - 1)]][a2[(j - 1)]];

            vOld = v[j];
            v[j] = maximum(x, y, z);
            if (v[j] == x) {
              pointers[i][j] = 3;
            } else if (v[j] == y) {
              pointers[i][j] = 1;
            } else {
              pointers[i][j] = 2;
            }
          }
          vOld = i * -_Gap;
        }
        cell->set(m - 1, n - 1, v[(n - 1)],pointers);
        return cell;
}

Alignment NeedlemanWunsch::traceback(QSequence seq1, QSequence seq2, SMatrix m, QVector<QVector<float> > pointers, Cell *cell)
{
    pointers=cell->getpointer();
    QByteArray array1 = seq1.toLocal8Bit();

    QByteArray array2 = seq2.toLocal8Bit();
        QVector<QVector<float>> scores = m.Matrix();

        Alignment alignment ;
        alignment.setScore(cell->getScore());


        int maxlen = seq1.length() + seq2.length();

        QByteArray  reversed1;
        QByteArray  reversed2;
        QByteArray  reversed3;

        int len1 = 0;
        int len2 = 0;
        int len3 = 0;

        int identity = 0;
        int similarity = 0;
        int gaps = 0;
char c1,c2;


        int i = cell->getRow();
        int j = cell->getCol();


        bool stillGoing = true;
        while (stillGoing) {
          switch ((int)pointers[i][j])
          {
          case 3:
            reversed1[(len1++)] = array1[(--i)];
            reversed2[(len2++)] = '-';
            reversed3[(len3++)] = ' ';
            gaps++;
            break;
          case 2:
             c1 = array1[(--i)];
             c2 = array2[(--j)];
            reversed1[(len1++)] = c1;
            reversed2[(len2++)] = c2;
            if (c1 == c2)
            {
              reversed3[(len3++)] = '|';
              identity++;
              similarity++;
            }
            else if (scores[c1][c2] > 0.0F)
            {
              reversed3[(len3++)] = ':';
              similarity++;
            }
            else
            {
              reversed3[(len3++)] = '.';
            }
            break;
          case 1:
            reversed1[(len1++)] = '-';
            reversed2[(len2++)] = array2[(--j)];
            reversed3[(len3++)] = ' ';
            gaps++;
            break;
          case 0:
            stillGoing = false;
          }
        }
        alignment.setSequence1(reverse(reversed1, len1));
        alignment.setStart1(i);
        alignment.setSequence2(reverse(reversed2, len2));
        alignment.setStart2(j);
        alignment.setMarkupLine(reverse(reversed3, len3));
        alignment.setIdentity(identity);
        alignment.setGaps(gaps);
        alignment.setSimilarity(similarity);

        return alignment;
}

float NeedlemanWunsch::maximum(float a, float b, float c)
{
    if (a > b) {
         return a > c ? a : c;
       }
    return b > c ? b : c;
}

QByteArray NeedlemanWunsch::reverse(QByteArray a, int len)
{
    QByteArray b;
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }
    return b;
}




} // namespace BioQt

