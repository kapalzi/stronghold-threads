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
        this->stronghold->breadsReady.wait(locker);
        for (int i = 0; i<20; i++) {
            this->stronghold->workingBowMakers[i] = false;
            this->stronghold->workingMiners[i] = false;
            this->stronghold->workingBakers[i] = false;
            this->stronghold->workingFarmers[i] = false;
            this->stronghold->workingLumberjacks[i] = false;
        }
        this->stronghold->armory.getBows(50);
        this->stronghold->armory.getSwords(50);
        this->stronghold->granary.getBreads(100);
        printf("Recruited \n");
        locker.unlock();
    }
}

