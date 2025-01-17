#include "Blacksmith.hpp"
#include "../Helper.h"
#include <ncurses.h>

Blacksmith::Blacksmith() {
    
}

void Blacksmith::startWorking() {
    
    while(this->stronghold->workingBowMakers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(this->workerId,130, "nr %d : %s", this->workerId, "Is gone                        ");
        refresh();
    }
}

void Blacksmith::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(this->workerId,115);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetIron()) {
            this->stronghold->warehouse.getIron();
            this->stronghold->warehouse.unlock();
             {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                  
                move(this->workerId,130);
                printw("nr %d : %s", this->workerId, "Went for resources to warehouse.      " );
                refresh();
            }
        } else {
            this->stronghold->warehouse.unlock();
            
        }
    }
}

void Blacksmith::workOnProduct()
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
            move(this->workerId,115);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
          
        move(this->workerId,130);
        printw("nr %d : %s", this->workerId, "Worked on product                 " );
        refresh();
    }
    
}
void Blacksmith::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->armory.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->armory.canStoreSwords(1)) {
                this->stronghold->armory.storeSwords(1);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->armory.unlock();
                this->stronghold->granary.unlock();
                {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                      
                    move(this->workerId,130);
                    printw("nr %d : %s", this->workerId, "Delivered product to armory.          " );
                    refresh();
                }
                if (this->stronghold->armory.swordsCapacity >= 35) {
                    this->stronghold->swordsReady.notify_one();
                }
            } else {
                this->stronghold->armory.unlock();
                this->stronghold->granary.unlock();
            }
        } else {
            this->stronghold->armory.unlock();
        }
    }
}
