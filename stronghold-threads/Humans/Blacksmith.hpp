#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Blacksmith: public Human{
public:
    
    Blacksmith();
    ~Blacksmith();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
