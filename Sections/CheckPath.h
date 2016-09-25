/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckPath.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 16.40
 */

#ifndef CHECKPATH_H
#define CHECKPATH_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class CheckPath {
public:
    string signature;
    uint32_t nr_entries;
    ckphentry_t** entries;
    CheckPath();
    CheckPath(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* CHECKPATH_H */

