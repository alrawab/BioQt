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



#ifndef  LOCATION_H
#define  LOCATION_H

#include <BioQt_global.h>
#include <QtCore>



namespace BioQt {
/**
*BioQt::Location
*@author Usama S Erawab
*
*/

/**
 * @brief The Location class  A set of integers, often used to represent positions on biological sequences
 *
 */


class BIOQTSHARED_EXPORT Location {
public:
    Location(): startPos(0), length(0){}
    Location(qint64 s, qint64 l): startPos(s), length(l){}

    /** location start position. */
    qint64 startPos;

    /** location length. */
    qint64 length;

    ////////////////////////// Member functions and operators ////////////////////

    /** location end position, exclusive. */
    qint64 endPos() const {return startPos + length;}

    /** Central point of the location. */
    qint64 center() const { return startPos + length / 2 ;}

    /** Checks if this location has zero length. */
    bool isEmpty() const {return length == 0; }

    /** Checks whether the specified point falls inside this location. */
    bool contains(qint64 pos) const {return pos>=startPos && pos < endPos();}

    /** Checks whether the specified location fits inside this location or is equal. */
    bool contains(const Location& r) const {return r.startPos >= startPos && r.endPos() <= endPos();}

    /** Checks whether the specified location has common points with this location. */
    bool intersects(const Location& r) const;

    /** Returns the intersection between 2 locations, or empty value if locations do not intersect. */
    Location intersect(const Location& r) const;

    /**
        Checks whether this location has common points with any location in the specified list.
        Returns the index of the first location found or -1 if no matches found
    */
    int findIntersectedlocation(const QVector<Location>& rs) const;

    /**
        Checks whether this location has common points with any location in the specified list.
        Returns the index of the first location found or -1 if no matches found
    */
    bool intersects(const QVector<Location>& rs) const {return findIntersectedlocation(rs) != -1;}

    /**
        Checks whether this location is located inside of any location in the specified list.
        Returns the index of the first location found or -1 if no matches found
    */
    int findOverlappinglocation(const QVector<Location>& locations) const;

    /** Checks if the specified location is equal to this location. */
    bool operator== ( const Location & r ) const { return r.startPos == startPos && r.length == length; }

    /** Checks whether the specified location is not equal to this location. */
    bool operator!= ( const Location & r ) const { return r.startPos != startPos || r.length != length; }

    /** Compares 2 locations by start position.
    Returns true if this location starts strictly earlier than the specified one. */
    bool operator<(const Location &r) const {return startPos < r.startPos;}




    ///////////////////////// Class functions /////////////////////////////////

    /** Returns least common location which contains both of the 2 specified locations. */
    static Location containinglocation(const Location& r1, const Location& r2);

    /** Returns least common location which contains all of the specified locations. */
    static Location containinglocation(const QVector<Location>& locations);

    /** Normalizes the specified list by joining overlapping locations.
    This function sorts locations by starting position then
    iterates through them and replaces all groups of intersecting locations by containing locations.
    */
    static QVector<Location> join(QVector<Location>& locations);

    /** Fixes start & len for all locations to ensure that the result location
        has startPos >= minPos & endPos <= maxPos
     */
    static void bound(qint64 minPos, qint64 maxPos, QVector<Location>& locations);

    /** mirrors locations by mirror pos: startPos = mirrorPos - startPos */
    static void mirror(qint64 mirrorPos, QVector<Location>& locations);

    /** divides locations by  div : startPos = startPos / div */
    static void divide(qint64 div, QVector<Location>& locations);

    /** multiplies locations by  mult : startPos = startPos * mult */
    static void multiply(qint64 mult, QVector<Location>& locations);

    /** Reverses order of locations in the list */
    static void reverse(QVector<Location>& locations);

    /** shifts locations by offset pos: startPos = startPos + offset */
    static void shift(qint64 offset, QVector<Location>& locations);

    /** Removes all items from 'locationsToRemove' from 'locationsToProcess'*/
    static void removeAll(QVector<Location>& locationsToProcess, const QVector<Location>& locationsToRemove);

private:
    static bool registerMeta;
};

//////////////////// inline implementations ///////////////////////////

inline bool Location::intersects(const Location& r) const {
    qint64 sd = startPos - r.startPos;
    return (sd >= 0) ? (sd < r.length) : (-sd < length);
}

inline Location Location::intersect(const Location& r) const {
    qint64 newStart = qMax(startPos, r.startPos);
    qint64 newEnd = qMin(endPos(), r.endPos());
    if (newStart > newEnd) {
        return Location();
    }
    return Location(newStart, newEnd - newStart);
}


inline Location Location::containinglocation(const Location& r1, const Location& r2) {
    qint64 newStart = qMin(r1.startPos, r2.startPos);
    qint64 newEnd = qMax(r1.endPos(), r2.endPos());
    return Location(newStart, newEnd - newStart);
}

inline Location Location::containinglocation(const QVector<Location>& locations) {
    Q_ASSERT(!locations.isEmpty());

    Location res = locations.first();
    foreach(const Location& r, locations) {
        res = containinglocation(res, r);
    }
    return res;
}

 BIOQTSHARED_EXPORT QDataStream &operator<<(QDataStream &out, const Location &myObj);
 BIOQTSHARED_EXPORT QDataStream &operator>>(QDataStream &in, Location &myObj);

} // namespace BioQt

Q_DECLARE_TYPEINFO(BioQt::Location, Q_PRIMITIVE_TYPE);
Q_DECLARE_METATYPE( BioQt::Location)
Q_DECLARE_METATYPE( QVector< BioQt::Location >)

#endif // BIOQT_LOCATION_H
