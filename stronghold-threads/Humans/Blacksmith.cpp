#include "Blacksmith.hpp"
#include "../Helper.h"

Blacksmith::Blacksmith() {
    
}

void Blacksmith::startWorking() {
    
    while(this->stronghold->workingBowMakers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Blacksmith::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetIron()) {
            this->stronghold->warehouse.getIron();
            this->stronghold->warehouse.unlock();
            //printf("Wzięto zelazo \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}

void Blacksmith::workOnProduct()
{
    //    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}
void Blacksmith::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->armory.try_lock()) {
        if (this->stronghold->armory.canStoreSwords(1)) {
            this->stronghold->armory.storeSwords(1);
            if (this->stronghold->armory.swordsCapacity >= 100) {
                this->stronghold->armoryReady.notify_one();
            }
            
            this->stronghold->armory.unlock();
            //printf("Zaniesiono miecze \n");
        } else {
            this->stronghold->armory.unlock();
        }
    }
}
