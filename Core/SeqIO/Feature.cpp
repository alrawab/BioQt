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
*BioQt::Feature
*@author Usama S Erawab
*
*/

#include "Feature.h"

namespace BioQt {
//****************************************
// 1. misc_difference
const QString Feature::KEY_misc_difference("misc_difference");
const QString Feature::KEY_conflict("conflict");
const QString Feature::KEY_unsure("unsure");
const QString Feature::KEY_old_sequence("old_sequence");
const QString Feature::KEY_variation("variation");
const QString Feature::KEY_modified_base("modified_base");
// 2. gene
const QString Feature::KEY_gene("gene");
// 3. misc_signal
// a) promoter
const QString Feature::KEY_promoter("promoter");
const QString Feature::KEY_CAAT_signal("CAAT_signal");
const QString Feature::KEY_TATA_signal("TATA_signal");
const QString Feature::KEY_GC_minus35("-35");
const QString Feature::KEY_GC_minus10("-10");
const QString Feature::KEY_GC_signal("GC_signal");
// b) RBS
const QString Feature::KEY_RBS("RBS");
const QString Feature::KEY_polyA_signal("polyA_signal");
const QString Feature::KEY_enhancer("enhancer");
const QString Feature::KEY_attenuator("attenuator");
const QString Feature::KEY_terminator("terminator");
const QString Feature::KEY_rep_origin("rep_origin");
const QString Feature::KEY_oriT("oriT");
const QString Feature::KEY_prim_transcript("prim_transcript");
//  4. misc_RNA
const QString Feature::KEY_misc_RNA("misc_RNA");
// a) prim_transcript
const QString Feature::KEY_precursor_RNA("precursor_RNA");
const QString Feature::KEY_mRNA("mRNA");
const QString Feature::KEY_5clip("5'clip ");
const QString Feature::KEY_3clip("3'clip ");
const QString Feature::KEY_5UTR("5'UTR");
const QString Feature::KEY_3UTR("3'UTR");
const QString Feature::KEY_exon("exon");
const QString Feature::KEY_CDS("CDS");
const QString Feature::KEY_sig_peptide("sig_peptide");
const QString Feature::KEY_transit_peptide("transit_peptide");
const QString Feature::KEY_mat_peptide("mat_peptide");
const QString Feature::KEY_intron("intron");
const QString Feature::KEY_polyA_site("polyA_site");
const QString Feature::KEY_rRNA("rRNA");
const QString Feature::KEY_tRNA("tRNA");
const QString Feature::KEY_scRNA("scRNA");
const QString Feature::KEY_snRNA("snRNA");
const QString Feature::KEY_snoRNA("snoRNA");
// 5. Immunogobulin related
const QString Feature::KEY_C_region("C_region");
const QString Feature::KEY_D_segment("D_segment");
const QString Feature::KEY_J_segment("J_segment");
const QString Feature::KEY_N_region("N_region");
const QString Feature::KEY_S_region("S_region");
const QString Feature::KEY_V_region("V_region");
const QString Feature::KEY_V_segment("V_segment");
// 6. repeat_region
const QString Feature::KEY_repeat_unit("repeat_unit");
const QString Feature::KEY_LTR("LTR");
const QString Feature::KEY_satellite("satellite");
//  7. misc_binding
const QString Feature::KEY_misc_binding("misc_binding");
const QString Feature::KEY_primer_bind("primer_bind");
const QString Feature::KEY_protein_bind("protein_bind");
//  8. misc_recomb
const QString Feature::KEY_iDNA("iDNA");
// 9. misc_structure
const QString Feature::KEY_stem_loop("stem_loop");
const QString Feature::KEY_Dloop("D-loop");
// 10. gap
const QString Feature::KEY_gap("gap");
// 11. operon
const QString Feature::KEY_operon("operon");

const QString Feature::KEY_misc_feature("misc_feature");
const QString Feature::KEY_source("source");
const QString Feature::KEY_Promoter("promoter");
const QString Feature::KEY_Rep_Origin("rep_origin");
const QString Feature::KEY_unknown("UNKNOWN");
const QString Feature::KEY_restriction_site("restric_site");
//**********************************************************************
const QString Feature::QUALIFIER_label("label");
const QString Feature::QUALIFIER_note("note");
const QString Feature::QUALIFIER_allele("allele");
const QString Feature::QUALIFIER_citation("citation");
const QString Feature::QUALIFIER_codon("codon");
const QString Feature::QUALIFIER_codon_start("codon_start");
const QString Feature::QUALIFIER_db_xref("db_xref");
const QString Feature::QUALIFIER_EC_number("EC_number");
const QString Feature::QUALIFIER_exception("exception");
const QString Feature::QUALIFIER_experiment("experiment");
const QString Feature::QUALIFIER_function("function");
const QString Feature::QUALIFIER_gene("gene");
const QString Feature::QUALIFIER_inference("inference");
const QString Feature::QUALIFIER_locus_tag("locus_tag");
const QString Feature::QUALIFIER_map("map");
const QString Feature::QUALIFIER_number("number");
const QString Feature::QUALIFIER_old_locus_tag("old_locus_tag");
const QString Feature::QUALIFIER_operon("operon");
const QString Feature::QUALIFIER_product("product");
const QString Feature::QUALIFIER_protein_id("protein_id");
const QString Feature::QUALIFIER_pseudo("pseudo");
const QString Feature::QUALIFIER_ribosomal_slippage("ribosomal_slippage");
const QString Feature::QUALIFIER_standard_name("standard_name");
const QString Feature::QUALIFIER_translation("translation");
const QString Feature::QUALIFIER_transl_except("transl_except");
const QString Feature::QUALIFIER_transl_table("transl_table");
const QString Feature::QUALIFIER_trans_splicing("trans_splicing");
const QString Feature::QUALIFIER_phenotype("phenotype");
const QString Feature::QUALIFIER_PCR_conditions("PCR_conditions");
const QString Feature::QUALIFIER_bound_moiety("bound_moiety");

//******************************************

Feature::Feature(const QString &_key, const QString &_location, QMap<QString, QString> _qualifiers)
    :key(_key),location(_location),qualifiers(_qualifiers)
{

}
/*
Feature::Feature(const QString &_key, const QString &_location, QList<QPair<QString, QString> > _qualifiers)
{

}*/

Feature::Feature(const QString &_key, const QString &_location, QList<QString> _qualifier)
    :key(_key),location(_location)
{
    QString qKey =QString().null;
    QString qValue;
    Q_FOREACH(QString line,_qualifier)
    {
        if(line.startsWith("/"))// qualifier start
        {
            // save reading buffer
            if(!qKey.isNull())
            {
                if(qualifiers.keys().contains(qKey))
                {
                    qValue = qualifiers[qKey] + ", " + qValue;
                    qualifiers.remove(qKey);
                    qualifiers.insert(qKey, qValue);
                }
                else
                {
                    qualifiers.insert(qKey, qValue);
                }
            }//----
            int equal = line.indexOf("=");
            if (equal >= 1)
            {

                qKey = line.mid(1, equal - 1);

                if (line.length() > equal)
                {
                    qValue = line.mid(equal + 1);
                }
                int firstQuote = line.indexOf('"');
                if (firstQuote >= 0) // check multi-line feature
                {
                    if (line.indexOf('\"', firstQuote + 1) < 0)
                    {
                        // no second quote, must be multiple line qualifiers
                        continue;
                    }
                }
            }//------
            else // may be only key
            {
                qKey = line.mid(1);
                qValue = "";
            }
            if (qualifiers.keys().contains(qKey))
            {
                qValue = qualifiers[qKey] + ", " + qValue;
                qualifiers.remove(qKey);
                qualifiers.insert(qKey, qValue);
            }
            else
            {
                qualifiers.insert(qKey, qValue);
            }
            qKey =QString().null;
            qValue = "";
        }
        else // continuation
        {
            qValue += line.trimmed();
        }

    }
    if (!qKey.isNull())
    {
        if (qualifiers.keys().contains(qKey))
        {
            qValue = qualifiers[qKey] + ", " + qValue;
            qualifiers.remove(qKey);
            qualifiers.insert(qKey, qValue);
        }
        else
        {
            qualifiers.insert(qKey, qValue);
        }
    }

}

QStringList Feature::KEYS()
{
    QStringList tmp;
    tmp <<KEY_misc_difference<<
          KEY_conflict<<
          KEY_unsure<<
          KEY_old_sequence<<
          KEY_variation<<
          KEY_modified_base<<
          // 2. gene
          KEY_gene<<
          // 3. misc_signal
          // a) promoter
          KEY_promoter<<
          KEY_CAAT_signal<<
          KEY_TATA_signal<<
          KEY_GC_minus35<<
          KEY_GC_minus10<<
          KEY_GC_signal<<
          // b) RBS
          KEY_RBS<<
          KEY_polyA_signal<<
          KEY_enhancer<<
          KEY_attenuator<<
          KEY_terminator<<
          KEY_rep_origin<<
          KEY_oriT<<
          KEY_prim_transcript<<
          //  4. misc_RNA
          KEY_misc_RNA<<
          // a) prim_transcript
          KEY_precursor_RNA<<
          KEY_mRNA<<
          KEY_5clip<<
          KEY_3clip<<
          KEY_5UTR<<
          KEY_3UTR<<
          KEY_exon<<
          KEY_CDS<<
          KEY_sig_peptide<<
          KEY_transit_peptide<<
          KEY_mat_peptide<<
          KEY_intron<<
          KEY_polyA_site<<
          KEY_rRNA<<
          KEY_tRNA<<
          KEY_scRNA<<
          KEY_snRNA<<
          KEY_snoRNA<<
          // 5. Immunogobulin related
          KEY_C_region<<
          KEY_D_segment<<
          KEY_J_segment<<
          KEY_N_region<<
          KEY_S_region<<
          KEY_V_region<<
          KEY_V_segment<<
          // 6. repeat_region
          KEY_repeat_unit<<
          KEY_LTR<<
          KEY_satellite<<
          //  7. misc_binding
          KEY_misc_binding<<
          KEY_primer_bind<<
          KEY_protein_bind<<
          //  8. misc_recomb
          KEY_iDNA<<
          // 9. misc_structure
          KEY_stem_loop<<
          KEY_Dloop<<
          // 10. gap
          KEY_gap<<
          // 11. operon
          KEY_operon<<

          KEY_misc_feature<<
          KEY_source<<
          KEY_Promoter<<
          KEY_Rep_Origin<<
          KEY_unknown;
    return tmp;
}

QStringList Feature::QualifierLabelList()
{
    QStringList tmp;
    tmp <<QUALIFIER_label<< QUALIFIER_gene
       <<QUALIFIER_product<< QUALIFIER_locus_tag
      <<QUALIFIER_note<< QUALIFIER_db_xref<< QUALIFIER_protein_id;
    return tmp;
}

QString Feature::Label()
{
   if(label.isEmpty()||label.isNull())
    {
        Q_FOREACH(QString qualifier,QualifierLabelList())
        {
            if(qualifiers.keys().contains(qualifier))
            {
                label = qualifiers[qualifier].trimmed();
               //  remove quotes
                if (label.startsWith("\""))
                    label = label.mid(1);

                if (label.endsWith("\""))
                     label.chop(1);

                break;

            }
        }

    }

return label;
}






} // namespace BioQt
