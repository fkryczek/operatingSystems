//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------
#include "Philosopher.h"
#include <thread>
#include <iostream>
//--------------------------------------------------
Philosopher::Philosopher(int name, int tTime, int eTime, int healthPoint) {
	philosopherID = name;
	thinkingTime = tTime;
	eatingTime = eTime;
	progress = 0;
	HP = healthPoint;
}
//--------------------------------------------------
int Philosopher::getID()
{
	return philosopherID;
}
//--------------------------------------------------
int Philosopher::getProgress()
{
	return progress;
}
//--------------------------------------------------
int Philosopher::getHP()
{
	return HP;
}
//--------------------------------------------------
void Philosopher::eat()
{
	HP = HP + 15;
	if(HP>100)
		HP=100;
	chrono::milliseconds timeToSleep(eatingTime + rand() % (eatingTime/2));
	this_thread::sleep_for(timeToSleep);
}
//--------------------------------------------------
void Philosopher::think()
{
	progress++;
	HP = HP - 5;
	chrono::milliseconds timeToSleep(thinkingTime + rand() % (thinkingTime/2));
	this_thread::sleep_for(timeToSleep);
}
//--------------------------------------------------
