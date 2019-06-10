#include "Lumberjack.hpp"
#include "../Helper.h"
#include <ncurses.h>

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
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
          
        move(this->workerId,30);
        printw("nr %d : %s", this->workerId, "Went for resources.                  " );
        refresh();
    }
    
}

void Lumberjack::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
          
        move(this->workerId,30);
        printw("nr %d : %s", this->workerId, "Worked on product.                     " );
        refresh();
    }

}
void Lumberjack::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->warehouse.canStoreWood(1)) {
                this->stronghold->warehouse.storeWood(1);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
                {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                      
                    move(this->workerId,30);
                    printw("nr %d : %s", this->workerId, "Delivered product to warehouse." );
                    refresh();
                }
                //printf("Zaniesiono drewno \n");
            } else {
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
            }
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
