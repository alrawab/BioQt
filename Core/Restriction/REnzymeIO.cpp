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
*BioQt::REnzymeIO
*@author Usama S Erawab
*
*/

#include "REnzymeIO.h"

namespace BioQt {


QVector<REnzyme> REnzymeIO::LoadEnzymes(const QString &path)throw(FileNotFoundException)
{

    QVector<REnzyme> res;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw FileNotFoundException("BiQt::REnzymeIO FileNotFoundException Unalbe to load File : "+path);

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if(line.isEmpty()||line.startsWith("#"))
            continue;
        QStringList TOKEN=line.split("\t",QString::SkipEmptyParts);
        Q_ASSERT(TOKEN.size()==9);
        res.push_back(REnzyme(TOKEN[0],
                              TOKEN[1],
                              TOKEN[2].toInt(),
                              TOKEN[3].toInt(),
                        (bool)TOKEN[4].toInt(),
                              TOKEN[5].toInt(),
                              TOKEN[6].toInt(),
                              TOKEN[7].toInt(),
                              TOKEN[8].toInt()));


    }
    return res;
}

} // namespace BioQt
