/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyRoutes.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.26
 */

#include "EnemyRoutes.h"

EnemyRoutes::EnemyRoutes(EnemyPoint* enpt, EnemyPath* enph) {
    nr_routes = enph->nr_entries;
    if (nr_routes==0) return;
    routes = new enemyroute_t[nr_routes];
    for (int path=0;path<nr_routes;path++)
    {
        uint16_t start = enph->entries[path]->start;
        uint16_t length = enph->entries[path]->length;
        routes[path].nr_entries = length;
        routes[path].unknown = enph->entries[path]->unknown;
        if (length!=0)
        {
            routes[path].entries = new enptentry_t[length];
            for (int i=0;i<16;i++)
            {
                routes[path].next[i] = enph->entries[path]->next[i];
                routes[path].previous[i] = enph->entries[path]->previous[i];
            }
            for (int i=0;i<length;i++)
            {
                routes[path].entries[i] = *enpt->entries[i+start];
            }
        }
    }
}

uint32_t EnemyRoutes::GetNrPoints()
{
    if (nr_routes == 0) return 0;
    uint32_t nr_points = 0;
    for (int path=0;path<nr_routes;path++)
    {
        nr_points+=routes[path].nr_entries;
    }
    return nr_points;
}

EnemyPoint* EnemyRoutes::ToENPT()
{
    EnemyPoint* enpt = new EnemyPoint();
    enpt->nr_entries = GetNrPoints();
    if (enpt->nr_entries > 0)
    {
        enpt->entries = new enptentry_t*[enpt->nr_entries];
        int id=0;
        for (int path=0;path<nr_routes;path++)
            for (int i=0;i<routes[path].nr_entries;i++,id++)
                enpt->entries[id] = &routes[path].entries[i];
    }
    return enpt;
}

EnemyPath* EnemyRoutes::ToENPH()
{
    EnemyPath* enph = new EnemyPath();
    enph->nr_entries = nr_routes;
    if (nr_routes>0)
    {
        enph->entries = new enphentry_t*[nr_routes];
        uint16_t start = 0;
        for (int i=0;i<nr_routes;i++)
        {
            enph->entries[i] = new enphentry_t;
            enph->entries[i]->length = routes[i].nr_entries;
            enph->entries[i]->start = start;
            enph->entries[i]->unknown = routes[i].unknown;
            for (int j=0;j<16;j++)
            {
                enph->entries[i]->next[j] = routes[i].next[j];
                enph->entries[i]->previous[j] = routes[i].previous[j];
            }
            start+=routes[i].nr_entries;
        }
    }
    return enph;
}