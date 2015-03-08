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

#include "GenBankParser.h"

namespace BioQt {



void GenBankParser::Parse()throw(FileNotFoundException)
{

    QString line ;
    QFile file(Filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        throw FileNotFoundException("FileNotFoundException::GenBankParser  "+Filename+" No Such File");
    }


    QTextStream reader(&file);

    do
    {
        line = ParseHeaders(line, reader);
        line=ParseFeatures(line,reader);
        line=ParseSequence(line,reader);


    }while (!line.isEmpty());


}

QString GenBankParser::ParseHeaders( QString line, QTextStream &stream)throw (BioQtException,ParseException)
{

    QStringList keywords;
    keywords <<GenbankFormat::LOCUS_TAG<<GenbankFormat::VERSION_TAG<<
               GenbankFormat::PROJECT_TAG<<GenbankFormat::SOURCE_TAG<<
               GenbankFormat::REFERENCE_TAG<<GenbankFormat::COMMENT_TAG<<
               GenbankFormat::PRIMARY_TAG<<GenbankFormat::DEFINITION_TAG<<
               GenbankFormat::ACCESSION_TAG<<GenbankFormat::DBLINK_TAG<<
               GenbankFormat::KEYWORDS_TAG<<GenbankFormat::SEGMENT_TAG<<GenbankFormat::FEATURE_TAG;

    line = GoToNextLine(line, stream);

    bool haveFinishedHeaders = false;
    bool haveParsedLocus = false;
    QString lineData;
    QStringList tokens ;
    QStringList accessions;
    QString data;
    while ((!line.isEmpty()) && !haveFinishedHeaders)
    {

        QString head=GetLineHeader(line, DataIndent);
        int index=keywords.indexOf(head);

        switch (index) {

        case 0://LOCUS
            if (haveParsedLocus)
            {

                throw ParseException("ParseException::GenBankParser::ParseHeaders Locus Section Had Been parsed");
            }
            //FIXME get header info osama !!!!
            line = ParseLocusByTokens(line,  stream);
            haveParsedLocus = true;
            break;
        case 1://VERSION

            lineData = GetLineData(line, DataIndent);
            tokens = lineData.split(" ",QString::SkipEmptyParts);
            rx.setPattern("^(\\w+)\\.(\\d+)");
            if(rx.exactMatch(tokens[0]))
            {
                /*A nucleotide sequence identification number that represents a single, specific sequence in the GenBank database. This identification number uses the accession.version format implemented by GenBank/EMBL/DDBJ in February 1999.

If there is any change to the sequence data (even a single base), the version number will be increased, e.g., U12345.1 → U12345.2, but the accession portion will remain stable.

The accession.version system of sequence identifiers runs parallel to the GI number system, i.e., when any change is made to a sequence, it receives a new GI number AND an increase to its version number.*/
                //see http://www.ncbi.nlm.nih.gov/Sitemap/samplerecord.html#VersionB
                metadata.Version.Version=tokens[0].split(".")[1];
                metadata.Version.Accession=tokens[0].split(".")[0];


            }
            rx.setPattern("^GI:(\\d+)");
            if(rx.exactMatch(tokens[1]))
            {
                metadata.Version.GiNumber=rx.cap(1);

            }

            line = GoToNextLine(line, stream);
            break;
        case 2://project
            lineData = GetLineData(line, DataIndent);
            tokens = lineData.split(':');

            if (tokens.length() == 2)
            {
                metadata.Project =  ProjectIdentifier( tokens[0],QStringList() );
                tokens = tokens[1].split(',');
                for (int i = 0; i < tokens.length(); i++)
                {
                    metadata.Project.Numbers.append(tokens[i]);
                }
            }
            else
            {
                qDebug()<<"WARN: unexpected PROJECT header: " << line;
            }

            line = GoToNextLine(line, stream);
            break;
        case 3://source

            line=ParseSource(line,stream);

            break;
        case 4://REFERENCE

            line = ParseReferences(line,stream);
            break;
        case 5://COMMENT
            line = ParseComments(line,  stream);

            break;
        case 6://PRIMARY
        case 7://DEFINITION
            metadata.Definition = ParseMultiLineData(line, " ", DataIndent, stream);
            break;
        case 8://ACCESSION

            data = ParseMultiLineData( line, " ", DataIndent, stream);
            // metadata.Accession = new GenBankAccession();
            accessions = data.split(' ');
            metadata.Accession.Primary = accessions[0];

            for (int i = 1; i < accessions.length(); i++)
            {
                metadata.Accession.Secondary.append(accessions[i]);
            }

            break;
        case 9://DBLINK

        case 10://DBSOURCE

        case 11://SEGMENT

            lineData = GetLineData(line, DataIndent);
            line = GoToNextLine(line, stream);
            break;
        case 12:

            haveFinishedHeaders = true;
            break;

        }//switch

    }

    return line;;

}

QString GenBankParser::ParseLocusByTokens(QString line, QTextStream &stream)
{

    QString lineData = GetLineData(line, DataIndent);

    gencontext.processHeaderLine(line);
    QMap<QString,QString> tmp=gencontext.getAnnotationMap();

    LocInfo.Name=tmp[GenbankFormat::LOCUS_TAG].trimmed();
    LocInfo.LocusDate=tmp[GenbankFormat::DATE_TAG].trimmed();
    LocInfo.SequenceLength=tmp[GenbankFormat::SIZE_TAG].toInt();
    LocInfo.MoleType=tmp[GenbankFormat::TYPE_TAG].trimmed();
    LocInfo.StrandTopology=tmp[GenbankFormat::CIRCULAR_TAG].trimmed();
    LocInfo.DivisionCode=tmp[GenbankFormat::DIVISION_TAG].trimmed();

    QStringList info_keys;
    QStringList mol_info;





    mol_info<<GenbankFormat::LOCUS_TAG;
    // qDebug()<<tmp;
    mol_info<<"NA"<<"DNA"<<"RNA"<<"tRNA"<<"rRNA"<<
              "mRNA"<<"uRNA"<<"snRNA"<<"snoRNA";


    line = GoToNextLine(line, stream);

    return line;
}

QString GenBankParser::ParseSource(QString line, QTextStream &stream)throw(ParseException)
{
    QString source;
    QString organism;
    QString classLevels;

    while(!line.isEmpty())
    {
        QString lineHeader = GetLineHeader(line, DataIndent);
        QString lineData;

        if (lineHeader == "SOURCE")
        {
            bool lastDotted = true;
            lineData = GetLineData(line, DataIndent);
            source = lineData;

            line = GoToNextLine(line, stream);

            lineHeader = GetLineHeader(line, DataIndent);

            while ((!line.isEmpty()) && (lineHeader.isEmpty()))
            {

                source += " " + GetLineData(line, DataIndent);
                lastDotted = (source.endsWith("."));
                line = GoToNextLine(line, stream);
                lineHeader = GetLineHeader(line, DataIndent);

            }


            if (!lastDotted )
            {
                throw ParseException("GenBankParser::ParseSource::ParseException source line dont end with dot(.)");
            }

        }

        else if (line.startsWith(" "))
        {

            if (lineHeader != "ORGANISM")
            {
                throw ParseException("GenBankParser::ParseSource::ParseException there is no ORGANISM keyword in the line !!!!");
            }

            lineData = GetLineData(line, DataIndent);

            // this also can be multiline
            organism = lineData;

            line = GoToNextLine(line, stream);

            lineHeader = GetLineHeader(line, DataIndent);
            while ((!line.isEmpty()) && (lineHeader.isEmpty()))
            {
                if (line.endsWith(";") || line.endsWith("."))
                {
                    if (classLevels.isEmpty())
                    {
                        classLevels += " ";
                    }

                    lineData = GetLineData(line, DataIndent);
                    classLevels += lineData;
                }
                else
                {
                    organism += " " + lineData;

                }

                line = GoToNextLine(line, stream);
                lineHeader = GetLineHeader(line, DataIndent);
            }


        }
        else
        {
            break;

        }


    }//
    metadata.Source.CommonName=source;
    if (!organism.isEmpty())
    {
        int index = organism.indexOf(" ");
        if (index > 0)
        {
            metadata.Source.Organism.Genus = organism.mid(0, index);
            if (organism.length() > index)
            {
                index++;
                metadata.Source.Organism.Species = organism.mid(index, organism.length() - index);
            }
        }
        else
        {
            metadata.Source.Organism.Genus = organism;

        }
    }
    metadata.Source.Organism.ClassLevels=classLevels;
    if (classLevels.trimmed().length() > 0)
    {
        QString genus = classLevels;
        genus.chop(1);
        QStringList tmp=genus.split(";",QString::SkipEmptyParts);

        if(metadata.Source.Organism.Genus.trimmed()!=tmp.last().trimmed())
        {
            metadata.Source.Organism.Species = organism;
            metadata.Source.Organism.Genus = genus;

        }

    }

    return line;
}

QString GenBankParser::ParseReferences(QString line, QTextStream &stream)throw(ParseException)
{
    QList<CitationReference> referenceList;

    CitationReference * reference=NULL;


    while (!line.isEmpty())
    {
        QString lineHeader = GetLineHeader(line, DataIndent);
        if (lineHeader == "REFERENCE")
        {

            if (reference != NULL)
            {
                referenceList.append(*reference);
            }


            QString lineData = GetLineData(line, DataIndent);
            rx.setPattern("^\\d+\\s+\\(\\w+\\s+\\d+\\s+\\w+\\s+\\d+\\)");


            if (!rx.exactMatch(lineData))
            {
                throw BioQtException("Invalid data");
            }

            QStringList tmp=lineData.split("(",QString::SkipEmptyParts);
            QString number = tmp[0].trimmed();
            QString location;
            if(tmp.size()<2)
                location="UNKNOWN";
            else
                location =tmp[1].replace(")","").trimmed();
            reference = new CitationReference();
            bool ok;
            int outValue=number.toInt(&ok);
            if (!ok)
                throw BioQtException("Invalid Ref Number");
            reference->Number = outValue;
            reference->Location = location;

            line = GoToNextLine(line, stream);
        }
        else if (line.startsWith(" "))
        {
            QStringList keyword;
            keyword<<"AUTHORS"<<"CONSRTM"<<
                     "TITLE"<<"JOURNAL"<<
                     "REMARK"<<"MEDLINE"<<"PUBMED";
            int index=keyword.indexOf(lineHeader);
            switch (index) {
            case 0://AUTHORS

                reference->Authors = ParseMultiLineData( line, " ", DataIndent, stream);

                break;
            case 1://CONSRTM
                reference->Consortiums = ParseMultiLineData( line, " ", DataIndent, stream);

                break;
            case 2://title
                reference->Title = ParseMultiLineData( line, " ", DataIndent, stream);

                break;
            case 3:
                reference->Journal = ParseMultiLineData( line, " ", DataIndent, stream);
                break;
            case 4://"REMARK":
                reference->Remarks = ParseMultiLineData( line, " ", DataIndent, stream);
                break;
            case 5://"MEDLINE":
                reference->Medline = ParseMultiLineData( line, " ", DataIndent, stream);
                break;
            case 6://"PUBMED":
                reference->PubMed = ParseMultiLineData( line, " ", DataIndent, stream);
                break;
            default:
                throw BioQtException("Parser Invalid Reference Field");
            }
        }
        else
        {
            // add last reference
            if (reference != NULL)
            {
                referenceList.append(*reference);
            }


            break;
        }
        //********************
    }
    return line;
}

QString GenBankParser::ParseMultiLineData(QString &line, QString lineBreakSubstitution, int dataIndent, QTextStream &stream)
{
    QString lineData = GetLineData(line, dataIndent);

    QString data = lineData;
    line = GoToNextLine(line, stream);
    QString lineHeader = GetLineHeader(line, dataIndent);


    while ((!line.isEmpty()) && (lineHeader.isEmpty()))
    {
        lineData = GetLineData(line, dataIndent);
        data += lineBreakSubstitution + lineData;
        line = GoToNextLine(line, stream);
        lineHeader = GetLineHeader(line, dataIndent);
    }

    return data;
}

QString GenBankParser::ParseComments( QString &line, QTextStream &stream)
{
    QStringList commentList;

    QString lineHeader = GetLineHeader(line, DataIndent);
    while ((!line.isEmpty() ) && lineHeader == "COMMENT")
    {
        QString data = ParseMultiLineData( line, "\n\r", DataIndent, stream);
        commentList.append(data);
        lineHeader = GetLineHeader(line, DataIndent);

    }
    metadata.Comments=commentList;

    return line;
}

QString GenBankParser::ParseFeatures( QString &line, QTextStream &reader)
{
    QList<QString> fsLines;
    const int FEATURE_INDENT = 6;
    QList<Feature> features ;
    QString key =QString().null;
    QString location = "";
    QList<QString> qualifiers;//
    const int FEATURE_QUALIFIER_INDENT = 16;
    QString head;
    while (!line.isEmpty())
    {
        line =GoToNextLine(line, reader)+"\n\r";
        if (line.length() < FEATURE_INDENT || line.startsWith(GenbankFormat::START_SEQUENCE_TAG)
                )

            break;
        line=line.mid(FEATURE_INDENT-1);

        head = line.mid(0, FEATURE_QUALIFIER_INDENT).trimmed();
        if(line.mid(0,3) =="   ")
        {
            qualifiers.append(line.mid(FEATURE_QUALIFIER_INDENT));
        }
        else
        {
            if (!key.isNull())
            {

                features.append( Feature(key, location, qualifiers));
                key =QString().null;
                location = "";
                qualifiers.clear();
            }
            if (Feature::KEYS().contains(head))
            {

                key = head;
            }
            else
            {
                // this is not suppose to be. New feature?

                key = Feature::KEY_unknown;
            }
            location = line.mid(FEATURE_QUALIFIER_INDENT);

        }

    }



    return line;

}

QString GenBankParser::ParseSequence(QString &line, QTextStream &reader)
{
    while (!line.isEmpty()) {
        line = GoToNextLine(line, reader);
        if(line.startsWith("\\"))
            break;
        seq.append(line.mid(10).trimmed().replace(" ",""));
    }

    return QString();

}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
QString GenBankParser::GetLineData(QString line, int dataIndent)
{
    QString lineData;
    if (line.length() >= dataIndent)
    {
        lineData = line.mid(dataIndent).trimmed();
    }
    else
    {
        lineData.clear();
    }

    return lineData;
}

QString GenBankParser::GoToNextLine( QString line, QTextStream &streamReader)
{

    if (line.isEmpty())
    {

        line = streamReader.readLine();
        lineNumber++;

        while (line.isEmpty())
        {
            if (streamReader.atEnd())
            {
                return QString();
            }

            line = streamReader.readLine();
            lineNumber++;
        }

        return line;
    }

    line = streamReader.readLine();

    lineNumber++;

    while (line.isEmpty())
    {
        if (streamReader.atEnd())
        {
            return QString();
        }

        line = streamReader.readLine();
        lineNumber++;
    }

    return line;
}

QString GenBankParser::GetLineHeader(QString line, int dataIndent)
{
    QString lineHeader;
    if (line.length() >= dataIndent)
    {
        lineHeader = line.mid(0, dataIndent).trimmed();
    }
    else
    {
        lineHeader = line.trimmed();
    }

    return lineHeader;
}

void GenBankParser::AddQualifierToFeature(FeatureItem feature, const QString &qualifierKey, const QString &qualifierValue)
{
    if (!feature.Qualifiers.contains(qualifierKey))
    {
        feature.Qualifiers[qualifierKey].clear();
    }

    feature.Qualifiers[qualifierKey].append(qualifierValue);
}



} // namespace BioQt
