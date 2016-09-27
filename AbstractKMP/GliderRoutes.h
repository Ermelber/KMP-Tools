/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GliderRoutes.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.31
 */

#ifndef GLIDERROUTES_H
#define GLIDERROUTES_H

#include "../KMPSections.h"

struct gliderroute_t
{
    uint32_t nr_entries;
    glptentry_t* entries;
    int8_t previous[6];
    int8_t next[6];
    uint32_t unknown_1;
	uint32_t unknown_2;
};

class GliderRoutes {
public:
    GliderRoutes(GliderPoint*,GliderPath*);
    GliderPoint* ToGLPT();
    GliderPath* ToGLPH();
private:
    uint32_t nr_routes;
    gliderroute_t* routes;
    uint32_t GetNrPoints();
};

#endif /* GLIDERROUTES_H */

