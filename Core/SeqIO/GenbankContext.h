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

#ifndef  GENBANKCONTEXT_H
#define  GENBANKCONTEXT_H

#include <BioQt_global.h>
#include <QtCore>
#include <SeqIO/SeqIOException.h>
#include "GenbankFormat.h"

namespace BioQt {


/**
*BioQt::GenbankContext
*@author Usama S Erawab
*
*/
/**
 * @brief The GenbankContext class performs the detailed formatting of
 * Genbank entries.
 */
class BIOQTSHARED_EXPORT GenbankContext
{
public:
    GenbankContext();
    void processHeaderLine(const QString& line)throw(ParseException);
     QMap<QString,QString> getAnnotationMap(){return GenbankAnnotationMap;}
     /**
      * @brief saveSeqAnno2 save genbank tags into @GenbankAnnotationMap
      * @param tag
      * @param value
      */
     void saveSeqAnno2(const QString& tag,const QString& value)throw(ParseException);

    private:
    /**
     * Checks which version of the locus line format is used.  The algorithm
     * switches on the size of the line; <75 means pre-127, otherwise it's 127.
     */
    bool isLocusLinePre127(const QString& line){return (line.length() < 75);}
    /**
     * Parses the locus line assuming it is in pre release 127 format.
     */
    void parseLocusLinePre127(const QString & line)throw(ParseException) ;
    /**
     * Parses the locus line assuming it is in post release 127 format.
     * Will also handle the case where the strand tag is optional.  That
     * is the only tag that is supported as optional.  Awaiting a response from
     * NCBI if it is or if their data is incorrectly formatted.
     */
    void parseLocusLinePost127(const QString& line)throw(ParseException);
    /**
     * @brief isValidDate checks if date format is valid dd-MMM-yyyy format.
     * @param date
     * @return
     */
    bool isValidDate(const QString& date){return QDate::fromString(date, "dd-MMM-yyyy").isValid();}
    /**
     * @brief saveSeqAnno
     */
    void saveSeqAnno()throw(ParseException);


    /**
     * @brief hasHeaderTag
     * @param line
     * @return does the line contain a header tag.
     * Yes, if any of the leading TAG_LENGTH characters aren't a space
     */
    bool hasHeaderTag(const QString &line);


    QString headerTag;
    QByteArray headerTagText;
    int HEADER;
    int FEATURES;
    int SEQUENCE;
    int TAG_LENGTH;
    QMap<QString,QString> GenbankAnnotationMap;
};

} // namespace BioQt

#endif // BIOQT_GENBANKCONTEXT_H
