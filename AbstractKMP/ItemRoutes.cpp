/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemRoutes.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.26
 */

#include "ItemRoutes.h"

ItemRoutes::ItemRoutes(ItemPoint* itpt, ItemPath* itph) {
    nr_routes = itph->nr_entries;
    if (nr_routes==0) return;
    routes = new itemroute_t[nr_routes];
    for (int path=0;path<nr_routes;path++)
    {
        uint16_t start = itph->entries[path]->start;
        uint16_t length = itph->entries[path]->length;
        routes[path].nr_entries = length;
        if (length!=0)
        {
            routes[path].entries = new itptentry_t[length];
            for (int i=0;i<6;i++)
            {
                routes[path].next[i] = itph->entries[path]->next[i];
                routes[path].previous[i] = itph->entries[path]->previous[i];
            }
            for (int i=0;i<length;i++)
            {
                routes[path].entries[i] = *itpt->entries[i+start];
            }
        }
    }
}

ItemPoint* ItemRoutes::ToITPT()
{
    ItemPoint* itpt = new ItemPoint();
    itpt->nr_entries = GetNrPoints();
    if (itpt->nr_entries > 0)
    {
        itpt->entries = new itptentry_t*[itpt->nr_entries];
        int id=0;
        for (int path=0;path<nr_routes;path++)
            for (int i=0;i<routes[path].nr_entries;i++,id++)
                itpt->entries[id] = &routes[path].entries[i];
    }
    return itpt;
}

ItemPath* ItemRoutes::ToITPH()
{
    ItemPath* itph = new ItemPath();
    itph->nr_entries = nr_routes;
    if (nr_routes>0)
    {
        itph->entries = new itphentry_t*[nr_routes];
        uint16_t start = 0;
        for (int i=0;i<nr_routes;i++)
        {
            itph->entries[i] = new itphentry_t;
            itph->entries[i]->length = routes[i].nr_entries;
            itph->entries[i]->start = start;
            for (int j=0;j<6;j++)
            {
                itph->entries[i]->next[j] = routes[i].next[j];
                itph->entries[i]->previous[j] = routes[i].previous[j];
            }
            start+=routes[i].nr_entries;
        }
    }
    return itph;
}

uint32_t ItemRoutes::GetNrPoints()
{
    if (nr_routes == 0) return 0;
    uint32_t nr_points = 0;
    for (int path=0;path<nr_routes;path++)
    {
        nr_points+=routes[path].nr_entries;
    }
    return nr_points;
}
