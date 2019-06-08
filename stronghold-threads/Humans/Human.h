#include <string>
#include <thread>
#include "../Stronghold.hpp"

#pragma once
using namespace std;

class Human: public thread{
protected:

	class
	int foodIndex;
public:

	Human();
	~Human();

	void setfoodIndex(int);
	int getfoodIndex();
	void setOccupation(string);
	string getOccupation();
	void startWorking();
	void goForResources();
	void workOnProduct();
	void deliverProduct();
	void stopWorking();
};
