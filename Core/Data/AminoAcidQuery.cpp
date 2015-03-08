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

#include "AminoAcidQuery.h"

namespace BioQt {

const AminInfoTable AminoAcidQuery::GetAminoTb(const QString &name)const throw (UnCompatibleCharException)
{

  //  alpha=new Protein();
QString _name;
    if (name.length()==1){
       _name=QIUPACData::Amino_Names()[QIUPACData::Amino_Names_1Lto3L()[name.toUpper()]];
    }
else if(name.length()==3)
        _name=QIUPACData::Amino_Names()[name[0].toUpper()+name.mid(1).toLower()];
    else
        _name=name;
  //  alpha=new Protein();


   // if(!alpha->isCharInAlphabet(name.toUpper()))
   //     throw UnCompatibleCharException(name + " Is Uncompatible letter");

    foreach(AminInfoTable c,QIUPACData::AminAcidPropertiesTable())
    {
        if(QString::compare(c.name(),_name,caseMode)==0)
        {

           return c;

        }
    }
}

} // namespace BioQt
