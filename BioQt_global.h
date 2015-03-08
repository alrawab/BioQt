#ifndef BIOQT_GLOBAL_H
#define BIOQT_GLOBAL_H

#include <QtCore/qglobal.h>


#define HI_NIBBLE(b) (((b) >> 4) & 0x0F)
#define LO_NIBBLE(b) ((b) & 0x0F)


#if defined(BIOQT_LIBRARY)
#  define BIOQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BIOQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BIOQT_GLOBAL_H
