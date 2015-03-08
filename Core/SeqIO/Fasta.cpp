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



#include "Fasta.h"

#include <Alphabet/DNA.h>
#include <Alphabet/Protein.h>
#include <Alphabet/RNA.h>
#include <Alphabet/AlphabetException.h>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceTools.h>
#include <SeqIO/LocalFileAdapter.h>
#include <SeqIO/ZlibAdapter.h>


namespace BioQt {

#define READ_BUFF_SIZE  4096

Fasta::Fasta(const QString &filename)throw (FileNotFoundException,IllegalFormatException,EmptyURLException)
    :IsCompresed(false),FrindelyFormatName("FASTA")
{
    readableFiles =QRegExp(".*(fa|mpfa|fna|fsa|fas|fasta|ffa|ffn|frn|sef|seq|seqs)$");


    if(filename.isEmpty()||filename.isNull())
        throw EmptyURLException("Please Supply a Valid file Name the FileName Is Empty ");

    uri =new Url(filename,Url_File);

    if(uri->fileName().endsWith(".gz"))
        IsCompresed=true;

    if(IsCompresed)
    {

        basefn.append( uri->fileName()).chop(3);
        adpt=new ZlibAdapter(new LocalFileAdapter());

    }
    else {
        basefn.append( uri->fileName());
        adpt=new LocalFileAdapter();
    }

    if(!readableFiles.exactMatch(basefn))
        throw IllegalFormatException("File extension not valid Fasat Format Extension");




}

QVector<QPair<QString, QSequence> > Fasta::readAll()throw(IllegalFormatException,LineOutOfRangeException,FileNotFoundException)
{
    QString headerline;
    QSequence sequence;
    QVector< QPair<QString,QSequence> > seqlist;
 if(! adpt->open(*uri,IOAdapterMode_Read))
     throw FileNotFoundException(uri->getURLString()+ ": No such file");
    //////////////////////////////////////////////////////////////////////////

    char fastaHeaderStartChar = '>';
    QBitArray fastaHeaderStart = FileUtils::createBitMap(fastaHeaderStartChar);
    QByteArray readBuff(READ_BUFF_SIZE + 1, 0);
    char* buff = readBuff.data();
    qint64 len = 0;
    bool lineOk = true;

    static QBitArray nonWhites = ~FileUtils::WHITES;

    bool headerReaded = false;

    adpt->readUntil(buff, READ_BUFF_SIZE, nonWhites, IOAdapter::Term_Exclude, &lineOk);
//------------------------------------------------------------------
    while (!adpt->isEof()) {
        len = adpt->readUntil(buff, READ_BUFF_SIZE,FileUtils::LINE_BREAKS , IOAdapter::Term_Include, &lineOk);
        if (len == 0) { //end if stream
            break;
        }
        if (!lineOk) {
            throw LineOutOfRangeException("line is too long");
        }

        headerline = QString(QByteArray::fromRawData(buff+1, len-1)).trimmed();
        if (buff[0]!= '>') {
            throw IllegalFormatException("Fasta first line dont start's with conventional '>' ");

        }
        len = adpt->readUntil(buff, READ_BUFF_SIZE,fastaHeaderStart, IOAdapter::Term_Exclude);
        if (len <= 0) {
            break;
        }


len = FileUtils::remove(buff, len, FileUtils::WHITES);
            buff[len] = 0;

            sequence.append(buff);
           seqlist.push_back(qMakePair(headerline,sequence));

           sequence.clear();
           headerline.clear();

    }
    adpt->close();
    return seqlist;
}

#define LINE_LEN 50
void Fasta::FastaWrite(const QString &header,const QSequence &_seq,IOAdapterMode mod)throw(IOErrorException)
{

    if (!adpt->open(*uri, mod)) {
           throw IOErrorException("unable to open "+uri->getURLString()+" for wrting");

        }

    QByteArray block;
    block.clear();
           block.append('>').append(header).append('\n');
           adpt->writeBlock(block);
           QByteArray tmp=_seq.toLocal8Bit();

           int len =_seq.size();
           for (int i=0; i < len; i+=LINE_LEN) {
                      int chunkSize = qMin(LINE_LEN, len - i);
                      adpt->writeBlock(tmp.constData() + i, chunkSize);
                      adpt->writeBlock("\n", 1);
                  }
           adpt->close();
}




} // namespace BioQt
