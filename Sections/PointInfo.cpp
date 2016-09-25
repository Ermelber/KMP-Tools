/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointInfo.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 19.56
 */

#include "PointInfo.h"

PointInfo::PointInfo() {
    signature = "ITOP";
    nr_routes = 0;
    nr_points = 0;
}

PointInfo::PointInfo(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_routes = er.ReadUInt16();
    nr_points = er.ReadUInt16();
    if (nr_routes==0) return;
    routes = new POTIRoute*[nr_routes];
    for (int i=0;i<nr_routes;i++)
        routes[i] = new POTIRoute(er);
}

void PointInfo::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_routes);
    ew.Write(nr_points);
    if (nr_routes==0) return;
    for (int i=0;i<nr_routes;i++)
        routes[i]->Write(ew);
}

POTIRoute::POTIRoute()
{
    nr_entries = 0;
    loop = 0;
    setting_2 = 0;
}

POTIRoute::POTIRoute(EndianBinaryReader& er)
{
    nr_entries = er.ReadUInt16();
    loop = er.ReadByte();
    setting_2 = er.ReadByte();
    if (nr_entries==0) return;
    entries = new potientry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<potientry_t>();
}

void POTIRoute::Write(EndianBinaryWriter& ew)
{
    ew.Write(nr_entries);
    ew.Write(loop);
    ew.Write(setting_2);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}