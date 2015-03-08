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
*BioQt::GenBankMetadata
*@author Usama S Erawab
*
*/

#include "GenBankMetadata.h"


namespace BioQt {

GenBankMetadata::GenBankMetadata()
{
}

/*QList<FeatureItem> GenBankMetadata::GetFeatures(int startPosition, int endPosition)
{
    return GetFeatures(QString(), startPosition, endPosition);
}*/

/*QList<FeatureItem> GenBankMetadata::GetFeatures(const QString &accession, int startPosition, int endPosition)throw(BioQtException)
{
   if (startPosition > endPosition)
       throw BioQtException("GenBankMetadata::BioQtException Invalid StartNEnd Positions");
   QList<FeatureItem> features;

   Q_FOREACH(FeatureItem feature , Features)
   {
       if (startPosition <= feature.location.length &&feature.location.startPos)
       {
           if(accession.isEmpty()&& feature.location.a)
       }

   }
}*/

} // namespace BioQt
