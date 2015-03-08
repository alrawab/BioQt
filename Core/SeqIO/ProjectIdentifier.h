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
*BioQt::ProjectIdentifier
*@author Usama S Erawab
*
*/

#ifndef PROJECTIDENTIFIER_H
#define PROJECTIDENTIFIER_H

#include <BioQt_global.h>
#include <QtCore>

namespace BioQt {
/**
 * @brief The ProjectIdentifier class The identifier of a project (such as a Genome Sequencing Project)
 * to which a GenBank sequence record belongs.
 * This is obsolete and was removed from the GenBank flat file format
 *  after Release 171.0 in April 2009.
 */
class BIOQTSHARED_EXPORT ProjectIdentifier
{
public:
    ProjectIdentifier(){}
      ProjectIdentifier(const QString&_name,QStringList _Numbers):Name(_name),Numbers(_Numbers){}
    /**
     * @brief Numbers Project numbers.
     */
    QStringList  Numbers;
    /**
     * @brief Name Name of the project.
     */
    QString Name;
};

} // namespace BioQt

#endif // BIOQT_PROJECTIDENTIFIER_H
