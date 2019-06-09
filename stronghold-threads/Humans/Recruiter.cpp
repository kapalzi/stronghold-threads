//
//  Recruiter.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 09/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Recruiter.hpp"
#include "../Helper.h"

Recruiter::Recruiter() {
    
}

void Recruiter::startWorking() {
    
    while(1) {
        signed int time = Helper::getRandomTime();
        std::this_thread::sleep_for(chrono::milliseconds(time));
        
        unique_lock<mutex> locker(this->stronghold->armory);
        this->stronghold->bowsReady.wait(locker);
        this->stronghold->swordsReady.wait(locker);
        for (int i = 0; i<20; i++) {
            this->stronghold->workingBowMakers[i] = false;
            this->stronghold->workingMiners[i] = false;
            this->stronghold->workingBakers[i] = false;
            this->stronghold->workingFarmers[i] = false;
            this->stronghold->workingLumberjacks[i] = false;
        }
        this->stronghold->armory.getBows(50);
        this->stronghold->armory.getSwords(50);
        
        printf("Bows Count: %d \nWood Count: %d \nWheat Count: %d \nIron Count: %d\nSwords Count: %d\nBread Count: %d \n XXXXXXXXXXXXXXX\n",this->stronghold->armory.bowsCapacity, this->stronghold->warehouse.woodCapacity,this->stronghold->warehouse.wheatCapacity,this->stronghold->warehouse.ironCapacity, this->stronghold->armory.swordsCapacity, this->stronghold->granary.breadCapacity);
        
        locker.unlock();
    }
}

