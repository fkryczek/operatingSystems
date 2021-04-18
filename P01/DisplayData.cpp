//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include "DisplayData.h"
//--------------------------------------------------
DisplayData::DisplayData(int numberOfPhilosopher){
  status=new int[numberOfPhilosopher];
  leftFork=new int[numberOfPhilosopher];
  rightFork=new int[numberOfPhilosopher];
  progress=new int[numberOfPhilosopher];
  hp=new int[numberOfPhilosopher];
}
//--------------------------------------------------
int DisplayData::getStatus(int number){
  return status[number];
}
//--------------------------------------------------
int DisplayData::getLeftFork(int number){
  return leftFork[number];
}
//--------------------------------------------------
int DisplayData::getRightFork(int number){
  return rightFork[number];
}
//--------------------------------------------------
int DisplayData::getProgress(int number){
  return progress[number];
}
//--------------------------------------------------
int DisplayData::getHP(int number){
  return hp[number];
}
//--------------------------------------------------
