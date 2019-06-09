//
//  BowMaker.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 09/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class BowMaker: public Human{
public:
    
    BowMaker();
    ~BowMaker();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
