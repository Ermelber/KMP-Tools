/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckPoints.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.26
 */

#include "CheckPoints.h"

CheckPoints::CheckPoints(CheckPoint* ckpt, CheckPath* ckph) {
    nr_routes = ckph->nr_entries;
    if (nr_routes==0) return;
    routes = new checkroute_t[nr_routes];
    for (int path=0;path<nr_routes;path++)
    {
        uint8_t start = ckph->entries[path]->start;
        uint8_t length = ckph->entries[path]->length;
        routes[path].nr_entries = length;
        routes[path].unknown = ckph->entries[path]->unknown;
        if (length!=0)
        {
            routes[path].entries = new ckptentry_t[length];
            for (int i=0;i<6;i++)
            {
                routes[path].next[i] = ckph->entries[path]->next[i];
                routes[path].previous[i] = ckph->entries[path]->previous[i];
            }
            for (int i=0;i<length;i++)
            {
                routes[path].entries[i] = *ckpt->entries[i+start];
            }
        }
    }
}

uint32_t CheckPoints::GetNrPoints()
{
    if (nr_routes == 0) return 0;
    uint32_t nr_points = 0;
    for (int path=0;path<nr_routes;path++)
    {
        nr_points+=routes[path].nr_entries;
    }
    return nr_points;
}

CheckPoint* CheckPoints::ToCKPT()
{
    CheckPoint* ckpt = new CheckPoint();
    ckpt->nr_entries = GetNrPoints();
    if (ckpt->nr_entries > 0)
    {
        ckpt->entries = new ckptentry_t*[ckpt->nr_entries];
        int id=0;
        for (int path=0;path<nr_routes;path++)
            for (int i=0;i<routes[path].nr_entries;i++,id++)
                ckpt->entries[id] = &routes[path].entries[i];
    }
    return ckpt;
}

CheckPath* CheckPoints::ToCKPH()
{
    CheckPath* ckph = new CheckPath();
    ckph->nr_entries = nr_routes;
    if (nr_routes>0)
    {
        ckph->entries = new ckphentry_t*[nr_routes];
        uint8_t start = 0;
        for (int i=0;i<nr_routes;i++)
        {
            ckph->entries[i] = new ckphentry_t;
            ckph->entries[i]->length = routes[i].nr_entries;
            ckph->entries[i]->start = start;
            ckph->entries[i]->unknown = routes[i].unknown;
            for (int j=0;j<6;j++)
            {
                ckph->entries[i]->next[j] = routes[i].next[j];
                ckph->entries[i]->previous[j] = routes[i].previous[j];
            }
            start+=routes[i].nr_entries;
        }
    }
    return ckph;
}
