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
*BioQt::FileUtils
*@author Usama S Erawab
*
*/

#include "FileUtils.h"

namespace BioQt {

static QBitArray getWhites();
static QBitArray getLines();
static QBitArray getBinary();
const QBitArray  FileUtils::WHITES = getWhites();
const QBitArray FileUtils::LINE_BREAKS = getLines();
const QBitArray  FileUtils::BINARY = getBinary();


static QBitArray getEmptyBitMap() {
    return QBitArray(256);
}


static QBitArray getWhites() {
    //'\t', '\n', '\v', '\f', '\r', and ' '
    QBitArray res = getEmptyBitMap();
    res['\t']=res['\n']=res['\v']=res['\f']=res['\r']=res[' ']=true;
    return res;
}

QBitArray getLines() {
    QBitArray res = getEmptyBitMap();
    res['\r'] = res['\n'] = true;
    return res;
}

QBitArray FileUtils::createBitMap(char c1) {
    QBitArray res = getEmptyBitMap();
    res[c1] = true;
    return res;
}

int FileUtils::remove(const char* srcSeq, int srcLen, char* dstSeq, const QBitArray& removeMap) {
   int dstLen = 0;
   for (int i=0;i<srcLen;i++) {
       unsigned char c = srcSeq[i];
       if (!removeMap[c]) {
           dstSeq[dstLen] = c;
           dstLen++;
       }
   }
   return dstLen;
}

static QBitArray getBinary() {
    QBitArray res = getEmptyBitMap();
    res.fill(true, 0, 31);
    res &= ~getWhites();
    return res;
}


 bool FileUtils::contains(const QBitArray& map, const char* str, int len) {
    for(int i=0; i<len; i++) {
        unsigned char c = str[i];
        if (map[c]) {
            return true;
        }
    }
    return false;
}


 bool FileUtils::equals(const char* str1, const char* str2, int n) {
    assert(n>0);
    if (str1[0] != str2[0]) {
        return false;
    }
    for(int i=1; i<n; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
 }

 std::auto_ptr<IOAdapter> FileUtils::GetAdaptor(bool ft)
 {
     if(ft)
         return std::auto_ptr<IOAdapter> (new ZlibAdapter(new LocalFileAdapter()));
     return          std::auto_ptr<IOAdapter> (new LocalFileAdapter());
 }

 bool FileUtils::IsCompresed(const QString &fn)
 {
     if(fn.endsWith(".gz"))
         return true;
     return false;
 }


} // namespace BioQt
