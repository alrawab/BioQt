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



#ifndef URL_H
#define URL_H

#include <BioQt_global.h>
#include <QtCore>

namespace BioQt {

/**
*BioQt::Url
*@author Usama S Erawab
*
*/

enum UrlType {
    Url_File,
    Url_Http,//todo
    Url_Ftp //todo

};


class BIOQTSHARED_EXPORT Url
{
public:

    // constructs empty url. The default type -> file
       Url(){type = Url_File;}

       // constructs url specified by string. The type is parsed
       Url(const QString& urlString);

       // constructs url specified by string. The type provided as param
       Url(const QString& urlString, const UrlType type);

       Url(const Url& anotherUrl);

       bool operator ==(const Url& url) const;

       bool operator !=(const Url& url) const;

       const QString& getURLString() const {return urlString;}

       UrlType getType() const {return type;}

       bool isEmpty() const {return urlString.isEmpty();}

       bool isLocalFile() const {return type == Url_File;}

       bool isHyperLink() const {return type == Url_Http;}



       QString dirPath() const;

       QString fileName() const;

       QString baseFileName() const;

       QString lastFileSuffix() const;

       QString completeFileSuffix() const;

       static UrlType getURLType(const QString& rawUrl);
private:
    static bool registerMeta;
    QString     urlString;
    UrlType    type;
};
QDataStream &operator<<(QDataStream &out, const Url &myObj);
QDataStream &operator>>(QDataStream &in, Url &myObj);

} // namespace BioQt
Q_DECLARE_METATYPE(BioQt::Url);
#endif // BIOQT_URL_H
