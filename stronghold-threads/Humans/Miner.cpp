#include "Miner.h"
#include "../Helper.h"

Miner::Miner() {
    
}

void Miner::startWorking() {
    while(1) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Miner::goForResources()
{
//    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}

void Miner::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));

}
void Miner::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canStoreIron(1)) {
            this->stronghold->warehouse.storeIron(1);
            this->stronghold->warehouse.unlock();
            printf("Zaniesiono żelazo \n");
        }
    }
}
