/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Objects.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 15.31
 */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "../KMPSections.h"

class Objects {
public:
    Objects(GlobalObject*);
    GlobalObject* ToGOBJ();
private:
    uint32_t nr_entries;
    gobjentry_t* entries;
};

#endif /* OBJECTS_H */

