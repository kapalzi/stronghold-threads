//
//  Life.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "Life.hpp"
#include "Stronghold.hpp"
#include "Humans/Miner.h"
#include "Humans/Lumberjack.hpp"


class Life {
    
    
public:
    Stronghold *stronghold;
    
    Life();
    void startLife();
    void startMiner(int id);
    void startLumberjack(int id);
};
