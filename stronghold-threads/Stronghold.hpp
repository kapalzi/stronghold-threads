//
//  Stronghold.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include <string>
#include <thread>
#define WORKERSCOUNT 20

using namespace std;

class Stronghold{
private:
    thread lumberjacks[WORKERSCOUNT];
    thread farmers[WORKERSCOUNT];
    thread miller[WORKERSCOUNT];
    thread bakers[WORKERSCOUNT];
    thread blacksmiths[WORKERSCOUNT];
    thread bowMakers[WORKERSCOUNT];
    
public:
    
    Stronghold();
    ~Stronghold();
    
    atomic_bool workingLumberjacks[WORKERSCOUNT];
    atomic_bool workingFarmers[WORKERSCOUNT];
    atomic_bool workingMiller[WORKERSCOUNT];
    atomic_bool workingBakers[WORKERSCOUNT];
    atomic_bool workingBlacksmiths[WORKERSCOUNT];
    atomic_bool workingBowMakers[WORKERSCOUNT];
    
    void initWorld();
    void initGranary();
    void initStock();
    void initArmory();
    void initPopulation();
    void startLife();
};