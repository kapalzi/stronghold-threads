//
//  Stock.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include <mutex>

struct Stock {
    int maxCapacity;
    int currentCapacity;
    std::mutex mtx;
    
    Stock();
    bool canStore(int amount);
};

struct Warehouse: public Stock {
    int woodCapacity;
    int woodMaxCapacity;
    int wheatCapacity;
    int wheatMaxCapacity;
    int flourCapacity;
    int flourMaxCapacity;
    int ironCapacity;
    int ironMaxCapacity;
};

struct Armory: public Stock {
    int bowsCapacity;
    int bowsMaxCapacity;
    int swordsCapacity;
    int swordsMaxCapacity;
};

struct Granary: public Stock {
    int breadCapacity;
    int breadMaxCapacity;
};
