//
//  BowMaker.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 09/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "BowMaker.hpp"
#include "../Helper.h"
#include <ncurses.h>

BowMaker::BowMaker() {
    
}

void BowMaker::startWorking() {
    
    while(this->stronghold->workingBowMakers[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
     {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT*4+this->workerId,30, "nr %d : %s", this->workerId, "Is recruited                 ");
        refresh();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        
        move(WORKERSCOUNT*4+this->workerId,30);
        printw("nr %d : %s", this->workerId, "Is recruited.                " );
        refresh();
    }
}

void BowMaker::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetWood()) {
            this->stronghold->warehouse.getWood();
            this->stronghold->warehouse.unlock();
            {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                      
                    move(WORKERSCOUNT*4+this->workerId,30);
                    printw("nr %d : %s", this->workerId, "Went for resources to warehouse.          " );
                    refresh();
            }
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
    std::this_thread::sleep_for(chrono::milliseconds(time));
    std::this_thread::sleep_for(chrono::milliseconds(time));
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
          
        move(WORKERSCOUNT*4+this->workerId,30);
        printw("nr %d : %s", this->workerId, "Worked on product.                " );
        refresh();
    }
    
}
void BowMaker::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->armory.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->armory.canStoreBows(1)) {
                this->stronghold->armory.storeBows(1);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                
                this->stronghold->armory.unlock();
                this->stronghold->granary.unlock();
                {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                      
                    move(WORKERSCOUNT*4+this->workerId,30);
                    printw("nr %d : %s", this->workerId, "Delivered product to armory.          " );
                    refresh();
                }
                if (this->stronghold->armory.bowsCapacity >= 35) {
                    this->stronghold->bowsReady.notify_one();
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
