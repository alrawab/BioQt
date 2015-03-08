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


#ifndef GENBANKFORMAT_H
#define GENBANKFORMAT_H

#include <BioQt_global.h>
#include <QtCore>
namespace BioQt {



/**
*BioQt::GenbankFormat
*@author Usama S Erawab
*
*/


class BIOQTSHARED_EXPORT GenbankFormat
{
public:
    static const QString DEFAULT;
    /**
     * @brief LOCUS_TAG
     * A short mnemonic name for the entry, chosen to suggest the
     *sequence's definition. Mandatory keyword/exactly one record.
     */
    static const QString LOCUS_TAG;
    static const QString SIZE_TAG ;
    static const QString STRAND_NUMBER_TAG;
    static const QString TYPE_TAG;
    static const QString CIRCULAR_TAG;
    static const QString DIVISION_TAG ;
    static const QString DATE_TAG ;
    static const QString ACCESSION_TAG;
    static const QString VERSION_TAG;
    static const QString GI_TAG ;
   // static const QString KEYWORDS_TAG;
    static const QString DEFINITION_TAG;
    static const QString SOURCE_TAG;
    static const QString ORGANISM_TAG;
    static const QString REFERENCE_TAG;
    static const QString COORDINATE_TAG;
    static const QString REF_ACCESSION_TAG;
    static const QString AUTHORS_TAG;
    static const QString TITLE_TAG;
    static const QString JOURNAL_TAG;
    static const QString PUBMED_TAG;
    static const QString MEDLINE_TAG;
    static const QString COMMENT_TAG;
    static const QString FEATURE_TAG ;
    static const QString BASE_COUNT_TAG;
    static const QString FEATURE_FLAG;
    static const QString START_SEQUENCE_TAG;
    static const QString PROJECT_TAG;
    /**
     * @brief GenbankFormat::PRIMARY_TAG
     * This header is followed by sequence info in a table format that could be
     * stored in a custom object.  The first line contains column headers.
     */
    static const QString PRIMARY_TAG;
    /**
    * @brief GenbankFormat::DBLINK_TAG
    * Provides cross-references to resources that
    *support the existence a sequence record, such as the Project Database
    *and the NCBI Trace Assembly Archive. Optional keyword/one or
    *more records.
    */
    static const QString DBLINK_TAG;
    /**
     * @brief KEYWORDS_TAG
     * The KEYWORDS field does not appear in unannotated entries, but is
     *required in all annotated entries. Keywords are separated by
     *semicolons; a "keyword" may be a single word or a phrase consisting of
     *several words. Each line in the keywords field ends in a semicolon;
     *the last line ends with a period. If no keywords are included in the
     *entry, the KEYWORDS record contains only a period.
     */
    static const QString KEYWORDS_TAG;
    /**
     * @brief SEGMENT_TAG
     * The SEGMENT keyword is used when two (or more) entries of known
     *relative orientation are separated by a short (<10 kb) stretch of DNA.
     *It is limited to one line of the form `n of m', where `n' is the
     *segment number of the current entry and `m' is the total number of
     *segments.
     */
    static const QString SEGMENT_TAG;
    static const QString END_SEQUENCE_TAG;
    static const QString FEATURE_LINE_PREFIX;

    static const QMap<QString,QString> GenBankLocationRegexpMap();
};

} // namespace BioQt

#endif // BIOQT_GENBANKFORMAT_H
