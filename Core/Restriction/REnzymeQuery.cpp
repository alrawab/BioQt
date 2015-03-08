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
*BioQt::REnzymeQuery
*@author Usama S Erawab
*
*/

#include "REnzymeQuery.h"

namespace BioQt {

REnzymeQuery::REnzymeQuery(const QString& fn)
{
    res=REnzymeIO::LoadEnzymes(fn);
    PopulateData();

}

REnzyme REnzymeQuery::GetRecord(const QString &enzName)
{

    return EnzymeDic[enzName];


}

QList<int> REnzymeQuery::GetCutSites(const QSequence&seq,const QString &enzName)
{
    QString pattren=PatrenList[enzName];

    return DigestTools::SearchMatches(seq,pattren);

}

QHash<QString, QList<int> > REnzymeQuery::GetMultiCutSites(const QSequence &seq, QStringList enzList)
{
    QHash<QString, QList<int> > tmp;
    Q_FOREACH(QString c,enzList)
    {
        QString pattren=PatrenList[c];
        QList<int> sites=DigestTools::SearchMatches(seq,pattren);
        if(!sites.isEmpty())
            tmp[c]=sites;


    }
    return tmp;
}

QStringList REnzymeQuery::GetEnzymeDealer(const QString &enzName)
{
    QStringList tmp;
    QHash<QString,QStringList>::iterator it;

    for(it=Suppliers.begin();it !=Suppliers.end();it++)
    {
        if(it.value().contains(enzName))
            tmp<<it.key();
    }


    return tmp;
}

void REnzymeQuery::PopulateData()
{
    foreach (REnzyme c,res)
    {

        EnzymeNames<<c.name();
        PatrenList[c.name()]=c.pattren().toUpper();
        EnzymeDic[c.name()]=c;
    }
    PopulateSuppliersList();
}

void REnzymeQuery::PopulateSuppliersList()
{

        QStringList tmp;
        //1- Invitrogen Corporation
        tmp<<"MluI"<< "HpaII"<< "SalI"<< "NcoI"<< "ClaI"<< "DraI"<< "SstII"<< "AvaI"<< "PvuI"<<
             "DpnI"<< "TaqI"<< "KpnI"<< "NdeI"<< "PinAI"<< "BglII"<< "NruI"<< "RsaI"<< "HincII"<<
             "XbaI"<< "MboI"<< "AluI"<< "MscI"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "PvuII"<<
             "SstI"<< "SpeI"<< "HinfI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "MseI"<< "HaeIII"<<
             "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "ScaI"<< "DdeI"<< "NotI"<< "HindIII"<< "BamHI"<<
             "HpaI"<< "HhaI";
        Suppliers["Invitrogen Corporation"]=tmp;
        tmp.clear();
        //==============================================================================
        //2-Minotech Biotechnology
        tmp<<"SgrBI"<< "BclI"<< "BglI"<< "SalI"<< "PspPI"<< "SnaBI"<< "BstEII"<< "NcoI"<<
             "BshFI"<< "AsuII"<< "BssAI"<< "BseAI"<< "TaqI"<< "KpnI"<< "BglII"<< "NaeI"<<
             "BseBI"<< "NruI"<< "SlaI"<< "RsaI"<< "BsiSI"<< "XbaI"<< "Sau3AI"<< "MboI"<<
             "AluI"<< "SseBI"<< "SmaI"<< "NheI"<< "SphI"<< "PvuII"<< "ApaLI"<< "SstI"<<
             "HinfI"<< "MspCI"<< "EcoRV"<< "EcoRI"<< "BseCI"<< "PstI"<< "SfiI"<< "SspI"<<
             "CspAI"<< "ScaI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI"<< "StyI";
        Suppliers["Minotech Biotechnology"]=tmp;
        tmp.clear();
        //==============================================================================
        //3-Stratagene
        tmp<<"SanDI"<< "DpnI"<< "SrfI""SanDI"<< "DpnI"<< "SrfI";
        Suppliers["Stratagene"]=tmp;
        tmp.clear();
        //==============================================================================
        //4-Fermentas International Inc
        tmp<<"MluI"<< "CseI"<< "PscI"<< "HpaII"<< "MreI"<< "BclI"<< "SacI"<< "PauI"<< "BglI"<<
             "SalI"<< "MspI"<< "Bsu15I"<< "Mva1269I"<< "Bsp68I"<< "LweI"<< "SmiI"<< "PteI"<<
             "BshTI"<< "TstI"<< "TscAI"<< "NcoI"<< "PsyI"<< "BseJI"<< "MauBI"<< "Eco24I"<<
             "Eco47III"<< "Eco91I"<< "DraI"<< "BseXI"<< "BstXI"<< "RruI"<< "Esp3I"<< "BseSI"<<
             "Cfr9I"<< "AarI"<< "RseI"<< "PvuI"<< "BspOI"<< "DpnI"<< "Hin6I"<< "Van91I"<<
             "Bst1107I"<< "Bme1390I"<< "BveI"<< "Psp5II"<< "TaqI"<< "Eco52I"<< "BfiI"<<
             "KpnI"<< "Kpn2I"<< "SspDI"<< "SsiI"<< "MlsI"<< "NdeI"<< "PpiI"<< "Cfr13I"<<
             "MboII"<< "SdaI"<< "BmsI"<< "BglII"<< "AjuI"<< "AloI"<< "FspBI"<< "SchI"<<
             "PfoI"<< "Bpu10I"<< "BshNI"<< "Acc65I"<< "XapI"<< "TaaI"<< "Bsp1407I"<< "MvaI"<<
             "PasI"<< "Hin1II"<< "Bsh1236I"<< "MssI"<< "CpoI"<< "Eco130I"<< "BdaI"<< "TaiI"<<
             "FspAI"<< "BfmI"<< "Eco47I"<< "BoxI"<< "RsaI"<< "HincII"<< "HpyF10VI"<< "XbaI"<<
             "Lsp1109I"<< "Cfr10I"<< "AjiI"<< "Bsp119I"<< "MboI"<< "AluI"<< "SduI"<< "SgsI"<<
             "BseGI"<< "Eco72I"<< "BcnI"<< "Mph1103I"<< "EcoRII"<< "Alw21I"<< "XagI"<< "Hpy8I"<<
             "PsuI"<< "PaeI"<< "SmaI"<< "NheI"<< "BplI"<< "Ppu21I"<< "SmoI"<< "FaqI"<< "AdeI"<<
             "BcuI"<< "BspTI"<< "GsuI"<< "BseLI"<< "AasI"<< "PvuII"<< "EheI"<< "Hin1I"<< "Alw26I"<<
             "SgrDI"<< "Eco31I"<< "HinfI"<< "Eam1105I"<< "BsuRI"<< "TsoI"<< "XmiI"<< "Eam1104I"<<
             "Ecl136II"<< "XmaJI"<< "SfaAI"<< "HphI"<< "Psp1406I"<< "Csp6I"<< "EcoO109I"<< "BseMII"<<
             "AatII"<< "BfuI"<< "EcoRI"<< "TauI"<< "XhoI"<< "Bsp143I"<< "BspPI"<< "CfrI"<< "MnlI"<<
             "PfeI"<< "CaiI"<< "Bpu1102I"<< "MunI"<< "Tru1I"<< "BspLI"<< "SmuI"<< "Eco105I"<< "NsbI"<<
             "PstI"<< "LguI"<< "VspI"<< "Alw44I"<< "SfiI"<< "BpiI"<< "XceI"<< "BseMI"<< "Eco57MI"<< "Cfr42I"<<
             "SatI"<< "Hin4I"<< "SspI"<< "Eco32I"<< "KflI"<< "BseDI"<< "KspAI"<< "Eco81I"<< "BauI"<<
             "AanI"<< "ApaI"<< "SaqAI"<< "Eco88I"<< "ScaI"<< "AlfI"<< "Eco57I"<< "Eco147I"<< "OliI"<<
             "PacI"<< "PdmI"<< "CsiI"<< "Bsp120I"<< "NotI"<< "MbiI"<< "HindIII"<< "BamHI"<< "BfoI"<<
             "TatI"<< "HpyF3I"<< "Pfl23II"<< "Bsh1285I"<< "HhaI"<< "NmuCI"<< "BseNI"<< "PagI"<< "PdiI";
        Suppliers["Fermentas International Inc"]=tmp;
        tmp.clear();
        //==============================================================================
        //5-American Allied Biochemical, Inc
        tmp<<"MluI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "BstXI"<<
             "KpnI"<< "BglII"<< "SacII"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "AluI"<< "SmaI"<<
             "SphI"<< "PvuII"<< "SpeI"<< "HinfI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "HaeIII"<<
             "NsiI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI""MluI"<< "SacI"<< "BglI"<< "SalI"<<
             "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "BstXI"<< "KpnI"<< "BglII"<< "SacII"<< "RsaI"<<
             "HincII"<< "XbaI"<< "Sau3AI"<< "AluI"<< "SmaI"<< "SphI"<< "PvuII"<< "SpeI"<< "HinfI"<<
             "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "HaeIII"<< "NsiI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI";
        Suppliers["American Allied Biochemical, Inc"]=tmp;
        tmp.clear();
        //==============================================================================
        //6-SibEnzyme Ltd
        tmp<<"AsuNHI"<< "AgsI"<< "BstSFI"<< "MluI"<< "CciI"<< "BstHHI"<< "HpaII"<< "AhlI"<< "PspN4I"<< "BglI"<< "SalI"<< "MspI"<< "VneI"<< "BstH2I"<< "BisI"<< "BmtI"<< "PspXI"<< "AsiGI"<< "CciNI"<< "Sfr274I"<< "SmiI"<< "Ksp22I"<< "BssT1I"<< "MspA1I"<< "Bsp19I"<< "Bse1I"<< "AspS9I"<< "AbsI"<< "FauNDI"<< "BstMWI"<< "AclWI"<< "DraI"<< "Bst2UI"<< "AluBI"<< "PsrI"<< "BstACI"<< "BstXI"<< "BstDEI"<< "GluI"<< "BspACI"<< "AcoI"<< "XmaI"<< "BstF5I"<< "BstMBI"<< "BstENI"<< "BssECI"<< "FalI"<< "EgeI"<< "Ama87I"<< "BstDSI"<< "BstV2I"<< "AjnI"<< "AspLEI"<< "PalAI"<< "Zsp2I"<< "DseDI"<< "BstAUI"<< "Bpu14I"<< "FaeI"<< "TaqI"<< "KpnI"<< "BstSNI"<< "AclI"<< "MboII"<< "BglII"<< "PspPPI"<< "SetI"<< "AcsI"<< "BstNSI"<< "BseX3I"<< "RsaNI"<< "Bpu10I"<< "Rsr2I"<< "Acc65I"<< "PspEI"<< "Bst2BI"<< "NruI"<< "Ple19I"<< "SmiMI"<< "PciI"<< "MalI"<< "Bse118I"<< "BsePI"<< "BstMCI"<< "Bme18I"<< "RsaI"<< "BssNAI"<< "BstV1I"<< "Bsp13I"<< "Bst4CI"<< "MabI"<< "AsuHPI"<< "BtrI"<< "XbaI"<< "ArsI"<< "BstC8I"<< "Psp124BI"<< "GlaI"<< "HgaI"<< "BstX2I"<< "AluI"<< "ZraI"<< "Bse21I"<< "Sfr303I"<< "BstSCI"<< "Bse3DI"<< "Bso31I"<< "AccB7I"<< "BstKTI"<< "AccBSI"<< "SmaI"<< "AspA2I"<< "Bsp1720I"<< "Bsc4I"<< "SphI"<< "Mly113I"<< "FriOI"<< "PvuII"<< "ErhI"<< "FokI"<< "AsuC2I"<< "GsaI"<< "HinfI"<< "BsuRI"<< "PpsI"<< "BstPAI"<< "HspAI"<< "RgaI"<< "Fsp4HI"<< "Kzo9I"<< "Acc36I"<< "DraIII"<< "Acc16I"<< "MspR9I"<< "EcoRV"<< "PsiI"<< "AatII"<< "MroXI"<< "EcoRI"<< "ZrmI"<< "BstFNI"<< "PspOMI"<< "BslFI"<< "Bsa29I"<< "MnlI"<< "SbfI"<< "PstI"<< "Bse8I"<< "FauI"<< "VspI"<< "PciSI"<< "SfiI"<< "Bst6I"<< "PspLI"<< "BspFNI"<< "Msp20I"<< "Bbv12I"<< "HaeIII"<< "BstAPI"<< "SspI"<< "AfeI"<< "Tth111I"<< "BstMAI"<< "BstSLI"<< "ApaI"<< "BlsI"<< "FblI"<< "BmuI"<< "BarI"<< "PctI"<< "FaiI"<< "BpmI"<< "AcuI"<< "AccB1I"<< "PceI"<< "Sse9I"<< "Tru9I"<< "MhlI"<< "BstBAI"<< "DriI"<< "MroNI"<< "HindIII"<< "EcoICRI"<< "FatI"<< "BamHI"<< "Psp6I"<< "BstAFI"<< "SfaNI"<< "RigI"<< "HpaI"<< "PspCI"<< "HindII";
        Suppliers["SibEnzyme Ltd"]=tmp;
        tmp.clear();
        //==============================================================================
        //7-Nippon Gene Co., Ltd
        tmp<<"BssHII"<< "AxyI"<< "MluI"<< "BclI"<< "SacI"<< "EcoT38I"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "TaqI"<< "AseI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "NdeI"<< "MboII"<< "AflII"<< "BglII"<< "AccII"<< "SacII"<< "NruI"<< "NarI"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "NciI"<< "FspI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "EcoO109I"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "Bsp1286I"<< "AccIII"<< "PstI"<< "BsmI"<< "Alw44I"<< "SfiI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "ScaI"<< "AgeI"<< "NspV"<< "BalI"<< "NotI"<< "HindIII"<< "AcyI"<< "BamHI"<< "AvaII"<< "HpaI"<< "StyI"<< "HhaI""BssHII"<< "AxyI"<< "MluI"<< "BclI"<< "SacI"<< "EcoT38I"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "TaqI"<< "AseI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "NdeI"<< "MboII"<< "AflII"<< "BglII"<< "AccII"<< "SacII"<< "NruI"<< "NarI"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "NciI"<< "FspI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "EcoO109I"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "Bsp1286I"<< "AccIII"<< "PstI"<< "BsmI"<< "Alw44I"<< "SfiI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "ScaI"<< "AgeI"<< "NspV"<< "BalI"<< "NotI"<< "HindIII"<< "AcyI"<< "BamHI"<< "AvaII"<< "HpaI"<< "StyI"<< "HhaI";
        Suppliers["Nippon Gene Co., Ltd"]=tmp;
        tmp.clear();
        //==============================================================================
        //8-Takara Bio Inc
        tmp<<"BssHII"<< "MluI"<< "BspT107I"<< "SacI"<< "XspI"<< "BglI"<< "SalI"<< "MspI"<< "BstPI"<< "BanII"<< "PmaCI"<< "SnaBI"<< "SmiI"<< "BmgT120I"<< "NcoI"<< "ClaI"<< "DraI"<< "BstXI"<< "PshAI"<< "PvuI"<< "Van91I"<< "Bst1107I"<< "TaqI"<< "EaeI"<< "Eco52I"<< "BspT104I"<< "KpnI"<< "HaeII"<< "EcoO65I"<< "NdeI"<< "HapII"<< "MboII"<< "AflII"<< "EcoT14I"<< "BglII"<< "NaeI"<< "AccII"<< "SacII"<< "BmeT110I"<< "Aor51HI"<< "Bsp1407I"<< "NruI"<< "MvaI"<< "Sse8387I"<< "CpoI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "Cfr10I"<< "MboI"<< "AluI"<< "BcnI"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "PvuII"<< "MflI"<< "FokI"<< "Hin1I"<< "ApaLI"<< "SpeI"<< "HinfI"<< "Eam1105I"<< "Psp1406I"<< "EcoO109I"<< "BbeI"<< "EcoRV"<< "AatII"<< "EcoRI"<< "XhoI"<< "VpaK11BI"<< "Bsp1286I"<< "AccIII"<< "Bpu1102I"<< "MunI"<< "Aor13HI"<< "NsbI"<< "PstI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "AccI"<< "SspI"<< "Tth111I"<< "FbaI"<< "Eco81I"<< "ApaI"<< "PshBI"<< "EcoT22I"<< "ScaI"<< "BalI"<< "AfaI"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HpaI"<< "HhaI""BssHII"<< "MluI"<< "BspT107I"<< "SacI"<< "XspI"<< "BglI"<< "SalI"<< "MspI"<< "BstPI"<< "BanII"<< "PmaCI"<< "SnaBI"<< "SmiI"<< "BmgT120I"<< "NcoI"<< "ClaI"<< "DraI"<< "BstXI"<< "PshAI"<< "PvuI"<< "Van91I"<< "Bst1107I"<< "TaqI"<< "EaeI"<< "Eco52I"<< "BspT104I"<< "KpnI"<< "HaeII"<< "EcoO65I"<< "NdeI"<< "HapII"<< "MboII"<< "AflII"<< "EcoT14I"<< "BglII"<< "NaeI"<< "AccII"<< "SacII"<< "BmeT110I"<< "Aor51HI"<< "Bsp1407I"<< "NruI"<< "MvaI"<< "Sse8387I"<< "CpoI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "Cfr10I"<< "MboI"<< "AluI"<< "BcnI"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "PvuII"<< "MflI"<< "FokI"<< "Hin1I"<< "ApaLI"<< "SpeI"<< "HinfI"<< "Eam1105I"<< "Psp1406I"<< "EcoO109I"<< "BbeI"<< "EcoRV"<< "AatII"<< "EcoRI"<< "XhoI"<< "VpaK11BI"<< "Bsp1286I"<< "AccIII"<< "Bpu1102I"<< "MunI"<< "Aor13HI"<< "NsbI"<< "PstI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "AccI"<< "SspI"<< "Tth111I"<< "FbaI"<< "Eco81I"<< "ApaI"<< "PshBI"<< "EcoT22I"<< "ScaI"<< "BalI"<< "AfaI"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HpaI"<< "HhaI";
        Suppliers["Takara Bio Inc"]=tmp;
        tmp.clear();
        //==============================================================================
        //9-Roche Applied Science
        tmp<<"BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "Asp718I"<< "MspI"<< "SnaBI"<< "XmaCI"<< "BstEII"<< "NcoI"<< "ClaI"<< "DraII"<< "Eco47III"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "PvuI"<< "BseAI"<< "DpnI"<< "Van91I"<< "Bst1107I"<< "BsiWI"<< "TaqI"<< "SexAI"<< "KpnI"<< "NdeI"<< "PinAI"<< "BglII"<< "NaeI"<< "MaeI"<< "AspI"<< "NruI"<< "MvaI"<< "BpuAI"<< "NarI"<< "RsaI"<< "MaeII"<< "AflIII"<< "AspEI"<< "XbaI"<< "Sau3AI"<< "MvnI"<< "AluI"<< "RsrII"<< "EcoRII"<< "CfoI"<< "SmaI"<< "NheI"<< "StuI"<< "BbrPI"<< "SphI"<< "MaeIII"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "DraIII"<< "MluNI"<< "EcoRV"<< "AatII"<< "EcoRI"<< "XhoI"<< "MunI"<< "EclXI"<< "PstI"<< "BsmI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "SgrAI"<< "NsiI"<< "ItaI"<< "ApaI"<< "SfuI"<< "ScaI"<< "BfrI"<< "NspI"<< "KspI"<< "Tru9I"<< "DdeI"<< "NotI"<< "MroI"<< "Asp700I"<< "HindIII"<< "AcyI"<< "RcaI"<< "BamHI"<< "AviII"<< "AvaII"<< "CelII"<< "HpaI"<< "StyI"<< "HindII""BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "Asp718I"<< "MspI"<< "SnaBI"<< "XmaCI"<< "BstEII"<< "NcoI"<< "ClaI"<< "DraII"<< "Eco47III"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "PvuI"<< "BseAI"<< "DpnI"<< "Van91I"<< "Bst1107I"<< "BsiWI"<< "TaqI"<< "SexAI"<< "KpnI"<< "NdeI"<< "PinAI"<< "BglII"<< "NaeI"<< "MaeI"<< "AspI"<< "NruI"<< "MvaI"<< "BpuAI"<< "NarI"<< "RsaI"<< "MaeII"<< "AflIII"<< "AspEI"<< "XbaI"<< "Sau3AI"<< "MvnI"<< "AluI"<< "RsrII"<< "EcoRII"<< "CfoI"<< "SmaI"<< "NheI"<< "StuI"<< "BbrPI"<< "SphI"<< "MaeIII"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "DraIII"<< "MluNI"<< "EcoRV"<< "AatII"<< "EcoRI"<< "XhoI"<< "MunI"<< "EclXI"<< "PstI"<< "BsmI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "SgrAI"<< "NsiI"<< "ItaI"<< "ApaI"<< "SfuI"<< "ScaI"<< "BfrI"<< "NspI"<< "KspI"<< "Tru9I"<< "DdeI"<< "NotI"<< "MroI"<< "Asp700I"<< "HindIII"<< "AcyI"<< "RcaI"<< "BamHI"<< "AviII"<< "AvaII"<< "CelII"<< "HpaI"<< "StyI"<< "HindII";
        Suppliers["Roche Applied Science"]=tmp;
        tmp.clear();
        //==============================================================================
        //10-New England Biolabs
        tmp<<"BssHII"<< "EciI"<< "BsrFI"<< "DpnII"<< "AlwI"<< "MluI"<< "NgoMIV"<< "HpaII"<< "TspMI"<< "BclI"<< "MlyI"<< "BsaWI"<< "SacI"<< "MwoI"<< "BfaI"<< "DrdI"<< "BmgBI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "MslI"<< "BmtI"<< "PspXI"<< "BsaBI"<< "SnaBI"<< "BstEII"<< "TspRI"<< "NcoI"<< "MspA1I"<< "BtgI"<< "ClaI"<< "BsaI"<< "BsrBI"<< "AlwNI"<< "XmnI"<< "DraI"<< "Hpy166II"<< "Hpy99I"<< "StyD4I"<< "BstXI"<< "PspGI"<< "BsiHKAI"<< "BlpI"<< "PshAI"<< "XmaI"<< "SwaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "CspCI"<< "PflFI"<< "BpuEI"<< "BsiWI"<< "TaqI"<< "EaeI"<< "SexAI"<< "BsrI"<< "AseI"<< "KpnI"<< "Sau96I"<< "BstNI"<< "HaeII"<< "AclI"<< "ApoI"<< "HpyCH4IV"<< "NdeI"<< "MboII"<< "AflII"<< "TseI"<< "BglII"<< "SmlI"<< "NaeI"<< "Bpu10I"<< "SacII"<< "Acc65I"<< "BspQI"<< "AvrII"<< "NruI"<< "BaeI"<< "BtsCI"<< "BssKI"<< "PciI"<< "PhoI"<< "BcgI"<< "BsaHI"<< "SfoI"<< "TliI"<< "NarI"<< "Bsu36I"<< "RsaI"<< "HincII"<< "AflIII"<< "BsgI"<< "XbaI"<< "Sau3AI"<< "BfuAI"<< "TfiI"<< "PmlI"<< "BbvI"<< "MboI"<< "HgaI"<< "BanI"<< "AluI"<< "BaeGI"<< "ZraI"<< "Hpy188III"<< "RsrII"<< "BspMI"<< "AciI"<< "ScrFI"<< "MscI"<< "BseYI"<< "CviQI"<< "BmrI"<< "Hpy188I"<< "SmaI"<< "PleI"<< "EcoNI"<< "NheI"<< "BccI"<< "BsiEI"<< "StuI"<< "BspCNI"<< "SphI"<< "HpyAV"<< "NciI"<< "FspI"<< "CviAII"<< "PvuII"<< "Eco53kI"<< "MfeI"<< "BsrDI"<< "BssSI"<< "FokI"<< "ApaLI"<< "ApeKI"<< "SpeI"<< "HinfI"<< "BciVI"<< "HinP1I"<< "BceAI"<< "HphI"<< "BsmAI"<< "DraIII"<< "EcoO109I"<< "BtsI"<< "SapI"<< "PpuMI"<< "EcoRV"<< "PsiI"<< "AatII"<< "EcoRI"<< "BsmFI"<< "XhoI"<< "Bsp1286I"<< "PspOMI"<< "MnlI"<< "EagI"<< "AscI"<< "AhdI"<< "NlaIII"<< "SbfI"<< "BsoBI"<< "PstI"<< "Tsp509I"<< "MseI"<< "FauI"<< "SfcI"<< "BspEI"<< "BsmI"<< "SfiI"<< "BstUI"<< "BstZ17I"<< "KasI"<< "HaeIII"<< "BsmBI"<< "XcmI"<< "BstAPI"<< "AccI"<< "SspI"<< "HpyCH4III"<< "BsrGI"<< "AfeI"<< "Tth111I"<< "SgrAI"<< "NsiI"<< "BspHI"<< "BstYI"<< "PmeI"<< "FseI"<< "ApaI"<< "BseRI"<< "MmeI"<< "ScaI"<< "AgeI"<< "BtgZI"<< "BpmI"<< "EarI"<< "CviKI_1"<< "AcuI"<< "BfuCI"<< "NspI"<< "PacI"<< "BstBI"<< "HpyCH4V"<< "NlaIV"<< "BbsI"<< "DdeI"<< "NotI"<< "BsaXI"<< "HindIII"<< "FatI"<< "BamHI"<< "BslI"<< "AvaII"<< "BspDI"<< "PaeR7I"<< "SfaNI"<< "HpaI"<< "BsaJI"<< "BbvCI"<< "Fnu4HI"<< "Cac8I"<< "Tsp45I"<< "StyI"<< "PflMI"<< "HhaI"<< "AsiSI"<< "AleI"<< "NmeAIII"<< "BsaAI";
        Suppliers["New England Biolabs"]=tmp;
        tmp.clear();
        //==============================================================================
        //11-Toyobo Biochemicals
        tmp<<"BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "BstEII"<< "NcoI"<< "Eco47III"<< "DraI"<< "BstXI"<< "Cfr9I"<< "AvaI"<< "PvuI"<< "DpnI"<< "BsiWI"<< "TaqI"<< "Eco52I"<< "AseI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "Cfr13I"<< "MboII"<< "TspEI"<< "BglII"<< "NaeI"<< "SacII"<< "NruI"<< "MvaI"<< "CspI"<< "NarI"<< "Eco47I"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "Cfr10I"<< "BanIII"<< "BanI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "MscI"<< "Csp45I"<< "SmaI"<< "NheI"<< "BbrPI"<< "SphI"<< "NciI"<< "FspI"<< "PvuII"<< "EheI"<< "Hin1I"<< "SpeI"<< "HinfI"<< "PpuMI"<< "EcoRV"<< "PsiI"<< "AatII"<< "EcoRI"<< "AatI"<< "XhoI"<< "SbfI"<< "Eco105I"<< "PstI"<< "BsmI"<< "Alw44I"<< "SfiI"<< "HaeIII"<< "AccI"<< "SspI"<< "SrfI"<< "Eco81I"<< "ApaI"<< "EcoT22I"<< "ScaI"<< "NspV"<< "BfrI"<< "PacI"<< "DdeI"<< "NotI"<< "MroI"<< "HindIII"<< "BamHI"<< "HpaI"<< "HhaI""BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "BstEII"<< "NcoI"<< "Eco47III"<< "DraI"<< "BstXI"<< "Cfr9I"<< "AvaI"<< "PvuI"<< "DpnI"<< "BsiWI"<< "TaqI"<< "Eco52I"<< "AseI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "Cfr13I"<< "MboII"<< "TspEI"<< "BglII"<< "NaeI"<< "SacII"<< "NruI"<< "MvaI"<< "CspI"<< "NarI"<< "Eco47I"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "Cfr10I"<< "BanIII"<< "BanI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "MscI"<< "Csp45I"<< "SmaI"<< "NheI"<< "BbrPI"<< "SphI"<< "NciI"<< "FspI"<< "PvuII"<< "EheI"<< "Hin1I"<< "SpeI"<< "HinfI"<< "PpuMI"<< "EcoRV"<< "PsiI"<< "AatII"<< "EcoRI"<< "AatI"<< "XhoI"<< "SbfI"<< "Eco105I"<< "PstI"<< "BsmI"<< "Alw44I"<< "SfiI"<< "HaeIII"<< "AccI"<< "SspI"<< "SrfI"<< "Eco81I"<< "ApaI"<< "EcoT22I"<< "ScaI"<< "NspV"<< "BfrI"<< "PacI"<< "DdeI"<< "NotI"<< "MroI"<< "HindIII"<< "BamHI"<< "HpaI"<< "HhaI";
        Suppliers["Toyobo Biochemicals"]=tmp;
        tmp.clear();
        //==============================================================================
        //12-Molecular Biology Resources - CHIMERx
        tmp<<"BssHII"<< "MluI"<< "HpaII"<< "BspTNI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "NcoI"<< "CviJI"<< "DraI"<< "BstXI"<< "AcvI"<< "PvuI"<< "TaqI"<< "SinI"<< "KpnI"<< "NdeI"<< "PinAI"<< "MboII"<< "BglII"<< "SacII"<< "NruI"<< "NarI"<< "TaqII"<< "RsaI"<< "HincII"<< "XbaI"<< "MboI"<< "AluI"<< "RsrII"<< "SmaI"<< "StuI"<< "SphI"<< "FokI"<< "SpeI"<< "HinfI"<< "BsiHKCI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "MnlI"<< "PstI"<< "SfiI"<< "HaeIII"<< "SspI"<< "Tth111I"<< "ApaI"<< "ScaI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI""BssHII"<< "MluI"<< "HpaII"<< "BspTNI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "NcoI"<< "CviJI"<< "DraI"<< "BstXI"<< "AcvI"<< "PvuI"<< "TaqI"<< "SinI"<< "KpnI"<< "NdeI"<< "PinAI"<< "MboII"<< "BglII"<< "SacII"<< "NruI"<< "NarI"<< "TaqII"<< "RsaI"<< "HincII"<< "XbaI"<< "MboI"<< "AluI"<< "RsrII"<< "SmaI"<< "StuI"<< "SphI"<< "FokI"<< "SpeI"<< "HinfI"<< "BsiHKCI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "MnlI"<< "PstI"<< "SfiI"<< "HaeIII"<< "SspI"<< "Tth111I"<< "ApaI"<< "ScaI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI";
        Suppliers["Molecular Biology Resources - CHIMERx"]=tmp;
        tmp.clear();
        //==============================================================================
        //13-Promega Corporation
        tmp<<"BssHII"<< "MluI"<< "NgoMIV"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "BstOI"<< "MspI"<< "BanII"<< "SnaBI"<< "BstEII"<< "NcoI"<< "MspA1I"<< "ClaI"<< "XmnI"<< "Eco47III"<< "DraI"<< "BstXI"<< "XmaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "BbuI"<< "TaqI"<< "SinI"<< "KpnI"<< "HaeII"<< "NdeI"<< "MboII"<< "BglII"<< "NaeI"<< "SacII"<< "Acc65I"<< "NruI"<< "CspI"<< "NarI"<< "Bsu36I"<< "Bst98I"<< "RsaI"<< "HincII"<< "XbaI"<< "BsrSI"<< "Sau3AI"<< "MboI"<< "BanI"<< "AluI"<< "CfoI"<< "Csp45I"<< "AccB7I"<< "SmaI"<< "NheI"<< "XhoII"<< "StuI"<< "SphI"<< "NciI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "SgfI"<< "EcoRV"<< "AatII"<< "EcoRI"<< "XhoI"<< "Bsp1286I"<< "AccIII"<< "PstI"<< "VspI"<< "BstZI"<< "Alw44I"<< "SfiI"<< "Hsp92I"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "Tth111I"<< "NsiI"<< "ApaI"<< "ScaI"<< "AgeI"<< "BsaMI"<< "BalI"<< "Tru9I"<< "Hsp92II"<< "DdeI"<< "NotI"<< "HindIII"<< "EcoICRI"<< "BamHI"<< "AvaII"<< "HpaI"<< "StyI"<< "HhaI";
        Suppliers["Promega Corporation"]=tmp;
        tmp.clear();
        //==============================================================================
        //14-Sigma Chemical Corporation
        tmp<<"BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "DraI"<< "SwaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "TaqI"<< "KpnI"<< "NdeI"<< "BglII"<< "MvaI"<< "RsaI"<< "XbaI"<< "Sau3AI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "CfoI"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "PvuII"<< "SpeI"<< "MluNI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "EclXI"<< "PstI"<< "BsmI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "ScaI"<< "KspI"<< "DdeI"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HpaI"<< "StyI"<< "HindII""BssHII"<< "MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "DraI"<< "SwaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "TaqI"<< "KpnI"<< "NdeI"<< "BglII"<< "MvaI"<< "RsaI"<< "XbaI"<< "Sau3AI"<< "AluI"<< "ScrFI"<< "EcoRII"<< "CfoI"<< "SmaI"<< "NheI"<< "StuI"<< "SphI"<< "PvuII"<< "SpeI"<< "MluNI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "EclXI"<< "PstI"<< "BsmI"<< "SfiI"<< "BlnI"<< "HaeIII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "ScaI"<< "KspI"<< "DdeI"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HpaI"<< "StyI"<< "HindII";
        Suppliers["Sigma Chemical Corporation"]=tmp;
        tmp.clear();
        //==============================================================================
        //15-Bangalore Genei
        tmp<<"MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "XmnI"<< "DraI"<< "XmaI"<< "AvaI"<< "PvuI"<< "AssI"<< "TaqI"<< "KpnI"<< "Sau96I"<< "BglII"<< "NaeI"<< "NruI"<< "NarI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "StrI"<< "MboI"<< "BanI"<< "AluI"<< "SmaI"<< "BasI"<< "NheI"<< "StuI"<< "PvuII"<< "ApaLI"<< "SpeI"<< "HinfI"<< "MvrI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "SfiI"<< "HaeIII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI"<< "HhaI""MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BstEII"<< "NcoI"<< "ClaI"<< "XmnI"<< "DraI"<< "XmaI"<< "AvaI"<< "PvuI"<< "AssI"<< "TaqI"<< "KpnI"<< "Sau96I"<< "BglII"<< "NaeI"<< "NruI"<< "NarI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "StrI"<< "MboI"<< "BanI"<< "AluI"<< "SmaI"<< "BasI"<< "NheI"<< "StuI"<< "PvuII"<< "ApaLI"<< "SpeI"<< "HinfI"<< "MvrI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "SfiI"<< "HaeIII"<< "AccI"<< "SspI"<< "NsiI"<< "ApaI"<< "NotI"<< "HindIII"<< "BamHI"<< "HpaI"<< "HhaI";
        Suppliers["Bangalore Genei"]=tmp;
        tmp.clear();
        //==============================================================================
        //16-Vivantis Technologies
        tmp<<"BssMI"<< "AsuNHI"<< "MluI"<< "BstHHI"<< "HpaII"<< "AhlI"<< "BglI"<< "SalI"<< "MspI"<< "VneI"<< "BstH2I"<< "BmtI"<< "AsiGI"<< "CciNI"<< "Sfr274I"<< "SmiI"<< "Ksp22I"<< "BssT1I"<< "MspA1I"<< "Bsp19I"<< "Bse1I"<< "AspS9I"<< "BmcAI"<< "FauNDI"<< "DraI"<< "Bst2UI"<< "Vha464I"<< "BstXI"<< "BstDEI"<< "XmaI"<< "BstF5I"<< "BpvUI"<< "BstMBI"<< "BstENI"<< "Ama87I"<< "BstDSI"<< "BstV2I"<< "AspLEI"<< "Zsp2I"<< "DseDI"<< "BstAUI"<< "Bpu14I"<< "TaqI"<< "KpnI"<< "BstSNI"<< "AclI"<< "MboII"<< "BmrFI"<< "BglII"<< "AcsI"<< "BstNSI"<< "BmeRI"<< "BseX3I"<< "Bpu10I"<< "Rsr2I"<< "Acc65I"<< "BtuMI"<< "PspEI"<< "Bst2BI"<< "SmiMI"<< "Bse118I"<< "BsnI"<< "BmiI"<< "BsePI"<< "BstMCI"<< "Bme18I"<< "RsaI"<< "BssNAI"<< "Bsp13I"<< "Bst4CI"<< "AsuHPI"<< "BtrI"<< "XbaI"<< "Psp124BI"<< "BstX2I"<< "AluI"<< "ZraI"<< "Bse21I"<< "Sfr303I"<< "BpuMI"<< "Bse3DI"<< "Bso31I"<< "AccB7I"<< "AccBSI"<< "SmaI"<< "AspA2I"<< "Bsp1720I"<< "SphI"<< "FriOI"<< "PvuII"<< "ErhI"<< "BshVI"<< "FokI"<< "HinfI"<< "BstPAI"<< "HspAI"<< "DraIII"<< "Acc16I"<< "EcoRV"<< "AatII"<< "MroXI"<< "EcoRI"<< "DinI"<< "BstFNI"<< "AfiI"<< "PspOMI"<< "MnlI"<< "SbfI"<< "PstI"<< "Bse8I"<< "VspI"<< "SfiI"<< "Bst6I"<< "Msp20I"<< "Bbv12I"<< "SspI"<< "Tth111I"<< "BstMAI"<< "ApaI"<< "FblI"<< "PctI"<< "AccB1I"<< "BssNI"<< "PceI"<< "Sse9I"<< "Tru9I"<< "MhlI"<< "BstBAI"<< "MroNI"<< "HindIII"<< "EcoICRI"<< "BamHI"<< "SfaNI"<< "HpaI"<< "PspCI"<< "HindII";
        Suppliers["Vivantis Technologies"]=tmp;
        tmp.clear();
        //==============================================================================
        //17-MP Biomedicals
        tmp<<"MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "BstEII"<< "NcoI"<< "DraII"<< "XmnI"<< "Eco47III"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "TaqI"<< "SinI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "NdeI"<< "MboII"<< "BglII"<< "SacII"<< "Acc65I"<< "BspXI"<< "NruI"<< "MvaI"<< "NarI"<< "RsaI"<< "HincII"<< "AflIII"<< "XbaI"<< "Sau3AI"<< "MboI"<< "AluI"<< "SmaI"<< "NheI"<< "XhoII"<< "SphI"<< "NciI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "DraIII"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "MnlI"<< "AccIII"<< "EagI"<< "AscI"<< "NlaIII"<< "PstI"<< "BsmI"<< "SfiI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "Tth111I"<< "NsiI"<< "PmeI"<< "ApaI"<< "ScaI"<< "PacI"<< "NlaIV"<< "Tru9I"<< "DdeI"<< "NotI"<< "HindIII"<< "BamHI"<< "BslI"<< "AvaII"<< "HpaI"<< "HhaI""MluI"<< "HpaII"<< "BclI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "BstEII"<< "NcoI"<< "DraII"<< "XmnI"<< "Eco47III"<< "DraI"<< "BstXI"<< "SwaI"<< "AvaI"<< "PvuI"<< "DpnI"<< "TaqI"<< "SinI"<< "KpnI"<< "Sau96I"<< "HaeII"<< "NdeI"<< "MboII"<< "BglII"<< "SacII"<< "Acc65I"<< "BspXI"<< "NruI"<< "MvaI"<< "NarI"<< "RsaI"<< "HincII"<< "AflIII"<< "XbaI"<< "Sau3AI"<< "MboI"<< "AluI"<< "SmaI"<< "NheI"<< "XhoII"<< "SphI"<< "NciI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "DraIII"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "MnlI"<< "AccIII"<< "EagI"<< "AscI"<< "NlaIII"<< "PstI"<< "BsmI"<< "SfiI"<< "HaeIII"<< "NdeII"<< "AccI"<< "SspI"<< "Tth111I"<< "NsiI"<< "PmeI"<< "ApaI"<< "ScaI"<< "PacI"<< "NlaIV"<< "Tru9I"<< "DdeI"<< "NotI"<< "HindIII"<< "BamHI"<< "BslI"<< "AvaII"<< "HpaI"<< "HhaI";
        Suppliers["MP Biomedicals"]=tmp;
        tmp.clear();
        //==============================================================================
        //18-EURx Ltd
        tmp<<"BssHII"<< "MluI"<< "HpaII"<< "BspTNI"<< "SacI"<< "BglI"<< "SalI"<< "MspI"<< "BanII"<< "NcoI"<< "CviJI"<< "DraI"<< "BstXI"<< "AcvI"<< "AvaI"<< "PvuI"<< "DpnI"<< "TaqI"<< "SinI"<< "KpnI"<< "NdeI"<< "PinAI"<< "MboII"<< "BglII"<< "SacII"<< "NruI"<< "NarI"<< "TaqII"<< "RsaI"<< "HincII"<< "XbaI"<< "Sau3AI"<< "TspGWI"<< "MboI"<< "AluI"<< "RsrII"<< "SmaI"<< "StuI"<< "SphI"<< "PvuII"<< "FokI"<< "SpeI"<< "HinfI"<< "BsiHKCI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "MnlI"<< "PstI"<< "SfiI"<< "HaeIII"<< "AccI"<< "SspI"<< "Tth111I"<< "ApaI"<< "MmeI"<< "ScaI"<< "TspDTI"<< "BalI"<< "NotI"<< "HindIII"<< "BamHI"<< "BsuTUI"<< "HpaI";
        Suppliers["EURx Ltd"]=tmp;
        tmp.clear();
        //==============================================================================
        //19-CinnaGen Inc
        tmp<<"BclI"<< "BglI"<< "SalI"<< "MspI"<< "NcoI"<< "DraI"<< "PvuI"<< "TaqI"<< "KpnI"<< "NdeI"<< "BglII"<< "RsaI"<< "HincII"<< "XbaI"<< "MboI"<< "AluI"<< "SmaI"<< "PvuII"<< "HinfI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "HaeIII"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HhaI""BclI"<< "BglI"<< "SalI"<< "MspI"<< "NcoI"<< "DraI"<< "PvuI"<< "TaqI"<< "KpnI"<< "NdeI"<< "BglII"<< "RsaI"<< "HincII"<< "XbaI"<< "MboI"<< "AluI"<< "SmaI"<< "PvuII"<< "HinfI"<< "EcoRV"<< "EcoRI"<< "XhoI"<< "PstI"<< "HaeIII"<< "NotI"<< "HindIII"<< "BamHI"<< "AvaII"<< "HhaI";
        Suppliers["CinnaGen Inc"]=tmp;
        tmp.clear();
        //==============================================================================



}


} // namespace BioQt
