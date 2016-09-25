/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KMP.h
 * Author: Ermii
 *
 * Created on 20 settembre 2016, 21.50
 */

#ifndef KMP_H
#define KMP_H

#include <iostream>
#include "Libs/EndianBinaryIO.h"
#include "KMPSections.h"

using namespace std;

class KMPHeader
{
public:
    string signature;
    uint32_t filesize;
    uint16_t nr_sections;
    uint16_t header_size;
    uint32_t version;
    uint32_t section_offsets[0xE];
    KMPHeader(EndianBinaryReader&);
    KMPHeader();
    void Write(EndianBinaryWriter&);
    void WriteSectionInfo(EndianBinaryWriter&,uint32_t);
    void WriteFileSize(EndianBinaryWriter&);
};

class KMP {
public:
    KMP(FILE*);
    KMPHeader* header;
    KartPoint* ktpt;
    EnemyPoint* enpt;
    EnemyPath* enph;
    ItemPoint* itpt;
    ItemPath* itph;
    CheckPoint* ckpt;
    CheckPath* ckph;
    GlobalObject* gobj;
    PointInfo* poti;
    AreaPoint* area;
    Camera* came;
    JugemPoint* jgpt;
    CannonPoint* cnpt;
    MissionPoint* mspt;
    StageInfo* stgi;
    CourseSect* cors;
    GliderPoint* glpt;
    GliderPath* glph;
    void Write(FILE*);
};



#endif /* KMP_H */

