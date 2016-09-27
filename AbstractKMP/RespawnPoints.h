/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RespawnPoints.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.32
 */




#ifndef RESPAWNPOINTS_H
#define RESPAWNPOINTS_H

#include "../KMPSections.h"

class RespawnPoints {
public:
    RespawnPoints(JugemPoint*);
    JugemPoint* ToJGPT();
private:
    uint32_t nr_entries;
    jgptentry_t* entries;
};

#endif /* RESPAWNPOINTS_H */

