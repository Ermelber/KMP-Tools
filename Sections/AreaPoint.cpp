/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AreaPoint.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 20.46
 */

#include "AreaPoint.h"

AreaPoint::AreaPoint() {
    signature = "AERA";
    nr_entries = 0;
}

AreaPoint::AreaPoint(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new areaentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<areaentry_t>();
}

void AreaPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}