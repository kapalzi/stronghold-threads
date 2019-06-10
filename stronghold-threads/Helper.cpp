#include "Helper.h"
#include <ctime>
#include <stdio.h>
#include <cstdlib>

double Helper::getRandomTime(){
    float time = 0.1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.5-0.1)));
    return time*1000;
}

double Helper::getRandomLiveTime(){
    float time = 60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120-60)));
    return time*1000;
}

double Helper::getPrintfTime(){
    float time = 1;
    return time*1000;
}

