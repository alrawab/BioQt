################################################################
# BioQt Library
# Copyright (C) 2013   Usama S Erawab alrawab@hotmail.com
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GPL License, Version 2.1
################################################################

QT       += network sql xml xmlpatterns

QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TEMPLATE = lib
DEFINES += BIOQT_LIBRARY
HEADERS += BioQt_global.h \
    windef.h

include(Core/Core.pri)
#include(third_party/third_party.pri)
#include(qcustomplot/qcustomplot.pri)

OTHER_FILES += \
    LICENSE \

INCLUDEPATH +=$$PWD/Core
#INCLUDEPATH +=$$PWD/third_party
#INCLUDEPATH +=$$PWD/qcustomplot
#system(./cpinclude.sh)
