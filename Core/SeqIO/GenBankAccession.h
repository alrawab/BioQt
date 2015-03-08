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
*BioQt::GenBankAccession
*@author Usama S Erawab
*
*/

#ifndef GENBANKACCESSION_H
#define GENBANKACCESSION_H

#include <BioQt_global.h>
#include <QtCore>

namespace BioQt {
/**
 * @brief The GenBankAccession class Accession is identifier assigned to each GenBank sequence record.
 * It contains primary accession number and may contain secondary accession numbers.
 */
class BIOQTSHARED_EXPORT GenBankAccession
{
public:
    GenBankAccession(){}
    /**
     * @brief Secondary List of secondary accession numbers.
     */
    QStringList Secondary;
    /**
     * @brief Primary accession number.
     */
    QString Primary;
    /**
     * @brief Contains Validates whether the specified accession number is present in
     * this Accession as primary or secondary accession number.
     * @param accession
     * @return
     */
    bool Contains(const QString & accession)
    {
        if(Primary ==accession)return true;
        Q_FOREACH(QString p,Secondary )
        {
            if(p==accession)return true;

        }
    return false;
}
};

} // namespace BioQt

#endif // BIOQT_GENBANKACCESSION_H
