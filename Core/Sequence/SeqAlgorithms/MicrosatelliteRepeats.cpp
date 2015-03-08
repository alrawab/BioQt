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

#include "MicrosatelliteRepeats.h"

namespace BioQt {

MicrosatelliteRepeats::MicrosatelliteRepeats(){}
//======================================================================
//**************************Find Microsatellite Repeats****************
//======================================================================
QString MicrosatelliteRepeats::includeN_1(const QString & primer,int minus)
{
    QString code="."+primer.mid(1);
    int wpos=1;

    while (wpos<primer.size()-minus){
        code+="|"+primer.mid(0,wpos)+"."+primer.mid(wpos+1);
        wpos++;
    }
    return code;
}
//----------------------------------------------------------
QString MicrosatelliteRepeats::includeN_2(const QString & primer,int minus)
{
    int max=primer.size()-minus;
    QString code="";
    for(int i=0;i<max;i++){
        for(int j=0; j<max-i-1;j++){
            code+="|"+primer.mid(0,i)+".";
            QString  resto=primer.mid(i+1);
            code+=resto.mid(0,j)+"."+resto.mid(j+1);

        }//j
    }
    code=code.mid(1);
    return code;
}
//---------------------------------------------------------------------
QString MicrosatelliteRepeats::includeN_3(const QString & primer,int minus)
{
    int max=primer.size()-minus;
    QString code="";
    for(int i=0;i<max;i++){
        for(int j=0;j<max-i-1;j++){
            code+="|"+primer.mid(0,i)+".";
            QString resto=primer.mid(i+1);
            code+=resto.mid(0,j)+"."+resto.mid(j+1);
        }
    }
    code=code.mid(1);
    return code;
}

MS_List MicrosatelliteRepeats::FindMicrosatelliteRepeats(QString sequence,int min_length,int max_length,int min_repeats,int min_length_of_MR,int mismatches_allowed)
{
    int len_seq= sequence.size();
    int counter=0;
    MS_List _ms_list;
    for (int i=0;i<len_seq-3;i++){

        for (int j=min_length;j<max_length+1;j++){

            if ((i+j)>len_seq){break;}
            QString sub_seq=sequence.mid(i,j);
            int len_sub_seq=sub_seq.size();
            int mismatches=floor((float)len_sub_seq*mismatches_allowed/100);
            QString sub_seq_pattern;
            if (mismatches==1){sub_seq_pattern=includeN_1(sub_seq,0);}
            else if(mismatches==2){sub_seq_pattern=includeN_2(sub_seq,0);}
            else if(mismatches==3){sub_seq_pattern=includeN_3(sub_seq,0);}
            else {sub_seq_pattern=sub_seq;}
            int matches=1;
            while(sequence.mid((i+j*matches),j).contains(QRegExp("("+sub_seq_pattern+")"))==true)matches++;


            if (matches>=min_repeats && (j*matches)>=min_length_of_MR){
                MS_Results _ms_results;
                _ms_results.Start_position=i;
                _ms_results.Length=j;
                _ms_results.Repeats=matches;
                _ms_results.MS_Sequence=sequence.mid(i,j*matches);
                _ms_list<<_ms_results;
                counter++;
                i+=j*matches;
            }


        }//j

    }//i

    return _ms_list;
}
//------------------------------------------------------------------------

} // namespace BioQt
