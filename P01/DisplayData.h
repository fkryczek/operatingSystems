#pragma once
//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

using namespace std;

class DisplayData {
public:
  DisplayData(int numberOfPhilosopher);
  int getStatus(int number);
  int getLeftFork(int number);
  int getRightFork(int number);
  int getProgress(int number);
  int getHP(int number);

	int* status;
  int* leftFork;
  int* rightFork;
  int* progress;
  int* hp;
};
