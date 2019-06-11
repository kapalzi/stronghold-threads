#include "Miller.hpp"
#include "../Helper.h"
#include <ncurses.h>

Miller::Miller() {
    
}

void Miller::startWorking() {
    
    while(this->stronghold->workingMillers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT*3+this->workerId,30, "nr %d : %s", this->workerId, "Is gone                        ");
        refresh();
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
             {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                move(WORKERSCOUNT*3+this->workerId,30);
                printw("nr %d : %s", this->workerId, "Went for resources to warehouse.            " );
                refresh();
            }
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}

void Miller::workOnProduct()
{
    //    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                move(WORKERSCOUNT*3+this->workerId,30);
                printw("nr %d : %s", this->workerId, "Worked on prodcut                  " );
                refresh();
            }
    
}
void Miller::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    std::this_thread::sleep_for(chrono::milliseconds(time));
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->warehouse.canStoreFlour(4)) {
                this->stronghold->warehouse.storeFlour(4);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
                {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                move(WORKERSCOUNT*3+this->workerId,30);
                printw("nr %d : %s", this->workerId, "Delivered to warehouse           " );
                refresh();
                }
            } else {
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
            }
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
