/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraPoints.cpp
 * Author: Ermii
 * 
 * Created on 27 settembre 2016, 19.19
 */

#include "CameraPoints.h"

CameraPoints::CameraPoints(Camera* came) {
    nr_entries = came->nr_entries;
    if (nr_entries==0) return;
    entries = new cameentry_t[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = *came->entries[i];
}

Camera* CameraPoints::ToCAME()
{
    Camera* came = new Camera();
    came->nr_entries = nr_entries;
    if (nr_entries>0)
    {
        came->entries = new cameentry_t*[nr_entries];
        for (int i=0;i<nr_entries;i++)
            came->entries[i] = &entries[i];
    }
    return came;
}

