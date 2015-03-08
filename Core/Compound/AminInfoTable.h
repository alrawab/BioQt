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

#ifndef AMININFOTABLE_H
#define AMININFOTABLE_H

//#include <BioQt_global.h>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace BioQt {

struct HalfLife
{
public:
    HalfLife(){Mammalian=Yeast=Ecoli=0;}
    HalfLife(double m,double y,double e){Mammalian = m; Yeast = y; Ecoli = e;}

    double Mammalian;
    double Yeast;
    double Ecoli;
};


class  AminInfoTableData : public QSharedData
{
public:
    AminInfoTableData() :
        molecularWeight(0.0),
        aminoAcidComposition(0.0),
        bulkiness(0.0),
        polarity(0.0),
        recognitionFactor(0.0),
        hydrophobicity(0.0),
        hydropathicityKD(0.0),
        refractivity(0.0),
        numberOfCodons(0.0),
        percentBuriedResidues(0.0),
        percentAccessibleResidues(0.0),
        averageAreaBuried(0.0),
        averageFlexibility(0.0),
        NormalizedFlexibility(0.0),
        Hydrophilicity(0.0),
        SurfaceAccessibility(0.0),
        InteriorToSurfaceTransferEnergyScale(0.0),
        halfLife(0.0,0.0,0.0){code.clear();triplet.clear();name.clear();molecularFormula.clear();}




    AminInfoTableData(const AminInfoTableData &other)
        : QSharedData(other),
          code(other.code),
          triplet(other.triplet),
          name(other.name),
          molecularFormula(other.molecularFormula),
          molecularWeight(other.molecularWeight),
          aminoAcidComposition(other.aminoAcidComposition),
          bulkiness(other.bulkiness),
          polarity(other.polarity),
          recognitionFactor(other.recognitionFactor),
          hydrophobicity(other.hydrophobicity),
          hydropathicityKD(other.hydropathicityKD),
          refractivity(other.refractivity),
          numberOfCodons(other.numberOfCodons),
          percentBuriedResidues(other.percentBuriedResidues),
          percentAccessibleResidues(other.percentAccessibleResidues),
          averageAreaBuried(other.averageAreaBuried),
          averageFlexibility(other.averageFlexibility),
          NormalizedFlexibility(other.NormalizedFlexibility),
          Hydrophilicity(other.Hydrophilicity),
          SurfaceAccessibility(other.SurfaceAccessibility),
          InteriorToSurfaceTransferEnergyScale(other.InteriorToSurfaceTransferEnergyScale),
          halfLife(other.halfLife){}

    ~AminInfoTableData() { }

    QString code;
    QString triplet;
    QString name;
    QString molecularFormula;
    double molecularWeight;
    double aminoAcidComposition;
    double bulkiness;
    double polarity;
    double recognitionFactor;
    double hydrophobicity;
    double hydropathicityKD;
    double refractivity;
    double numberOfCodons;
    double percentBuriedResidues;
    double percentAccessibleResidues;
    double averageAreaBuried;
    double averageFlexibility;
    double NormalizedFlexibility;
    double Hydrophilicity;
    double SurfaceAccessibility;
    double InteriorToSurfaceTransferEnergyScale;
    HalfLife halfLife;
};
//================================================================================
//                             AminInfoTable
//===================================================================================
class  AminInfoTable
{
public:
    AminInfoTable() { d = new AminInfoTableData; }
    AminInfoTable( QString code,
                   QString triplet,
                   QString name,
                   QString molecularFormula,
                   double molecularWeight,
                   double aminoAcidComposition,
                   double bulkiness,
                   double polarity,
                   double recognitionFactor,
                   double hydrophobicity,
                   double hydropathicityKD,
                   double refractivity,
                   double numberOfCodons,
                   double percentBuriedResidues,
                   double percentAccessibleResidues,
                   double averageAreaBuried,
                   double averageFlexibility,
                   double NormalizedFlexibility,
                   double Hydrophilicity,
                   double SurfaceAccessibility,
                   double InteriorToSurfaceTransferEnergyScale,
                   HalfLife halfLife) {
        d = new AminInfoTableData;
        setcode(code);
        settriplet(triplet);
        setname(name);
        setmolecularFormula(molecularFormula);
        setmolecularWeight(molecularWeight);
        setaminoAcidComposition(aminoAcidComposition);
        setbulkiness(bulkiness);
        setpolarity(polarity);
        setrecognitionFactor(recognitionFactor);
        sethydrophobicity(hydrophobicity);
        sethydropathicityKD(hydropathicityKD);
        setrefractivity(refractivity);
        setnumberOfCodons(numberOfCodons);
        setpercentBuriedResidues(percentBuriedResidues);
        setpercentAccessibleResidues(percentAccessibleResidues);
        setaverageAreaBuried(averageAreaBuried);
        setaverageFlexibility(averageFlexibility);
        setNormalizedFlexibility(NormalizedFlexibility);
        setHydrophilicity(Hydrophilicity);
        setSurfaceAccessibility(SurfaceAccessibility);
        setInteriorToSurfaceTransferEnergyScale(InteriorToSurfaceTransferEnergyScale);
        sethalfLife(halfLife);




    }
    AminInfoTable(const AminInfoTable &other)
        : d (other.d)
    {
    }

    void setcode(QString code){d->code=code;}
    void settriplet(QString triplet){d->triplet=triplet;}
    void setname(QString name){d->name=name;}
    void setmolecularFormula(QString molecularFormula){d->molecularFormula=molecularFormula;}
    void setmolecularWeight(double molecularWeight){d->molecularWeight=molecularWeight;}
    void setaminoAcidComposition(double aminoAcidComposition){d->aminoAcidComposition=aminoAcidComposition;}
    void setbulkiness(double bulkiness){d->bulkiness=bulkiness;}
    void setpolarity(double polarity){d->polarity=polarity;}
    void setrecognitionFactor(double recognitionFactor){d->recognitionFactor=recognitionFactor;}
    void sethydrophobicity(double hydrophobicity){d->hydrophobicity=hydrophobicity;}
    void sethydropathicityKD(double hydropathicityKD){d->hydropathicityKD=hydropathicityKD;}
    void setrefractivity(double refractivity){d->refractivity=refractivity;}
    void setnumberOfCodons(double numberOfCodons){d->numberOfCodons=numberOfCodons;}
    void setpercentBuriedResidues(double percentBuriedResidues){d->percentBuriedResidues=percentBuriedResidues;}
    void setpercentAccessibleResidues(double percentAccessibleResidues){d->percentAccessibleResidues=percentAccessibleResidues;}
    void setaverageAreaBuried(double averageAreaBuried){d->averageAreaBuried=averageAreaBuried;}
    void setaverageFlexibility(double averageFlexibility){d->averageFlexibility=averageFlexibility;}
    void setNormalizedFlexibility(double NormalizedFlexibility){d->NormalizedFlexibility=NormalizedFlexibility;}
    void setHydrophilicity(double Hydrophilicity){d->Hydrophilicity=Hydrophilicity;}
    void setSurfaceAccessibility(double SurfaceAccessibility){d->SurfaceAccessibility=SurfaceAccessibility;}
    void setInteriorToSurfaceTransferEnergyScale(double InteriorToSurfaceTransferEnergyScale){d->InteriorToSurfaceTransferEnergyScale=InteriorToSurfaceTransferEnergyScale;}


    void sethalfLife(HalfLife halfLife){d->halfLife=halfLife;}
    //============================================================================================================================
    //
    //=============================================================================================================================

    QString code() const { return d->code ; }
    QString triplet() const { return d->triplet ; }
    QString name() const { return d->name ; }
    QString molecularFormula() const { return d->molecularFormula ; }
    double molecularWeight() const { return d->molecularWeight ; }
    double aminoAcidComposition() const { return d->aminoAcidComposition ; }
    double bulkiness() const { return d->bulkiness ; }
    double polarity() const { return d->polarity ; }
    double recognitionFactor() const { return d->recognitionFactor ; }
    double hydrophobicity() const { return d->hydrophobicity ; }
    double hydropathicityKD() const { return d->hydropathicityKD ; }
    double refractivity() const { return d->refractivity ; }
    double numberOfCodons() const { return d->numberOfCodons ; }
    double percentBuriedResidues() const { return d->percentBuriedResidues ; }
    double percentAccessibleResidues() const { return d->percentAccessibleResidues ; }
    double averageAreaBuried() const { return d->averageAreaBuried ; }
    double averageFlexibility() const { return d->averageFlexibility ; }
    double NormalizedFlexibility() const { return d->NormalizedFlexibility ; }
    double Hydrophilicity() const { return d->Hydrophilicity ; }
    double SurfaceAccessibility() const { return d->SurfaceAccessibility ; }
    double InteriorToSurfaceTransferEnergyScale() const { return d->InteriorToSurfaceTransferEnergyScale ; }


    HalfLife halfLife() const {return d->halfLife;}





private:
    QSharedDataPointer<AminInfoTableData> d;
};

} // namespace BioQt

#endif // BIOQT_AMININFOTABLE_H
