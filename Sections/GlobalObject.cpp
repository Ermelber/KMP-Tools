/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalObject.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 19.39
 */

#include "GlobalObject.h"

GlobalObject::GlobalObject() {
    signature = "JBOG";
    nr_entries = 0;
}

GlobalObject::GlobalObject(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    entries = new gobjentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<gobjentry_t>();
}

void GlobalObject::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}