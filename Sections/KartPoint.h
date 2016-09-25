/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KartPoint.h
 * Author: Ermii
 *
 * Created on 20 settembre 2016, 22.41
 */

#ifndef KARTPOINT_H
#define KARTPOINT_H

#include <list>
#include <stdio.h>
#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

using namespace std;

class KartPoint {
public:
    string signature;
    uint32_t nr_entries;
    ktptentry_t** entries;
    KartPoint(EndianBinaryReader&);
    KartPoint();
    void Write(EndianBinaryWriter&);
};

#endif /* KARTPOINT_H */

