  /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyPoint.h
 * Author: Ermii
 *
 * Created on 21 settembre 2016, 19.14
 */

#ifndef ENEMYPOINT_H
#define ENEMYPOINT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class EnemyPoint {
public:
    string signature;
    uint32_t nr_entries;
    enptentry_t** entries;
    EnemyPoint();
    EnemyPoint(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* ENEMYPOINT_H */

