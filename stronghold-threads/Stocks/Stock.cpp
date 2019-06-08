//
//  Stock.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Stock.hpp"

Stock::Stock(){}

bool Stock::canStore(int amount) {
    if (currentCapacity + amount <= maxCapacity) {
        return true;
    }
    else {
        return false;
    }
}
