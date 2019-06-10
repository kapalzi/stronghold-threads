//
//  Life.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 08/06/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include "Life.hpp"
#include <iostream>
#include "Helper.h"
#include <ncurses.h>



Life::Life() {
    stronghold = new Stronghold();
}

void Life::initNcurses(){
    initscr();
    curs_set(0);
    printw( "Hello World !!!" );
    int x= 0;
    int y= 0;
    for(int i=0; i<WORKERSCOUNT;i++){
        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x=i;
        y=0;
        move(x,y);
        printw("Lumberjack nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }
        
        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= WORKERSCOUNT+i;
        y= 0;
        move(x,y);
        printw("Miner nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }

        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= WORKERSCOUNT*2+i;
        y= 0;
        move(x,y);
        printw("Farmer nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }

        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= WORKERSCOUNT*3+i;
        y= 0;
        move(x,y);
        printw("Miller nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }

        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= WORKERSCOUNT*4+i;
        y= 0;
        move(x,y);
        printw("Bow maker nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }

        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= i;
        y= 100;
        move(x,y);
        printw("Blacksmith nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }
        {
        std::lock_guard<std::mutex> output_lock(cout_mutex);
        x= WORKERSCOUNT+i;
        y= 100;
        move(x,y);
        printw("Baker nr %d : %s", i, " " );
//        refresh();
//        clrtoeol();
        }

    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(64,100);
    printw("Recruiter: %s", " " );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(65,100);
    printw("Granary " );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(66,100);
    printw("Bread:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(67,100);
    printw("Armory" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(68,100);
    printw("Bows:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(69,100);
    printw("Swords:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(70,100);
    printw("Warehouse" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(71,100);
    printw("Iron:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(72,100);
    printw("Wood:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(73,100);
    printw("Wheat:" );
    }
    {
    std::lock_guard<std::mutex> output_lock(cout_mutex);
    move(74,100);
    printw("Flour:" );
    }
    getch();
    endwin();
    }
    
}
void Life::initLife() {
    
    initNcurses();
    
    recruiter = thread([=] {this->startRecruiter(0);});
    for (int i = 0; i < WORKERSCOUNT; ++i) {
        this->stronghold->workingMiners[i] = true;
        this->stronghold->workingLumberjacks[i] = true;
        this->stronghold->workingFarmers[i] = true;
        this->stronghold->workingBowMakers[i] = true;
        this->stronghold->workingBlacksmiths[i] = true;
        this->stronghold->workingMillers[i] = true;
        this->stronghold->workingBakers[i] = true;
        
        this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
        this->stronghold->lumberjacks[i] = thread([=] {this->startLumberjack(i);});
        this->stronghold->farmers[i] = thread([=] {this->startFarmer(i);});
        this->stronghold->bowMakers[i] = thread([=] {this->startBowMaker(i);});
        this->stronghold->blacksmiths[i] = thread([=] {this->startBlacksmith(i);});
        this->stronghold->millers[i] = thread([=] {this->startMiller(i);});
        this->stronghold->bakers[i] = thread([=] {this->startBaker(i);});
    }
    this->startLife();
    //    thread recruiter = thread([=] {this->startRecruiter(0);});
    
}

void Life::clean() {
    for (int i = 0; i < WORKERSCOUNT; ++i) {
            this->stronghold->miners[i].join();
        
            this->stronghold->lumberjacks[i].join();
        
            this->stronghold->farmers[i].join();
        
            this->stronghold->millers[i].join();
        
            this->stronghold->bowMakers[i].join();
        
            this->stronghold->blacksmiths[i].join();
        
            this->stronghold->millers[i].join();
        
            this->stronghold->bakers[i].join();
    }
    recruiter.join();
    
}

void Life::startLife() {

    while(!finish) {
        if (std::cin.get() == 's') {
            finish = true;
        }
    }

    std::cin.get();
    endwin();

        for (int i = 0; i < WORKERSCOUNT; ++i) {
            
            if (this->stronghold->workingMiners[i] == false) {
                this->stronghold->miners[i].join();
                this->stronghold->workingMiners[i] = true;
                this->stronghold->miners[i] = thread([=] {this->startMiner(i);});
            }
            if (this->stronghold->workingLumberjacks[i] == false) {
                this->stronghold->lumberjacks[i].join();
                this->stronghold->workingLumberjacks[i] = true;
                this->stronghold->lumberjacks[i] = thread([=] {this->startLumberjack(i);});
            }
            if (this->stronghold->workingFarmers[i] == false) {
                this->stronghold->farmers[i].join();
                this->stronghold->workingFarmers[i] = true;
                this->stronghold->farmers[i] = thread([=] {this->startFarmer(i);});
            }
            if (this->stronghold->workingBowMakers[i] == false) {
                this->stronghold->bowMakers[i].join();
                this->stronghold->workingBowMakers[i] = true;
                this->stronghold->bowMakers[i] = thread([=] {this->startBowMaker(i);});
            }
            if (this->stronghold->workingBlacksmiths[i] == false) {
                this->stronghold->blacksmiths[i].join();
                this->stronghold->workingBlacksmiths[i] = true;
                this->stronghold->blacksmiths[i] = thread([=] {this->startBlacksmith(i);});
            }
            if (this->stronghold->workingMillers[i] == false) {
                this->stronghold->millers[i].join();
                this->stronghold->workingMillers[i] = true;
                this->stronghold->millers[i] = thread([=] {this->startMiller(i);});
            }
            if (this->stronghold->workingBakers[i] == false) {
                this->stronghold->bakers[i].join();
                this->stronghold->workingBakers[i] = true;
                this->stronghold->bakers[i] = thread([=] {this->startBaker(i);});
            }
        }
        
    signed int time = Helper::getPrintfTime();
    std::this_thread::sleep_for(chrono::milliseconds(time));
    printf("Bows Count: %d \nWood Count: %d \nWheat Count: %d \nIron Count: %d\nSwords Count: %d \nFlour Count: %d \nBread Count: %d \n XXXXXXXXXXXXXXX\n",
        this->stronghold->armory.bowsCapacity, this->stronghold->warehouse.woodCapacity,this->stronghold->warehouse.wheatCapacity,this->stronghold->warehouse.ironCapacity, this->stronghold->armory.swordsCapacity,this->stronghold->warehouse.flourCapacity, this->stronghold->granary.breadCapacity);
    
}

void Life::startMiner(int id) {
    Miner *miner = new Miner();
    miner->workerId = id;
    miner->stronghold = this->stronghold;
    miner->startWorking();
}

void Life::startLumberjack(int id) {
    Lumberjack *lumberjack = new Lumberjack();
    lumberjack->workerId = id;
    lumberjack->stronghold = this->stronghold;
    lumberjack->startWorking();
}

void Life::startFarmer(int id) {
    Farmer *farmer = new Farmer();
    farmer->workerId = id;
    farmer->stronghold = this->stronghold;
    farmer->startWorking();
}

void Life::startBowMaker(int id) {
    BowMaker *bowMaker = new BowMaker();
    bowMaker->workerId = id;
    bowMaker->stronghold = this->stronghold;
    bowMaker->startWorking();
}

void Life::startBlacksmith(int id) {
    Blacksmith *blacksmith = new Blacksmith();
    blacksmith->workerId = id;
    blacksmith->stronghold = this->stronghold;
    blacksmith->startWorking();
}

void Life::startRecruiter(int id) {
    Recruiter *recruiter = new Recruiter();
    recruiter->workerId = id;
    recruiter->stronghold = this->stronghold;
    recruiter->startWorking();
}

void Life::startMiller(int id) {
    Miller *miller = new Miller();
    miller->workerId = id;
    miller->stronghold = this->stronghold;
    miller->startWorking();
}

void Life::startBaker(int id) {
    Baker *baker = new Baker();
    baker->workerId = id;
    baker->stronghold = this->stronghold;
    baker->startWorking();
}

