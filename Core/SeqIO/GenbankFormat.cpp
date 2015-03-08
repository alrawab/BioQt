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


#include "GenbankFormat.h"

namespace BioQt {

const QString GenbankFormat::DEFAULT ("GENBANK");
const QString GenbankFormat::LOCUS_TAG ("LOCUS");
const QString GenbankFormat::SIZE_TAG ("SIZE");
const QString GenbankFormat::STRAND_NUMBER_TAG ("STRANDS");
const QString GenbankFormat::TYPE_TAG ("TYPE");
const QString GenbankFormat::CIRCULAR_TAG ("CIRCULAR");
const QString GenbankFormat::DIVISION_TAG ("DIVISION");
const QString GenbankFormat::DATE_TAG ("MDAT");
const QString GenbankFormat::ACCESSION_TAG ("ACCESSION");
const QString GenbankFormat::VERSION_TAG ("VERSION");
const QString GenbankFormat::GI_TAG ("GI");
//const QString GenbankFormat::KEYWORDS_TAG ("KW");
const QString GenbankFormat::DEFINITION_TAG ("DEFINITION");
const QString GenbankFormat::SOURCE_TAG ("SOURCE");
const QString GenbankFormat::ORGANISM_TAG ("ORGANISM");
const QString GenbankFormat::REFERENCE_TAG ("REFERENCE");
const QString GenbankFormat::COORDINATE_TAG ("COORDINATE");
const QString GenbankFormat::REF_ACCESSION_TAG ("");
const QString GenbankFormat::AUTHORS_TAG ("AUTHORS");
const QString GenbankFormat::TITLE_TAG ("TITLE");
const QString GenbankFormat::JOURNAL_TAG ("JOURNAL");
const QString GenbankFormat::PUBMED_TAG ("PUBMED");
const QString GenbankFormat::MEDLINE_TAG ("MEDLINE");
const QString GenbankFormat::COMMENT_TAG ("COMMENT");
const QString GenbankFormat::FEATURE_TAG ("FEATURES");
const QString GenbankFormat::BASE_COUNT_TAG ("BASE");
const QString GenbankFormat::FEATURE_FLAG ("FT");
const QString GenbankFormat::START_SEQUENCE_TAG ("ORIGIN");
const QString GenbankFormat::END_SEQUENCE_TAG ("//");
const QString GenbankFormat::FEATURE_LINE_PREFIX ("     ");
const QString GenbankFormat::PROJECT_TAG("PROJECT");

const QString GenbankFormat::PRIMARY_TAG("PRIMARY");

const QString GenbankFormat::DBLINK_TAG("DBLINK");

const QString GenbankFormat::KEYWORDS_TAG("KEYWORDS");
const QString GenbankFormat::SEGMENT_TAG("SEGMENT");
const QMap<QString, QString> GenbankFormat::GenBankLocationRegexpMap()
{

    QMap<QString,QString> GenBankLocationRegExp;
    GenBankLocationRegExp["SoloLocation"]="[<>]?\\d+";
    GenBankLocationRegExp["PairLocation"]="[<>]?\\d+\\.\\.[<>]?\\d+";
    GenBankLocationRegExp["BetweenLocation"]="\\d+\\^\\d+";
    GenBankLocationRegExp["WithinPosition"]="\\(\\d+\\.\\d+\\)";
    GenBankLocationRegExp["WithinLocation"]=QString("([<>]?\\d+|%1)\\.\\.([<>]?\\d+|%2)")
            .arg(GenBankLocationRegExp["WithinPosition"])
            .arg(GenBankLocationRegExp["WithinPosition"]);


    Q_ASSERT( QRegExp(GenBankLocationRegExp["WithinPosition"]).exactMatch("(3.9)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["WithinLocation"]).exactMatch("(3.9)..10"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["WithinLocation"]).exactMatch("26..(30.33)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["WithinLocation"]).exactMatch("(13.19)..(20.28)"));

    GenBankLocationRegExp["OneOfPosition"]="one\\-of\\(\\d+(,\\d+)+\\)";
    GenBankLocationRegExp["OneOfLocation"]=QString("([<>]?\\d+|%1)\\.\\.([<>]?\\d+|%2)")
            .arg(GenBankLocationRegExp["OneOfPosition"])
            .arg(GenBankLocationRegExp["OneOfPosition"]);

    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfPosition"]).exactMatch("one-of(6,9)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfLocation"]).exactMatch("one-of(6,9)..101"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfLocation"]).exactMatch("one-of(6,9)..one-of(101,104)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfLocation"]).exactMatch("6..one-of(101,104)"));

    Q_ASSERT(! QRegExp(GenBankLocationRegExp["OneOfPosition"]).exactMatch("one-of(3)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfPosition"]).exactMatch("one-of(3,6)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["OneOfPosition"]).exactMatch("one-of(3,6,9)"));


    GenBankLocationRegExp["SimpleLocation"]="\\d+\\.\\.\\d+";
    GenBankLocationRegExp["SimpleCompound"]=QString("^(join|order|bond)\\(%1(,%2)*\\)$")
            .arg(GenBankLocationRegExp["SimpleLocation"])
            .arg(GenBankLocationRegExp["SimpleLocation"]);
    GenBankLocationRegExp["ComplexLocation"]=QString("([a-zA-z][a-zA-Z0-9_]*(\\.[a-zA-Z0-9]+)?\\:)?(%1|%2|%3|%4|%5)")
            .arg(GenBankLocationRegExp["PairLocation"])
            .arg(GenBankLocationRegExp["SoloLocation"])
            .arg(GenBankLocationRegExp["BetweenLocation"])
            .arg(GenBankLocationRegExp["WithinLocation"])
            .arg(GenBankLocationRegExp["OneOfLocation"]) ;
    GenBankLocationRegExp["ReComplexLocation"]=QString("^%1$")
            .arg(GenBankLocationRegExp["ComplexLocation"]);
    GenBankLocationRegExp["PossiblyComplementedComplexLocation"]=QString("(%1|complement\\(%2\\))")
            .arg(GenBankLocationRegExp["ComplexLocation"])
            .arg(GenBankLocationRegExp["ComplexLocation"]);

    GenBankLocationRegExp["ReComplexCompound"]=QString("^(join|order|bond)\\(%1(,%2)*\\)$")
            .arg(GenBankLocationRegExp["PossiblyComplementedComplexLocation"])
            .arg(GenBankLocationRegExp["PossiblyComplementedComplexLocation"]);



    Q_ASSERT( QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("104..160"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("<104..>160"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("104"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("<1"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch(">99999"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("join(104..160,320..390,504..579)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("bond(12,63)"));

    Q_ASSERT( QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(104..160,320..390,504..579)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("order(1..69,1308..1465)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("order(1..69,1308..1465,1524)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(<1..442,992..1228,1524..>1983)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(<1..181,254..336,422..497,574..>590)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(1475..1577,2841..2986,3074..3193,3314..3481,4126..>4215)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("test(1..69,1308..1465)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("complement(1..69)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("(1..69)"));

    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("(3.9)..10"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("26..(30.33)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("(13.19)..(20.28)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("41^42"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("AL121804:41^42"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("AL121804:41..610"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("AL121804.2:41..610"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ComplexLocation"]).exactMatch("one-of(3,6)..101"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ReComplexCompound"]).exactMatch("join(153490..154269,AL121804.2:41..610,AL121804.2:672..1487)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(153490..154269,AL121804.2:41..610,AL121804.2:672..1487)"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ReComplexCompound"]).exactMatch("join(complement(69611..69724),139856..140650)"));


    //Trans-spliced example from NC_016406, note underscore in reference name: see biopython
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ReComplexLocation"]).exactMatch("NC_016402.1:6618..6676"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ReComplexLocation"]).exactMatch("181647..181905"));
    Q_ASSERT( QRegExp(GenBankLocationRegExp["ReComplexCompound"]).exactMatch("join(complement(149815..150200),complement(293787..295573),NC_016402.1:6618..6676,181647..181905)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["ReComplexLocation"]).exactMatch("join(complement(149815..150200),complement(293787..295573),NC_016402.1:6618..6676,181647..181905)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleCompound"]).exactMatch("join(complement(149815..150200),complement(293787..295573),NC_016402.1:6618..6676,181647..181905)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["ReComplexLocation"]).exactMatch("join(complement(149815..150200),complement(293787..295573),NC_016402.1:6618..6676,181647..181905)"));
    Q_ASSERT(! QRegExp(GenBankLocationRegExp["SimpleLocation"]).exactMatch("join(complement(149815..150200),complement(293787..295573),NC_016402.1:6618..6676,181647..181905)"));

    return GenBankLocationRegExp;
}



} // namespace BioQt
