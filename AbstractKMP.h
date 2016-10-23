/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractKMP.h
 * Author: Ermii
 *
 * Created on 25 settembre 2016, 14.17
 */

#ifndef ABSTRACTKMP_H
#define ABSTRACTKMP_H

#include "Libs/EndianBinaryIO.h"
#include "AbstractKMPSections.h"
#include "Libs/pugixml.hpp"
#include "KMP.h"
#include <iostream>

using namespace std;
using namespace pugi;

class AbstractKMP {
public:
    AbstractKMP();
    AbstractKMP(FILE*);
    AbstractKMP(string);    
    void Write(FILE*);
    void Write(string);
    void WriteXML(string);
private:
    void FromKMP();
    void ToKMP();
    void ToXML();
    KMP* kmp_data;
    xml_document* xml_data;
public:
    KartPoints* kart_points;
    EnemyRoutes* enemy_routes;
    ItemRoutes* item_routes;
    CheckPoints* check_points;
    Objects* objects;
    Routes* routes;
    RespawnPoints* respawn_points;
    Area* area;
    CameraPoints* camera;
    StageSettings* settings;
    GliderRoutes* glider_routes;
};

#endif /* ABSTRACTKMP_H */

