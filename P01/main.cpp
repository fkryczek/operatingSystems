//--------------------------------------------------
//--------- "Problem ucztujacych filozofow" --------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------
// Muszą zostać spełnione warunki:
//  - Filozof je wtedy gdy zdobędzie dwa widelce.
//  - 2 filozofów nie może trzymać tego samego widelca.
//  - Każdy z filozofów musi się w końcu najeść.
//--------------------------------------------------
#include <iostream>
#include <thread>
#include <mutex>
#include <ncurses.h>
#include "Philosopher.h"
#include "Fork.h"
#include "Waiter.h"
#include "DisplayData.h"
using namespace std;

int numberOfPhilosopher, timeToStopIt;
thread* forkThreads = new thread[numberOfPhilosopher];
//----------------WYSWIETLANIE DANYCH---------------
//--------------------------------------------------
void Display(DisplayData* dataToDisplay) {
	chrono::milliseconds sleepTime(5);
  chrono::milliseconds endSleepTime(5000);
	string name, forks, progresStat;
	bool displayEnd=true;
    while (displayEnd)
    {
        clear();

	    mvprintw(0, 21,"----- SYMULACJA ROZPOCZETA -----\n");
			mvprintw(1, 2, "-NAZWA-      -HP-");
			mvprintw(1, 25, "-STATUS-");
			mvprintw(1, 43, "-SZTUCCE-");
			mvprintw(1, 57, "-WYKONANO-");
        for (int y = 0; y < numberOfPhilosopher; y++) {
            name ="Filozof[" + to_string(y) + "]   <" + to_string(dataToDisplay->getHP(y)) + ">";
						progresStat= to_string(dataToDisplay->getProgress(y)) + "/" + to_string(timeToStopIt);
            switch(dataToDisplay->getStatus(y)){
			    case 0:
				    mvprintw(y + 2, 0, name.c_str());
				    mvprintw(y + 2, 25, "mysli");
						mvprintw(y + 2, 60, progresStat.c_str());
			    break;
			    case 1:
				    mvprintw(y + 2, 0, name.c_str());
				    mvprintw(y + 2, 25, "je");
						forks = "(" + to_string(dataToDisplay->getLeftFork(y)) + "|" +to_string(dataToDisplay->getRightFork(y)) + ")";
						mvprintw(y + 2, 45, forks.c_str());
						mvprintw(y + 2, 60, progresStat.c_str());
			    break;
			    case 2:
				    mvprintw(y + 2, 0, name.c_str());
				    mvprintw(y + 2, 25, "praca wykonana");
						mvprintw(y + 2, 60, progresStat.c_str());
			    break;
          case 4:
          mvprintw(y + 2, 0, name.c_str());
          mvprintw(y + 2, 25, "filozof nie zyje");
          mvprintw(y + 2, 60, progresStat.c_str());
          break;
		    }

        }
        refresh();
        this_thread::sleep_for(sleepTime);
			for(int x=0; x<numberOfPhilosopher; x++){
					displayEnd=true;
					if(dataToDisplay->getStatus(x)!=2) break;
					else displayEnd=false;
			}
    }
    this_thread::sleep_for(endSleepTime);
 }
//--------------------------------------------------

//----------------ZYCIE FILOZOFA--------------------
//--------------------------------------------------
    void Life(Philosopher* philosopher, Waiter* waiter,  Fork* forks, int timeToStopIt, DisplayData* dataToDisplay)
    {
        dataToDisplay->hp[philosopher->getID()]=philosopher->getHP();
        int* myFork = new int[2];
        if (philosopher->getID() == 0) {
            myFork[0] = numberOfPhilosopher-1;
            myFork[1] = 0;
        }
        else{
            myFork[0] = philosopher->getID() - 1;
            myFork[1] = philosopher->getID();
        }
        do {
            waiter->takeMyHPStatus(philosopher->getID(), philosopher->getHP());

            //-----MYSLENIE-----
            dataToDisplay->status[philosopher->getID()] = 0;
            philosopher->think();

            //-----JEDZENIE-----
            if(waiter->theyAreHealth(philosopher->getID()) || philosopher->getHP()<=10)
                if(forks[myFork[0]].takeFork()){
                  dataToDisplay->leftFork[philosopher->getID()] = myFork[0];
                  if (forks[myFork[1]].takeFork()) {
                      dataToDisplay->status[philosopher->getID()] = 1;
                      dataToDisplay->rightFork[philosopher->getID()] = myFork[1];
                      philosopher->eat();
                      forks[myFork[1]].putDownFork();
                  }
                  forks[myFork[0]].putDownFork();
                }

            dataToDisplay->progress[philosopher->getID()]=philosopher->getProgress();
            dataToDisplay->hp[philosopher->getID()]=philosopher->getHP();
            if(philosopher->getHP()<=0)
              break;
        } while (philosopher->getProgress() != timeToStopIt);
        if(philosopher->getHP()<=0)
          dataToDisplay->status[philosopher->getID()]= 3;
        else
          dataToDisplay->status[philosopher->getID()] = 2;
        delete myFork;
    }
//--------------------------------------------------




int main()
{
    cout << "--------------------------------------------------" << endl
         << "---------- Problem ucztujacych filozofow ---------" << endl
         << "-------------- FILIP KRYCZEK, 241302 -------------" << endl
         << "--------------------------------------------------" << endl;

    //---------- DANE KONFIGURACYJNE ----------
    int thinkingTime, eatingTime, healthPoint;
    do{
    cout<< "Wypelnij poprawne dane konfiguracyjne" <<endl;
    cout << endl << "Podaj liczbe filozofow (min 2): ";
    cin >> numberOfPhilosopher;
    cout << "Podaj liczbe cykli aby filozof osiagnal sukces: ";
    cin >> timeToStopIt;
    cout << "Czas myslenia [ms]: ";
    cin >> thinkingTime;
    cout << "Czas jedzenia [ms]: ";
    cin >> eatingTime;
    cout << "Punkty zycia (min. 15, maks 100): ";
    cin >> healthPoint;
  }while(numberOfPhilosopher<2 || timeToStopIt<1 || thinkingTime<0 || eatingTime<0 || healthPoint<15);
  if(healthPoint>100)
    healthPoint=100;
    //----------------------------------------

		initscr();
  	refresh();
    thread* philosopherThreads = new thread[numberOfPhilosopher];
    Fork* forks = new Fork[numberOfPhilosopher];
    Waiter* waiter = new Waiter(numberOfPhilosopher);

    DisplayData* dataToDisplay = new DisplayData(numberOfPhilosopher);
    thread display(Display, dataToDisplay);

		//-------------watki filozofow-------------
    for (int x = 0; x < numberOfPhilosopher; x++) {
        Philosopher* philosophers = new Philosopher(x, thinkingTime, eatingTime, healthPoint);
        philosopherThreads[x] = thread(Life, philosophers, waiter, forks, timeToStopIt, dataToDisplay);
    }

		//-----------rozpoczecie symulacji-----------
    for (int x = 0; x < numberOfPhilosopher; x++) {
        philosopherThreads[x].join();
    }
    display.join();


    delete[] philosopherThreads;
    delete[] forks;
    delete waiter;
		delete dataToDisplay;
    endwin();
}
