/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckPoint.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 16.40
 */

#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class CheckPoint {
public:
    string signature;
    uint32_t nr_entries;
    ckptentry_t** entries;
    CheckPoint();
    CheckPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* CHECKPOINT_H */

