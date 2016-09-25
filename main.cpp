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
#include "KMP.h"
#include "Libs/EndianBinaryIO.h"

using namespace std;


int main(int argc, char** argv) {
    FILE* file = fopen("Gctr_GlideLake.kmp","rb");
    KMP kmp_data(file);
    
    FILE* file2 = fopen("2_save.kmp","wb");
    kmp_data.Write(file);
    
    cout << "hello";
    return 0;
}

