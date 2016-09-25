/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StageInfo.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 20.47
 */

#include "StageInfo.h"


StageInfo::StageInfo() {
    signature = "IGTS";
    nr_entries = 0;
}

StageInfo::StageInfo(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new stgientry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<stgientry_t>();
}

void StageInfo::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}

