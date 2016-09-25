/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MissionPoint.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.47
 */

#ifndef MISSIONPOINT_H
#define MISSIONPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class MissionPoint {
public:
    string signature;
    uint32_t nr_entries;
    msptentry_t** entries;
    MissionPoint();
    MissionPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);

};

#endif /* MISSIONPOINT_H */

