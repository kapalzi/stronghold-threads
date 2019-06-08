//
//  Armory.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Stock.hpp"

struct Armory: public Stock {
    int bowsCapacity;
    int bowsMaxCapacity;
    int swordsCapacity;
    int swordsMaxCapacity;
};
