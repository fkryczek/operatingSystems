//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "DisplayData.h"
DisplayData::DisplayData(int numberOfServices, int numberOfCyclist, int numberOfSupplier, int numberOfServiceCar) {
	serviceStatus = new int[numberOfServices];
	for(int x = 0; x < numberOfServices; x++)
		setServiceStatus(x,1);
	whoIsMyClient = new int[numberOfServices];
	bikeParts = new int[numberOfServices];
	cyclistStatus = new int[numberOfCyclist];
	bikeCondition = new int[numberOfCyclist];
	progress = new int[numberOfCyclist];
	supplyStatus = new int[numberOfSupplier];
	deliveryDirection = new int[numberOfSupplier];
	serviceCarStatus = new int[numberOfServiceCar];
	whoIsRepairingByServiceCar = new int[numberOfServiceCar];

	cyclistNumber = numberOfCyclist;

}

int DisplayData::getServiceStatus(int ID)
{
	return serviceStatus[ID];
}

int DisplayData::getCyclistStatus(int ID)
{
	return cyclistStatus[ID];
}

int DisplayData::getSupplyStatus(int ID)
{
	return supplyStatus[ID];
}

int DisplayData::getDeliveryDirection(int ID)
{
	return deliveryDirection[ID];
}

int DisplayData::getWhoIsMyClient(int ID)
{
	return whoIsMyClient[ID];
}

int DisplayData::getWhoIsRepairingByServiceCar(int ID)
{
	return whoIsRepairingByServiceCar[ID];
}

int DisplayData::getBikeCondition(int ID)
{
	return bikeCondition[ID];
}

int DisplayData::getProgress(int ID)
{
	return progress[ID];
}

int DisplayData::getBikeParts(int ID)
{
	return bikeParts[ID];
}

void DisplayData::setBikeParts(int ID, int status)
{
	bikeParts[ID] = status;
}

void DisplayData::setBikeCondition(int ID, int status)
{
	bikeCondition[ID] = status;
}

int DisplayData::getServiceCarStatus(int ID)
{
	return serviceCarStatus[ID];
}

void DisplayData::setProgress(int ID, int status)
{
	progress[ID] = status;
}

void DisplayData::setWhoIsMyClient(int ID, int status)
{
	whoIsMyClient[ID] = status;
}

void DisplayData::setWhoIsRepairingByServiceCar(int ID, int status)
{
	whoIsRepairingByServiceCar[ID] = status;
}

void DisplayData::setDeliveryDirection(int ID, int status)
{
	deliveryDirection[ID] = status;
}

void DisplayData::setServiceStatus(int ID, int status)
{
	serviceStatus[ID] = status;
}

void DisplayData::setCyclistStatus(int ID, int status)
{
	cyclistStatus[ID] = status;
}

void DisplayData::setSupplyStatus(int ID, int status)
{
	supplyStatus[ID] = status;
}

void DisplayData::setServiceCarStatus(int ID, int status)
{
	serviceCarStatus[ID] = status;
}