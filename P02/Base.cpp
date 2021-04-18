//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "Base.h"

Base::Base(int nServices, int nServiceCar, int nCyclist, int parts) {
	inventory = new int[nServices];
	iNeedParts = new bool[nServices];
	iAmWorking = new bool[nServices];
	iNeedServiceCar = new bool [nCyclist];
	numberOfServices = nServices;
	numberOfServicesCar = nServiceCar;
	numberOfCyclist = nCyclist;
	for (int x = 0; x < nServices; x++){
		inventory[x] = parts;
		iNeedParts[x] = false;
		iAmWorking[x] = false;
	}
	for (int x = 0; x< nCyclist; x++)
		iNeedServiceCar[x] = false;
}

int Base::getInventory(int serviceID)
{
	return inventory[serviceID];
}

void Base::setInventory(int serviceId, int parts)
{
	inventory[serviceId] = inventory[serviceId] + parts;
}

void Base::setINeedParts(int serviceId)
{
	iNeedParts[serviceId] = true;
}

void Base::setIDontNeedParts(int serviceId)
{
	iNeedParts[serviceId] = false;
}

bool Base::needSomething(int serviceID)
{
	return iNeedParts[serviceID];
}

bool Base::serviceBusy(int serviceID)
{
	return iAmWorking[serviceID];
}

int Base::getNumberOfServices() {
	return numberOfServices;
}

bool Base::someoneNeedServiceCar()
{
	for (int x = 0; x< numberOfCyclist; x++)
		if(iNeedServiceCar[x]) return true;
	return false;
}

int Base::whoNeedServiceCar(){
	for (int x = 0; x< numberOfCyclist; x++)
		if(iNeedServiceCar[x]) return x;
}

void Base::setHeDontNeedServiceCar(int ID)
{
	iNeedServiceCar[ID] = false;
}

void Base::setINeedServiceCar(int ID)
{
	iNeedServiceCar[ID] = true;
}