#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Cyclist {
public:
	Cyclist();	
	void setValue(int ID, int rTime, int repTime, int goal, int bCondition);
	int getId();
	int getKmGoal();
	int getDistance();
	int getBikeCondition();

	void ride();
	void repair();

	bool lock();
	void unlock();


private:
	int cyclistID;
	int ridingTime;
	int repairingTime;
	int kmGoal;
	int distance;
	int bikeCondition;
	mutex cyclistMTX;
};