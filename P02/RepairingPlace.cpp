//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "RepairingPlace.h"

RepairingPlace::RepairingPlace()
{
}

bool RepairingPlace::serviceCloseDelivery()
{
	if (deliveryMTX.try_lock())
		return true;
	else
		return false;
}

bool RepairingPlace::serviceCloseParts()
{
	if (partsMTX.try_lock())
		return true;
	else
		return false;
}
bool RepairingPlace::serviceClosedRepair()
{
	if (repairMTX.try_lock())
		return true;
	else
		return false;
}


void RepairingPlace::serviceOpenDelivery()
{
	deliveryMTX.unlock();
}

void RepairingPlace::serviceOpenParts()
{
	partsMTX.unlock();
}

void RepairingPlace::serviceOpenRepair()
{
	repairMTX.unlock();
}