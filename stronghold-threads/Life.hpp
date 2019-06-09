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
#include "Humans/Farmer.hpp"
#include "Humans/BowMaker.hpp"
#include "Humans/Recruiter.hpp"
#include "Humans/Blacksmith.hpp"
#include "Humans/Miller.hpp"

class Life {
    
    
public:
    Stronghold *stronghold;
    thread recruiter;
    
    Life();
    void initLife();
    void startLife();
    void clean();
    void startMiner(int id);
    void startLumberjack(int id);
    void startFarmer(int id);
    void startBowMaker(int id);
    void startBlacksmith(int id);
    void startRecruiter(int id);
    void startMiller(int id);
    void startBaker(int id);

};
