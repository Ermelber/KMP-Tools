/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KartPoint.cpp
 * Author: Ermii
 * 
 * Created on 20 settembre 2016, 22.41
 */

#include "KartPoint.h"

KartPoint::KartPoint()
{
    signature = "TPTK";
    nr_entries = 0;
}

KartPoint::KartPoint(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new ktptentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<ktptentry_t>();
}

void KartPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}