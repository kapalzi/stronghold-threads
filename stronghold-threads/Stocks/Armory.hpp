//
//  Armory.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//
#pragma once
#include "Stock.hpp"

struct Armory: public Stock {
    int bowsCapacity;
    int bowsMaxCapacity;
    int swordsCapacity;
    int swordsMaxCapacity;
    
    bool canStoreBows(int amount);
    void storeBows(int amount);
    bool canStoreSwords(int amount);
    void storeSwords(int amount);
    void getBows(int amount);
    void getSwords(int amount);
};
