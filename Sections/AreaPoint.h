/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AreaPoint.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.46
 */

#ifndef AREAPOINT_H
#define AREAPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class AreaPoint {
public:
    string signature;
    uint32_t nr_entries;
    areaentry_t** entries;
    AreaPoint();
    AreaPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);

};

#endif /* AREAPOINT_H */

