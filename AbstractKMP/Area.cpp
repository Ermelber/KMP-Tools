/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Area.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.31
 */

#include "Area.h"

Area::Area(AreaPoint* area) {
    nr_entries = area->nr_entries;
    if (nr_entries==0) return;
    entries = new areaentry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *area->entries[i];
}

AreaPoint* Area::ToAREA()
{
    AreaPoint* area = new AreaPoint();
    area->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        area->entries = new areaentry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            area->entries[i] = &entries[i];
    }
    return area;
}