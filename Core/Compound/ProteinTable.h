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

#ifndef PROTEINTABLE_H
#define PROTEINTABLE_H

#include <BioQt_global.h>
#include <QSharedData>

namespace BioQt {

class BIOQTSHARED_EXPORT ProteinTableData : public QSharedData
{


public:
    ProteinTableData() : id(-2) {sname.clear(); fname.clear();Iletter_code.clear() ;}
    ProteinTableData(const ProteinTableData &other)
        : QSharedData(other), id(other.id), sname(other.sname),Iletter_code(other.Iletter_code),fname(other.fname) { }
    ~ProteinTableData() { }

    int id;
    QString sname;
    QString fname;
    QString Iletter_code;


};
//==============================================================================================
//
//=================================================================================================
class BIOQTSHARED_EXPORT  ProteinTable
{
public:
    ProteinTable() { d = new  ProteinTableData; }
    ProteinTable(int id, QString sname,QString Iletter_code,QString fname) {
        d = new  ProteinTableData;
        setId(id);
        setsName(sname);
        setIletter_code(Iletter_code);
        setfName(fname);

    }
    ProteinTable(const  ProteinTable &other)
        : d (other.d)
    {
    }
    void setId(int id) { d->id = id; }
    void setsName(QString name) { d->sname = name; }
    void  setIletter_code(QString name){d->Iletter_code=name;};
    void setfName(QString name) { d->fname = name; }


    int id() const { return d->id; }
    QString sname() const { return d->sname; }
    QString Iletter_code() const { return d->Iletter_code; }
    QString fname() const { return d->fname; }


private:
    QSharedDataPointer< ProteinTableData> d;
};



} // namespace BioQt

#endif // BIOQT_PROTEINTABLE_H
