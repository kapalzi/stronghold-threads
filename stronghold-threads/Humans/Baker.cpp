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
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId,130, "nr %d : %s", this->workerId, "Is gone                        ");
        refresh();
    }
}

void Baker::goForResources()
{
    //    Human:goForResources();
    signed int time = Helper::getRandomTime();
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT+this->workerId,115);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    if (this->stronghold->warehouse.try_lock()) {
        if (this->stronghold->warehouse.canGetFlour()) {
            this->stronghold->warehouse.getFlour();
            this->stronghold->warehouse.unlock();
            
            {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Went for resources.           ");
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
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT+this->workerId,115);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    {
        std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
        mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Worked on product.                ");
        refresh();
    }
    
}
void Baker::deliverProduct()
{
    //    Human:deliverProduct();
    signed int time = Helper::getRandomTime();
    int wait = time/10;
    for (int i = 0; i<=10; i++) {
        std::this_thread::sleep_for(chrono::milliseconds(wait));
        {
            std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
            move(WORKERSCOUNT+this->workerId,115);
            printw("%d %%  ", i*10);
            refresh();
        }
    }
    
    if (this->stronghold->granary.try_lock()) {
        if (this->stronghold->granary.canStoreBreads(7)) {
            this->stronghold->granary.storeBreads(7);
            {
                std::lock_guard<std::mutex> output_lock(this->stronghold->cout_mutex);
                mvprintw(WORKERSCOUNT+this->workerId, 130, "nr %d : %s", this->workerId, "Delivered to granary.         ");
                refresh();
            }
            this->stronghold->granary.unlock();
            if (this->stronghold->granary.breadCapacity >= 100) {
                this->stronghold->breadsReady.notify_one();
            }
            //printf("Zaniesiono chleb \n");
        } else {
            this->stronghold->granary.unlock();
        }
    }
}
