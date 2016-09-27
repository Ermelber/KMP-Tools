/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraPoints.h
 * Author: Ermii
 *
 * Created on 27 settembre 2016, 19.19
 */

#ifndef CAMERAPOINTS_H
#define CAMERAPOINTS_H

#include "../KMPSections.h"

class CameraPoints {
public:
    CameraPoints(Camera*);
    Camera* ToCAME();
private:
    uint32_t nr_entries;
    cameentry_t* entries;
};

#endif /* CAMERAPOINTS_H */

