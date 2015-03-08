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
*BioQt::GenBankMetadata
*@author Usama S Erawab
*
*/

#ifndef GENBANKMETADATA_H
#define GENBANKMETADATA_H
#include <BioQt_global.h>
#include <QtCore>
#include <Utils/Exceptions/BioQtException.h>
#include "CitationReference.h"
#include "SequenceSegment.h"
#include "SequenceSource.h"
#include "Feature.h"
#include "CrossReferenceLink.h"
#include "ProjectIdentifier.h"
#include "GenBankVersion.h"
#include "GenBankAccession.h"
#include "GenBankLocusInfo.h"
#include "FeatureItem.h"



namespace BioQt {
/**
 * @brief The GenBankMetadata class  holds metadata provided by the gen bank flat file format.
 */
class BIOQTSHARED_EXPORT GenBankMetadata
{
public:
    GenBankMetadata();
    /**
    * @brief GetFeatures
    * @return Returns the features which are partly or completely inside the specified range.
    *    Note that the startPosition and endPosition are one based position.
    */
  // QList<FeatureItem>  GetFeatures(int startPosition, int endPosition);
   /**
    * @brief GetFeatures
    * @param accession
    * @param startPosition
    * @param endPosition
    * @return Returns the features which are partly or completely inside the specified range
    *  and belongs to specified accession.
    * Note that the startPosition and endPosition are one based position.
    */
//   QList<FeatureItem> GetFeatures(const QString& accession, int startPosition, int endPosition)throw(BioQtException);

    /**
     * @brief References Citations for all articles containing data reported in this entry.
     */
    QList<CitationReference> References;
    /**
     * @brief DbSource DBSource provies reference to the GenBank record from which the protein
     * translation was obtained.
     */
    QString DbSource;

    /**
     * @brief Keywords Short phrases describing gene products and other information about the sequence.
     */
    QString Keywords ;
    /**
     * @brief Segment Segment provides the information on the order in which this entry appears in a
     * series of discontinuous sequences from the same molecule.
     */
    SequenceSegment Segment;
    /**
     * @brief Source  provides the common name of the organism or the name most frequently used
     * in the literature along with the taxonomic classification levels .
     */
    SequenceSource Source ;
    /**
     * @brief Comments Cross-references to other sequence entries, comparisons to
     * other collections, notes of changes in LOCUS names, and other remarks.
     */
    QStringList Comments;
    /**
     * @brief Primary  Provides the reference to the primary GenBank files from which annotations
     * in this file are derived.
     */
    QString Primary;
    /**
     * @brief Features Containing information on portions of the sequence that code for
     * proteins and RNA molecules and information on experimentally determined
     * sites of biological significance.
     */
    Feature Features;
    /**
     * @brief BaseCount
     * Summary of the number of occurrences of each base pair code
     * (a, c, t, g, and other) in the sequence.
     *
     * This is obsolete and was removed from the GenBank flat-file
     * format in October 2003.
     */
    QString BaseCount;
    /**
     * @brief Origin Specification of how the first base of the reported sequence is
     * operationally located within the genome. Where possible, this
     * includes its location within a larger genetic map.
     */
    QString Origin;
    /**
     * @brief Contig  provides information about how individual sequence records can be
        * combined to form larger-scale biological objects, such as chromosomes
        * or complete genomes. Rather than presenting actual sequence data, a
        * special join() statement provides the accession numbers and base pair
        * ranges of the underlying records which comprise the object.
     */
    QString Contig ;
    /**
     * @brief DbLinks DBLink provides cross-references to resources that support the existence
     * a sequence record, such as the Project Database and the NCBI Trace Assembly Archive.
     *
     */
    QList<CrossReferenceLink> DbLinks;
    /**
     * @brief Project The identifier of a project (such as a Genome Sequencing Project)
        * to which a GenBank sequence record belongs.
        * This is obsolete and was removed from the GenBank flat-file format
        * after Release 171.0 in April 2009.
        */
    ProjectIdentifier Project;
    /**
     * @brief Version A compound identifier consisting of the primary accession number and
        * a numeric version number associated with the current version of the
        * sequence data in the record. This is followed by an integer key
        * (a "GI") assigned to the sequence by NCBI.
     */
    GenBankVersion Version;
    /**
     * @brief Accession Accession is identifier assigned to each GenBank sequence record.
     */
    GenBankAccession Accession;
    /**
     * @brief Definition Gets or sets the definition.
     * Definition is a concise description of the sequence.
     */
    QString Definition ;
    /**
     * @brief Locus Gets or sets the locaus information.
     * Locus is a short mnemonic name for the entry, chosen to suggest the
     * sequence's definition.
     */
    GenBankLocusInfo Locus;
};

} // namespace BioQt

#endif // BIOQT_GENBANKMETADATA_H
