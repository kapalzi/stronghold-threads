#pragma once
//#include "../Stronghold.hpp"
#include <thread>
#include <string>
using namespace std;

class Stronghold;

class Human: public thread{
protected:

    
	int foodIndex;
	
public:

	Human();
	~Human();
//    Stronghold *stronghold;
    int workerId;
	string state;
	void setfoodIndex(int);
	int getfoodIndex();
	void setOccupation(string);
	string getOccupation();
	void startWorking();
	void goForResources();
	void workOnProduct();
	void deliverProduct();
	void stopWorking();
	void setState(string);
};
