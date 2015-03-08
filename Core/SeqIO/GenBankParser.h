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
*BioQt::GenBankParser
*@author Usama S Erawab
*
*/

#ifndef GENBANKPARSER_H
#define GENBANKPARSER_H

#include <BioQt_global.h>
#include <QtCore>
#include "Feature.h"
#include <Sequence/QSequence.h>
#include <SeqIO/SeqIOException.h>
#include <Utils/Exceptions/BioQtException.h>
#include "GenbankFormat.h"
#include "GenBankMetadata.h"
#include "Feature.h"
#include "StrandedFeature.h"
#include "EmblLikeLocationParser.h"
#include "GenbankContext.h"

namespace BioQt {
/**
 * @brief The GenBankParser class
 * A GenBankParser reads from a source of text that is formatted according to the GenBank flat
 * file specification. There is also a default encoding for each alphabet that may be encountered.
 * Documentation for the latest GenBank file format can be found at
 * ftp.ncbi.nih.gov/genbank/gbrel.txt
 */
class BIOQTSHARED_EXPORT GenBankParser
{
public:
    /**
     * @brief GenBankParser Default constructor
     */
    GenBankParser():DataIndent(12),FeatureDataIndent(21),lineNumber(0){}
    GenBankParser(const QString &filename):DataIndent(12),FeatureDataIndent(21),lineNumber(0),Filename(filename){}
    void Parse()throw(FileNotFoundException);
    QString ParseHeaders( QString line,QTextStream &stream)throw (BioQtException,ParseException);
    QString ParseLocusByTokens( QString line,QTextStream &stream);
    QString ParseSource( QString line,QTextStream &stream)throw(ParseException);
    QString ParseReferences(QString line,QTextStream &stream)throw(ParseException);

    QString ParseMultiLineData( QString& line, QString lineBreakSubstitution, int dataIndent, QTextStream &stream);
    QString ParseComments( QString& line,  QTextStream& stream);

    QString ParseFeatures( QString& line,QTextStream& reader);
    QString ParseSequence(QString& line,QTextStream &reader);
    // QString ParseFeatures(QString line, QTextStream& stream);
    QList<Feature> getFeature(){return fetures;}
    GenBankMetadata Getmetadata(){return metadata;}
    QSequence GetSeq(){return seq;}
    GenBankLocusInfo GetLocusInfo(){return LocInfo;}
    GenbankContext GetGenContext(){return gencontext;}


private:
    /**
  * @brief GetLineData
  * @param line
  * @param dataIndent
  * @return
  */
    QString GetLineData(QString line, int dataIndent);
    /**
  * @brief GoToNextLine Reads the next line of text, storing it in the Line property.  If SkipBlankLines.
  * @param line The current line
  * @param streamReader
  * @return  The next line
  */
    QString GoToNextLine( QString line, QTextStream& streamReader);
    /**
  * @brief GetLineHeader
  * @param line The Line to be processed
  * @param dataIndent The Indent for Header Calculation
  * @return the header
  */
    QString GetLineHeader(QString line, int dataIndent);

    void AddQualifierToFeature(FeatureItem feature,const QString& qualifierKey,const QString& qualifierValue);
    // the standard indent for data is different from the indent for data in the features section
    const int DataIndent;
    const int FeatureDataIndent;
    QSequence sequenceWithData;
    int lineNumber;
    QList<Feature> fetures;
    QTextStream * streamReader;
    QString Filename;
    GenbankContext gencontext;
    GenBankMetadata metadata;
    QRegExp rx;
    GenBankLocusInfo LocInfo;
    QSequence seq;


};

} // namespace BioQt

#endif // BIOQT_GENBANKPARSER_H
