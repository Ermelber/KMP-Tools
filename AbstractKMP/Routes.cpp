/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Routes.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.32
 */

#include "Routes.h"

Routes::Routes(PointInfo* poti)
{
    nr_routes = poti->nr_routes;
    if (nr_routes==0) return;
    routes = new route_t[nr_routes];
    for (int i=0;i<nr_routes;i++)
    {
        routes[i].nr_entries = poti->routes[i]->nr_entries;
        routes[i].loop = poti->routes[i]->loop;
        routes[i].setting_2 = poti->routes[i]->setting_2;
        if (routes[i].nr_entries>0)
        {
            routes[i].entries = new potientry_t[routes[i].nr_entries];
            for (int j=0;j<routes[i].nr_entries;j++)
                routes[i].entries[j] = *poti->routes[i]->entries[j];
        }
    }
}

uint16_t Routes::GetNrPoints()
{
    if (nr_routes == 0) return 0;
    uint16_t nr_points = 0;
    for (int path=0;path<nr_routes;path++)
    {
        nr_points+=routes[path].nr_entries;
    }
    return nr_points;
}

PointInfo* Routes::ToPOTI()
{
    PointInfo* poti = new PointInfo();
    poti->nr_points = GetNrPoints();
    poti->nr_routes = nr_routes;
    if (nr_routes>0)
    {
        poti->routes = new POTIRoute*[nr_routes];
        for (int i=0;i<nr_routes;i++)
        {
            poti->routes[i] = new POTIRoute();
            poti->routes[i]->loop = routes[i].loop;
            poti->routes[i]->setting_2 = routes[i].setting_2;
            poti->routes[i]->nr_entries = routes[i].nr_entries;
            if (routes[i].nr_entries>0)
            {
                poti->routes[i]->entries = new potientry_t*[routes[i].nr_entries];
                for (int j=0;j<routes[i].nr_entries;j++)
                    poti->routes[i]->entries[j] = &routes[i].entries[j];
            }
        }
    }
    return poti;
}