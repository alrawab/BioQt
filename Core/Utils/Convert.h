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

#ifndef CONVERT_H
#define CONVERT_H
#include <BioQt_global.h>
#include <QtCore>
#include <Sequence/QSequence.h>
#include <Sequence/SequenceException.h>

namespace BioQt {

class BIOQTSHARED_EXPORT Convert
{
public:
    static float CellusToFahrenheit(float f)
    {
        return (f * 1.8) + 32;
    }

    static float FahrenheitToCellus(float c)
    {
        return (c-32)*5 /9;
    }
    /**
     * @brief MWofdsDNA
     * @param seq  subjected QSequence to evaluate Molecualar weight of double stand DNA
     *MW=Number of BasePairs x 660 Da.
     *
     */
    static float MWofdsDNA(const QSequence &seq)
    {
        if(seq.isEmpty()||seq.isNull())
            throw EmptySequenceException("BioQt::Convert the Sequence Is empty");
        return seq.length()*(660);
    }
    /**
     * @brief MWofssDNA
     *@param seq  subjected QSequence to evaluate Molecualar weight of single stand DNA
     *MW=Number of BasePairs x 330 Da.
     */
    static float MWofssDNA(const QSequence &seq)
    {
        if(seq.isEmpty()||seq.isNull())
            throw EmptySequenceException("BioQt::Convert the Sequence Is empty");
        return seq.length()*(330);
    }
};

} // namespace BioQt

#endif // BIOQT_CONVERT_H
