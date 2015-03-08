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
*BioQt::CrossReferenceLink
*@author Usama S Erawab
*
*/

#ifndef CROSSREFERENCELINK_H
#define CROSSREFERENCELINK_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/SeqInfo.h>
#include "CrossReferenceLink.h"


namespace  BioQt {
/**
 * @brief The CrossReferenceLink class CrossReferenceLink provides cross-references
 * to resources that support the existence a sequence record, such as the Project Database and the NCBI
 * Trace Assembly Archive.
 */
class BIOQTSHARED_EXPORT CrossReferenceLink
{
public:
    CrossReferenceLink(){}



    /**
     * @brief Type A CrossReferenceType specifies whether the DBLink is
     * referring to project or a Trace Assembly Archive.
     */
    CrossReferenceType Type;
    /**
     * @brief Numbers  Project numbers.
     */
    QStringList Numbers;
};

} // namespace BioQt

#endif // BIOQT_CROSSREFERENCELINK_H
