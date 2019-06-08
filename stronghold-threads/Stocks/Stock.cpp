//
//  Stock.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Stock.hpp"

Stock::Stock(){}

bool Stock::canStore(int amount, int current, int max) {
    if (current + amount <= max) {
        return true;
    }
    else {
        return false;
    }
}

bool Stock::canGet(int current) {
    if (current >= 1) {
        return true;
    }
    else {
        return false;
    }
}
