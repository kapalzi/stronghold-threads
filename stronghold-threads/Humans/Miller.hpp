#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Miller: public Human{
public:
    
    Miller();
    ~Miller();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
