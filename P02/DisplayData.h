#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
using namespace std;
class DisplayData {
public:
	DisplayData(int numberOfServices, int numberOfCyclist, int numberOfSupplier, int numberOfServiceCar);

	int getServiceStatus(int ID);
	int getCyclistStatus(int ID);
	int getSupplyStatus(int ID);

	int getDeliveryDirection(int ID);
	int getWhoIsMyClient(int ID);
	int getBikeCondition(int ID);
	int getProgress(int ID);
	int getBikeParts(int ID);
	int getWhoIsRepairingByServiceCar(int ID);
	int getServiceCarStatus(int ID);

	void setBikeParts(int ID, int status);
	void setBikeCondition(int ID, int status);
	void setProgress(int ID, int status);
	void setWhoIsMyClient(int ID, int status);
	void setDeliveryDirection(int ID, int status);
	void setWhoIsRepairingByServiceCar(int ID, int status);
	void setServiceStatus(int ID, int status);
	void setCyclistStatus(int ID, int status);
	void setSupplyStatus(int ID, int status);
	void setServiceCarStatus(int ID, int status);

	int cyclistNumber;
private:
	int* serviceStatus;
	int* cyclistStatus;
	int* supplyStatus;
	int* deliveryDirection;
	int* whoIsMyClient;
	int* bikeCondition;
	int* progress;
	int* bikeParts;
	int* serviceCarStatus;
	int* whoIsRepairingByServiceCar;
};
