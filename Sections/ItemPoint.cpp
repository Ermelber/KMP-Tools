/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemPoint.cpp
 * Author: Ermii
 * 
 * Created on 22 settembre 2016, 16.40
 */

#include "ItemPoint.h"

ItemPoint::ItemPoint() {
    signature = "TPTI";
    nr_entries = 0;
}

ItemPoint::ItemPoint(EndianBinaryReader& er) {
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new itptentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<itptentry_t>();
}

void ItemPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}