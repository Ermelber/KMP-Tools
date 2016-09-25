/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyPoint.cpp
 * Author: Ermii
 * 
 * Created on 21 settembre 2016, 19.14
 */

#include "EnemyPoint.h"

EnemyPoint::EnemyPoint() 
{
    signature = "TPNE";
    nr_entries = 0;
}

EnemyPoint::EnemyPoint(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt32();
    if (nr_entries==0) return;
    entries = new enptentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<enptentry_t>();
}

void EnemyPoint::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}