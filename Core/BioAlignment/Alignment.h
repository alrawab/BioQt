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

#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <QtCore>
#include <BioQt_global.h>
#include <BioAlignment/SubstMatrix/SMatrix.h>



namespace BioQt {


/**
 * Holds the output of a pairwise sequences alignment.
 *
 * @author Usama S Erawab
 */

class  BIOQTSHARED_EXPORT Alignment
{
public:
    /**
     * Constructor for Alignment
     */
    Alignment();
    ~Alignment();
    //=================================================
    /**
     * @brief format
     * @return
     */
    QByteArray format();

    /**
     * @return Returns the extend.
     */
    float getExtend() {
        return extend;
    }

    /**
     * @param extend
     *    The extend to set.
     */
    void setExtend(float _extend) {
        extend = _extend;
    }

    /**
     * @return Returns the matrix.
     */
    SMatrix getMatrix() {
        return matrix;
    }

    /**
     * @param matrix
     *   The matrix to set.
     */
    void setMatrix(SMatrix _matrix) {
        matrix = _matrix;
    }

    /**
     * @return Returns the name1.
     */
    QString getName1() {
        return   name1;
    }

    /**
     * @param name1
     *            The name1 to set.
     */
    void setName1(const QString& _name1) {
        name1 = _name1;
    }

    /**
     * @return Returns the name2.
     */
    QString getName2() {
        return  name2;
    }

    /**
     * @param name2
     *   The name2 to set.
     */
    void setName2(const QString& _name2) {
        name2 = _name2;
    }

    /**
     * @return Returns the open.
     */
    float getOpen() {
        return open;
    }

    /**
     * @param open
     *            The open to set.
     */
    void setOpen(float _open) {
        open = _open;
    }

    /**
     * @return Returns the score.
     */
    float getScore() {
        return score;
    }

    /**
     * @param score
     *            The score to set.
     */
    void setScore(float _score) {
        score = _score;
    }

    /**
     * Returns the length of the alignment
     *
     * @return Alignment length
         */
    int getLength() {
        return sequence1.size();
    }

    /**
     * @return Returns the sequence1.
     */
    QByteArray getSequence1() {
        return sequence1;
    }

    /**
     * @param sequence1
     *            The sequence1 to set.
     */
    void setSequence1(const QByteArray& _sequence1) {
        sequence1 = _sequence1;
    }

    /**
     * @return Returns the sequence2.
     */
    QByteArray getSequence2() {
        return sequence2;
    }

    /**
     * @param sequence2
     *   The sequence2 to set.
     */
    void setSequence2(const QByteArray& _sequence2) {
        sequence2 = _sequence2;
    }

    /**
     * @return Returns the start1.
     */
    int getStart1() {
        return start1;
    }

    /**
     * @param start1
     *   The start1 to set.
     */
    void setStart1(int _start1) {
        start1 = _start1;
    }

    /**
     * @return Returns the start2.
     */
    int getStart2() {
        return start2;
    }

    /**
     * @param start2
     * The start2 to set.
     */
    void setStart2(int _start2) {
        start2 = _start2;
    }

    /**
     * @return Returns the gaps.
     */
    int getGaps() {
        return gaps;
    }

    /**
     * @param gaps
     *   The gaps to set.
     */
    void setGaps(int _gaps) {
        gaps = _gaps;
    }

    /**
     * @return Returns the identity.
     */
    int getIdentity() {
        return identity;
    }

    /**
     * @param identity
     *   The identity to set.
     */
    void setIdentity(int _identity) {
        identity = _identity;
    }

    /**
     * @return Returns the markupLine.
     */
    QByteArray getMarkupLine() {
        return markupLine;
    }

    /**
     * @param markupLine
     * The markupLine to set.
     */
    void setMarkupLine(const QByteArray& _markupLine) {
        markupLine = _markupLine;
    }

    /**
     * @return Returns the similarity.
     */
    int getSimilarity() {
        return similarity;
    }

    /**
     * @param similarity
     *            The similarity to set.
     */
    void setSimilarity(int _similarity) {
        similarity = _similarity;
    }
    /**
     * Returns original Sequence #1
     *
     * @return original Sequence #1
     */
    QString getOriginalSequence1() {return originalSequence1;};


    /**
     *
     * @param originalSequence1
     */
    void setOriginalSequence1(const QString& _originalSequence1) {
        originalSequence1 = _originalSequence1;
    }

    /**
         * Returns original  Sequence #2
         *
         * @return original  Sequence #2
         */
    QString getOriginalSequence2() {
        return originalSequence2;
    }




    /**
             *
             * @param originalSequence2
             */
    void setOriginalSequence2(QString _originalSequence2) {
        originalSequence2 = _originalSequence2;
    }

    /**
              * Returns the number of gaps of the aligned sequence #1
              *
              * @return the number of gaps of the aligned sequence #1
              */
    int getGaps1();

    /**
               * Returns the number of gaps of the aligned sequence #2
               *
               * @return the number of gaps of the aligned sequence #2
               */
    int getGaps2() ;

    /**
              * Returns a summary for alignment
              *
              * @return  alignment summary
              */
    QByteArray getSummary() ;


    /**
          * Calculate the score of the alignment, not using the score field (the
          * function only uses sequence1, sequence2, matrix and gap penalties).
          *
          * @return the calculated score
          *
          */
    float calculateScore();

    /**
          * Calculate the score of the alignment without the terminal gaps.
          *
          */
    float getScoreWithNoTerminalGaps();

    /**
           * Check if the calculated score matches the field score.
           *
           * @return true if equal, else false. (By: Bram Minnaert)
           */
    bool checkScore();


private:
    /**
         * Scoring matrix
         */
    SMatrix matrix;

    /**
         * Gap open cost
         */
    float open;

    /**
         * Gap extend cost
         */
    float extend;

    /**
         * Alignment score
         */
    float score;

    /**
         * Aligned sequence #1
         */
    QByteArray sequence1;

    /**
         * Name of sequence #1
         */
    QString name1;

    /**
         * Alignment start location in sequence #1
         */
    int start1;

    /**
         * Aligned sequence #2
         */
    QByteArray sequence2;

    /**
         * Name of sequence #2
         */
    QString name2;

    /**
         * Alignment start location in sequence #2
         */
    int start2;

    /**
         * Markup line
         */
    QByteArray markupLine;

    /**
         * Count of identical locations
         */
    int identity;

    /**
         * Count of similar locations
         */
    int similarity;

    /**
         * Count of gap locations
         */
    int gaps;

    QString originalSequence1;

    QString originalSequence2;

    /**
     * Name width
     */
    int NAME_WIDTH ;

    /**
     * Position width
     */
    int POSITION_WIDTH ;

    /**
     * Sequence width
     */
    int SEQUENCE_WIDTH ;

    /**
     * Space
     */
    QString BLANK ;
    /**
     * @brief adjustName
     * @param name
     * @return
     */
    QString adjustName(QString name);
    /**
     * @brief adjustPosition
     * @param position
     * @return
     */
    QString adjustPosition(QString position);
};

} // namespace BioQt

#endif // BIOQT_ALIGNMENT_H
