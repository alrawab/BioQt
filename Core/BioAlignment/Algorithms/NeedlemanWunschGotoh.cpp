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

#include "NeedlemanWunschGotoh.h"

namespace BioQt {

NeedlemanWunschGotoh::NeedlemanWunschGotoh()
{

}

NeedlemanWunschGotoh::~NeedlemanWunschGotoh()
{

}

Alignment NeedlemanWunschGotoh::align(QSequence seq1, QSequence seq2, SMatrix matrix, float o, float e)
{
    QVector<QVector<float>> scores =matrix.Matrix();

     QSequence _s1;
     QSequence _s2;
     if (seq1.length() < seq2.length())
     {
       _s1 = seq2;
       _s2 = seq1;
     }
     else
     {
       _s1 = seq1;
       _s2 = seq2;
     }
     int m = _s1.length() + 1;
     int n = _s2.length() + 1;

     QVector<int> pointers(m*n);

     QVector<short> lengths(m*n);


     pointers[0] = 0;


     int i = 1;
     for (int k = n; i < m; k += n)
     {
       pointers[k] = 3;
       lengths[k] = ((short)i);i++;
     }
     for (int j = 1; j < n; j++)
     {
       pointers[j] = 1;
       lengths[j] = ((short)j);
     }
     Cell * cell = construct(_s1, _s2, scores, o, e, pointers, lengths);

     Alignment alignment = traceback(_s1, _s2, matrix, pointers, cell, lengths);


     alignment.setMatrix(matrix);
     alignment.setOpen(o);
     alignment.setExtend(e);
   //  alignment.setName1(_s1.getId());
  //   alignment.setName2(_s2.getId());
     alignment.setOriginalSequence1(_s1);
     alignment.setOriginalSequence2(_s2);

     return alignment;
}

Cell *NeedlemanWunschGotoh::construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float o, float e, QVector<int> pointers, QVector<short> lengths)
{
    QByteArray a1 = seq1.toLocal8Bit();

    QByteArray a2 = seq2.toLocal8Bit();

       int m = seq1.length() + 1;
       int n = seq2.length() + 1;

      QVector<float> v(n);
       float vDiagonal = 0.0F;
       float f = (1.0F / -1.0F);
       float h = (1.0F / -1.0F);

        QVector<float> g(n);


       g[0] = (1.0F / -1.0F);
       for (int j = 1; j < n; j++)
       {
         v[j] = 0.0F;
         g[j] = (1.0F / -1.0F);
       }
       int lengthOfHorizontalGap = 0;
       QVector<int> lengthOfVerticalGap(n);


       float maximumScore = (1.0F / -1.0F);
       int maxi = 0;
       int maxj = 0;


       int i = 1;
       for (int k = n; i < m; k += n)
       {
         v[0] = (-o - (i - 1) * e);
         int j = 1;
         for (int l = k + 1; j < n; l++)
         {
           float similarityScore = matrix[a1[(i - 1)]][a2[(j - 1)]];

           f = vDiagonal + similarityScore;
           if (h - e >= v[(j - 1)] - o)
           {
             h -= e;
             lengthOfHorizontalGap++;
           }
           else
           {
             h = v[(j - 1)] - o;
             lengthOfHorizontalGap = 1;
           }
           if (g[j] - e >= v[j] - o)
           {
             g[j] -= e;
             lengthOfVerticalGap[j] += 1;
           }
           else
           {
             v[j] -= o;
             lengthOfVerticalGap[j] = 1;
           }
           vDiagonal = v[j];
           v[j] = maximum(f, g[j], h);
           if (v[j] > maximumScore)
           {
             maximumScore = v[j];
             maxi = i;
             maxj = j;
           }
           if (v[j] == f)
           {
             pointers[l] = 2;
           }
           else if (v[j] == g[j])
           {
             pointers[l] = 3;
             lengths[l] = ((short)lengthOfVerticalGap[j]);
           }
           else if (v[j] == h)
           {
             pointers[l] = 1;
             lengths[l] = ((short)lengthOfHorizontalGap);
           }
           j++;
         }
         h = (1.0F / -1.0F);
         vDiagonal = 0.0F;

         lengthOfHorizontalGap = 0;i++;
       }
       Cell * cell = new Cell();
       cell->set(maxi, maxj, v[(n - 1)],pointers);



       return cell;
}

Alignment NeedlemanWunschGotoh::traceback(QSequence s1, QSequence s2, SMatrix m, QVector<int> pointers, Cell *cell, QVector<short> lengths)
{
    pointers=cell->getpointers();
    QByteArray array1 = s1.toLocal8Bit();

    QByteArray array2 = s2.toLocal8Bit();
       QVector<QVector<float>> scores = m.Matrix();

        Alignment alignment;
        alignment.setScore(cell->getScore());


        int maxlen = s1.length() + s2.length();

        QByteArray  reversed1;
        QByteArray  reversed2;
        QByteArray  reversed3;

        int len1 = 0;
        int len2 = 0;
        int len3 = 0;

        int identity = 0;
        int similarity = 0;
        int gaps = 0;
 int k ;
    char c1,c2;

        int i = cell->getRow();
        int j = cell->getCol();
        int n = s2.length() + 1;
        int row = i * n;

        int a = s1.length() - 1;
        int b = s2.length() - 1;
        if (a - i > b - j)
        {
          for (; a - i > b - j; a--)
          {
            reversed1[(len1++)] = array1[a];
            reversed2[(len2++)] = '-';
            reversed3[(len3++)] = ' ';
            gaps++;
          }
          for (; b > j - 1; b--)
          {
            char c1 = array1[a];
            char c2 = array2[b];

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
            a--;
          }
        }
        for (; b - j > a - i; b--)
        {
          reversed1[(len1++)] = '-';
          reversed2[(len2++)] = array2[b];
          reversed3[(len3++)] = ' ';
          gaps++;
        }
        for (; a > i - 1; b--)
        {
          char c1 = array1[a];
          char c2 = array2[b];

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
          a--;
        }
        bool stillGoing = true;
        while (stillGoing)
        {
          int l = row + j;
          switch ((int)pointers[l])
          {
          case 3:
             k = 0;
            for (int len = lengths[l]; k < len; k++)
            {
              reversed1[(len1++)] = array1[(--i)];
              reversed2[(len2++)] = '-';
              reversed3[(len3++)] = ' ';
              row -= n;
              gaps++;
            }
            break;
          case 2:
             c1 = array1[(--i)];
             c2 = array2[(--j)];
            reversed1[(len1++)] = c1;
            reversed2[(len2++)] = c2;
            row -= n;
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
             k = 0;
            for (int len = lengths[l]; k < len; k++)
            {
              reversed1[(len1++)] = '-';
              reversed2[(len2++)] = array2[(--j)];
              reversed3[(len3++)] = ' ';
              gaps++;
            }
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

QByteArray  NeedlemanWunschGotoh::reverse(QByteArray a, int len)
{
    QByteArray b;
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }
    return b;
}

float  NeedlemanWunschGotoh::maximum(float a, float b, float c)
{
    if (a > b) {
         return a > c ? a : c;
       }
    return b > c ? b : c;
}

} // namespace BioQt

