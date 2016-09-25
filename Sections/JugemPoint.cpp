/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JugemPoint.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 20.46
 */

#include "JugemPoint.h"

JugemPoint::JugemPoint() {
    signature = "EMAC";
    nr_entries = 0;
}

JugemPoint::JugemPoint(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new jgptentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<jgptentry_t>();
}

void JugemPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}
