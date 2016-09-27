/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemRoutes.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.26
 */

#ifndef ITEMROUTES_H
#define ITEMROUTES_H

#include "../KMPSections.h"

struct itemroute_t
{
    uint32_t nr_entries;
    itptentry_t* entries;
    int16_t previous[6];
    int16_t next[6];
};

class ItemRoutes {
public:
    ItemRoutes(ItemPoint*,ItemPath*);
    ItemPoint* ToITPT();
    ItemPath* ToITPH();
private:
    uint32_t nr_routes;
    itemroute_t* routes;
    uint32_t GetNrPoints();
};

#endif /* ITEMROUTES_H */

