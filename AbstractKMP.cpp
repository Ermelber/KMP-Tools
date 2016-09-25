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
    enemy_routes = new EnemyRoutes(kmp_data->enpt,kmp_data->enph);
}

void AbstractKMP::ToKMP()
{
    kmp_data->enpt = enemy_routes->ToENPT();
    kmp_data->enph = enemy_routes->ToENPH();
}

void AbstractKMP::Write(FILE* file_stream)
{
    ToKMP();
    kmp_data->Write(file_stream);
}

void AbstractKMP::Write(string filename)
{
    ToKMP();
    FILE* file_stream = fopen(filename.c_str(),"wb");
    kmp_data->Write(file_stream);
}