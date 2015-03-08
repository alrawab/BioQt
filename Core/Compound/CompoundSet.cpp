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

#include "CompoundSet.h"

namespace BioQt {

const QStringList CompoundSet::AmbiguityDNACompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"C"<<"G"<<"T"<<
         "M"<<"R"<<"W"<<"S"<<
         "Y"<<"K"<<"V"<<"H"<<
         "D"<<"B"<<"N";
    return  tmp;
}

const QStringList CompoundSet::DNACompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"C"<<"G"<<"T";

    return  tmp;

}

const QStringList CompoundSet::AmbiguityRNACompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"C"<<"G"<<"U"<<
         "M"<<"R"<<"W"<<"S"<<
         "Y"<<"K"<<"V"<<"H"<<
         "D"<<"B"<<"N";
    return  tmp;
}

const QStringList CompoundSet::RNACompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"C"<<"G"<<"U";

    return  tmp;

}

const QStringList CompoundSet::ExtendedProteinCompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"R"<<"N"<<"D"<<"C"<<
         "Q"<<"E"<<"G"<<"H"<<"I"<<
         "L"<<"K"<<"M"<<"F"<<"P"<<
         "S"<<"T"<<"W"<<"Y"<<"V"<<
         "B"<<"Z"<<"J"<<"X";

    return  tmp;
}
const QStringList CompoundSet::ProteinCompoundSet()
{
    QStringList tmp;
    tmp<<"A"<<"R"<<"N"<<"D"<<"C"<<
         "Q"<<"E"<<"G"<<"H"<<"I"<<
         "L"<<"K"<<"M"<<"F"<<"P"<<
         "S"<<"T"<<"W"<<"Y"<<"V";

    return  tmp;

}
} // namespace BioQt
