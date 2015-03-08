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

#ifndef BIOQT_GENETICCODEQUERY_H
#define BIOQT_GENETICCODEQUERY_H

#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/DNATranslation/GeneticCodeData.h>

namespace BioQt {

class BIOQTSHARED_EXPORT GeneticCodeQuery
{
public:
    /**
 * @brief GetTransList
 * source: http://www.ncbi.nlm.nih.gov/Taxonomy/Utils/wprintgc.cgi
 * http://www.bioinformatics.org/jambw/2/3/TranslationTables.html
 * @return
 */
static QList<GeneticCode> GetTransList();
static GeneticCode  recod(const QString& Tbn);
static GeneticCode  recod(int Tbn);
static QStringList GettbNames();
static QList<int>  GettbIds();
static QMap<QString,QStringList> GetRoles(int Tbn);
static QMap<QString,QStringList> GetRoles(const QString& Tbn);
    //GeneticCodeQuery();
  //  ~GeneticCodeQuery();
};

} // namespace BioQt

#endif // BIOQT_GENETICCODEQUERY_H
