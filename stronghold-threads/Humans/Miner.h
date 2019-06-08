#pragma once
#include "Human.h"
//#include "../Headers.h"

class Miner: public Human{
public:

    Miner();
    ~Miner();

    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
