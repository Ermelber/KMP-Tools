/*
 * KMP Tools - Made by Ermelber and MKGirlism
 * Copyright 2016 - Ermiisoft
 */

/* 
 * File:   main.cpp
 * Author: Ermii
 *
 * Created on 19 settembre 2016, 17.10
 */

#include <cstdlib>
#include <stdio.h>
#include "AbstractKMP.h"

using namespace std;

int main(int argc, char** argv) {
    AbstractKMP glide_lake("files//Gctr_GlideLake.kmp");
    glide_lake.Write("files//GlideLake.dat");
    AbstractKMP battle_course1("files//battle.kmp");
    battle_course1.Write("files//battle.dat");
    
    cout << "hello";
    return 0;
}

