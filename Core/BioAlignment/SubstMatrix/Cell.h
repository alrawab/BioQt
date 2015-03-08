#ifndef CELL_H
#define CELL_H

#include <limits>
#include <QtCore>
#include <Math/bioqtmath.h>
namespace BioQt {
class BIOQTSHARED_EXPORT Cell
{
public:
    Cell();
    /**
            * @return Returns the col.
            */
            int getCol() {
               return col;
           }
           /**
            * @param col The col to set.
            */
           void setCol(int _col) {
               col = _col;
           }
           /**
            * @return Returns the row.
            */
            int getRow() {
               return row;
           }
           /**
            * @param row The row to set.
            */
          void setRow(int _row) {
               row = _row;
           }
           /**
            * @return Returns the score.
            */
            float getScore() {
               return score;
           }
           /**
            * @param score The score to set.
            */
           void setScore(float _score) {
               score = _score;
           }

           /**
            * Sets the row, column and score of the cell.
            * @param row The row to set.
            * @param col The col to set.
            * @param score The score to set.
            */
           void set(int _row, int _col, float _score) {
               row = _row;
               col = _col;
               score = _score;
           }
 QVector<int> getpointers()
{
    return pointers;
}

 QVector<QVector<float> > getpointer()
{
    return pointer;
}
           void set(int _row, int _col, float _score, QVector<int>  _pointers) {
               row = _row;
               col = _col;
               score = _score;
               pointers=_pointers;
           }

           void set(int _row, int _col, float _score, QVector<QVector<float> > _pointer) {
               row = _row;
               col = _col;
               score = _score;
               pointer=_pointer;
           }
private:
    /**
     * Row of the cell
     */
    int row;
    /**
     * Column of the cell
     */
    int col;
    /**
     * Alignment score at this cell
     */
    float score;
     QVector<int>  pointers;
     QVector<QVector<float> > pointer;

};
}
#endif // CELL_H
