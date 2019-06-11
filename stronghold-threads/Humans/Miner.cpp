#include "Miner.h"
#include "../Helper.h"
#include <ncurses.h>

Miner::Miner() {
    
}

void Miner::startWorking() {
    
    while(this->stronghold->workingMiners[this->workerId]) {
        this -> goForResources();
        this -> workOnProduct();
        this -> deliverProduct();
    }
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId,30, "nr %d : %s", this->workerId, "Is gone                        ");
        refresh();
    }
}

void Miner::goForResources()
{
//    Human:goForResources();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId,30, "nr %d : %s", this->workerId, "Went for resources.               ");
        refresh();
    }
}

void Miner::workOnProduct()
{
//    Human:workOnProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId,30, "nr %d : %s", this->workerId, "Worked on product.                 ");
        refresh();
    }

}
void Miner::deliverProduct()
{
//    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->granary.try_lock()) {
            if (this->stronghold->warehouse.canStoreIron(1)) {
                this->stronghold->warehouse.storeIron(1);
                if (this->stronghold->granary.canGetBread()) {
                    this->stronghold->granary.getBreads(1);
                }
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
                {
                    std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                    mvprintw(WORKERSCOUNT+this->workerId,30, "nr %d : %s", this->workerId, "Delivered to warehouse. ");
                    refresh();
                }
                //printf("Zaniesiono żelazo od górnika %d\n",this->workerId);
            } else {
                this->stronghold->warehouse.unlock();
                this->stronghold->granary.unlock();
            }
        } else {
            this->stronghold->warehouse.unlock();
        }
    }
}
