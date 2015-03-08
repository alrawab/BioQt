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



#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QtCore/QBitArray>
#include <QtCore/QSet>
#include <QtCore/QVector>
#include <assert.h>
#include <BioQt_global.h>
#include "IOAdapter.h"
#include "LocalFileAdapter.h"
#include "ZlibAdapter.h"
#include "Url.h"

namespace BioQt {

/**
*BioQt::FileUtils
*@author Usama S Erawab
*
*/
class BIOQTSHARED_EXPORT FileUtils
{
public:
    static const QBitArray WHITES;
    static const QBitArray LINE_BREAKS;
    static const QBitArray BINARY;
    static QBitArray createBitMap(char c1);
     static bool contains(const QBitArray& map, const char* str, int len);
     static bool equals(const char* str1, const char* str2, int n);

     static std::auto_ptr<IOAdapter> GetAdaptor(bool ft=false);
     static bool IsCompresed(const QString &fn);

     static int remove(const char* srcSeq, int len, char* dstSeq, const QBitArray& removeMap);

    inline static int remove(char* srcSeq, int len, const QBitArray& removeMap) {return remove(srcSeq, len, srcSeq, removeMap);}






};

} // namespace BioQt

#endif // BIOQT_FILEUTILS_H
