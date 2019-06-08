#include "Production.h"
#include <thread>
#include <mutex>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

Production::Production()
{

}

Production::~Production()
{

}

void Production::setStock(int x)
{
	this -> stock = x;
}

void Production::setWorkers(int x)
{
	this -> workers = x;
}

void Production::work()
{
	int numSeconds = 10;
	int workRate = 10;
	clock_t thisTime = clock();
	clock_t lastTime = thisTime;
    double timeCounter = 0;
	while(1)
	{
		thisTime = clock();
		timeCounter += (double)(thisTime - lastTime);
		lastTime = thisTime;

		if(timeCounter > (double)(numSeconds * CLOCKS_PER_SEC))
		{
			timeCounter -= (double)(numSeconds * CLOCKS_PER_SEC);
			this -> stock = (this -> stock) + (this->workers) * workRate;
		}
	}
	
}
