//
//  Warehouse.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//
#pragma once
#include "Stock.hpp"

struct Warehouse: public Stock {
    int woodCapacity;
    int woodMaxCapacity;
    int wheatCapacity;
    int wheatMaxCapacity;
    int flourCapacity;
    int flourMaxCapacity;
    int ironCapacity;
    int ironMaxCapacity;
    
    bool canStoreWood(int amount);
    bool canGetWood();
    bool canStoreWheat(int amount);
    bool canGetWheat();
    bool canStoreIron(int amount);
    bool canGetIron();
    bool canStoreFlour(int amount);
    bool canGetFlour();
    
    void storeIron(int amount);
    void storeWood(int amount);
    void storeWheat(int amount);
    void getWood();
    void getIron();
    
};
