#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------
#include <iostream>
#include <thread>

#include "Base.h"
using namespace std;
class ServiceCar {
public:
   	ServiceCar(int ID, int cTime, int tpTime);
	int getID();
	void goToCyclist();
    void takeEssentialParts();

private:
	int serviceCarID;
	int parts;
    int commuteTime;
    int takingPartsTime;
};
