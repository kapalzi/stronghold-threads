#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Farmer: public Human{
public:

    Farmer();
    ~Farmer();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
