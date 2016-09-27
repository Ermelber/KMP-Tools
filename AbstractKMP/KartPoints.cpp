/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KartPoints.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 15.31
 */

#include "KartPoints.h"

KartPoints::KartPoints(KartPoint* ktpt) {
    nr_entries = ktpt->nr_entries;
    if (nr_entries==0) return;
    entries = new ktptentry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *ktpt->entries[i];
}

KartPoint* KartPoints::ToKTPT()
{
    KartPoint* ktpt = new KartPoint();
    ktpt->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        ktpt->entries = new ktptentry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            ktpt->entries[i] = &entries[i];
    }
    return ktpt;
}