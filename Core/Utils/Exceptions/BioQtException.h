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

#ifndef BIOQTEXCEPTION_H
#define BIOQTEXCEPTION_H

#include <QtCore>
#include <stdexcept>
#include <BioQt_global.h>

namespace BioQt {

class BIOQTSHARED_EXPORT BioQtException:
        public std::exception
{
protected:
    std::string message_;

public:
    /**
     * @brief Build a new BioQtException.
     *
     * @param text A message to be passed to the bioqtexception hierarchy.
     */
    BioQtException(const char* text): message_(std::string(text)) {}
    BioQtException(const QString& text): message_(text.toStdString()) {}
    BioQtException(const std::string& text): message_(text) {}

    virtual ~BioQtException() throw() {}

public:

    /**
     * @brief Method to get the message of the exception (STL method redefinition).
     *
     * @return The message passed to the exception hierarchy.
     */
    const char* what() const throw() { return message_.c_str(); }
};


} // namespace BioQt

#endif // BIOQT_BIOQTEXCEPTION_H
