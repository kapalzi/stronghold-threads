//
//  Granary.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Granary.hpp"
bool Granary::canStoreBreads(int amount) {
    return Stock::canStore(amount, this->breadCapacity, this->breadMaxCapacity);
}

void Granary::storeBreads(int amount) {
    breadCapacity+=amount;
}

void Granary::getBreads(int amount) {
    breadCapacity-=amount;
}