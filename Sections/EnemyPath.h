/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyPath.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 16.08
 */

#ifndef ENEMYPATH_H
#define ENEMYPATH_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class EnemyPath {
public:
    string signature;
    uint32_t nr_entries;
    enphentry_t** entries;
    EnemyPath();
    EnemyPath(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
private:

};

#endif /* ENEMYPATH_H */

