/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GliderPoint.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 20.48
 */

#include "GliderPoint.h"

GliderPoint::GliderPoint() {
    signature = "TPGL";
    nr_entries = 0;
}

GliderPoint::GliderPoint(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new glptentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<glptentry_t>();
}

void GliderPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}

