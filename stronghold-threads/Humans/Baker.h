#pragma once
#include "Human.h"
//#include "../Headers.h"

class Baker: public Human{
private:

public:
    Baker();
    ~Baker();

    void goForResources();
    void workOnProduct();
    void deliverProduct();

};
