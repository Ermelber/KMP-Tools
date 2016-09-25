/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyPath.cpp
 * Author: Ermii
 * 
 * Created on 22 settembre 2016, 16.08
 */

#include "EnemyPath.h"

EnemyPath::EnemyPath() {
    signature = "HPNE";
    nr_entries = 0;
}

EnemyPath::EnemyPath(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new enphentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<enphentry_t>();
}

void EnemyPath::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}