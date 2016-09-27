/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Routes.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.32
 */

#ifndef ROUTES_H
#define ROUTES_H

#include "../KMPSections.h"

struct route_t
{
    uint16_t nr_entries;
    uint8_t loop;
    uint8_t setting_2;
    potientry_t* entries;
};

class Routes {
public:
    Routes(PointInfo*);
    PointInfo* ToPOTI();
private:
    uint16_t nr_routes;
    route_t* routes;
    uint16_t GetNrPoints();
};

#endif /* ROUTES_H */

