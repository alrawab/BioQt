/*****************************************************************************************
                        BioQt - Integrated Bioinformatics Library
Copyright (C) 2012-2013 Usama S Erawab <alrawab@hotmail.com>
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
#ifndef CHECKSUM_H
#define CHECKSUM_H
#include "../../BioQt_global.h"
#include <QtCore>

namespace BioQt
{

/**
 *@brief CheckSum Class
 *@details Various types of checksums implementation
 *@author    Usama S Erawab <alrawab@hotmail.com>
 */
class BIOQTSHARED_EXPORT  CheckSum
{

public:
    /**
     * @brief Crc32 Implementation  operating on safe QByteArray
     * @param seq Sequence
     * @return sequence Crc32 CheckSum
     */
    static const quint32 Crc32( const QByteArray& seq);
    /**
         * @brief seguid ported form Biopython
         *Returns the SEGUID for a sequence .
         *Given a nucleotide or amino-acid secuence (or any string),
         *returns the SEGUID string (A SEquence Globally Unique IDentifier).
         *seq type = str.
         *For more information about SEGUID, see:
         *http://bioinformatics.anl.gov/seguid/
         *DOI: 10.1002/pmic.200600032
         * @param seq sequence to get it's SEGUID
         * @return SEGUID QByteArray
         */
        static const  QByteArray seguid(const QByteArray & seq);
        /**
           * @brief GCG ported form Biopython
           *Returns the GCG checksum (int) for a sequence
           * Given a nucleotide or amino-acid secuence (or any string),
           *returns the GCG checksum (int). Checksum used by GCG program.
           *Based on BioPerl GCG_checksum.
           * @param seq sequence to get it's GCG
           * @return GCG as int
           */
          static const  int GCG(const QByteArray &seq);
          /**
           * @brief Crc64 Implementation  operating on safe QByteArray
           * @param seq Sequence
           * @return sequence Crc64 CheckSum
           */
           static const QString Crc64HexString(const QByteArray & seq);





};
}

#endif // CHECKSUM_H
