//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "ServiceCar.h"

ServiceCar::ServiceCar(int ID, int cTime, int tpTime )
{
	serviceCarID = ID;
	parts = 0;
    commuteTime = cTime;
    takingPartsTime = tpTime;
}

int ServiceCar::getID()
{
	return serviceCarID;
}
    
void ServiceCar::goToCyclist(){
	chrono::milliseconds timeToSleep(commuteTime + rand() % (commuteTime / 2));
	this_thread::sleep_for(timeToSleep);
}

void ServiceCar::takeEssentialParts(){
    parts = 20;
    chrono::milliseconds timeToSleep(takingPartsTime + rand() % (takingPartsTime / 2));
	this_thread::sleep_for(timeToSleep);
}