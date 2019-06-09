#include "Farmer.hpp"
#include "../Helper.h"

Farmer::Farmer() {
    
}

void Farmer::startWorking() {
    
    while(this->stronghold->workingFarmers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Farmer::goForResources()
{
//    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}

void Farmer::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));

}
void Farmer::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canStoreWheat(1)) {
            this->stronghold->warehouse.storeWheat(1);
            this->stronghold->warehouse.unlock();
            //printf("Zaniesiono zborze \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
