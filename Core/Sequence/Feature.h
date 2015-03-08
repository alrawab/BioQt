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
*BioQt::Feature
*@author Usama S Erawab
*
*/

#ifndef BIOQT_FEATURE_H
#define BIOQT_FEATURE_H
#include <BioQt_global.h>
#include <QtCore>
#include <QtGlobal>

namespace BioQt {
//idiots and make no sense FIXME//OSAMA

struct BIOQTSHARED_EXPORT Feature
{
public:

   static bool isValid( const QVariantMap& map ) {
        return hasName( map );
    }


   static QString getName( const QVariantMap& map ) {
       return getValue( NAME, map ).toString();
   }

  static  void setName( QVariantMap& map, const QString& name ) {
      setValue( map, NAME, name );
  }

  static  bool hasName( const QVariantMap& map ) {
      return !getName( map ).isEmpty();
  }



  static QVariant getValue( const QString& tag, const QVariantMap& map ) {
      return map.value( tag );
  }

  static void setValue( QVariantMap& map, const QString& tag, const QVariant& val ) {
      Q_ASSERT( !tag.isEmpty() );
      if( !val.isNull() ) {
          map.insert( tag, val );
      }
  }



     static const QString NAME;
};
const QString Feature::NAME= "NAME";
//------------------------------------------------------------


} // namespace BioQt

#endif // BIOQT_FEATURE_H
