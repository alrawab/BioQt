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
*BioQt::REnzyme
*@author Usama S Erawab
*
*/

#ifndef RENZYME_H
#define RENZYME_H

#include <BioQt_global.h>
#include <QtCore>


namespace BioQt {

class BIOQTSHARED_EXPORT REnzymeData : public QSharedData
{
public:
    REnzymeData(){ }

    REnzymeData(const REnzymeData &other)
        : QSharedData(other),
          name(other.name),pattern(other.pattern),
          length(other.length),ncuts(other.ncuts),
          blunt(other.blunt),c1(other.c1),
          c2(other.c2),c3(other.c3),
          c4(other.c4){}

    ~REnzymeData() { }
    /**
      * @brief name name of enzyme.
      */
    QString name;
    /**
      * @brief pattern recognition site
      */
    QString pattern;
    /**
      * @brief length  of pattern
      */
    int length;//pattren length
    /**
      * @brief ncuts number of cuts made by enzyme
      * Zero represents unknown
      */
    int ncuts;//
    /**
      * @brief blunt true if blunt end cut, false if sticky
      */
    bool blunt;
    /**
     * @brief c1 First 5' cut
     */
    int c1;
    /**
     * @brief c2 First 3' cut
     */
    int c2;
    /**
     * @brief c3 Second 5' cut
     */
    int c3;
    /**
     * @brief c4 Second 3' cut
     */
    int c4;

};



class BIOQTSHARED_EXPORT REnzyme
{

     //   Q_PROPERTY(QString name READ getName WRITE name)
   //  Q_PROPERTY(QString pattern READ get WRITE setName)
public:

    REnzyme() { d = new REnzymeData; }
    //------------------->
    REnzyme( QString name,QString pattern,int length,
             int ncuts, bool blunt,int c1,int c2,int c3,int c4  ) {

        d = new REnzymeData;
        setName(name);
        setPattern(pattern);
        setLength(length);
        setNcuts(ncuts);
        setBlunt(blunt);
        setC1(c1);
        setC2(c2);
        setC3(c3);
        setC4(c4);
    }
    //------------>
    REnzyme(const REnzyme &other)
        : d (other.d)
    {
    }
    void setName(QString name) { d->name = name; }
    void setPattern(QString pattern){d->pattern=pattern;}
    void setLength(int length) {d->length=length;}
    void setNcuts(int ncuts) {d->ncuts=ncuts;}
    void setBlunt(bool blunt){d->blunt=blunt;}
    void  setC1(int c1){d->c1=c1;}
    void  setC2(int c2){d->c2=c2;}
    void  setC3(int c3) {d->c3=c3;}
    void  setC4(int c4){d->c4=c4;}

    QString name() const { return d->name; }
    QString pattren() const { return d->pattern; }
    int     length() const {return d->length;}
    int     ncuts()   const {return d->ncuts;}
    bool    blunt()   const {return d->blunt;}
    int     c1()   const {return d->c1;}
    int     c2()   const {return d->c2;}
    int     c3()   const {return d->c3;}
    int     c4()   const {return d->c4;}



    //-----------------------------------------------------------
private:
    QSharedDataPointer<REnzymeData> d;
};

} // namespace BioQt

#endif // BIOQT_RENZYME_H
