/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StageInfo.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.47
 */

#ifndef STAGEINFO_H
#define STAGEINFO_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class StageInfo {
public:
    string signature;
    uint32_t nr_entries;
    stgientry_t** entries;
    StageInfo();
    StageInfo(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);

};

#endif /* STAGEINFO_H */

