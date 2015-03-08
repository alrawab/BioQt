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



#ifndef SAFEPOINTS_H
#define SAFEPOINTS_H

#include <assert.h>
#include <QtCore>

/**
    Recover utility. Must be used when code tries to recover from invalid internal state
    by returning from the method some default value.
    Traces the message to log. Asserts in debug mode.

    Warning: never use this function as a simple check since it stops application execution in debug mode
            use CHECK_OP instead
*/
#define SAFE_POINT(condition, message, result)  \
    if (!(condition)) { \
        qDebug()<< QString("Trying to recover from error: %1 at %2:%3").arg(message).arg(__FILE__).arg(__LINE__); \
        assert(condition); \
        return result; \
    } \


/**
    Recover utility. Must be used when code tries to recover from invalid internal state
    by returning from the method some default value.
    Dumps the message to the error-level log. Asserts in debug mode.

    Warning: never use this function as a simple check since it stops application execution in debug mode
    use CHECK_OP instead

*/
#define SAFE_POINT_OP(os, result)  \
    if (os.hasError()) { \
        qDebug()<< QString("Trying to recover from error: %1 at %2:%3").arg(os.getError()).arg(__FILE__).arg(__LINE__); \
        assert(0); \
        return result; \
    } \


/**
    Recover utility. Must be used when code tries to recover from invalid internal state
    by returning from the method some default value.
    Asserts in debug mode. Performs extra recovery op in release

    Warning: never use this function as a simple check since it stops application execution in debug mode
            use CHECK_OP instead
*/
#define SAFE_POINT_EXT(condition, extraOp, result)  \
    if (!(condition)) { \
        assert(condition); \
        extraOp; \
        return result; \
    } \

/**
    FAIL utility. Same as SAFE_POINT but uses unconditional fail.
    Can be used in code that must be unreachable
*/
#define FAIL(message, result)  \
    qDebug()<<QString("Trying to recover from error: %1 at %2:%3").arg(message).arg(__FILE__).arg(__LINE__); \
    assert(0); \
    return result; \

/**
    Checks condition is false and returns the result if it is

    Code style hint: use CHECK macro only to make error processing more compact but not all if {return;} patterns !
*/
#define CHECK(condition, result) \
    if (!(condition)) { \
        return result; \
    }

/**
    Checks condition is false and returns the result if it is.
    Before the result is returned the 'extraOp' operation is performed (for example logging)

    Code style hint: use CHECK macro only to make error processing more compact but not all if {return;} patterns !
*/
#define CHECK_EXT(condition, extraOp, result) \
    if (!(condition)) { \
        extraOp; \
        return result; \
    }


/**
    Checks that operation is neither not failed nor canceled and returns the result if it does
*/
#define CHECK_OP(os, result)  CHECK(!os.isCoR(), result)

/**
    Checks that operation is neither failed nor canceled and returns the result if it does.
    Before the result is returned the 'extraOp' operation is performed (for example logging)
*/
#define CHECK_OP_EXT(os, extraOp, result)  CHECK_EXT(!(os.isCoR()), extraOp, result)

#endif











