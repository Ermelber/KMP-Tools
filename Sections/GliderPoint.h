/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GliderPoint.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.48
 */

#ifndef GLIDERPOINT_H
#define GLIDERPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class GliderPoint {
public:
    string signature;
    uint32_t nr_entries;
    glptentry_t** entries;
    GliderPoint();
    GliderPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* GLIDERPOINT_H */

