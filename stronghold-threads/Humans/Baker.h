#pragma once
#include "Human.h"
#include "../Stronghold.hpp"

class Baker: public Human{
public:
    
    Baker();
    ~Baker();
    
    Stronghold *stronghold;
    void goForResources();
    void workOnProduct();
    void deliverProduct();
    void startWorking();
};
