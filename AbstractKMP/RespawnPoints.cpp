/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RespawnPoints.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.32
 */

#include "RespawnPoints.h"

RespawnPoints::RespawnPoints(JugemPoint* jgpt) {
    nr_entries = jgpt->nr_entries;
    if (nr_entries==0) return;
    entries = new jgptentry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *jgpt->entries[i];
}

JugemPoint* RespawnPoints::ToJGPT()
{
    JugemPoint* jgpt = new JugemPoint();
    jgpt->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        jgpt->entries = new jgptentry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            jgpt->entries[i] = &entries[i];
    }
    return jgpt;
}