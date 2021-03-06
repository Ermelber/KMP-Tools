/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemPoint.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 16.40
 */

#ifndef ITEMPOINT_H
#define ITEMPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class ItemPoint {
public:
    string signature;
    uint32_t nr_entries;
    itptentry_t** entries;
    ItemPoint();
    ItemPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* ITEMPOINT_H */

