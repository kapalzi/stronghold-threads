#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Lumberjack: public Human{
public:

    Lumberjack();
    ~Lumberjack();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
    void printStocks();
};
