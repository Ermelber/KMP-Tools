/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemPath.cpp
 * Author: Ermii
 * 
 * Created on 22 settembre 2016, 16.40
 */

#include "ItemPath.h"

ItemPath::ItemPath() {
    signature = "HPTI";
    nr_entries = 0;
}

ItemPath::ItemPath(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new itphentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<itphentry_t>();
}

void ItemPath::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}