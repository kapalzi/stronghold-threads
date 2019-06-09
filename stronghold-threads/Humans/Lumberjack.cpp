#include "Lumberjack.hpp"
#include "../Helper.h"

Lumberjack::Lumberjack() {
    
}

void Lumberjack::startWorking() {
    
    while(this->stronghold->workingLumberjacks[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Lumberjack::goForResources()
{
//    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}

void Lumberjack::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));

}
void Lumberjack::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canStoreWood(1)) {
            this->stronghold->warehouse.storeWood(1);
            this->stronghold->warehouse.unlock();
            //printf("Zaniesiono drewno \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
