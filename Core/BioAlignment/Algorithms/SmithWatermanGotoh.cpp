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

#include "SmithWatermanGotoh.h"
#include <BioAlignment/SubstMatrix/Cell.h>




namespace BioQt {





Alignment SmithWatermanGotoh::align(const QSequence &seq1, const QSequence &seq2, SMatrix matrix, float _OpenGapPenalty, float _ExtendGapPenalty)
{

    QVector<QVector<float>> scores =matrix.Matrix();
    int m = seq1.length() + 1;
    int n = seq2.length() + 1;
    QVector<int> pointers(m*n);

    QVector<short> sizesOfVerticalGaps(m * n);
    QVector<short> sizesOfHorizontalGaps(m * n);

    int i = 0;
    for (int k = 0; i < m; k += n)
    {
        for (int j = 0; j < n; j++)
        {
            /*int lambda = 1;*/sizesOfHorizontalGaps[(k + j)] = sizesOfVerticalGaps[(k + j)] =1;// lambda;
        }
        i++;
    }

    Cell * cell = construct(seq1, seq2, scores, _OpenGapPenalty, _ExtendGapPenalty, pointers, sizesOfVerticalGaps, sizesOfHorizontalGaps);
    Alignment alignment= traceback(seq1, seq2, matrix, pointers, cell, sizesOfVerticalGaps, sizesOfHorizontalGaps);


    alignment.setOriginalSequence1(seq1);
    alignment.setOriginalSequence2(seq2);
    alignment.setMatrix(matrix);
    alignment.setOpen(_OpenGapPenalty);
    alignment.setExtend(_ExtendGapPenalty);

    return alignment;

}

Cell * SmithWatermanGotoh::construct(QSequence seq1, QSequence seq2, QVector<QVector<float> > matrix, float _OpenGapPenalty, float  _ExtendGapPenalty, QVector<int> pointers, QVector<short> sizesOfVerticalGaps, QVector<short> sizesOfHorizontalGaps)
{

    QByteArray a1 = seq1.toLocal8Bit();

    QByteArray a2 = seq2.toLocal8Bit();

    int m = seq1.length() + 1;
    int n = seq2.length() + 1;
    QVector<float> g(n);
    QVector<float> v(n);

    g[0] = (1.0F / -1.0F);
    float h = (1.0F / -1.0F);
    v[0] = 0.0F;
    Cell * cell = new Cell();

    int i = 1;
    for (int k = n; i < m; k += n)
    {
        h = (1.0F / -1.0F);
        float vDiagonal = v[0];
        int j = 1;
        for (int l = k + 1; j < n; l++)
        {
            float similarityScore = matrix[a1[(i - 1)]][a2[(j - 1)]];


            float f = vDiagonal + similarityScore;

            float g1 = g[j] -  _ExtendGapPenalty;
            float g2 = v[j] - _OpenGapPenalty;
            if (g1 > g2)
            {
                g[j] = g1;
                sizesOfVerticalGaps[l] = ((short)(sizesOfVerticalGaps[(l - n)] + 1));
            }
            else
            {
                g[j] = g2;
            }
            float h1 = h -  _ExtendGapPenalty;
            float h2 = v[(j - 1)] - _OpenGapPenalty;
            if (h1 > h2)
            {
                h = h1;
                sizesOfHorizontalGaps[l] = ((short)(sizesOfHorizontalGaps[(l - 1)] + 1));
            }
            else
            {
                h = h2;
            }
            vDiagonal = v[j];
            v[j] = maximum(f, g[j], h, 0.0F);
            if (v[j] == 0.0F) {
                pointers[l] = 0;
            } else if (v[j] == f) {
                pointers[l] = 2;
            } else if (v[j] == g[j]) {
                pointers[l] = 3;
            } else {
                pointers[l] = 1;
            }
            if (v[j] > cell->getScore()) {
                cell->set(i, j, v[j],pointers);
            }
            j++;
        }
        i++;
    }


    return cell;
}

Alignment SmithWatermanGotoh::traceback(QSequence seq1, QSequence seq2, SMatrix m, QVector<int> pointers, Cell *cell, QVector<short> sizesOfVerticalGaps, QVector<short> sizesOfHorizontalGaps)
{
pointers=cell->getpointers();

    QByteArray a1 = seq1.toLocal8Bit();
    QByteArray a2 = seq2.toLocal8Bit();

    QVector<QVector<float>> scores = m.Matrix();

    int n = seq2.length() + 1;

    Alignment alignment;
    alignment.setScore(cell->getScore());

    int maxlen = seq1.length() + seq2.length();


    QByteArray  reversed1;//(maxlen,' ');
    QByteArray  reversed2;//(maxlen,' ');
    QByteArray  reversed3;//(maxlen,' ');

    int len1 = 0;
    int len2 = 0;
    int len3 = 0;

    int identity = 0;
    int similarity = 0;
    int gaps = 0;

    char c1,c2;


    int i = cell->getRow();

    int j = cell->getCol();
    int k = i * n;

    bool stillGoing = true;
    while (stillGoing) {

        switch ( (pointers[k + j])) {
        case 3:
            for (int l = 0, len = sizesOfVerticalGaps[k + j]; l < len; l++) {

                reversed1[len1++] = a1[--i];
               reversed2[len2++] = '-';
               reversed3[len3++] = ' ';
                k -= n;
                gaps++;
            }
            break;
        case 2:
            c1 = a1[--i];
            c2 = a2[--j];
            k -= n;

            reversed1[len1++] = c1;
            reversed2[len2++] = c2;
            if (c1 == c2) {
                reversed3[len3++] = '|';
                identity++;
                similarity++;
            } else if (scores[c1][c2] > 0.0) {
                reversed3[len3++] = ':';
                similarity++;
            } else {
                reversed3[len3++] = '.';
            }
            break;
        case 1:

            for (int l = 0, len = sizesOfHorizontalGaps[k + j]; l < len; l++) {
                reversed1[len1++] = ' ';
                reversed2[len2++] = a2[--j];

                reversed3[len3++] = ' ';
                gaps++;
            }
            break;
        case 0:

            stillGoing = false;


        }
    }
reversed1;
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


float SmithWatermanGotoh::maximum(float a, float b, float c, float d)
{
    if (a > b) {
        if (a > c) {
            return a > d ? a : d;
        } else {
            return c > d ? c : d;
        }
    }
    else if (b > c) {
        return b > d ? b : d;
    } else {
        return c > d ? c : d;
    }
}

QByteArray SmithWatermanGotoh::reverse(QByteArray a, int len)
{


    QByteArray b;//(len,' ');
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }
    return b;
}




} // namespace BioQt

