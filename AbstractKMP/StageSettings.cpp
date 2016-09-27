/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StageSettings.cpp
 * Author: Ermii
 * 
 * Created on 27 settembre 2016, 19.21
 */

#include "StageSettings.h"

StageSettings::StageSettings(StageInfo* stgi) {
    nr_entries = stgi->nr_entries;
    if (nr_entries==0) return;
    entries = new stgientry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *stgi->entries[i];
}

StageInfo* StageSettings::ToSTGI()
{
    StageInfo* stgi = new StageInfo();
    stgi->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        stgi->entries = new stgientry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            stgi->entries[i] = &entries[i];
    }
    return stgi;
}