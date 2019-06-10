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
    std::this_thread::sleep_for(chrono::milliseconds(time));
    std::this_thread::sleep_for(chrono::milliseconds(time));

}
void Farmer::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->warehouse.canStoreWheat(4)) {
                this->stronghold->warehouse.storeWheat(4);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
                //printf("Zaniesiono zborze \n");
            } else {
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
            }
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
