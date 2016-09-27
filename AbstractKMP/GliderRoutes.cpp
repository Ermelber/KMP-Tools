/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GliderRoutes.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.31
 */

#include "GliderRoutes.h"

GliderRoutes::GliderRoutes(GliderPoint* glpt, GliderPath* glph) {
    nr_routes = glph->nr_entries;
    if (nr_routes==0) return;
    routes = new gliderroute_t[nr_routes];
    for (int path=0;path<nr_routes;path++)
    {
        uint8_t start = glph->entries[path]->start;
        uint8_t length = glph->entries[path]->length;
        routes[path].nr_entries = length;
        routes[path].unknown_1 = glph->entries[path]->unknown_1;
		routes[path].unknown_2 = glph->entries[path]->unknown_2;
        if (length!=0)
        {
            routes[path].entries = new glptentry_t[length];
            for (int i=0;i<6;i++)
            {
                routes[path].next[i] = glph->entries[path]->next[i];
                routes[path].previous[i] = glph->entries[path]->previous[i];
            }
            for (int i=0;i<length;i++)
            {
                routes[path].entries[i] = *glpt->entries[i+start];
            }
        }
    }
}

uint32_t GliderRoutes::GetNrPoints()
{
    if (nr_routes == 0) return 0;
    uint32_t nr_points = 0;
    for (int path=0;path<nr_routes;path++)
    {
        nr_points+=routes[path].nr_entries;
    }
    return nr_points;
}

GliderPoint* GliderRoutes::ToGLPT()
{
    GliderPoint* glpt = new GliderPoint();
    glpt->nr_entries = GetNrPoints();
    if (glpt->nr_entries > 0)
    {
        glpt->entries = new glptentry_t*[glpt->nr_entries];
        int id=0;
        for (int path=0;path<nr_routes;path++)
            for (int i=0;i<routes[path].nr_entries;i++,id++)
                glpt->entries[id] = &routes[path].entries[i];
    }
    return glpt;
}

GliderPath* GliderRoutes::ToGLPH()
{
    GliderPath* glph = new GliderPath();
    glph->nr_entries = nr_routes;
    if (nr_routes>0)
    {
        glph->entries = new glphentry_t*[nr_routes];
        uint8_t start = 0;
        for (int i=0;i<nr_routes;i++)
        {
            glph->entries[i] = new glphentry_t;
            glph->entries[i]->length = routes[i].nr_entries;
            glph->entries[i]->start = start;
            glph->entries[i]->unknown_1 = routes[i].unknown_1;
            glph->entries[i]->unknown_2 = routes[i].unknown_2;
            for (int j=0;j<6;j++)
            {
                glph->entries[i]->next[j] = routes[i].next[j];
                glph->entries[i]->previous[j] = routes[i].previous[j];
            }
            start+=routes[i].nr_entries;
        }
    }
    return glph;
}
