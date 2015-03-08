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



#include "GenbankContext.h"
#include <Utils/qstringtokenizer.h>
#include <QtGlobal>

namespace BioQt {

GenbankContext::GenbankContext()
    :HEADER(1),FEATURES(2),SEQUENCE(3),TAG_LENGTH(12)
{
}

void GenbankContext::processHeaderLine(const QString &line)throw(ParseException)
{

    // Genbank changed the format of the Locus line for release 127.
    // The new format is incompatible with the old.
    if(line.startsWith(GenbankFormat::LOCUS_TAG))
    {
        // Genbank changed the format of the Locus line for release 127.
        // The new format is incompatible with the old.
        if (isLocusLinePre127(line))
        {
            parseLocusLinePre127(line);

        }
        else
        {
            parseLocusLinePost127(line);

        }

    }
    else if (line.startsWith(GenbankFormat::VERSION_TAG))
    {

        // VERSION line is a special case because it contains both
        // the VERSION field and the GI number
        saveSeqAnno();
        QStringTokenizer lineTokens(line);
        headerTag = lineTokens.nextToken();
        headerTagText.clear();
        headerTagText.append(lineTokens.nextToken());

        if (lineTokens.hasMoreToken()) {
            QString nextToken = lineTokens.nextToken();
            if (nextToken.startsWith(GenbankFormat::GI_TAG))
            {
                saveSeqAnno();
                headerTag = GenbankFormat::GI_TAG;
                headerTagText.clear();
                headerTagText.append(nextToken.mid(3));

            }
        }
       saveSeqAnno2(GenbankFormat::GI_TAG,headerTagText);
    }
    else if (hasHeaderTag(line))
    {	// line	has a header tag
        saveSeqAnno();
        headerTag =	line.mid(0, TAG_LENGTH).trimmed();
        headerTagText.append(line.mid(TAG_LENGTH));
    }
    // gbpri1.seq (Release 125.0) has a line which is not
    // TAG_LENGTH long.
    else if (line.length() >= TAG_LENGTH)
    {	// keep	appending tag text value
        headerTagText.append(" " + line.mid(TAG_LENGTH));
    }

}

void GenbankContext::parseLocusLinePre127(const QString &line)throw(ParseException)
{
    if (line.length() < 73)
    {
        QStringTokenizer locusTokens(line);
        //Locus Tag
        locusTokens.nextToken();
        if (locusTokens.hasMoreToken()) {
            //saveSeqAnno2(GenbankFormat::LOCUS_TAG, locusTokens.nextToken());
if ((locusTokens.countTokens() == 8) || (locusTokens.countTokens() == 7))
{

    saveSeqAnno2(GenbankFormat::LOCUS_TAG, locusTokens.getTokens()[1]);
    saveSeqAnno2(GenbankFormat::SIZE_TAG,locusTokens.getTokens()[2]);
    saveSeqAnno2(GenbankFormat::TYPE_TAG,locusTokens.getTokens()[4]);
    saveSeqAnno2(GenbankFormat::CIRCULAR_TAG, locusTokens.getTokens()[5]);
    saveSeqAnno2(GenbankFormat::DIVISION_TAG, locusTokens.getTokens()[6]);
    saveSeqAnno2(GenbankFormat::DATE_TAG,locusTokens.getTokens()[7]);

}




        }
        else {
            throw  ParseException("LOCUS line too short [" + line + "]");
        }


    }
    else {
        saveSeqAnno2(GenbankFormat::LOCUS_TAG, line.mid(12, 10));
        saveSeqAnno2(GenbankFormat::SIZE_TAG, line.mid(22, 7));
        saveSeqAnno2(GenbankFormat::STRAND_NUMBER_TAG, line.mid(33, 2));
        saveSeqAnno2(GenbankFormat::TYPE_TAG, line.mid(36, 5));
        saveSeqAnno2(GenbankFormat::CIRCULAR_TAG, line.mid(42, 10));
        saveSeqAnno2(GenbankFormat::DIVISION_TAG, line.mid(52, 3));
        saveSeqAnno2(GenbankFormat::DATE_TAG, line.mid(62, 11));
    }

}

void GenbankContext::parseLocusLinePost127(const QString &line)throw(ParseException)
{
    if (line.length() < 79)
    {
        throw  ParseException("LOCUS line too short [" + line + "]");
    }
    QStringTokenizer locusTokens(line);

    if ((locusTokens.countTokens() == 8) || (locusTokens.countTokens() == 7))
    {
        /* While Genbank 127 documentation doesn't allow the strand tag to
           be optional, some files don't have it.  A key assumption here is
           that this is the only tag that is optional.  The parser will
           generate incorrect data if this assumption is violated.*/
        bool includedStrandTag = (locusTokens.countTokens() == 8);

        // LOCUS tag; not stored
        locusTokens.nextToken();

        // Locus name
         saveSeqAnno2(GenbankFormat::LOCUS_TAG, locusTokens.nextToken());

        // Sequence length
        saveSeqAnno2(GenbankFormat::SIZE_TAG, locusTokens.nextToken());

        // "bp"; not stored
        locusTokens.nextToken();
        // Strand information
        // Both the strand and type are in the same token.  The strand
        // information is an optional part, so this is a bit hairy
        // Some files do not have a strand token.  While this is not allowed
        // by Genbank's documentation, we will treat this as an optional
        // token.  It is the only optional token this parser will allow.
        if (includedStrandTag)
        {
            QString strandString = locusTokens.nextToken();
            QStringTokenizer strandTokens(strandString, "-");
            if (strandTokens.countTokens() > 1)
            {
                 saveSeqAnno2(GenbankFormat::STRAND_NUMBER_TAG, strandTokens.nextToken());
            }
           saveSeqAnno2(GenbankFormat::TYPE_TAG, strandTokens.nextToken());

            // Circularity
            saveSeqAnno2(GenbankFormat::CIRCULAR_TAG, locusTokens.nextToken());

            // Division code
           saveSeqAnno2(GenbankFormat::DIVISION_TAG, locusTokens.nextToken());

            // Date in dd-MMM-yyyy format

             //  Q_ASSERT_X(isValidDate(locusTokens.nextToken()),":parseLocusLinePost127","Token with illegal date format");
            saveSeqAnno2(GenbankFormat::DATE_TAG, locusTokens.nextToken());


        }



    }
    else
    {
        //Try using currently specified positions for tokens
        saveSeqAnno2(GenbankFormat::LOCUS_TAG, line.mid(12, 16));
        saveSeqAnno2(GenbankFormat::SIZE_TAG, line.mid(29, 11));
        saveSeqAnno2(GenbankFormat::STRAND_NUMBER_TAG, line.mid(44,2));
        saveSeqAnno2(GenbankFormat::TYPE_TAG, line.mid(47, 6));
        saveSeqAnno2(GenbankFormat::CIRCULAR_TAG,line.mid(55, 8 ));
        saveSeqAnno2(GenbankFormat::DIVISION_TAG, line.mid(64, 2));
        saveSeqAnno2(GenbankFormat::DATE_TAG, line.mid(68, 11));
    }

}
//..................................................................................//
void GenbankContext::saveSeqAnno()throw(ParseException)
{
    if (! headerTag.isEmpty()||!headerTag.isNull())
    {
        //TODO......
        headerTag.clear();
        headerTagText.clear();
    }


}

void GenbankContext::saveSeqAnno2(const QString &tag, const QString &value)throw(ParseException)
{
    if(tag.isEmpty()||value.isEmpty())
        throw ParseException("Annoation is Empty");
    GenbankAnnotationMap.insert(tag,value);

}

bool GenbankContext::hasHeaderTag(const QString &line)
{
    bool isHeaderTag = false;
    int len = qMin(line.length(),TAG_LENGTH);
    for (int i = 0; i < len && i < line.length(); i++)
    {
        if (line[i] != ' ')
        {

            isHeaderTag = true;
            break;
        }
    }

    return isHeaderTag;
}

} // namespace BioQt
