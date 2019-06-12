#include "Farmer.hpp"
#include "../Helper.h"
#include <ncurses.h>

Farmer::Farmer() {
    
}

void Farmer::startWorking() {
    
    while(this->stronghold->workingFarmers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        
        move(WORKERSCOUNT*2+this->workerId,30);
        printw("nr %d : %s", this->workerId, "Is gone                   " );
        refresh();
    }
}

void Farmer::goForResources()
{
//    Human:goForResources();
    signed int time = Helper::getRandomTime();
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT*2+this->workerId,15);
            printw("%d %%  ", i*10);
            refresh();
        }
    }

    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT*2+this->workerId,30, "nr %d : %s", this->workerId, "Went for resources.       ");
        refresh();
    }
}

void Farmer::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
//    std::this_thread::sleep_for(chrono::milliseconds(time));
//    std::this_thread::sleep_for(chrono::milliseconds(time));
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT*2+this->workerId,15);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        
        move(WORKERSCOUNT*2+this->workerId,30);
        printw("nr %d : %s", this->workerId, "Worked on product.            " );
        refresh();
    }

}
void Farmer::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT*2+this->workerId,15);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->warehouse.canStoreWheat(4)) {
                this->stronghold->warehouse.storeWheat(4);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
                {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                    
                    move(WORKERSCOUNT*2+this->workerId,30);
                    printw("nr %d : %s", this->workerId, "Delivered to warehouse.       " );
                    refresh();
                }
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
