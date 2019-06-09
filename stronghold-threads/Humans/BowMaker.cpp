//
//  BowMaker.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 09/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "BowMaker.hpp"
#include "../Helper.h"

BowMaker::BowMaker() {
    
}

void BowMaker::startWorking() {
    
    while(this->stronghold->workingBowMakers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void BowMaker::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetWood()) {
            this->stronghold->warehouse.getWood();
            this->stronghold->warehouse.unlock();
            //printf("Wzięto drewno \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}

void BowMaker::workOnProduct()
{
    //    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}
void BowMaker::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->armory.try_lock()) {
        if (this->stronghold->armory.canStoreBows(1)) {
            this->stronghold->armory.storeBows(1);
            if (this->stronghold->armory.bowsCapacity >= 100) {
                this->stronghold->bowsReady.notify_one();
            }
            
            this->stronghold->armory.unlock();
            //printf("Zaniesiono łuk \n");
        } else {
            this->stronghold->armory.unlock();
        }
    }
}
