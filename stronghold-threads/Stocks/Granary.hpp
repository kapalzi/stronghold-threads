//
//  Granary.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//
#pragma once
#include "Stock.hpp"

struct Granary: public Stock {
    int breadCapacity;
    int breadMaxCapacity;
};
