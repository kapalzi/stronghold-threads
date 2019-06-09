#include "Miller.hpp"
#include "../Helper.h"

Miller::Miller() {
    
}

void Miller::startWorking() {
    
    while(this->stronghold->workingMillers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Miller::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetWheat()) {
            this->stronghold->warehouse.getWheat();
            this->stronghold->warehouse.unlock();
            //printf("Wzięto drewno \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}

void BowMaker::workOnProduct()
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
        if (this->stronghold->warehouse.canStoreFlour(1)) {
            this->stronghold->warehouse.storeFlour(1);
            this->stronghold->warehouse.unlock();
            //printf("Zaniesiono make \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
