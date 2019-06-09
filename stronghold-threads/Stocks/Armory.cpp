//
//  Armory.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Armory.hpp"

bool Armory::canStoreBows(int amount) {
    return Stock::canStore(amount, this->bowsCapacity, this->bowsMaxCapacity);
}

void Armory::storeBows(int amount) {
    bowsCapacity+=amount;
}

bool Armory::canStoreSwords(int amount) {
    return Stock::canStore(amount, this->swordsCapacity, this->swordsMaxCapacity);
}

void Armory::storeSwords(int amount) {
    swordsCapacity+=amount;
}

void Armory::getBows(int amount) {
    bowsCapacity-=amount;
}

void Armory::getSwords(int amount) {
    swordsCapacity-=amount;
}
