//
//  Life.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Life.hpp"

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
        
        this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
        this->stronghold->lumberjacks[i] = thread([=] {this->startLumberjack(i);});
        this->stronghold->farmers[i] = thread([=] {this->startFarmer(i);});
        this->stronghold->bowMakers[i] = thread([=] {this->startBowMaker(i);});
        this->stronghold->blacksmiths[i] = thread([=] {this->startBlacksmith(i);});
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

void Life::startRecruiter(int id) {
    Recruiter *recruiter = new Recruiter();
    recruiter->workerId = id;
    recruiter->stronghold = this->stronghold;
    recruiter->startWorking();
}
