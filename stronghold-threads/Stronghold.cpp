//
//  Stronghold.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Stronghold.hpp"

Stronghold::Stronghold() {
    this->initWorld();
}

Stronghold::~Stronghold() {
    
}

void Stronghold::initWorld() {
    this->initGranary();
    this->initWarehouse();
    this->initArmory();
    this->initPopulation();
//    this->startLife();
}

void Stronghold::initGranary() {
    this->granary.maxCapacity = 10000;
    this->granary.currentCapacity = 0;
}

void Stronghold::initWarehouse() {
    this->warehouse.woodCapacity = 0;
    this->warehouse.woodMaxCapacity = 2000;
    
    this->warehouse.flourCapacity = 0;
    this->warehouse.flourMaxCapacity = 2000;
    
    this->warehouse.wheatCapacity = 0;
    this->warehouse.wheatMaxCapacity = 2000;
    
    this->warehouse.ironCapacity = 0;
    this->warehouse.ironMaxCapacity = 2000;
}

void Stronghold::initArmory() {
    this->armory.swordsMaxCapacity = 150;
    this->armory.swordsCapacity = 0;
    this->armory.bowsMaxCapacity = 150;
    this->armory.bowsCapacity = 0;
}

void Stronghold::initPopulation(){
    
}

//void Life::startLife() {
//    //miners
//    for (int i = 0; i < WORKERSCOUNT; ++i) {
//        this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
//        //        this->workingMiners[i] = true;
//    }
//}
//
//void Life::startMiner(int id) {
//    Miner *miner = new Miner();
//    miner->workerId = id;
//}



