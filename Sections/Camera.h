/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.46
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"

class Camera {
public:
    string signature;
    uint16_t nr_entries;
    uint16_t unknown;
    cameentry_t** entries;
    Camera();
    Camera(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);
};

#endif /* CAMERA_H */

