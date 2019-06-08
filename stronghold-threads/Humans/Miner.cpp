#include "Miner.h"


Miner::Miner() {
    
}

void Miner::startWorking() {
    
    
//    while(this->currentStronghold->workingMiners[this->workerId])
//          workingMiners[this->workerId])
    
    while(1) // current time - get live time
    {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Miner::goForResources()
{
    Human:goForResources();
    
}

void Miner::workOnProduct()
{
    Human:workOnProduct();

}
void Miner::deliverProduct()
{
    Human:deliverProduct();
    
    

}
