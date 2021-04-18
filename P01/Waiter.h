#pragma once
#include <mutex>
#include <thread>
#include "Fork.h"
//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

using namespace std;

class Waiter {
public:
	Waiter(int numberOfPhilosopher);
	void takeMyHPStatus(int ID, int HP);
	bool theyAreHealth(int ID);

private:
	int number;
	int* philosopherHealth;
};
