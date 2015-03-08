include(Oligo/Oligo.pri)
include(SeqAlgorithms/SeqAlgorithms.pri)
include(DNATranslation/DNATranslation.pri)
HEADERS += \
    Core/Sequence/SequenceException.h \
    Core/Sequence/SequenceTools.h \
    Core/Sequence/MoleculeType.h \
    Core/Sequence/OligonucleotideProperties.h \
    Core/Sequence/QSequence.h \
    Core/Sequence/Feature.h \
    Core/Sequence/SeqInfo.h

SOURCES += \
    Core/Sequence/SequenceTools.cpp \
    Core/Sequence/MoleculeType.cpp \
    Core/Sequence/OligonucleotideProperties.cpp \
    Core/Sequence/QSequence.cpp \
    Core/Sequence/SeqRecord.cpp
