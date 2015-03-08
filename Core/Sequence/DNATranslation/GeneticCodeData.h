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

#ifndef BIOQT_GENETICCODEDATA_H
#define BIOQT_GENETICCODEDATA_H

#include <BioQt_global.h>
#include <QtCore>
#include <QSharedData>
#include <QSharedDataPointer>

namespace BioQt {



class BIOQTSHARED_EXPORT GeneticCodeData : public  QSharedData
{
public:
    GeneticCodeData(){};
    GeneticCodeData(const GeneticCodeData &other)
        : QSharedData(other),
          Base1(other.Base1 ),
          Base2(other.Base2),
          Base3(other.Base3),
          AMS(other.AMS),
          TbID(other.TbID),
          TbName(other.TbName){}



    //GeneticCodeData &operator=(const GeneticCodeData &);
    ~GeneticCodeData(){}


    QString Base1;
    QString Base2;
    QString Base3;
    QString Starts;
    QString AMS;
    int TbID;
    QString  TbName;




};

class BIOQTSHARED_EXPORT GeneticCode
{
public:
    GeneticCode(){ d = new GeneticCodeData;}
    GeneticCode(QString AMS,
                QString Starts,
                QString Base1,
                QString Base2,
                QString Base3,
                int TbID,
                QString TbName)
    {
        d = new GeneticCodeData;
        setBase1(Base1);
        setBase2(Base2);
        setBase3(Base3);
        setStarts(Starts);
        setAMS(AMS);
        setTbID(TbID);
        setTbName(TbName);

    }
    GeneticCode(const GeneticCode &other)
        :d(other.d){}
    void setBase1(QString Base1){d->Base1=Base1;}
    void setBase2(QString Base2){d->Base2=Base2;}
    void setBase3(QString Base3){d->Base3=Base3;}
    void setStarts(QString Starts){d->Starts=Starts;}
    void setAMS(QString AMS){d->AMS=AMS;}
    void setTbID(int TbID){d->TbID=TbID;}
    void setTbName(QString TbName){d->TbName=TbName;}
    //============================================================================================================================
    //
    //=============================================================================================================================

    QString Base1()const{return d->Base1;}
    QString Base2()const{return d->Base2;}
    QString Base3()const{return d->Base3;}
    QString Starts()const{return d->Starts;}
    QString AMS()const{return d->AMS;}
    int TbID()const{return d->TbID;}
    QString TbName()const{return d->TbName;}

    private:
        QSharedDataPointer<GeneticCodeData> d;
};

} // namespace BioQt

#endif // BIOQT_GENETICCODEDATA_H
