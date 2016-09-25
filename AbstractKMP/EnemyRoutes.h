/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyRoutes.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.26
 */

#ifndef ENEMYROUTES_H
#define ENEMYROUTES_H

#include "../KMPSections.h"

struct enemyroute_t
{
    uint32_t nr_entries;
    enptentry_t* entries;
    int16_t previous[16];
    int16_t next[16];
    uint32_t unknown;
};

class EnemyRoutes {
public:
    EnemyRoutes(EnemyPoint*,EnemyPath*);
    EnemyPoint* ToENPT();
    EnemyPath* ToENPH();
private:
    uint32_t nr_routes;
    enemyroute_t* routes;
    uint32_t GetNrPoints();
};

#endif /* ENEMYROUTES_H */

