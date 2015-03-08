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
*BioQt::GenBankVersion
*@author Usama S Erawab
*
*/

#ifndef GENBANKVERSION_H
#define GENBANKVERSION_H

#include <BioQt_global.h>
#include <QtCore>


namespace BioQt {
/**
 * @brief The GenBankVersion class  A compound identifier consisting of the primary accession number
 * and a numeric version number associated with the current version of the sequence data in the record.
 *  This is followed by an integer key (a "GI") assigned to the sequence by NCBI.
 */
class BIOQTSHARED_EXPORT GenBankVersion
{
public:
    GenBankVersion(){};
    /**
     * @brief Accession Primary accession number.
     */
    QString Accession;
    /**
     * @brief Version  Version number.
     */
    QString Version;
    /**
     * @brief CompoundAccession Gets the CompoundAccession that is Accession.Version.
     * @return
     */
    QString CompoundAccession()
    {
        return Accession + "." + Version;
    }
    /**
     * @brief GiNumber GI number.
     */
    QString GiNumber ;
};

} // namespace BioQt

#endif // BIOQT_GENBANKVERSION_H
