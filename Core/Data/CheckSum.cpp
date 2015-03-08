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

#include "CheckSum.h"
#include "Crc32.h"
#include <assert.h>
#include <QCryptographicHash>
#include "crc64.h"
namespace BioQt
{

const quint32 CheckSum::Crc32(const QByteArray&  seq)
{
    //assert ("Sequence can't possibly be Empty or NULL",! seq.isEmpty() || !seq.isNull());/* cannot be NULL or Empty*/
    quint32 crc=crc32buf(QByteArray(seq).data(),seq.size());
    return crc;
}

const  QByteArray  CheckSum::seguid(const QByteArray & seq)
 {
   // assert ("Sequence can't possibly be Empty or NULL",! seq.isEmpty() || !seq.isNull());/* cannot be NULL or Empty*/
     QByteArray result = QCryptographicHash::hash(QByteArray(seq).toUpper(), QCryptographicHash::Sha1).toBase64();
      while(result.endsWith('=')) result.chop(1);
      return result;

 }

const int CheckSum::GCG(const QByteArray &seq)
  {
  //  assert ("Sequence can't possibly be Empty or NULL",! seq.isEmpty() || !seq.isNull());/* cannot be NULL or Empty*/
      int index =0;
              int checksum = 0;
      foreach(QChar chr,seq)
      {
          index += 1;
                  checksum += index *(int)chr.toUpper().toAscii();
                  if(index==57)
                      index=0;

      }
      return checksum % 10000;
  }

const QString CheckSum::Crc64HexString(const QByteArray & seq)

{
  //  assert ("Sequence can't possibly be Empty or NULL",! seq.isEmpty() || !seq.isNull());/* cannot be NULL or Empty*/
    return QString::fromStdString(crc64digest(seq.data()));
}



}
