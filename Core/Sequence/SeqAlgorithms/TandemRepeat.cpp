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

#include "TandemRepeat.h"

namespace BioQt {

QList<TandemRepeatRecord> TandemRepeat::find_tandem_repeats(const QString & sequence,int min_length,int max_length,int min_repeats,int min_length_of_TR)
{
    QList<TandemRepeatRecord> tmp;
       int len_seq=sequence.size();
       int counter=0;
       for (int i=0;i<len_seq-min_length_of_TR;i++){
           for (int j=min_length;j<max_length+1;j++){
               if(i+j>len_seq)break;
               QString sub_seq=sequence.mid(i,j);
               int len_sub_seq=sub_seq.size();
               int matches=1;
               int plus_extra=0;
               //  qDebug()<<sub_seq;
               while (sub_seq==sequence.mid((i+j*matches),j))  matches++;
               //  qDebug()<<matches;
               if (matches>=min_repeats){
                   for (int p=0; p<sub_seq.size();p++){
                       if ( sub_seq.mid(p,1)==sequence.mid((i+j*matches),1)){plus_extra++;}else{break;}
                   }}

               if (((j*matches)+plus_extra)>=min_length_of_TR){
                   /*   qDebug()<<"start_position = "<<i;
                   qDebug()<<"pattern = "<<sub_seq;
                   qDebug()<<"number_of_repeats = "<<matches;

                   qDebug()<<"tandem_repeat_sequence = "<<SubSequence(sequence,i,(j*matches)+plus_extra);
                   qDebug()<<counter;*/
                   TandemRepeatRecord c(i,sub_seq,matches,sequence.mid(i,(j*matches)+plus_extra));
                   tmp.append(c);
                   counter++;
               }

           }


       }//j loop
       return tmp;
}

} // namespace BioQt
