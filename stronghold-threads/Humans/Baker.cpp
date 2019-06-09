//#include "Baker.h"
#include "Baker.h"
#include "../Helper.h"

Baker::Baker() {
    
}

void Baker::startWorking() {
    
    while(this->stronghold->workingBakers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
}

void Baker::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetFlour()) {
            this->stronghold->warehouse.getFlour();
            this->stronghold->warehouse.unlock();
            //printf("Wzięto make \n");
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}

void Baker::workOnProduct()
{
    //    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
}
void Baker::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->granary.try_lock()) {
        if (this->stronghold->granary.canStoreBreads(1)) {
            this->stronghold->granary.storeBreads(1);
            this->stronghold->armory.unlock();
            //printf("Zaniesiono chleb \n");
        } else {
            this->stronghold->armory.unlock();
        }
    }
}
