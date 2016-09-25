/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CannonPoint.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.46
 */

#ifndef CANNONPOINT_H
#define CANNONPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class CannonPoint {
public:
    string signature;
    uint32_t nr_entries;
    cnptentry_t** entries;
    CannonPoint();
    CannonPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);

};

#endif /* CANNONPOINT_H */

