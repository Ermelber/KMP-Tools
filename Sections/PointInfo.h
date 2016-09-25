/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointInfo.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 19.56
 */

#ifndef POINTINFO_H
#define POINTINFO_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class POTIRoute{
public:
    uint16_t nr_entries;
    uint8_t loop;
    uint8_t setting_2;
    potientry_t** entries;
    POTIRoute();
    POTIRoute(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

class PointInfo {
public:
    string signature;
    uint16_t nr_routes;
    uint16_t nr_points;
    POTIRoute** routes;
    PointInfo();
    PointInfo(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* POINTINFO_H */

