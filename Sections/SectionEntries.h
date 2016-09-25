/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SectionStructs.h
 * Author: Ermii
 *
 * Created on 22 settembre 2016, 15.27
 */

#ifndef SECTIONSTRUCTS_H
#define SECTIONSTRUCTS_H

#include "../CommonTypes.h"
#include "../Libs/EndianBinaryIO.h"

struct __attribute__((packed)) ktptentry_t
{
private:
    Vector3 position;
    Vector3 rotation;
    uint32_t index;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<ktptentry_t>(this);
    }
};

struct __attribute__((packed)) enptentry_t
{
private:
    Vector3 position;
    float scale;
    uint32_t unknown_1;
    uint32_t unknown_2;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<enptentry_t>(this);
    }
};

struct __attribute__((packed)) enphentry_t
{
private:
    uint16_t start;
    uint16_t length;
    int16_t previous[16];
    int16_t next[16];
    uint32_t unknown;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<enphentry_t>(this);
    }
};

struct __attribute__((packed)) itptentry_t
{
private:
    Vector3 position;
    float scale;
    uint32_t unknown;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<itptentry_t>(this);
    }
};

struct __attribute__((packed)) itphentry_t
{
private:
    uint16_t start;
    uint16_t length;
    int16_t previous[6];
    int16_t next[6];
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<itphentry_t>(this);
    }
};

struct __attribute__((packed)) ckptentry_t
{
private:
    Vector2 point_1;
    Vector2 point_2;
    int8_t respawn_id;
    int8_t type;
    int8_t previous;
    int8_t next;
    uint8_t unknown_1;
    int8_t section;
    uint8_t unknown_2;
    uint8_t unknown_3;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<ckptentry_t>(this);
    }
};

struct __attribute__((packed)) ckphentry_t
{
private:
    uint8_t start;
    uint8_t length;
    int8_t previous[6];
    int8_t next[6];
    uint16_t unknown;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<ckphentry_t>(this);
    }
};

struct __attribute__((packed)) gobjentry_t
{
private:
    uint16_t object_id;
    uint16_t unknown_1;
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    int16_t route_id;
    uint16_t settings[8];
    uint16_t visibility;
    uint16_t unknown_2;
    uint16_t unknown_3;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<gobjentry_t>(this);
    }
};

struct __attribute__((packed)) potientry_t
{
private:
    Vector3 position;
    uint16_t settings[2];
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<potientry_t>(this);
    }
};

struct __attribute__((packed)) areaentry_t
{
private:
    uint8_t mode;
    uint8_t type;
    int8_t came_index;
    uint8_t unknown_1;
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    uint16_t unknown_2;
    uint16_t unknown_3;
    uint16_t unknown_4;
    uint16_t unknown_5;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<areaentry_t>(this);
    }
};

struct __attribute__((packed)) cameentry_t
{
private:
    uint8_t type;
    uint8_t next;
    uint8_t unknown_1;
    uint8_t route_id;
    uint16_t route_speed;
    uint16_t fov_speed;
    uint16_t viewpoint_speed;
    uint8_t unknown_2;
    uint8_t unknown_3;
    Vector3 position;
    Vector3 rotation;
    float fov_begin;
    float fov_end;
    Vector3 viewpoint_1;
    Vector3 viewpoint_2;
    float duration;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<cameentry_t>(this);
    }
};

struct __attribute__((packed)) jgptentry_t
{
private:
    Vector3 position;
    Vector3 rotation;
    uint16_t index;
    uint16_t unknown;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<jgptentry_t>(this);
    }
};

struct __attribute__((packed)) cnptentry_t
{
    //It is unknown how this works.
};

struct __attribute__((packed)) msptentry_t
{
    //It is unknown how this works.
};

struct __attribute__((packed)) stgientry_t
{
private:
    uint8_t nr_laps;
    uint8_t unknown[11];
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<stgientry_t>(this);
    }
};

struct __attribute__((packed)) corsentry_t
{
    //It is unknown how this works.
};

struct __attribute__((packed)) glptentry_t
{
private:
    Vector3 position;
    float scale;
    uint32_t unknown_1;
    uint32_t unknown_2;
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<glptentry_t>(this);
    }
};

struct __attribute__((packed)) glphentry_t
{
private:
    uint8_t start;
    uint8_t length;
    int8_t previous[6];
    int8_t next[6];
    uint32_t unknown_1;
    uint32_t unknown_2;
    //uint8_t idk[8];
public:
    void Write(EndianBinaryWriter& ew)
    {
        ew.WriteObject<glphentry_t>(this);
    }    
};

#endif /* SECTIONSTRUCTS_H */
