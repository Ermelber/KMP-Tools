/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StageSettings.h
 * Author: Ermii
 *
 * Created on 27 settembre 2016, 19.21
 */

#ifndef STAGESETTINGS_H
#define STAGESETTINGS_H

#include "../KMPSections.h"

class StageSettings {
public:
    StageSettings(StageInfo*);
    StageInfo* ToSTGI();
private:
    uint32_t nr_entries;
    stgientry_t* entries;
};

#endif /* STAGESETTINGS_H */

