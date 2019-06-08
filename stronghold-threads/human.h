#include <string>

class Human{
private:
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
};
