#include "Helper.h"
#include <ctime>
#include <stdio.h>
#include <cstdlib>

double Helper::getRandomTime(){
    float time = 2.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3.5-2.5)));
    return time*1000;
}
g