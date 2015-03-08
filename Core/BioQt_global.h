#ifndef BIOQT_GLOBAL_H
#define BIOQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BIOQT_LIBRARY)
#  define BIOQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BIOQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BIOQT_GLOBAL_H
