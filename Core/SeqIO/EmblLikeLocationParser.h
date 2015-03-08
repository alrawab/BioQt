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



#ifndef EMBLLIKELOCATIONPARSER_H
#define EMBLLIKELOCATIONPARSER_H

#include <BioQt_global.h>
#include <QtCore>
#include <Utils/Exceptions/BioQtException.h>
#include <Utils/Location.h>
#include "StrandedFeature.h"

namespace BioQt {
/**
*BioQt::EmblLikeLocationParser
*@author Usama S Erawab
* thanks to Keith James and Greg Cox
*
*/
class BIOQTSHARED_EXPORT EmblLikeLocationParser
{
public:
    EmblLikeLocationParser();
void parseLocation(QString _location);
QList<Location> FTLOCLST;
private:
/**
 * @brief processCoords ses the coordinate data in the
 * start/endCoords Lists to create a Location and add to the
 * subLocations List. As this code will require further
 * modification to support fuzzy point locations, please keep any
 * changes well-commented.
 */
void processCoords() throw(BioQtException);
    // For the LocationLexer inner classs
    QString        location;

    int           nextCharIndex;
    QVariant        thisToken;

    // seq ID of the sequence we are parsing features for
    QString        parentSeqID;

    // Stores join/order/complement instructions
    QList<QVariant> instructStack;
    // joinType is a hack to store if a compound location is a
    // join(...) or an order(...) location.  If this isn't sufficient
    // for your needs, feel free to fix it.  If you do, please make
    // sure the AbstractGenEmblFileFormer class is still able to
    // format join and order correctly. The joinType is stored in the
    // Feature Annotation under the internal data key
    // Feature.PROPERTY_DATA_KEY which means that it won't get printed
    // in flatfile dumps.
    QString joinType;

    // List of sublocations.  Used for compound locations on the current
    // sequence
    QList<QString>  subLocations;//no string its region
    // List of subRegions.  Used to store remote regions
    QList<QString>  subRegions ;//no string its region

    // These hold working data for each (sub)location and are cleared
    // by calling the processCoords() function
    QString mRegionSeqID;
    QList<QVariant>   startCoords;
    QList<QVariant>     endCoords;
    bool isPointLoc;
    bool fuzzyCoord ;
    bool unboundMin;
    bool unboundMax ;
    bool isBetweenLocation;

private:
    void processInstructs();
    StrandedFeature::Strand mStrandType;
    //****************Implementation of Lexer*************//
    /**
     * @brief getNextToken returns the next token. A null
     * indicates no more tokens.
     * @return return an QVariant vlaue
     */
    QVariant getNextToken();
    /**
     * @brief followInteger returns single sequence coordinate.
     * @return
     */
    int followInteger();
    /**
     * @brief followText returns a single text string.
     * @return
     */
    QString followText();
    /**
     * @brief intString
     */
    QString intString;
    /**
     * @brief textString
     */
    QString textString;
//****************END of Lexer*************//



    // Currently set per Feature; this is a deficiency in the current
    // parser. Features are assumed to be on the positive strand until
    // complemented.
    // No features have a strand type of UNKNOWN
  //  StrandedFeature.Strand mStrandType = StrandedFeature.POSITIVE;

};


} // namespace BioQt

#endif // BIOQT_EMBLLIKELOCATIONPARSER_H
