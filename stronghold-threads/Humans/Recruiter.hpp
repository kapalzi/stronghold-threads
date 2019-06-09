//
//  Recruiter.hpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 09/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Recruiter: public Human{
public:
    
    Recruiter();
    ~Recruiter();
    
    Stronghold *stronghold;
    void startWorking();
};
