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



#ifndef FEATURE_H
#define FEATURE_H
#include <BioQt_global.h>
#include <QtCore>
namespace BioQt {
/**
*BioQt::Feature
*@author Usama S Erawab
*
*/

/**
 * @brief The Feature class
 * Feature element  including feature keys, qualifiers, accession numbers,
 * database name abbreviations, feature labels, and location operators, are all named
 * following the same conventions.
 */
class BIOQTSHARED_EXPORT Feature
{
public:
    /**
     * @brief Feature
     */
    Feature(){}
    /**
     * @brief Feature
     * @param _key
     * @param _location
     * @param _qualifiers
     */
    Feature(const QString &_key,const QString &_location, QMap<QString,QString> _qualifiers);
    /**
     * @brief Feature
     * @param _key
     * @param _location
     * @param _qualifier
     */
    Feature(const QString &_key,const QString &_location, QList<QString> _qualifier);
    //*****************************************************************************//
    // 1. misc_difference
    static const QString KEY_misc_difference ;
    static const QString KEY_conflict;
    static const QString KEY_unsure;
    static const QString KEY_old_sequence;
    static const QString KEY_variation;
    static const QString KEY_modified_base;
    // 2. gene
    static const QString KEY_gene;
    // 3. misc_signal
    // a) promoter
    static const QString KEY_promoter;
    static const QString KEY_CAAT_signal;
    static const QString KEY_TATA_signal;
    static const QString KEY_GC_minus35;
    static const QString KEY_GC_minus10;
    static const QString KEY_GC_signal;
    // b) RBS
    static const QString KEY_RBS;
    static const QString KEY_polyA_signal;
    static const QString KEY_enhancer;
    static const QString KEY_attenuator;
    static const QString KEY_terminator;
    static const QString KEY_rep_origin;
    static const QString KEY_oriT;
    static const QString KEY_prim_transcript;
    //  4. misc_RNA
    static const QString KEY_misc_RNA;
    // a) prim_transcript
    static const QString KEY_precursor_RNA;
    static const QString KEY_mRNA;
    static const QString KEY_5clip;
    static const QString KEY_3clip ;
    static const QString KEY_5UTR;
    static const QString KEY_3UTR ;
    static const QString KEY_exon;
    static const QString KEY_CDS ;
    static const QString KEY_sig_peptide ;
    static const QString KEY_transit_peptide;
    static const QString KEY_mat_peptide;
    static const QString KEY_intron;
    static const QString KEY_polyA_site;
    static const QString KEY_rRNA ;
    static const QString KEY_tRNA ;
    static const QString KEY_scRNA ;
    static const QString KEY_snRNA ;
    static const QString KEY_snoRNA ;
    // 5. Immunogobulin related
    static const QString KEY_C_region;
    static const QString KEY_D_segment;
    static const QString KEY_J_segment ;
    static const QString KEY_N_region ;
    static const QString KEY_S_region ;
    static const QString KEY_V_region ;
    static const QString KEY_V_segment ;
    // 6. repeat_region
    static const QString KEY_repeat_unit;
    static const QString KEY_LTR ;
    static const QString KEY_satellite;
    //  7. misc_binding
    static const QString KEY_misc_binding;
    static const QString KEY_primer_bind ;
    static const QString KEY_protein_bind ;
    //  8. misc_recomb
    static const QString KEY_iDNA ;
    // 9. misc_structure
    static const QString KEY_stem_loop;
    static const QString KEY_Dloop ;
    // 10. gap
    static const QString KEY_gap ;
    // 11. operon
    static const QString KEY_operon ;

    static const QString KEY_misc_feature ;
    static const QString KEY_source ;
    static const QString KEY_Promoter;
    static const QString KEY_Rep_Origin;
    static const QString KEY_unknown ;
    //Restriction site, this is non standard qualifier..
    static const QString KEY_restriction_site;
    //-------------------------------------------------------------
    static const QString QUALIFIER_label ;
    static const QString QUALIFIER_note ;
    static const QString QUALIFIER_allele;
    static const QString QUALIFIER_citation;
    static const QString QUALIFIER_codon;
    static const QString QUALIFIER_codon_start;
    static const QString QUALIFIER_db_xref ;
    static const QString QUALIFIER_EC_number;
    static const QString QUALIFIER_exception ;
    static const QString QUALIFIER_experiment ;
    static const QString QUALIFIER_function ;
    static const QString QUALIFIER_gene ;
    static const QString QUALIFIER_inference ;
    static const QString QUALIFIER_locus_tag ;
    static const QString QUALIFIER_map ;
    static const QString QUALIFIER_number ;
    static const QString QUALIFIER_old_locus_tag ;
    static const QString QUALIFIER_operon ;
    static const QString QUALIFIER_product ;
    static const QString QUALIFIER_protein_id;
    static const QString QUALIFIER_pseudo ;
    static const QString QUALIFIER_ribosomal_slippage ;
    static const QString QUALIFIER_standard_name ;
    static const QString QUALIFIER_translation ;
    static const QString QUALIFIER_transl_except;
    static const QString QUALIFIER_transl_table ;
    static const QString QUALIFIER_trans_splicing;
    static const QString QUALIFIER_phenotype ;
    static const QString QUALIFIER_PCR_conditions ;
    static const QString QUALIFIER_bound_moiety;

    //*****************************************************************************//
    /**
     * @brief KEYS
     * @return
     */
    static     QStringList KEYS();//{return setKeysList();}
    /**
     * @brief QualifierLabelList
     * @return
     */
    static     QStringList QualifierLabelList();
    /**
     * @brief getLocation
     * @return
     */
    QString getLocation(){return location;}
    /**
     * @brief getLocation
     * @param loc
     */
    void getLocation(const QString & loc){location=loc;}
    /**
     * @brief setKey
     * @param _key
     */
    void setKey(const QString & _key){key=_key;}
    /**
     * @brief getKey
     * @return
     */
    QString getKey(){return key;}
    /**
     * @brief getQualifiers
     * @return
     */
    QMap<QString,QString> getQualifiers(){return qualifiers;}
    /**
     * @brief setQualifiers
     * @param mp
     */
    void setQualifiers(QMap<QString,QString> mp){qualifiers=mp;};
    /**
     * @brief Label
     * @return
     */
    QString Label();

protected:
    QString key;
    QString location;
    QMap<QString,QString> qualifiers;
    QString label;
private:

};

} // namespace BioQt

#endif // BIOQT_FEATURE_H
