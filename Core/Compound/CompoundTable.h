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

#ifndef COMPOUNDTABLE_H
#define COMPOUNDTABLE_H
#include <BioQt_global.h>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>



namespace BioQt {
//========================================================================
//           CompoundTable providing thread-safe reference counting.
//========================================================================
class BIOQTSHARED_EXPORT CompoundTableData : public QSharedData
 {
   public:
    CompoundTableData() : id(-2),BinaryVal(-2) {sname.clear(); fname.clear(); }
     CompoundTableData(const CompoundTableData &other)
         : QSharedData(other), id(other.id),BinaryVal(other.BinaryVal), sname(other.sname),fname(other.fname) { }
     ~CompoundTableData() { }

     int id;
     QString sname;
     QString fname;
     int BinaryVal;
 };

 class BIOQTSHARED_EXPORT CompoundTable
 {
   public:
     CompoundTable() { d = new CompoundTableData; }
     CompoundTable(int id, QString sname,int BinaryVal,QString fname) {
         d = new CompoundTableData;
         setId(id);
         setsName(sname);
         setfName(fname);
         setBinaryVal(BinaryVal);
     }
     CompoundTable(const CompoundTable &other)
           : d (other.d)
     {
     }
     void setId(int id) { d->id = id; }
     void setsName(QString name) { d->sname = name; }
      void setfName(QString name) { d->fname = name; }
    void  setBinaryVal(int Val){d->BinaryVal=Val;};

     int id() const { return d->id; }
     QString sname() const { return d->sname; }
      QString fname() const { return d->fname; }
      int BinaryVal() const { return d->BinaryVal; }

   private:
     QSharedDataPointer<CompoundTableData> d;
 };




} // namespace BioQt

#endif // COMPOUNDTABLE_H
