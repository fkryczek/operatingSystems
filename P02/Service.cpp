//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "Service.h"

Service::Service(int ID, Base* b)
{
	serviceID = ID;
	base = b;
	parts = base->getInventory(serviceID);
}

int Service::getID()
{
	return serviceID;
}

int Service::getStock()
{
	return base->getInventory(serviceID);
}

void Service::takeOrder()
{
	base->setINeedParts(serviceID);
}
