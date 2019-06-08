#include "Human.h"

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

