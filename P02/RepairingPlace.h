#pragma once
//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <mutex>
using namespace std;
class RepairingPlace {
public:
	RepairingPlace();

	bool serviceCloseDelivery();
	bool serviceCloseParts();
	bool serviceClosedRepair();

	void serviceOpenDelivery();
	void serviceOpenParts();
	void serviceOpenRepair();

private:
	mutex repairMTX;
	mutex partsMTX;
	mutex deliveryMTX;
};
