#include <string>
#include <thread>

using namespace std;

class Human: public thread{
protected:
	/*
	enum occupation{
		LUMBERJACK
		BLACKSMITH
		BOWMAKER
		MINER
		SOLDIER
		FARMER
		BAKER
		MILLER
		NONE
	};
	*/
	string occupation;
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