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
*BioQt::Location
*@author Usama S Erawab
*
*/

#include "Location.h"

namespace BioQt {

QVector<Location> Location::join(QVector<Location>& locations)  {
    QVector<Location> result = locations;
    qStableSort(result.begin(), result.end()); //sort by location start pos first
    for (int i = 0; i < result.size()-1;) {
        const Location& ri0 = result[i];
        const Location& ri1 = result[i+1];
        if (!ri0.intersects(ri1)) {
            i++;
            continue;
        }
        Location newRi = containinglocation(ri0, ri1);
        result[i] = newRi;
        result.remove(i+1);
    }
    return result;
}

void Location::bound(qint64 minPos, qint64 maxPos, QVector<Location>& locations) {
    for (int i = 0, n = locations.size(); i < n; i++) {
        Location& r = locations[i];
        int start = qBound(minPos, r.startPos, maxPos);
        int end = qBound(minPos, r.endPos(), maxPos);
        r.startPos = start;
        r.length = end - start;
    }
}

void Location::mirror(qint64 mirrorPos, QVector<Location>& locations) {
    for (int i = 0, n = locations.size(); i < n; i++) {
        Location& r = locations[i];
        Q_ASSERT(r.endPos() <= mirrorPos);
        r.startPos = mirrorPos - r.endPos();
    }
}

void Location::divide(qint64 div, QVector<Location>& locations) {
    for (int i = 0, n = locations.size(); i < n; i++) {
        Location& r = locations[i];
        r.startPos = r.startPos / div;
    }
}

void Location::multiply(qint64 mult, QVector<Location>& locations) {
    for (int i = 0, n = locations.size(); i < n; i++) {
        Location& r = locations[i];
        r.startPos = r.startPos * mult;
    }
}

void Location::reverse(QVector<Location>& locations) {
    QVector<Location> old = locations;
    locations.clear();
    foreach(const Location& r, old) {
        locations.prepend(r);
    }
}

void Location::shift(qint64 offset, QVector<Location>& locations) {
    QVector<Location> res;
    for (int i = 0, n = locations.size(); i < n; i++) {
        Location& r = locations[i];
        r.startPos += offset;
    }
}

int Location::findIntersectedlocation(const QVector<Location>& rs) const {
    for (int i = 0, n = rs.size(); i < n; i++) {
        const Location& r = rs[i];
        if (intersects(r)) {
            return i;
        }
    }
    return -1;
}


int Location::findOverlappinglocation(const QVector<Location>& rs) const {
    for (int i = 0, n = rs.size(); i < n; i++) {
        const Location& r = rs[i];
        if (r.contains(*this)) {
            return i;
        }
    }
    return -1;
}

void Location::removeAll(QVector<Location>& locationsToProcess, const QVector<Location>& locationsToRemove) {
    QVector<Location> result;
    foreach(const Location& pr, locationsToProcess) {
        if (locationsToRemove.indexOf(pr) == -1) {
            result.append(pr);
        }
    }
    locationsToProcess = result;
}



static bool _registerMeta() {
    qRegisterMetaType<Location>("Location");
    qRegisterMetaTypeStreamOperators<Location>("BioQt::Location");

    qRegisterMetaType<QVector<Location> >("QVector<BioQt::Location>");
    qRegisterMetaTypeStreamOperators< QVector<Location> >("QVector<BioQt::Location>");
    return true;
}

bool Location::registerMeta = _registerMeta();

QDataStream &operator<<(QDataStream &out, const Location &myObj) {
    out << myObj.startPos << myObj.length;
    return out;
}

QDataStream &operator>>(QDataStream &in, Location &myObj) {
    in >> myObj.startPos;
    in >> myObj.length;
    return in;
}

} // namespace BioQt
