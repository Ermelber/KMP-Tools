/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Objects.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.31
 */

#include "Objects.h"

Objects::Objects(GlobalObject* gobj) {
    nr_entries = gobj->nr_entries;
    if (nr_entries==0) return;
    entries = new gobjentry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *gobj->entries[i];
}

GlobalObject* Objects::ToGOBJ()
{
    GlobalObject* gobj = new GlobalObject();
    gobj->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        gobj->entries = new gobjentry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            gobj->entries[i] = &entries[i];
    }
    return gobj;
}
