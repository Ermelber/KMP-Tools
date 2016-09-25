/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: Ermii
 * 
 * Created on 23 settembre 2016, 20.46
 */

#include "Camera.h"

Camera::Camera() {
    signature = "EMAC";
    nr_entries = 0;
    unknown = 0xFFFF;
}

Camera::Camera(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    nr_entries = er.ReadUInt16();
    unknown = er.ReadUInt16();
    if (nr_entries==0) return;
    entries = new cameentry_t*[nr_entries];
    for (int i=0;i<nr_entries;i++)
        entries[i] = er.ReadObject<cameentry_t>();
}

void Camera::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(nr_entries);
    ew.Write(unknown);
    if (nr_entries==0) return;
    for (int i=0;i<nr_entries;i++)
        entries[i]->Write(ew);
}