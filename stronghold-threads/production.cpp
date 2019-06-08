#include "production.h"
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
	clock_t lasTime = thisTime;
	while(1)
	{
		thisTime = clok();
		timeCounter += (double)(thiTime - lastTime);
		lasTime = thisTime;

		if(timeCounter > (double)(numSeconds * CLOCKS_PER_SEC))
		{
			timeCounter -= (double)(numSeconds * CLOCKS_PER_SEC);
			this -> stock = (this -> stock) + (this->workers) * workRate;
		}
	}
	
}