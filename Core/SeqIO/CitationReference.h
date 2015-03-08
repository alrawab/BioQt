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
*BioQt::CitationReference
*@author Usama S Erawab
*
*/

#ifndef CITATIONREFERENCE_H
#define CITATIONREFERENCE_H

#include <BioQt_global.h>
#include <QtCore>

namespace  BioQt {

//typedef struct  CitationReference
class BIOQTSHARED_EXPORT CitationReference
{
   //  Q_OBJECT
public:
     CitationReference(){}   //QObject *parent = 0):QObject(parent){}
    /**
     * @brief Number Reference number.
     */
    int Number;


    /**
     * @brief Location The range of bases in the sequence entry reported in this citation.
     */
    QString Location;


    /**
     * @brief Authors Lists the authors in the order in which they appear in the cited article
     * Last names are separated from initials by a comma (no space); there is no comma
     *  before the final `and'. The list of authors ends with a period.
     */
    QString Authors;


    /**
     * @brief Consortiums Lists the collective names of consortiums associated with the citation
     * (eg, International Human Genome Sequencing Consortium), rather than individual author names.
     */
    QString Consortiums ;


    /**
     * @brief Title Full title of citation.
     * Present in all but unpublished citations.
     */
    QString Title;


    /**
     * @brief Journal Lists the journal name, volume, year, and page numbers of the citation
     */
    QString Journal;

    /**
     * @brief Medline The National Library of Medicine's Medline unique identifier for a citation (if known).
     * Medline UIs are 8 digit numbers.
     */
    QString Medline;

    /**
     * @brief PubMed The PubMed unique identifier for a citation (if known).
     * PUBMED ids are numeric, and are record identifiers for article abstracts in the PubMed database.
     * http://www.ncbi.nlm.nih.gov/entrez/query.fcgi?db=PubMed
     */
    QString PubMed;

    /**
     * @brief Remarks The REMARK line is a textual comment that specifies the relevance
     *  of the citation to the entry.
     */
    QString Remarks;
private:
//  Q_DISABLE_COPY(CitationReference)


 //   struct CitationReference * child;
};
//Q_DECLARE_METATYPE(BioQt::CitationReference)
//Q_DECLARE_METATYPE(BioQt::CitationReference*)
} // namespace BioQt

#endif // BIOQT_CITATIONREFERENCE_H
