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

#ifndef BIOQT_ALPHABET_H
#define BIOQT_ALPHABET_H
#include <BioQt_global.h>
#include <Alphabet/AlphabetException.h>
#include <QtCore>

namespace BioQt {

/**
 * @brief Standard nucleotide and protein alphabets defined by IUPAC..
 *
 * An alphabet object defines all the Bases allowed for a particular type of
 * Qsequence. These Bases are coded as a QString and an integer.
 * for computionnal needs, this is often more efficient to store the sequences as
 * a QList of integers.
 * The link between the two descriptions is made <i>via</i>
 * the Alphabet classes, and the two methods intToChar() and charToInt().
 * The Alphabet interface also provides other methods, like getting the full name
 * of the Bases and so on.
 *
 * The alphabet objects may throw several exceptions derived of the AlphabetException
 * class.
 *
 * @see AlphabetException, UnCompatibleCharException, UnCompatibleIntException
 */

/**
 * @brief The Triplet struct deal with triplet bases (ACG TGA etc)
 */
/*struct BIOQTSHARED_EXPORT Triplet {
public:
    Triplet() { c[0] = c[1] = c[2] = '\0'; }
    Triplet(const char* s) { c[0] = s[0]; c[1] = s[1]; c[2] = s[2]; }
    Triplet(char c0, char c1, char c2) {c[0] = c0; c[1] = c1; c[2] = c2;}

    char c[3];
};
*/
class BIOQTSHARED_EXPORT AlphaBet
{

public:
 AlphaBet() {}
 //virtual ~Alphabet() {}

  public:

 /**
  * @brief Get the complete name of a Base given its int description.
  *
  * In case of several Bases with identical number (i.e. N and X for nucleic alphabets),
  * this method returns the name of the first found .
  *
  * @param Base The int description of the given Base.
  * @return The name of the Base.
  * @throw  UnCompatibleIntException When Base is not a valid integer.
  */
 virtual QString GetFullName(int Base) const  throw (UnCompatibleIntException)  = 0;
 //******************************************************************************************************************//
 /**
  * @brief Get the complete name of a Base given its string description.
  *
  * In case of several Bases with identical number (i.e. N and X for nucleic alphabets),
  * this method will return the name of the first found .
  *
  * @param Base The QString description of the given Base.
  * @return The name of the Base.
  * @throw UnCompatibleCharException When Base is not a valid char description.
  */
 virtual QString GetFullName(const QString& Base) const throw (UnCompatibleCharException) = 0;
 //********************************************************************************************************************************//
 /**
  * @brief Tell if a Base (specified by its int description) is allowed by the
  * the alphabet.
  *
  * @param Base The int description.
  * @return 'true' if the Base in known.
  */
virtual bool isIntInAlphabet(int Base) const = 0;
 //----------------------------------------------------------------------------------------------------------//
 /**
  * @brief Tell if a Base (specified by its String description) is allowed by the
  * the alphabet.
  *
  * @param Base The string description.
  * @return 'true' if the Base in known.
  */
 virtual bool isCharInAlphabet(const QString& Base) const = 0;
   //--------------------------------------------------------------------------------------------------------
 /**
  * @brief Give the String description of a Base given its int description.
  *
  * @param Base The int description.
  * @return The string description.
  * @throw UnCompatibleIntException When Base is not a valid integer.
  */
virtual QString intToChar(int Base) const throw (UnCompatibleIntException) = 0;
 //*******************************************************************************************************
 /**
  * @brief Give the int description of a Base given its string description.
  *
  * @param Base The string description.
  * @return The int description.
  * @throw UnCompatibleCharException When Base is not a valid char description.
  */
 virtual int charToInt(const QString& Base) const throw (UnCompatibleCharException) = 0;
 //-----------------------------------------------------------------------------------------------------------------------
 /**
 * @brief Give the string description of a Base given its int description.
 *Genericion in this alphabet,
 * including generic characters (e.g. return 20 for DNA alphabet).
 *
 * @return The total number of supported character descriptions.
 */
virtual unsigned int GetNumberOfChars() const = 0;
//*************************************************************************************************
/**
 * @brief Get the number of <strong>distinct</strong> Bases in alphabet (e.g. return 15 for DNA alphabet).
 * This is the number of integers used for Base description.
 *
 * @return The number of distinct Bases.
 */
virtual unsigned int GetNumberOfTypes() const = 0;
//************************************************************************************************************
/**
 * @brief Get the number of <strong>resolved</strong> Bases in the alphabet (e.g. return 4 for DNA/RNA alphabet and 20 for protein).
 * This is the method you'll need in most cases.
 *
 * @return The number of resolved Bases.
 */
virtual unsigned int GetSize() const = 0;
 //***********************************************************************************************************************
 /**
 * @return A QList<int> of resolved Bases.
 * @throw UnCompatibleIntException When Base is not a valid integer.
 */
virtual QList<int> getAlias(int Base) const throw (UnCompatibleIntException) = 0;
//********************************************************************************************************
/**
 * @param Base The alias to resolve.
 * @return A QList<QString> of resolved Bases.
 * @throw UnCompatibleCharException When Base is not a valid char description.
 */
virtual QList<QString> getAlias(const QString& Base) const throw (UnCompatibleCharException) = 0;
 //**********************************************************************
 /**
  * @return A list of all supported int codes.
  *
  */
virtual  QList<int> getSupportedInts() const = 0;
 //*****************************************************************************************
 /**
  * @return A list of all supported character codes.
  */
 virtual  QStringList getSupportedChars() const = 0;
 //*****************************************************************************
 /**
  * @return The int code for gap characters.
  */
virtual int getGapCharacterCode() const = 0;
 //*************************************************************************
 /**
  * @return 'True' if the Base is a gap.
  */
 virtual bool isGap(int Base) const = 0;
//*********************************************************************************
 /**
  * @return 'True' if the Base is a gap.
  */
 virtual bool isGap(const QString& Base) const = 0;
//**************************************************************************************
 /**
  * @return 'True' if the Base is unresolved.
  */
virtual bool isUnresolved(int Base) const = 0;
//******************************************************************************************************
 /**
  * @return 'True' if the Base is unresolved.
  */
 virtual bool isUnresolved(const QString& Base) const = 0;
 //***********************************************************************************************
 /**
  * @return A text describing the alphabet.
  */
virtual QString getAlphabetType() const = 0;
 /**
      * @brief Get the size of the string coding a Base.
      * @return The size of the tring coding each Bases in the Alphabet.
      *
      */
     virtual unsigned int getBaseCodingSize() const = 0;
 //----------------------
 /**
  * @brief GetLto3 Get the abbreviation (3 letter code) for a Base coded as char.
  * @param Base Char description of the amino-acid to analyse.
  * @return
  */
// virtual QString GetLto3(int Base) const throw (UnCompatibleIntException){};
 /**
  * @brief GetLto3 Get the abbreviation (3 letter code) for a Base coded as int.
  * @param Base Int description of the amino-acid to analyse.
  * @return
  */
 //virtual QString GetLto3(const QString& Base) const throw (UnCompatibleCharException){};
};

} // namespace BioQt

#endif // BIOQT_ALPHABET_H
