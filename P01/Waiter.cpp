//--------------------------------------------------
//--------- "Problem ucztuj�cych filozof�w" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "Waiter.h"
//--------------------------------------------------
Waiter::Waiter(int numberOfPhilosopher) {
	number = numberOfPhilosopher;
	philosopherHealth = new int[numberOfPhilosopher];
}
//--------------------------------------------------
void Waiter::takeMyHPStatus(int ID, int HP)
{
	philosopherHealth[ID] = HP;
}
//--------------------------------------------------
bool Waiter::theyAreHealth(int ID)
{
	int leftNeighbour, rightNeighbour;

	if (ID == 0) {
		leftNeighbour = number-1;
		rightNeighbour = 1;
	}
	else if (ID == number-1) {
		leftNeighbour = number - 2;
		rightNeighbour = 0;
	}
	else {
		leftNeighbour = ID - 1;
		rightNeighbour = ID + 1;
	}

	if (philosopherHealth[leftNeighbour] >= 10 && philosopherHealth[rightNeighbour] >= 10)
		return true;
	else
		return false;
}
//--------------------------------------------------
