/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Area.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.31
 */

#ifndef AREA_H
#define AREA_H

#include "../KMPSections.h"

class Area {
public:
    Area(AreaPoint*);
    AreaPoint* ToAREA();
private:
    uint32_t nr_entries;
    areaentry_t* entries;
};

#endif /* AREA_H */

