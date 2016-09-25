/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommonTypes.h
 * Author: Ermii
 *
 * Created on 21 settembre 2016, 15.06
 */

#ifndef COMMONTYPES_H
#define COMMONTYPES_H

//#include <string.h>
//typedef char sign_t[5];
#include <stdio.h>

struct __attribute__((packed)) Vector3
{
private:
    float x,y,z;
public:
    void set(float x,float y,float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float get_x(){return x;}
    float get_y(){return y;}
    float get_z(){return z;}
};

struct __attribute__((packed)) Vector2
{
private:
    float x,z;
public:
    void set(float x,float z)
    {
        this->x = x;
        this->z = z;
    }
    float get_x(){return x;}
    float get_z(){return z;}
};

#endif /* COMMONTYPES_H */

