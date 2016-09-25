/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalObject.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 19.39
 */

#ifndef GLOBALOBJECT_H
#define GLOBALOBJECT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class GlobalObject {
public:
    string signature;
    uint32_t nr_entries;
    gobjentry_t** entries;
    GlobalObject();
    GlobalObject(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* GLOBALOBJECT_H */

