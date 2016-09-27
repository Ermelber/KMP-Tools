/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KartPoints.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.31
 */

#ifndef KARTPOINTS_H
#define KARTPOINTS_H

#include "../KMPSections.h"

class KartPoints {
public:
    KartPoints(KartPoint*);
    KartPoint* ToKTPT();
private:
    uint32_t nr_entries;
    ktptentry_t* entries;
};

#endif /* KARTPOINTS_H */

