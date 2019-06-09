//
//  Warehouse.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Warehouse.hpp"

bool Warehouse::canStoreWood(int amount) {
    return Stock::canStore(amount, this->woodCapacity, this->woodMaxCapacity);
}

bool Warehouse::canGetWood() {
    return Stock::canGet(this->woodCapacity);
}

bool Warehouse::canStoreWheat(int amount) {
    return Stock::canStore(amount, this->wheatCapacity, this->wheatMaxCapacity);
}

bool Warehouse::canGetWheat() {
    return Stock::canGet(this->wheatCapacity);
}

bool Warehouse::canStoreIron(int amount) {
    return Stock::canStore(amount, this->ironCapacity, this->ironMaxCapacity);
}

bool Warehouse::canGetIron() {
    return Stock::canGet(this->ironCapacity);
}

bool Warehouse::canStoreFlour(int amount) {
    return Stock::canStore(amount, this->flourCapacity, this->flourMaxCapacity);
}

bool Warehouse::canGetFlour() {
    return Stock::canGet(this->flourCapacity);
}

void Warehouse::storeIron(int amount) {
    ironCapacity+=amount;
}
void Warehouse::storeWood(int amount) {
    woodCapacity+=amount;
}

void Warehouse::storeWheat(int amount) {
    wheatCapacity+=amount;
}

void Warehouse::getWood() {
    woodCapacity--;
}
