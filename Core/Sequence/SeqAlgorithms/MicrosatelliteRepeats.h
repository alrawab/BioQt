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

#ifndef MICROSATELLITEREPEATS_H
#define MICROSATELLITEREPEATS_H

#include <BioQt_global.h>
#include <QtCore>


namespace BioQt {
/**
 *@brief The MicrosatelliteRepeats class :
 * Microsatellites, also known as simple sequence repeats (SSRs) or short tandem repeats (STRs),
 *are repeating sequences of 2-5 base pairs of DNA.[1] It is a type of Variable Number Tandem Repeat (VNTR).
 * Microsatellites are typically co-dominant. They are used as molecular markers in STR analysis,
 *for kinship, population and other studies. They can also be used for studies of gene duplication or deletion,
 * marker assisted selection, and fingerprinting.
 * \n see: http://en.wikipedia.org/wiki/Microsatellite
 *@author Usama S Erawab
 *orignal code in php by  Joseba Bikandi (thanks for biophp team).
 *
 */
struct  MS_Results
{
    int Matches;
    int Start_position;
    int Length;
    int Repeats;
    QString MS_Sequence;
};

typedef QList<MS_Results> MS_List;
class BIOQTSHARED_EXPORT MicrosatelliteRepeats
{
public:
    MicrosatelliteRepeats();
    /**
 * @brief FindMicrosatelliteRepeats
 * @param sequence
 * @param min_length
 * @param max_length
 * @param min_repeats
 * @param min_length_of_MR
 * @param mismatches_allowed
 * @return
 */
static MS_List FindMicrosatelliteRepeats(QString sequence,int min_length,int max_length,int min_repeats,int min_length_of_MR,int mismatches_allowed);
private:
    /**
     * @brief includeN_1
     *When a DNA sequence ("primer") is provided to this function, as for example "acgt", this function will return
     * a pattern like ".cgt|a.gt|ac.t|acg.". This pattern may be useful to find within a DNA sequence
     *subsequences matching primer, but allowing one missmach. The parameter minus
     * is a numeric value which indicates number of bases always maching  the DNA sequence in 3' end.
     * For example, when minus is 1, the pattern for "acgt" will be  ".cgt|a.gt|ac.t".
     * Check also IncludeN_2 and IncludeN_3.
     *
     * @param prime  DNA sequence (oligonucleotide, primer).
     * @param minus  indicates number of bases in 3' which will always much the DNA sequence.
     * @return a pattern (as described in "includeN_1 Description").
     */
  static  QString includeN_1(const QString & primer,int minus);
  /**
   * @brief includeN_2
   *Similar to function IncludeN_1. When a DNA sequence ("primer") is provided to this function, as for example "acgt",
   *this function will return a pattern like "..gt|.c.t|.cg.|a..t|a.g.|ac..". This pattern may be useful to find within
   * a DNA sequence subsequences matching primer, but allowing two missmaches. The parameter minus
   *is a numeric value which indicates number of bases always maching  the DNA sequence in 3' end.
   *For example, when minus is 1, the pattern for "acgt" will be  "..gt|.c.t|a..t".
   *Check also IncludeN_1 and IncludeN_3.
   * @param primer is a DNA sequence (oligonucleotide, primer)
   * @param minus indicates number of bases in 3' which will always much the DNA sequence.
   * @return a pattern (as described in "includeN_2 Description").
   */
  static  QString includeN_2(const QString & primer,int minus);
  /**
   * @brief includeN_3
   *Similar to function IncludeN_1 and IncludeN_2, but allows two missmaches. The parameter minus
   *is a numeric value which indicates number of bases always maching  the DNA sequence in 3' end.
   * @param primer is a DNA sequence (oligonucleotide, primer)
   * @param minus indicates number of bases in 3' which will always much the DNA sequence.
   * @return a pattern (as described in "includeN_3 Description").
   */
  static  QString includeN_3(const QString & primer,int minus);

};

} // namespace BioQt

#endif // BIOQT_MICROSATELLITEREPEATS_H
