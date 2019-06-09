//
//  Life.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Life.hpp"
#include <iostream>

Life::Life() {
    stronghold = new Stronghold();
}

void Life::initLife() {
    recruiter = thread([=] {this->startRecruiter(0);});
    for (int i = 0; i < WORKERSCOUNT; ++i) {
        this->stronghold->workingMiners[i] = true;
        this->stronghold->workingLumberjacks[i] = true;
        this->stronghold->workingFarmers[i] = true;
        this->stronghold->workingBowMakers[i] = true;
        this->stronghold->workingBlacksmiths[i] = true;
        this->stronghold->workingMillers[i] = true;
        this->stronghold->workingBakers[i] = true;
        
        this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
        this->stronghold->lumberjacks[i] = thread([=] {this->startLumberjack(i);});
        this->stronghold->farmers[i] = thread([=] {this->startFarmer(i);});
        this->stronghold->bowMakers[i] = thread([=] {this->startBowMaker(i);});
        this->stronghold->blacksmiths[i] = thread([=] {this->startBlacksmith(i);});
        this->stronghold->millers[i] = thread([=] {this->startMiller(i);});
        this->stronghold->bakers[i] = thread([=] {this->startBaker(i);});
    }
    this->startLife();
    //    thread recruiter = thread([=] {this->startRecruiter(0);});
    
}

void Life::clean() {
    for (int i = 0; i < WORKERSCOUNT; ++i) {
        if (this->stronghold->workingMiners[i] == false) {
            this->stronghold->miners[i].join();
        }
        if (this->stronghold->workingLumberjacks[i] == false) {
            this->stronghold->lumberjacks[i].join();
        }
        if (this->stronghold->workingFarmers[i] == false) {
            this->stronghold->farmers[i].join();
        }
        if (this->stronghold->workingBowMakers[i] == false) {
            this->stronghold->bowMakers[i].join();
        }
        if (this->stronghold->workingBlacksmiths[i] == false) {
            this->stronghold->blacksmiths[i].join();
        }
        if (this->stronghold->workingMillers[i] == false) {
            this->stronghold->millers[i].join();
        }
    }
}

void Life::startLife() {
    while (1) {
        for (int i = 0; i < WORKERSCOUNT; ++i) {
            
            if (this->stronghold->workingMiners[i] == false) {
                this->stronghold->miners[i].join();
                this->stronghold->workingMiners[i] = true;
                this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
            }
            if (this->stronghold->workingLumberjacks[i] == false) {
                this->stronghold->lumberjacks[i].join();
                this->stronghold->workingLumberjacks[i] = true;
                this->stronghold->lumberjacks[i] = thread([=] {this->startLumberjack(i);});
            }
            if (this->stronghold->workingFarmers[i] == false) {
                this->stronghold->farmers[i].join();
                this->stronghold->workingFarmers[i] = true;
                this->stronghold->farmers[i] = thread([=] {this->startFarmer(i);});
            }
            if (this->stronghold->workingBowMakers[i] == false) {
                this->stronghold->bowMakers[i].join();
                this->stronghold->workingBowMakers[i] = true;
                this->stronghold->bowMakers[i] = thread([=] {this->startBowMaker(i);});
            }
            if (this->stronghold->workingBlacksmiths[i] == false) {
                this->stronghold->blacksmiths[i].join();
                this->stronghold->workingBlacksmiths[i] = true;
                this->stronghold->blacksmiths[i] = thread([=] {this->startBlacksmith(i);});
            }
            if (this->stronghold->workingMillers[i] == false) {
                this->stronghold->millers[i].join();
                this->stronghold->workingMillers[i] = true;
                this->stronghold->millers[i] = thread([=] {this->startMiller(i);});
            }
            if (this->stronghold->workingBakers[i] == false) {
                this->stronghold->bakers[i].join();
                this->stronghold->workingBakers[i] = true;
                this->stronghold->bakers[i] = thread([=] {this->startBaker(i);});
            }
        }
    }   
}

void Life::startMiner(int id) {
    Miner *miner = new Miner();
    miner->workerId = id;
    miner->stronghold = this->stronghold;
    miner->startWorking();
}

void Life::startLumberjack(int id) {
    Lumberjack *lumberjack = new Lumberjack();
    lumberjack->workerId = id;
    lumberjack->stronghold = this->stronghold;
    lumberjack->startWorking();
}

void Life::startFarmer(int id) {
    Farmer *farmer = new Farmer();
    farmer->workerId = id;
    farmer->stronghold = this->stronghold;
    farmer->startWorking();
}

void Life::startBowMaker(int id) {
    BowMaker *bowMaker = new BowMaker();
    bowMaker->workerId = id;
    bowMaker->stronghold = this->stronghold;
    bowMaker->startWorking();
}

void Life::startBlacksmith(int id) {
    Blacksmith *blacksmith = new Blacksmith();
    blacksmith->workerId = id;
    blacksmith->stronghold = this->stronghold;
    blacksmith->startWorking();
}

void Life::startRecruiter(int id) {
    Recruiter *recruiter = new Recruiter();
    recruiter->workerId = id;
    recruiter->stronghold = this->stronghold;
    recruiter->startWorking();
}

void Life::startMiller(int id) {
    Miller *miller = new Miller();
    miller->workerId = id;
    miller->stronghold = this->stronghold;
    miller->startWorking();
}

void Life::startBaker(int id) {
    Baker *baker = new Baker();
    baker->workerId = id;
    baker->stronghold = this->stronghold;
    baker->startWorking();
}

