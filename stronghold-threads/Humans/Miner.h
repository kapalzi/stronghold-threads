#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Miner: public Human{
public:

    Miner();
    ~Miner();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
