/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckPoints.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.26
 */

#ifndef CHECKPOINTS_H
#define CHECKPOINTS_H

#include "../KMPSections.h"

struct checkroute_t
{
    uint32_t nr_entries;
    ckptentry_t* entries;
    int8_t previous[6];
    int8_t next[6];
    uint16_t unknown;
};

class CheckPoints {
public:
    CheckPoints(CheckPoint*,CheckPath*);
    CheckPoint* ToCKPT();
    CheckPath* ToCKPH();
private:
    uint32_t nr_routes;
    checkroute_t* routes;
    uint32_t GetNrPoints();
};

#endif /* CHECKPOINTS_H */

