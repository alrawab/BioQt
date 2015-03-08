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



#include "Url.h"

namespace BioQt {

static QString makeFilePathCanonical(const QString& originalUrl) {
    //ensure that name is canonical
    QString result = originalUrl.trimmed();

    QString fileUrlPrefix = "file://";
    if(result.startsWith(fileUrlPrefix)) {
        result = result.mid(fileUrlPrefix.length());
#ifdef Q_OS_WIN
        // on Windows, all slashes after "file:" can be trimmed, on Unix/Mac one must be kept to specify that it's an absolute path
        while(result.startsWith("/")) {
            result = result.mid(1);
        }
#endif
    }

    // Windows drive letter, Qt resource designation or Samba share designation and name
    QString prefix;

    if(originalUrl.startsWith(':')) { // is a Qt resource
        prefix = ":";
        result = result.mid(1);
    } else {
        result = QFileInfo(result).absoluteFilePath();
    }

#ifdef Q_OS_WIN
    bool isSambaPath = false;
    if(result.startsWith("//") && prefix.isEmpty()) {
        // keep Samba share designation
        prefix = "//";
        isSambaPath = true;
    }
#endif

    QStringList parts = result.split('/', QString::SkipEmptyParts);
    if(parts.size() > 0) {
        QStringList canonicalParts;
#ifdef Q_OS_WIN
        // append drive spec letter or Samba server name to the prefix
        if(isSambaPath) {
            prefix += parts.takeFirst();
        } else if(parts.at(0).endsWith(':') && parts.at(0).length() == 2 && prefix.isEmpty()) { // Windows drive letter designation
            prefix = parts.takeFirst();
        }
#endif
        // get rid of redundant '.' and '..' now
        QStringListIterator it(parts);
        while(it.hasNext()) {
            QString part = it.next();
            if(part == ".") {
                continue;
            } else if(part == "..") {
                if(!canonicalParts.isEmpty()) {
                    canonicalParts.removeLast();
                }
            } else if (!part.isEmpty()) {
                canonicalParts.append(part);
            }
        }
        result = prefix + "/" + canonicalParts.join("/");
    }


    return result;
}


UrlType Url::getURLType(const QString& rawUrl) {
    UrlType result = Url_File;
    if (rawUrl.startsWith("http://") || rawUrl.startsWith("https://")) {
        result = Url_Http;
    } else if (rawUrl.startsWith("ftp://")) {
        result = Url_Ftp;
    }
    return result;
}

// constructs url specified by string. The type is parsed
Url::Url(const QString& _urlString) {
    urlString = _urlString;
    type = getURLType(urlString);
    if (type == Url_File) {
        urlString = makeFilePathCanonical(urlString);
    }
}


// constructs url specified by string. The type provided as param
Url::Url(const QString& _urlString, const UrlType _type) {
    urlString = _urlString;
    type = _type;
    if (type == Url_File) {
        urlString = makeFilePathCanonical(urlString);
    }
}

Url::Url(const Url& anotherUrl) {
    urlString = anotherUrl.getURLString();
    type = anotherUrl.getType();
}

bool Url::operator ==(const Url& url) const {
    return urlString == url.getURLString();
}

bool Url::operator !=(const Url& url) const {
    return !(*this == url);
}

static QString path(const Url* url) {
    //TODO: parse HTTP and other formats for path part
    QString result;

    result = url->getURLString();
    return result;
}

QString Url::dirPath() const {
    QString result;

    result = QFileInfo(path(this)).absoluteDir().absolutePath();
    return result;
}

QString Url::fileName() const {
    QString result;

    result = QFileInfo(path(this)).fileName();
    return result;
}

QString Url::baseFileName() const {
    QString result;

        result = QFileInfo(path(this)).baseName();

    return result;
}

QString Url::lastFileSuffix() const {
    QString result;

    result = QFileInfo(path(this)).suffix();
    return result;
}

QString Url::completeFileSuffix() const {
    QString result;

    result = QFileInfo(path(this)).completeSuffix();
    return result;
}


static bool registerMetas()  {
    qRegisterMetaType<Url>("GUrl");
    qRegisterMetaTypeStreamOperators<Url>("BioQt::GUrl");

    return true;
}

QDataStream &operator<<(QDataStream &out, const Url &myObj) {
    out << myObj.getURLString() << myObj.getType();
    return out;
}

QDataStream &operator>>(QDataStream &in, Url &myObj) {
    QString urlString; in >> urlString;
    int t; in >> t;
    UrlType type = (UrlType)t;
    myObj = Url(urlString, type);
    return in;
}


bool Url::registerMeta  = registerMetas();

} // namespace BioQt
