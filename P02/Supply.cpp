//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------
#include "Supply.h"

Supply::Supply(int ID, int sCapability, int deliveryT, int takingPartsT)
{
	supplyID = ID;
	supplyCapabilty = sCapability;
	deliveryTime = deliveryT;
	takingPartsTime = takingPartsT;
	partsToTake = 0;
}

int Supply::getId()
{
	return supplyID;
}

int Supply::getSypplyCapability()
{
	return supplyCapabilty;
}

int Supply::getPartsToTake()
{
	return partsToTake;
}

void Supply::takeParts()
{
	partsToTake = supplyCapabilty;
	chrono::milliseconds timeToSleep(takingPartsTime + rand() % (takingPartsTime / 2));
	this_thread::sleep_for(timeToSleep);
}

void Supply::supplyParts()
{
	partsToTake = 0;
	chrono::milliseconds timeToSleep(deliveryTime + rand() % (deliveryTime / 2));
	this_thread::sleep_for(timeToSleep);
}

