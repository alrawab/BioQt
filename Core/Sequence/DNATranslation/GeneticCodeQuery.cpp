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

#include "GeneticCodeQuery.h"

namespace BioQt {

QList<GeneticCode> GeneticCodeQuery::GetTransList()
{
    QList<GeneticCode> tmp;

    tmp<<GeneticCode("FFLLSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "---L---------------L---------------M----------------------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     1,
                     "Standard") ;

    tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNKKSS**VVVVAAAADDEEGGGG",
                     "--------------------------------LLLM---------------L------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     2,
                     "Vertebrate Mitochondrial");

    tmp<<GeneticCode("FFLLSSSSYY**CCWWTTTTPPPPHHQQRRRRIIMMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "----------------------------------LM----------------------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     3,
                     "Yeast Mitochondrial");

    tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "--LL---------------L------------LLLM---------------L------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     4,
                     "Protozoan Mitochondrial");


    tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNKKSSSSVVVVAAAADDEEGGGG",
                     "---L----------------------------LLLM---------------L------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     5,
                     "Invertebrate Mitochondrial");


    tmp<<GeneticCode("FFLLSSSSYYQQCC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "-----------------------------------M----------------------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     6,
                     "Ciliate Nuclear");


    tmp<<GeneticCode( "FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNNKSSSSVVVVAAAADDEEGGGG",
                      "-----------------------------------M---------------L------------",
                      "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                      "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                      "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                      9,
                      "Flatworm Mitochondrial");

    tmp<<GeneticCode("FFLLSSSSYY**CCCWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "-----------------------------------M----------------------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     10,
                     "Euplotid Nuclear");

    tmp<<GeneticCode("FFLLSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                     "---L---------------L------------LLLM---------------L------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     11,
                     "Plant Plastid");


    tmp<<GeneticCode("FFLLSSSSYY**CC*WLLLSPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                      "-------------------L---------------M----------------------------",
                      "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                      "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                      "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                      12,
                      "Alternative Yeast Nuclear");

    tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNKKSSGGVVVVAAAADDEEGGGG",
                     "---L------------------------------LM---------------L------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     13,
                     "Ascidian Mitochondrial");

    tmp<<GeneticCode("FFLLSSSSYYY*CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNNKSSSSVVVVAAAADDEEGGGG",
                     "-----------------------------------M----------------------------",
                     "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                     "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                     "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                     14,
                     "Alternative Flatworm Mitochondrial");

   tmp<<GeneticCode("FFLLSSSSYY*QCC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                    "-----------------------------------M----------------------------",
                    "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                    "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                    "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                    15,
                    "Blepharisma Nuclear");

   tmp<<GeneticCode("FFLLSSSSYY*LCC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                    "-----------------------------------M----------------------------",
                    "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                    "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                    "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                    16,
                    "Chlorophycean Mitochondrial");

  tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNNKSSSSVVVVAAAADDEEGGGG",
                   "-----------------------------------M---------------L------------",
                   "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                   "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                   "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                   21,
                   "Trematode Mitochondrial");
  tmp<<GeneticCode("FFLLSS*SYY*LCC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                   "-----------------------------------M----------------------------",
                   "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                   "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                   "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                   22,
                   "Scenedesmus obliquus Mitochondrial");
  tmp<<GeneticCode("FF*LSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
                   "--------------------------------L--M---------------L------------",
                   "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                   "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                   "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                   23,
                   "Thraustochytrium Mitochondrial");

  tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSSKVVVVAAAADDEEGGGG",
                   "---M---------------M---------------M---------------M------------",
                   "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                   "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                   "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                   24,
                   "Pterobranchia Mitochondrial");


  tmp<<GeneticCode("FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSSKVVVVAAAADDEEGGGG",
                   "---M---------------M---------------M---------------M------------",
                   "TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG",
                   "TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG",
                   "TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG",
                   25,
                   "Candidate Division SR1 and Gracilibacteria");





return tmp;
}

GeneticCode GeneticCodeQuery::recod(const QString &Tbn)
{


for (int x=0;x< GeneticCodeQuery::GetTransList().size();++x)
{
 if(GeneticCodeQuery::GetTransList()[x].TbName()==Tbn)
     return GeneticCodeQuery::GetTransList()[x];
}

    return GeneticCode();


}

GeneticCode GeneticCodeQuery::recod(int Tbn)
{
    for (int x=0;x< GeneticCodeQuery::GetTransList().size();++x)
    {
     if(GeneticCodeQuery::GetTransList()[x].TbID()==Tbn)
         return GeneticCodeQuery::GetTransList()[x];
    }

    return GeneticCode();
}

QStringList GeneticCodeQuery::GettbNames()
{
    QStringList tmp;
    tmp<<"Standard"<<"Vertebrate Mitochondrial"<< "Yeast Mitochondrial"<<
         "Protozoan Mitochondrial"<<"Invertebrate Mitochondrial"<<"Ciliate Nuclear"<<
         "Flatworm Mitochondrial"<<"Euplotid Nuclear"<<"Plant Plastid"<<
         "Alternative Yeast Nuclear"<<"Ascidian Mitochondrial"<<"Alternative Flatworm Mitochondrial"<<
         "Blepharisma Nuclear"<<"Chlorophycean Mitochondrial"<<"Trematode Mitochondrial"<<
         "Scenedesmus obliquus Mitochondrial"<<"Thraustochytrium Mitochondrial"<<"Pterobranchia Mitochondrial"<<
         "Candidate Division SR1 and Gracilibacteria";

    return tmp;
}

QList<int> GeneticCodeQuery::GettbIds()
{
    QList<int> tmp;
    tmp<<1<<2<<3<<4<<5<<6<<
         9<<10<<11<<12<<13<<14<<15<<16<<
         21<<22<<23<<24<<25;
    return tmp;
}

QMap<QString, QStringList> GeneticCodeQuery::GetRoles(int Tbn)
{
GeneticCode Tmp = recod( Tbn);
QStringList StartCodon,StopCodon,StarAlternative;

for(int x=0;x<Tmp.Starts().size();++x)
{
    if(Tmp.Starts()[x]=='M')
    {
        StartCodon<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);
    }
    else if(Tmp.Starts()[x]=='L')
    {
        StarAlternative<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);

    }
    else if(Tmp.AMS()[x]=='*')
    {
        StopCodon<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);

    }
}
QMap<QString, QStringList> Lambda;
Lambda.insert("StartCodon",StartCodon);
Lambda.insert("StopCodon",StopCodon);
Lambda.insert("StartAlteranative",StarAlternative);

return Lambda;


}
//---

QMap<QString, QStringList> GeneticCodeQuery::GetRoles(const QString &Tbn)
{
    GeneticCode Tmp = recod( Tbn);
    QStringList StartCodon,StopCodon,StarAlternative;

    for(int x=0;x<Tmp.Starts().size();++x)
    {
        if(Tmp.Starts()[x]=='M')
        {
            StartCodon<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);
        }
        else if(Tmp.Starts()[x]=='L')
        {
            StarAlternative<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);

        }
        else if(Tmp.AMS()[x]=='*')
        {
            StopCodon<< QString("%1%2%3").arg(Tmp.Base1()[x]).arg(Tmp.Base2()[x]).arg(Tmp.Base3()[x]);

        }
    }
    QMap<QString, QStringList> Lambda;
    Lambda.insert("StartCodon",StartCodon);
    Lambda.insert("StopCodon",StopCodon);
    Lambda.insert("StartAlteranative",StarAlternative);

    return Lambda;

}


} // namespace BioQt

