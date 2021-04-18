#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
#include <thread>

#include "RepairingPlace.h"
#include "Base.h"
using namespace std;
class Service {
public:
	Service(int ID, Base* b);
	int getID();
	int getStock();
	void takeOrder();

private:
	int serviceID;
	Base* base;
	int parts;
};
