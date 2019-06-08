#include "Human.h"

class Miner: public Human{
public:

    Miner();
    ~Miner();

    void goForResources();
    void workOnProduct();
    void deliverProduct();
};