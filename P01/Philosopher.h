#pragma once
//--------------------------------------------------
//--------- "Problem ucztuj�cych filozof�w" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------
#include "Fork.h"
using namespace std;

class Philosopher {
public:
	Philosopher(int name, int tTime, int eTime, int healthPoint);

	int getID();
	int getProgress();
	int getHP();
	void eat();
	void think();


private:
	void HPChange();

	int philosopherID;
	int thinkingTime;
	int eatingTime;
	int progress;
	int HP;


};
