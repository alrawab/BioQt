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
*BioQt::IsoelectricPoint
*@author Usama S Erawab
*
*/

#include "IsoelectricPoint.h"
#include <memory>
namespace BioQt {

//http://www.its.caltech.edu/~ppmal/sample_prep/work3.html
QMap<QString,double> AminoAcidResidueMasses()
{
    QMap<QString,double> tmp;
    tmp["G"]=57.052;
    tmp["A"]=71.079;
    tmp["S"]=87.078;
    tmp["P"]=97.117;
    tmp["V"]=99.113;
    tmp["T"]=101.105;
    tmp["C"]=103.144;
    tmp["I"]=113.160;
    tmp["L"]=113.160;
    tmp["N"]=104.104;
    tmp["D"]=115.089;
    tmp["Q"]=128.131;
    tmp["K"]=128.174;
    tmp["E"]=129.116;
    tmp["M"]=131.198;
    tmp["H"]=137.142;
    tmp["F"]=147.177;
    tmp["R"]=156.188;
    tmp["Y"]=163.170;
    tmp["W"]=186.213;
    return tmp;
}


IsoelectricPoint::IsoelectricPoint(const QSequence&_seq)
    :seq(_seq)
{
    // plys=new ProteinAnalysis(_seq);
    // aacidscount=plys->CountAminoAcids();


}

QMap<QString, double> IsoelectricPoint::GetPKmap(Method method)
{
    QMap<QString, double> tmp;
    switch (method) {
    case DavidTabb:
        tmp["Cterm"]=3.55;
        tmp["D"]=4.05;
        tmp["E"]=4.25;
        tmp["C"]=9.0;
        tmp["Y"]=10.0;
        tmp["H"]=5.98;
        tmp["Nterm"]=7.5;
        tmp["K"]=10.0;
        tmp["R"]=12.0;
        break;
    case EMBOSS:
        tmp["Cterm"]=3.6;
        tmp["D"]=3.9;
        tmp["E"]=4.1;
        tmp["C"]=8.5;
        tmp["Y"]=10.1;
        tmp["H"]=6.5;
        tmp["Nterm"]=8.6;
        tmp["K"]=10.8;
        tmp["R"]=12.5;
        break;
    case DTASelect:
        tmp["Cterm"]=3.1;
        tmp["D"]=4.4;
        tmp["E"]=4.4;
        tmp["C"]=8.5;
        tmp["Y"]=10.0;
        tmp["H"]=6.5;
        tmp["Nterm"]=8.0;
        tmp["K"]=10.0;
        tmp["R"]=12.0;
        break;
    case Solomon:
        tmp["Cterm"]=2.4;
        tmp["D"]=3.9;
        tmp["E"]=4.3;
        tmp["C"]=8.3;
        tmp["Y"]=10.1;
        tmp["H"]=6.0;
        tmp["Nterm"]=9.6;
        tmp["K"]=10.5;
        tmp["R"]=12.5;
        break;
    case Sillero:
        tmp["Cterm"]=3.2;
        tmp["D"]=4.0;
        tmp["E"]=4.5;
        tmp["C"]=9.0;
        tmp["Y"]=10.0;
        tmp["H"]=6.4;
        tmp["Nterm"]=8.2;
        tmp["K"]=10.4;
        tmp["R"]=12.0;
        break;
    case Rodwell:
        tmp["Cterm"]=3.1;
        tmp["D"]=3.68;
        tmp["E"]=4.25;
        tmp["C"]=8.33;
        tmp["Y"]=10.07;
        tmp["H"]=6.0;
        tmp["Nterm"]=8.0;
        tmp["K"]=11.5;
        tmp["R"]=11.5;
        break;
    case Patrickios:
        tmp["Cterm"]=4.2;
        tmp["D"]=4.2;
        tmp["E"]=4.2;
        tmp["C"]=0.0;
        tmp["Y"]=0.0;
        tmp["H"]=0.0;
        tmp["Nterm"]=11.2;
        tmp["K"]=11.2;
        tmp["R"]=11.2;
        break;
    default://ToDo raise exception
        break;
    }
    return tmp;

}

double IsoelectricPoint::PI(IsoelectricPoint::Method method)
{
    double pKCterm, pKD, pKE, pKC, pKY, pKH, pKNterm, pKK, pKR;
    QMap<QString, double> tmp=GetPKmap(method);
    pKCterm=tmp["Cterm"];
    pKD=tmp["D"];
    pKE=tmp["E"];
    pKC=tmp["C"];
    pKY=tmp["Y"];
    pKH=tmp["H"];
    pKNterm=tmp["Nterm"];
    pKK=tmp["K"];
    pKR=tmp["R"];

    std::auto_ptr<ProteinAnalysis> dd(new ProteinAnalysis(seq));
    QMap<QString, int> AACount=dd->CountAminoAcids();

    int ProteinLength=0;
    double mass = 18.01524;// add water molecule

    for(int i=0;i<QIUPACData::Protein_Chars.size();++i)
    {
        ProteinLength +=AACount[QIUPACData::Protein_Chars[i]] ;
        mass +=AACount[QIUPACData::Protein_Chars[i]]*AminoAcidResidueMasses()[QIUPACData::Protein_Chars[i]];

    }

    double NQ = 0.0; //net chare in given pH

    double QN1=0;  //C-terminal charge
    double QN2=0;  //D charge
    double QN3=0;  //E charge
    double QN4=0;  //C charge
    double QN5=0;  //Y charge
    double QP1=0;  //H charge
    double QP2=0;  //NH2 charge
    double QP3=0;  //K charge
    double QP4=0;  //R charge

    double pH = 6.5;             //starting point pI = 6.5 - theoretically it should be 7, but
    //average protein pI is 6.5 so we increase the probability
    double pHprev = 0.0;         //of finding the solution
    double pHnext = 14.0;        //0-14 is possible pH range

    double E = 0.01;             //epsilon means precision [pI = pH ? E]
    double temp = 0.0;

    Q_FOREVER
    {
        QN1=-1/(1+pow(10,(pKCterm-pH)));
        QN2=-AACount["D"]/(1+pow(10,(pKD-pH)));
        QN3=-AACount["E"]/(1+pow(10,(pKE-pH)));
        QN4=-AACount["C"]/(1+pow(10,(pKC-pH)));
        QN5=-AACount["Y"]/(1+pow(10,(pKY-pH)));
        QP1=AACount["H"]/(1+pow(10,(pH-pKH)));
        QP2=1/(1+pow(10,(pH-pKNterm)));
        QP3=AACount["K"]/(1+pow(10,(pH-pKK)));
        QP4=AACount["R"]/(1+pow(10,(pH-pKR)));

        NQ=QN1+QN2+QN3+QN4+QN5+QP1+QP2+QP3+QP4;
        if(NQ<0)              //we are out of range, thus the new pH value must be smaller
        {
            temp = pH;
            pH = pH-((pH-pHprev)/2);
            pHnext = temp;

        }
        else                  //we used to small pH value, so we have to increase it
        {
            temp = pH;
            pH = pH + ((pHnext-pH)/2);
            pHprev = temp;


        }

        if ((pH-pHprev<E)&&(pHnext-pH<E)) //terminal condition, finding pI with given precision
            break;

    }
//qDebug()<<pH<<" "<<mass;



    return pH;

}

} // namespace BioQt
