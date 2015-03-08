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

#include "MatrixLoader.h"
#include <Utils/qstringtokenizer.h>


namespace BioQt {

SMatrix MatrixLoader::Load(const QString &_path,const QString& _name)
{
    QFile file(_path);
    if (!file.open(QIODevice::ReadOnly)) {

        qDebug()<<"Error opening file for read";
    }
    QList<SScore> charScores;
    QString description;



    QTextStream in(&file);
    QString line ;

    while((line=in.readLine())!=NULL && line.trimmed().at(0).toAscii() == '#')
    {
        QString commentLine = line.mid(1).trimmed();
        if (line.isEmpty() && commentLine.isEmpty()) {
            continue; //skip first empty lines
        }
        description += commentLine + "\n";

    };
    QByteArray acids;
    QStringTokenizer tokenizer(line.trimmed());
    for (int j = 0; tokenizer.hasMoreToken(); ++j) {
        acids.append( tokenizer.nextToken().at(0).toAscii());
    }


    while ((line = in.readLine()) != NULL) {
        QStringTokenizer  tokenizer(line.trimmed());
        char acid = tokenizer.nextToken().at(0).toAscii();

        for (int i = 0; i < acids.size(); ++i) {
            float weight = tokenizer.nextToken().toFloat();
            charScores.append(SScore(acid, acids.at(i), weight));

        }

    }
    return SMatrix (_name,charScores,description,acids);


}

}
