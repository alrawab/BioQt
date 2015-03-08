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


#ifndef STRANDEDFEATURE_H
#define STRANDEDFEATURE_H

#include <BioQt_global.h>
#include <QtCore>


namespace BioQt {

/**
*BioQt::StrandedFeature
*@author Usama S Erawab
*
*/
class BIOQTSHARED_EXPORT StrandedFeature
{
public:
    enum Strand {
        POSITIVE = 1,
        NEGATIVE = -1,
        UNKNOWN  =0
    };
    StrandedFeature(): value(POSITIVE)  {};
    StrandedFeature(Strand val){value = val == NEGATIVE ? NEGATIVE : POSITIVE;}
    bool isPostive() const { return value == POSITIVE;}

    bool isNegative() const { return value == NEGATIVE;}

    bool operator==(const StrandedFeature& s) const {return value == s.value;}

    bool operator!=(const StrandedFeature& s) const {return value != s.value;}

    Strand getStrand() const {return (StrandedFeature::Strand)value;}
    /**
     * @brief getStrandValue
     * @return Returns the integer label for strandedness. That is, "+1", "-1",
     * or "0" for positive, negative, and unknown strands respectively.
     */
    int getStrandValue() const {return value;}
    /**
     * @brief flip
     * @return a strand that represents flipping this onto the opposite strand.
     */
    int flip() {
          if(value == 1) {
            return -1;
          } else if(value == -1) {
            return 1;
          } else {
            return value;
          }
        }

private:
    int value;
};

} // namespace BioQt

#endif // BIOQT_STRANDEDFEATURE_H
