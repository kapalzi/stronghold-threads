//
//  Stock.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//
#pragma once
#include <mutex>

struct Stock {
    int maxCapacity;
    int currentCapacity;
    std::mutex mtx;
    
    Stock();
    bool canStore(int amount, int current, int max);
    bool canGet(int current);
};






