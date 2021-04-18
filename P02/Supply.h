#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
#include <thread>
using namespace std;

class Supply {
public:
	Supply(int ID, int sCapability, int deliveryT, int takingPartsT);

	int getId();
	int getSypplyCapability();
	int getPartsToTake();

	void takeParts();
	void supplyParts();

private:
	int supplyID;
	int supplyCapabilty;
	int partsToTake;

	int takingPartsTime;
	int deliveryTime;
};