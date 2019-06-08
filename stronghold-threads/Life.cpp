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

void Life::startLife() {
    //miners
    for (int i = 0; i < WORKERSCOUNT; ++i) {
        this->stronghold->workingMiners[i] = true;
        this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
    }
    
    //tutaj wszuscu pracownicy po kolei
}

void Life::startMiner(int id) {
    Miner *miner = new Miner();
    miner->workerId = id;
    miner->stronghold = this->stronghold;
    miner->startWorking();
}
