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
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(this->workerId,30, "nr %d : %s", this->workerId, "Is recruited                 ");
        refresh();
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
                printStocks();
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

void Lumberjack::printStocks() {
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+13, 130, "%d / %d", this->stronghold->granary.breadCapacity, this->stronghold->granary.breadMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+16, 130, "%d / %d", this->stronghold->armory.bowsCapacity, this->stronghold->armory.bowsMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+17, 130, "%d / %d", this->stronghold->armory.swordsCapacity, this->stronghold->armory.swordsMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+20, 130, "%d / %d", this->stronghold->warehouse.ironCapacity, this->stronghold->warehouse.ironMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+21, 130, "%d / %d", this->stronghold->warehouse.woodCapacity, this->stronghold->warehouse.woodMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+22, 130, "%d / %d", this->stronghold->warehouse.wheatCapacity, this->stronghold->warehouse.wheatMaxCapacity);
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+23, 130, "%d / %d", this->stronghold->warehouse.flourCapacity, this->stronghold->warehouse.flourMaxCapacity);
        refresh();
    }
}
