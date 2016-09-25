/*
 * KMPEdit - Made by Ermelber and MKGirlism
 * 2016
 */

/* 
 * File:   main.cpp
 * Author: Ermii
 *
 * Created on 19 settembre 2016, 17.10
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "AbstractKMP.h"

using namespace std;
using namespace pugi;

int main(int argc, char** argv) {
    AbstractKMP glide_lake("Gctr_GlideLake.kmp");
    glide_lake.Write("GlideLake.dat");
    
    xml_document doc;
    xml_parse_result result = doc.load_file("kmp.xml");
    
    
    cout << "hello";
    return 0;
}

