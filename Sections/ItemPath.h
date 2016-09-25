/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemPath.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 16.40
 */

#ifndef ITEMPATH_H
#define ITEMPATH_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class ItemPath {
public:
    string signature;
    uint32_t nr_entries;
    itphentry_t** entries;
    ItemPath();
    ItemPath(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* ITEMPATH_H */

