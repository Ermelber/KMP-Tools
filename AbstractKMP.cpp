/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractKMP.cpp
 * Author: Ermii
 * 
 * Created on 25 settembre 2016, 14.17
 */

#include "AbstractKMP.h"

AbstractKMP::AbstractKMP() {
}

AbstractKMP::AbstractKMP(FILE* file_stream)
{
    kmp_data = new KMP(file_stream);
    
    FromKMP();
}

AbstractKMP::AbstractKMP(string filename)
{
    FILE* file_stream = fopen(filename.c_str(),"rb");
    kmp_data = new KMP(file_stream);
    
    FromKMP();
}

void AbstractKMP::FromKMP()
{
    kart_points = new KartPoints(kmp_data->ktpt);
    enemy_routes = new EnemyRoutes(kmp_data->enpt,kmp_data->enph);
    item_routes = new ItemRoutes(kmp_data->itpt,kmp_data->itph);
    check_points = new CheckPoints(kmp_data->ckpt,kmp_data->ckph);
    objects = new Objects(kmp_data->gobj);
    routes = new Routes(kmp_data->poti);
    area = new Area(kmp_data->area);
    camera = new CameraPoints(kmp_data->came);
    respawn_points = new RespawnPoints(kmp_data->jgpt);
    settings = new StageSettings(kmp_data->stgi);
    glider_routes = new GliderRoutes(kmp_data->glpt,kmp_data->glph);
}

void AbstractKMP::ToKMP()
{
    kmp_data->ktpt = kart_points->ToKTPT();
    kmp_data->enpt = enemy_routes->ToENPT();
    kmp_data->enph = enemy_routes->ToENPH();
    kmp_data->itpt = item_routes->ToITPT();
    kmp_data->itph = item_routes->ToITPH();
    kmp_data->ckpt = check_points->ToCKPT();
    kmp_data->ckph = check_points->ToCKPH();
    kmp_data->gobj = objects->ToGOBJ();
    kmp_data->poti = routes->ToPOTI();
    kmp_data->area = area->ToAREA();
    kmp_data->came = camera->ToCAME();
    kmp_data->jgpt = respawn_points->ToJGPT();
    kmp_data->cnpt = new CannonPoint();
    kmp_data->mspt = new MissionPoint();
    kmp_data->stgi = settings->ToSTGI();
    kmp_data->cors = new CourseSect();
    kmp_data->glpt = glider_routes->ToGLPT();
    kmp_data->glph = glider_routes->ToGLPH();
}

void AbstractKMP::Write(FILE* file_stream)
{
    ToKMP();
    kmp_data->Write(file_stream);
}

void AbstractKMP::Write(string filename)
{
    FILE* file_stream = fopen(filename.c_str(),"wb");
    
    ToKMP();
    kmp_data->Write(file_stream);
}