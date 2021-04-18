#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
#include <thread>

using namespace std;
class Base {
public:


	Base(int nServices, int nServiceCars, int nCyclist, int parts);
	int getInventory(int serviceID);
	void setInventory(int serviceID, int parts);
	void setINeedParts(int serviceID);
	void setIDontNeedParts(int serviceId);
	bool serviceBusy(int serviceID);
	bool needSomething(int serviceID);
	int getNumberOfServices();
	void setINeedServiceCar(int ID);
	bool someoneNeedServiceCar();
	int whoNeedServiceCar();
	void setHeDontNeedServiceCar(int ID);

private:
	int* inventory;
	bool* iNeedParts;
	bool* iNeedServiceCar;
	bool* iAmWorking;
	int numberOfServices;
	int numberOfCyclist;
	int numberOfServicesCar;
};
