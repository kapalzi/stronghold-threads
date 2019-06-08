#include "Human.h"
#include "Helper.cpp"
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>

Human::Human()
{

}

Human::~Human()
{

}

void Human::setfoodIndex(int x)
{
	this -> foodIndex = x;
}

int Human::getfoodIndex()
{
	return this -> foodIndex;
}

void Human::setOccupation(string x)
{
	this -> occupation = x;
}

void Human::startWorking()
{
	while(1)
	{
		//if(this.currentStronghold.)
		this -> goForResources();
		this -> workOnProduct();
		this -> deliverProduct();
	}
}

void Human::goForResources()
{
	float time = Helper::getRandomTime();
	std::this_thread::sleep_for(chrono::milliseconds(time));

}

void Human::workOnProduct()
{
	float time = Helper::getRandomTime();
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Human::deliverProduct()
{
	float time = Helper::getRandomTime();
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

