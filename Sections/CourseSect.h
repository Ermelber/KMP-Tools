/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CourseSect.h
 * Author: Ermii
 *
 * Created on 23 settembre 2016, 20.47
 */

#ifndef COURSESECT_H
#define COURSESECT_H

#include "../Libs/EndianBinaryIO.h"
#include "../CommonTypes.h"
#include "SectionEntries.h"


class CourseSect {
public:
    string signature;
    uint32_t nr_entries;
    corsentry_t** entries;
    CourseSect();
    CourseSect(EndianBinaryReader&);
    void Write(EndianBinaryWriter&);

};

#endif /* COURSESECT_H */

