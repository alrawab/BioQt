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
*BioQt::IsoelectricPoint
*@author Usama S Erawab
*
*/

#ifndef ISOELECTRICPOINT_H
#define ISOELECTRICPOINT_H

#include <BioQt_global.h>
#include <QtCore>
#include <Data/QIUPACData.h>
#include <Sequence/QSequence.h>
#include "ProteinAnalysis.h"

namespace BioQt {


class BIOQTSHARED_EXPORT IsoelectricPoint
{
public:
    enum Method
    {
        DavidTabb,
        EMBOSS,
        DTASelect,
        Solomon,
        Sillero,
        Rodwell,
        Patrickios
    };

    IsoelectricPoint(const QSequence&_seq);
    QMap<QString,double> GetPKmap(Method method);
    double PI(Method method=DavidTabb);


private:

    QSequence seq;


};

} // namespace BioQt

#endif // BIOQT_ISOELECTRICPOINT_H
