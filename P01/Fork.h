#pragma once
#include <mutex>
//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

using namespace std;

class Fork {
public:
	Fork();
	bool takeFork();
	void putDownFork();
	mutex mtx;
};
