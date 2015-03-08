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
*bioQt::FeatureItem
*@author Usama S Erawab
*
*/

#ifndef FEATUREITEM_H
#define FEATUREITEM_H

#include <BioQt_global.h>
#include <QtCore>
#include <Utils/Location.h>

namespace BioQt {
/**
 * @brief The FeatureItem class All qualifiers of the feature will be stored as sub items.
 */
class BIOQTSHARED_EXPORT FeatureItem
{
public:
    /**
     * @brief FeatureItem Creates new feature item with given key and location.
     * @param _key
     * @param _location
     */
    FeatureItem(const QString& _key,const QString& _location):Key(_key),location(_location){}

   // FeatureItem(const QString& _key,Location _location);


    QString Key;
    QString location;

    QMap<QString, QList<QString>> Qualifiers  ;

};

} // namespace bioQt

#endif // BIOQT_FEATUREITEM_H
