/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GliderPath.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.48
 */

#ifndef GLIDERPATH_H
#define GLIDERPATH_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class GliderPath {
public:
    string signature;
    uint32_t nr_entries;
    glphentry_t** entries;
    GliderPath();
    GliderPath(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* GLIDERPATH_H */

