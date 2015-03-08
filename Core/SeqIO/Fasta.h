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



#ifndef FASTA_H
#define FASTA_H

#include <BioQt_global.h>
#include <QtCore>
#include <Alphabet/Alphabet.h>
#include <Sequence/QSequence.h>
#include "SeqIOException.h"
#include "IOAdapter.h"
#include "Url.h"
#include "FileUtils.h"



namespace BioQt {

/**
*BioQt::Fasta
*@author Usama S Erawab
*
*/
class BIOQTSHARED_EXPORT Fasta
{
public:
    /**
     * @brief Fasta
     * @param filename
     */
    Fasta(const QString &filename)throw (FileNotFoundException,IllegalFormatException,EmptyURLException);
    /**
     * @brief readAll
     * @return
     */
    QVector< QPair<QString,QSequence> > readAll()throw(IllegalFormatException,LineOutOfRangeException,FileNotFoundException);

    void FastaWrite(const QString &header,const QSequence &_seq,IOAdapterMode mod)throw(IOErrorException);

private:
    AlphaBet * alpha;
    QString basefn;
    QFile file;
    QTextStream *in;
    QRegExp readableFiles;
    QString FrindelyFormatName;
    bool IsCompresed;
    IOAdapter * adpt;
    Url *uri;
};

} // namespace BioQt

#endif // BIOQT_FASTA_H
