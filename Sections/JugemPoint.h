/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JugemPoint.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.46
 */

#ifndef JUGEMPOINT_H
#define JUGEMPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class JugemPoint {
public:
    string signature;
    uint32_t nr_entries;
    jgptentry_t** entries;
    JugemPoint();
    JugemPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* JUGEMPOINT_H */

