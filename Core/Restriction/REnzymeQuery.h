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

#ifndef RENZYMEQUERY_H
#define RENZYMEQUERY_H

#include <QtCore>
#include <BioQt_global.h>
#include <Sequence/QSequence.h>
#include <Restriction/REnzyme.h>
#include <Restriction/REnzymeIO.h>
#include <Restriction/DigestTools.h>


namespace BioQt {

class BIOQTSHARED_EXPORT REnzymeQuery
{
public:
    REnzymeQuery(const QString& fn);
    QStringList GetEnzymeList(){return EnzymeNames;}
    QHash<QString,QString> GetPatrenList(){return PatrenList;}
    QHash<QString,REnzyme> GetEnzymeDic(){return EnzymeDic;};
    REnzyme  GetRecord(const QString& enzName);
    QList<int> GetCutSites(const QSequence& seq,const QString& enzName);
    QHash<QString,QList<int> > GetMultiCutSites(const QSequence& seq,QStringList enzList);
    QHash<QString,QStringList> GetSuppliers(){return Suppliers;}
    QStringList GetEnzymeDealer(const QString& enzName);





private:
    void PopulateData();

    QStringList EnzymeNames;
    QHash<QString,QString> PatrenList;
    QHash<QString,REnzyme> EnzymeDic;
    QVector<REnzyme> res;
    QHash<QString,QStringList> Suppliers;
    void PopulateSuppliersList();
};

} // namespace BioQt

#endif // BIOQT_RENZYMEQUERY_H
