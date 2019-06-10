#include "Helper.h"
#include <ctime>
#include <stdio.h>
#include <cstdlib>

double Helper::getRandomTime(){
    float time = 0.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5-0.5)));
    return time*1000;
}

double Helper::getRandomLiveTime(){
    float time = 60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120-60)));
    return time*1000;
}

double Helper::getPrintfTime(){
    float time = 5;
    return time*1000;
}

