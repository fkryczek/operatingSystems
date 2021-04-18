//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "Cyclist.h"
Cyclist::Cyclist(){

}

void Cyclist::setValue(int ID, int rTime, int repTime, int goal, int bCondition)
{
	cyclistID = ID;
	ridingTime = rTime;
	repairingTime = repTime;
	distance = 0;
	kmGoal = goal;
	bikeCondition = bCondition;
}

int Cyclist::getId()
{
	return cyclistID;
}

int Cyclist::getKmGoal()
{
	return kmGoal;
}

int Cyclist::getDistance()
{
	return distance;
}

int Cyclist::getBikeCondition()
{
	return bikeCondition;
}

void Cyclist::ride()
{
	distance = distance + rand() % 150;
	bikeCondition = bikeCondition - (5 + rand() % 10);
	chrono::milliseconds timeToSleep(ridingTime + rand() % (ridingTime / 2));
	this_thread::sleep_for(timeToSleep);
}

void Cyclist::repair()
{
	bikeCondition = bikeCondition + (20 + rand() % 10);
	if(bikeCondition>100)
		bikeCondition=100;

	chrono::milliseconds timeToSleep(repairingTime+ rand() % (repairingTime / 2));
	this_thread::sleep_for(timeToSleep);
}

bool Cyclist::lock()
{
	if (cyclistMTX.try_lock())
		return true;
	else
		return false;
}

void Cyclist::unlock()
{
	cyclistMTX.unlock();
}