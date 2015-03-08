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


#include "EmblLikeLocationParser.h"

namespace BioQt {


bool is_whitespace(const char c)
{
    return (' '  == c) || ('\n' == c) ||
            ('\r' == c) || ('\t' == c) ||
            ('\b' == c) || ('\v' == c) ||
            ('\f' == c) ;
}

EmblLikeLocationParser::EmblLikeLocationParser()
    :isBetweenLocation(false),isPointLoc(true),fuzzyCoord(false),
      unboundMax(false),unboundMin(false),mStrandType(StrandedFeature::POSITIVE)
{
}

void EmblLikeLocationParser::parseLocation(QString _location)
{
    location=_location;
    nextCharIndex = 0;
    
    instructStack.clear();
    subLocations.clear();
    FTLOCLST.clear();
    thisToken = getNextToken();

    while (!thisToken.isNull())
    {
        if (thisToken.type()==QVariant::String)
        {
            QString toke =  thisToken.toString();
            if (toke=="..")
            {
                // This token indicates that this isn't a point
                isPointLoc = false;
            }
            else
            {

                instructStack.append(thisToken);
            }
        }
        else if (thisToken.type()==QVariant::Int)
        {
            if (isPointLoc)
            {
                startCoords.append(thisToken);

            }
            else

                endCoords.append(thisToken);
        }
        else if (thisToken.type()==QVariant::Char)
        {
            QChar toke = thisToken.toChar();
            
            switch (toke.toLatin1())
            {
            case '(':
                break;
                
            case ':':
                processInstructs();
                break;
                
            case '^':
                isBetweenLocation = true;
                break;
                
            case '<':
                unboundMin = true;
                break;
                
            case '>':
                unboundMax = true;
                break;
                
            case '.':
                // Catch range: (123.567)
                fuzzyCoord = true;
                break;
                
            case ',':
                processCoords();
                break;
                
            case ')':
                // Catch the end of range: (123.567)
                if (fuzzyCoord)
                {
                    fuzzyCoord = false;
                }
                else
                {
                    processCoords();
                    processInstructs();
                }
                break;
                
            default:
                //   throw new BioException("Unknown character '"
                //                          + toke
                //                          + "' within location: "
                //                         + location);
                break;
            }
        }
        
        
        
        thisToken = getNextToken();
        
    }//while
    
    processCoords();
    
}

void EmblLikeLocationParser::processCoords()
{
    int outerMin, innerMin, innerMax, outerMax;
    //*********   Location createdLocation = null;

    // This is expected where two calls to processCoords() are
    // made sequentially e.g. where two levels of parens are
    // closed. The second call will have no data to process.
    if (startCoords.isEmpty() && endCoords.isEmpty())
        return;

    // Range of form 5^6 or 5^7
    if (isBetweenLocation)
    {
        // Create a ranged location, and wrap it in a between location

        int minCoord = 0;//startCoords.at(0).toInt();
        int maxCoord = 0;//startCoords.at(1).toInt();
        //*****    createdLocation = new BetweenLocation(new RangeLocation(minCoord, maxCoord));

         FTLOCLST.append(Location(minCoord,maxCoord));
    }
    // Range of form: 123
    else if (startCoords.size() == 1 && endCoords.isEmpty())
    {
        innerMin = outerMin = ( startCoords.at(0).toInt());
        innerMax = outerMax = innerMin;

        // This looks like a point, but is actually a range which
        // lies entirely outside the current entry
        if (unboundMin || unboundMax)
        {
           // qDebug()<<innerMax;
FTLOCLST.append(Location(innerMin,innerMax));
            //  createdLocation = new FuzzyPointLocation(unboundMin ? Integer.MIN_VALUE : innerMin,
            //                                           unboundMax ? Integer.MAX_VALUE : innerMax,
            //                                       FuzzyPointLocation.RESOLVE_AVERAGE);
        }
        else if (isPointLoc)
        {
            FTLOCLST.append(Location(innerMin,innerMin));
            //  createdLocation = new PointLocation(innerMin);
        }
        else
        {
            //   throw new BioException("Internal error in location parsing; parser became confused: "
            //     + location);
        }
    }
    // Range of form: (123.567)
    else if (startCoords.size() == 2 && endCoords.isEmpty())
    {
        innerMin = outerMin = ( startCoords.at(0).toInt());
        innerMax = outerMax = ( startCoords.at(1).toInt());

        //   createdLocation = new FuzzyPointLocation(innerMin,
        //                                          innerMax,
        //                                        FuzzyPointLocation.RESOLVE_AVERAGE);
    }
    // Range of form: 123..567 or <123..567 or 123..>567 or <123..>567
    else if (startCoords.size() == 1 && endCoords.size() == 1)
    {

        innerMin = outerMin = ( startCoords.at(0).toInt());
        innerMax = outerMax = ( endCoords.at(0).toInt());

        if (unboundMin || unboundMax)
        {
          //  qDebug()<<outerMin<<" "<<innerMax;
FTLOCLST.append(Location(outerMin,outerMax));
            /*  createdLocation = new FuzzyLocation(unboundMin ? Integer.MIN_VALUE : outerMin,
                                                     unboundMax ? Integer.MAX_VALUE : outerMax,
                                                     innerMin,
                                                     innerMax,
                                                     FuzzyLocation.RESOLVE_INNER);*/
        }
        else
        {
           // qDebug()<<outerMin<<" "<<outerMax;
            FTLOCLST.append(Location(outerMin,outerMax));

            //  try
            //   {
            //   createdLocation = new RangeLocation(outerMin, outerMax);
            //   }
            //  catch (IndexOutOfBoundsException ioe)
            //  {
            //throw new BioException(ioe);
            //   }
        }
    }
         // Range of form: (123.567)..789
         else if (startCoords.size() == 2 && endCoords.size() == 1)
         {

             outerMin = (startCoords.at(0).toInt());
             innerMin = (startCoords.at(1).toInt());
             innerMax = outerMax = (endCoords.at(0).toInt());
FTLOCLST.append(Location(innerMin,innerMax));
           /*  createdLocation = new FuzzyLocation(outerMin,
                                                 outerMax,
                                                 innerMin,
                                                 innerMax,
                                                 FuzzyLocation.RESOLVE_INNER);*/
         }
         // Range of form: 123..(567.789)
         else if (startCoords.size() == 1 && endCoords.size() == 2)
         {

             outerMin = innerMin = (startCoords.at(0).toInt());
             innerMax = (endCoords.at(0).toInt());
             outerMax = (endCoords.at(1).toInt());
FTLOCLST.append(Location(outerMin,outerMax));
           /*  createdLocation = new FuzzyLocation(outerMin,
                                                 outerMax,
                                                 innerMin,
                                                 innerMax,
                                                 FuzzyLocation.RESOLVE_INNER);*/
         }
         // Range of form: (123.345)..(567.789)
         else if (startCoords.size() == 2 && endCoords.size() == 2)
         {
      //  qDebug()<<"3";
             outerMin = ( startCoords.at(0).toInt());
             innerMin = ( startCoords.at(1).toInt());
             innerMax = ( endCoords.at(0).toInt());
             outerMax = ( endCoords.at(1).toInt());
FTLOCLST.append(Location(outerMin,outerMax));
             /*createdLocation = new FuzzyLocation(outerMin,
                                                 outerMax,
                                                 innerMin,
                                                 innerMax,
                                                 FuzzyLocation.RESOLVE_INNER);*/
         }
         else
         {
          //   throw new BioException("Internal error in location parsing; parser became confused; "
            //                        + location);
         }

         startCoords.clear();
         endCoords.clear();

         if (mRegionSeqID.isEmpty()||mRegionSeqID.isNull())
         {
           //  subLocations.append(createdLocation);
            // subRegions.add(new RemoteFeature.Region(createdLocation, parentSeqID, false));
         }
         else
         {
         //    subRegions.add(new RemoteFeature.Region(createdLocation, mRegionSeqID, true));
         }

    //   mRegionSeqID = null;

    isPointLoc   = true;
    unboundMin   = false;
    unboundMax   = false;
    fuzzyCoord   = false;
    isBetweenLocation = false;
    mStrandType  = StrandedFeature::POSITIVE;
}

void EmblLikeLocationParser::processInstructs()
{
   // instructStack.removeAt(instructStack.size()-1);
    QString instruct;//=instructStack.last().toString();
   // qDebug()<<instructStack;
    if (instruct =="join" || instruct == "order")
    {
        joinType = instruct;
    }
    else if (instruct == "complement")
    {

          mStrandType = StrandedFeature::NEGATIVE;
    }
    else
    {

        // e.g. J00194:(100..202)
        mRegionSeqID = instruct;
    }
}


//---------------------------------------------------------------------------------------------------
QVariant EmblLikeLocationParser::getNextToken()
{
    if (nextCharIndex == location.length())
        return QVariant();
    
    QChar thisChar = location.at(nextCharIndex);
    char ss;
    switch (thisChar.toLatin1())
    {
    case ' ' : case '\t' :
        nextCharIndex++;
        break;
        
    case ':' : case '^' : case ',' :
    case '(' : case ')' : case '<' :
    case '>' :
        nextCharIndex++;
        return  thisChar;
    case '.' :
        if (location.at(nextCharIndex + 1) == '.')
        {
            nextCharIndex += 2;
            return QString("..");
        }
        else
        {
            nextCharIndex++;
            return QChar('.');
        }
        
    case '0' : case '1' : case '2' : case '3' : case '4' :
    case '5' : case '6' : case '7' : case '8' : case '9' :
        return followInteger();
        
    default :
        QString text = followText();
        if (text.isNull()|| text.isEmpty())
        {
            nextCharIndex++;
            return QString(thisChar);
        }
        else
            return text;
        
        
        
    }
    
    
    
    
    
    
    
}

int EmblLikeLocationParser::followInteger()
{
    intString.clear();
    QChar thisChar = location.at(nextCharIndex);
    while (thisChar.isDigit())
    {
        intString.append(thisChar);
        nextCharIndex++;
        
        if (nextCharIndex >= location.length())
            break;
        
        thisChar = location.at(nextCharIndex);
    }
    return intString.toInt();
}

QString EmblLikeLocationParser::followText()
{
    textString.clear();
    QChar thisChar = location.at(nextCharIndex);
    
    // First character must be a letter
    if (! thisChar.isLetter())
        return QString();
    while (thisChar.isLetterOrNumber() ||
           thisChar == '.')
    {
        textString.append(thisChar);
        nextCharIndex++;
        
        if (nextCharIndex >= location.length())
            break;
        
        thisChar = location.at(nextCharIndex);
    }
    return textString;
}


} // namespace BioQt
