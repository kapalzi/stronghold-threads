//#include "Baker.h"
#include "Baker.h"
#include "../Helper.h"
#include <ncurses.h>

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
            
            {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Went for resources.");
                refresh();
            }
            
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
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Worked on product.");
        refresh();
    }
    
}
void Baker::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->granary.try_lock()) {
        if (this->stronghold->granary.canStoreBreads(3)) {
            this->stronghold->granary.storeBreads(3);
            if (this->stronghold->granary.breadCapacity >= 100) {
                this->stronghold->breadsReady.notify_one();
            }
            {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Delivered to granary.");
                refresh();
            }
            this->stronghold->granary.unlock();
            //printf("Zaniesiono chleb \n");
        } else {
            this->stronghold->granary.unlock();
        }
    } else {
        deliverProduct();
    }
}
