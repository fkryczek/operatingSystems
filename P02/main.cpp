//--------------------------------------------------
//-------------- FILIP KRYCZEK, 241302 -------------
//--------------------------------------------------

#include <iostream>
#include <thread>
#include <mutex>
#include <ncurses.h>
#include <condition_variable>

#include "Cyclist.h"
#include "Base.h"
#include "Supply.h"
#include "Service.h"
#include "RepairingPlace.h"
#include "DisplayData.h"
#include "ServiceCar.h"

using namespace std;
bool timeToStop = false;
DisplayData* dataToDisplay;
mutex serviceCarMTX;
condition_variable serviceCarCV;

void displayIt(int numberOfServices, int numberOfCyclist, int numberOfSupplier, int numberOfServiceCar){
     chrono::milliseconds refreshingTime(25);
    chrono::milliseconds seeDataAfterAllWillBeDone(5000);

    bool displayEnd = true;
    string name, forks, progresStat;

    while (displayEnd)
    {
        clear();

        mvprintw(0, 35, "----- SYMULACJA -----\n");
        mvprintw(1, 4, "---DOSTAWCA CZESCI---");
        mvprintw(2, 0, "[ID]");
        mvprintw(2, 12, "[STATUS]");

        mvprintw(numberOfSupplier+4, 4, "---SERWIS ROWEROWY---");
        mvprintw(numberOfSupplier+5, 0, "[ID]");
        mvprintw(numberOfSupplier+5, 4, "[CZESCI]");
        mvprintw(numberOfSupplier+5, 12, "[STATUS]");

        mvprintw(numberOfSupplier+numberOfServices+7, 4, "---SAMOCHODY SERWISOWE---");
        mvprintw(numberOfSupplier+numberOfServices+8, 0, "[ID]");
        mvprintw(numberOfSupplier+numberOfServices+8, 12, "[STATUS]");

        mvprintw(1, 56, "---KOLARZE---");
        mvprintw(2, 44, "[ID]");
        mvprintw(2, 51, "[KM]");
        mvprintw(2, 57, "[%]");
        mvprintw(2, 70, "[STATUS]");

        for (int y = 0; y < numberOfSupplier; y++) {
            switch (dataToDisplay->getSupplyStatus(y)) {
            case 0:
                name = "D[" + to_string(y) + "] => przygotowuje dostawe";
                mvprintw(y+3, 0, name.c_str());
                break;
            case 1:
                name = "D[" + to_string(y) + "] => wyszukuje serwisu";
                mvprintw(y+3, 0, name.c_str());
                break;
            case 2:
                name = "D[" + to_string(y) + "] => dostarcza czesci do " + to_string(dataToDisplay->getDeliveryDirection(y));
                mvprintw(y+3 , 0, name.c_str());
                break;
            case 3:
                name = "D[" + to_string(y) + "] => koniec pracy";
                mvprintw(y+3, 0, name.c_str());
                break;    
            }
        }

        for (int y = 0; y < numberOfServices; y++) {
            switch (dataToDisplay->getServiceStatus(y)) {
            case 0:
                name = "S[" + to_string(y) + "] " + to_string(dataToDisplay->getBikeParts(y)) + " => dostawa";
                mvprintw(y+6+numberOfSupplier, 0, name.c_str());
                break;
            case 1:
                name = "S[" + to_string(y) + "] " + to_string(dataToDisplay->getBikeParts(y)) + " => bezczynny";
                mvprintw(y+6+numberOfSupplier, 0, name.c_str());
                break;
            case 2:
                name = "S[" + to_string(y) + "] " + to_string(dataToDisplay->getBikeParts(y)) + " => obsluga klienta " + to_string(dataToDisplay->getWhoIsMyClient(y));
                mvprintw(y+6+numberOfSupplier, 0, name.c_str());
                break;
            case 3:
                name = "S[" + to_string(y) + "] " + to_string(dataToDisplay->getBikeParts(y)) + " => czeka na dostawe";
                mvprintw(y+6+numberOfSupplier, 0, name.c_str());
                break;    
             case 4:
                name = "S[" + to_string(y) + "] " + to_string(dataToDisplay->getBikeParts(y)) + " => koniec pracy";
                mvprintw(y+6+numberOfSupplier, 0, name.c_str());
                break;    
            }
        }

        for (int y = 0; y < numberOfCyclist; y++) {
            switch (dataToDisplay->getCyclistStatus(y)) {
            case 0:
                name = "Kolarz[" + to_string(y) + "] " + to_string(dataToDisplay->getProgress(y)) + "   " + to_string(dataToDisplay->getBikeCondition(y)) + " jezdzi";
                mvprintw(y + 3, 41, name.c_str());
                break;
            case 1:
                name = "Kolarz[" + to_string(y) + "] " + to_string(dataToDisplay->getProgress(y)) + "   " + to_string(dataToDisplay->getBikeCondition(y)) + " serwis";
                mvprintw(y + 3, 41, name.c_str());
                break;
            case 2:
                name = "Kolarz[" + to_string(y) + "] " + to_string(dataToDisplay->getProgress(y)) + "   " + to_string(dataToDisplay->getBikeCondition(y)) + " osiagnal cel";
                mvprintw(y + 3, 41, name.c_str());
                break;
            case 3:
                name = "Kolarz[" + to_string(y) + "] " + to_string(dataToDisplay->getProgress(y)) + "   "  + to_string(dataToDisplay->getBikeCondition(y)) + " stracil rower";
                mvprintw(y + 3, 41, name.c_str());
                break;
            case 4:
                name = "Kolarz[" + to_string(y) + "] " + to_string(dataToDisplay->getProgress(y)) + "   "  + to_string(dataToDisplay->getBikeCondition(y)) + " czeka na pilna naprawe";
                mvprintw(y + 3, 41, name.c_str());
                break;    
            }
        }

        for (int y = 0; y < numberOfServiceCar; y++) {
            switch (dataToDisplay->getServiceCarStatus(y)) {
            case 0:
                name = "SC[" + to_string(y) + "] => zbiera czesci";
                mvprintw(y+9+numberOfSupplier+numberOfServices, 0, name.c_str());
                break;
            case 1:
                name = "SC[" + to_string(y) + "] => oczekuje na zgloszenie";
                mvprintw(y+9+numberOfSupplier+numberOfServices, 0, name.c_str());
                break;
            case 2:
                name = "SC[" + to_string(y) + "]  => w trasie ";
                mvprintw(y+9+numberOfSupplier+numberOfServices, 0, name.c_str());
                break;
            case 3:
                name = "SC[" + to_string(y) + "] => naprawia rower kolarza nr " + to_string(dataToDisplay->getWhoIsRepairingByServiceCar(y));
                mvprintw(y+9+numberOfSupplier+numberOfServices, 0, name.c_str());
                break;    
             case 4:
                name = "SC[" + to_string(y) + "] => koniec pracy";
                mvprintw(y+9+numberOfSupplier+numberOfServices, 0, name.c_str());
                break;    
            }
        }

        refresh();
        this_thread::sleep_for(refreshingTime);
        for (int x = 0; x < numberOfCyclist; x++) {
            displayEnd = true;
            if (dataToDisplay->getCyclistStatus(x) != 2 && dataToDisplay->getCyclistStatus(x) != 3) break;
           else displayEnd = false;
        }
    }
    lock_guard<mutex> lk(serviceCarMTX);
    serviceCarCV.notify_all();
    this_thread::sleep_for(seeDataAfterAllWillBeDone);
    clear();
    mvprintw(10, 51, "KONIEC");
    refresh();
}


void serviceCarLife(ServiceCar* serviceCars, Base* base, Cyclist** cyclistList){
    int cyclistID;
    do{        
        dataToDisplay->setServiceCarStatus(serviceCars->getID(), 0);
        serviceCars->takeEssentialParts();
        dataToDisplay->setServiceCarStatus(serviceCars->getID(), 1);
       
        unique_lock<mutex> lk(serviceCarMTX);
        while(!base->someoneNeedServiceCar() && !timeToStop) serviceCarCV.wait(lk);
        if(timeToStop) break;
        
            cyclistID = base->whoNeedServiceCar();
            if(cyclistList[cyclistID]->lock()){
                dataToDisplay->setWhoIsRepairingByServiceCar(serviceCars->getID(),cyclistID);
                dataToDisplay->setServiceCarStatus(serviceCars->getID(), 2);
                serviceCars->goToCyclist();
                dataToDisplay->setServiceCarStatus(serviceCars->getID(), 3);
                base->setHeDontNeedServiceCar(cyclistID);
                cyclistList[cyclistID]->repair();
                cyclistList[cyclistID]->unlock();
            }
            
    }while(!timeToStop);
    dataToDisplay->setServiceCarStatus(serviceCars->getID(), 4);
}

void serviceLife(Service* services, RepairingPlace* repairingPlace, Base* base) {
    do {
          dataToDisplay->setBikeParts(services->getID(), services->getStock());
          if (services->getStock() < 100){              
            if (repairingPlace[services->getID()].serviceCloseParts()){
                services->takeOrder();
                dataToDisplay->setServiceStatus(services->getID(), 3);
            }
          }
          else{
            base->setIDontNeedParts(services->getID());
            dataToDisplay->setServiceStatus(services->getID(), 1);
            repairingPlace[services->getID()].serviceOpenParts();
          }
       } while (!timeToStop);
       dataToDisplay->setServiceStatus(services->getID(), 4);
}

void supplyLife(Supply* suppliers, Base* base, RepairingPlace* repairingPlace) {   
    do {
        if (suppliers->getPartsToTake() != suppliers->getSypplyCapability()) {
            suppliers->takeParts();
            dataToDisplay->setSupplyStatus(suppliers->getId(), 0);
        }

        dataToDisplay->setSupplyStatus(suppliers->getId(), 1);
        for (int x = 0; x < base->getNumberOfServices(); x++)
            if (base->needSomething(x))
                if(!(repairingPlace[x].serviceCloseParts())){
                    if(repairingPlace[x].serviceCloseDelivery()){
                        if(repairingPlace[x].serviceClosedRepair()){
                            dataToDisplay->setSupplyStatus(suppliers->getId(), 2);
                            dataToDisplay->setServiceStatus(x, 1);
                            dataToDisplay->setDeliveryDirection(suppliers->getId(), x);
                            
                            base->setInventory(x, suppliers->getPartsToTake());
                            suppliers->supplyParts();

                            repairingPlace[x].serviceOpenRepair();                        
                            repairingPlace[x].serviceOpenDelivery();
                            break;
                        }
                        repairingPlace[x].serviceOpenDelivery();
                    }
                }
                else 
                    repairingPlace[x].serviceOpenParts();
    } while (!timeToStop);
    timeToStop=true;
    dataToDisplay->setSupplyStatus(suppliers->getId(), 3);
}

void cyclistLife(Cyclist* cyclist, Base* base, RepairingPlace* repairingPlace) {
    do {
        dataToDisplay->setCyclistStatus(cyclist->getId(), 0);
        cyclist->ride();

        dataToDisplay->setProgress(cyclist->getId(), cyclist->getDistance());
        dataToDisplay->setBikeCondition(cyclist->getId(), cyclist->getBikeCondition());

        if (cyclist->getBikeCondition() < 0) {
            dataToDisplay->setCyclistStatus(cyclist->getId(), 3);
            break;
        }

        do{
            for (int x = 0; x < base->getNumberOfServices(); x++) {
                if(!(repairingPlace[x].serviceCloseParts())){
                    if(repairingPlace[x].serviceCloseDelivery()){
                        if(repairingPlace[x].serviceClosedRepair()){
                            if(base->getInventory(x) >= 100){
                                    dataToDisplay->setServiceStatus(x, 2);
                                    dataToDisplay->setWhoIsMyClient(x, cyclist->getId());
                                    dataToDisplay->setCyclistStatus(cyclist->getId(), 1);

                                    cyclist->repair();
                                    base->setInventory(x,-(cyclist->getBikeCondition()));

                                    dataToDisplay->setServiceStatus(x, 1);
                                    dataToDisplay->setBikeCondition(cyclist->getId(), cyclist->getBikeCondition());

                                    repairingPlace[x].serviceOpenRepair();
                                    repairingPlace[x].serviceOpenDelivery();
                                    break;
                                } 
                            repairingPlace[x].serviceOpenRepair();
                        }
                        repairingPlace[x].serviceOpenDelivery();
                    }
                }
                else
                repairingPlace[x].serviceOpenParts();
            }

            if(cyclist->getBikeCondition() < 5){
                base->setINeedServiceCar(cyclist->getId());
                dataToDisplay->setCyclistStatus(cyclist->getId(), 4);
            }
            while(cyclist->getBikeCondition() < 5){
                lock_guard<mutex> lk(serviceCarMTX);
                serviceCarCV.notify_one();
            }
            
        }while(cyclist->getBikeCondition() < 15);
        
    } while (cyclist->getDistance() < cyclist->getKmGoal());
    if (cyclist->getBikeCondition() > 0)
        dataToDisplay->setCyclistStatus(cyclist->getId(), 2);     
}







int main() {
    cout << "--------------------------------------------------" << endl
         << "-------------- FILIP KRYCZEK, 241302 -------------" << endl
         << "--------------------------------------------------" << endl;

    int numberOfCyclist=15, ridingTime=100, cyclistGoal=10000, cyclistBike=25;
    int numberOfServices=10, repairingTime=50, startingParts=100;
    int numberOfSupplier=2, supplyCapabilty=50, deliveryTime=35, takingPartsTime=15;
    int numberOfServiceCar=5, repairTimeByCar=50, commuteTime=50, takingPartsByCarTime=15;


    cout << "Wypelnij poprawnie dane konfiguracyjne" << endl << endl
        << "Podaj liczbe serwisow rowerowych: (5) ";
    cin >> numberOfServices;
    cout << "Podaj liczbe rowerzystow: (15) ";
    cin >> numberOfCyclist;
    cout << "Podaj liczbe dostawcow: (2) ";
    cin >> numberOfSupplier;
    cout << "--------------------------------------------------" << endl;
    cout << "Sredni czas jazdy kolarza [ms]: (100) ";
    cin >> ridingTime;
    cout << "Cel liczby km kolarzy: (10000) ";
    cin >> cyclistGoal;
    cout << "Stan rowerow kolarzy (25-100) (25) ";
    cin >> cyclistBike;
    cout << "--------------------------------------------------" << endl;
    cout << "Poczatkowa liczba czesci w serwisie: (75) ";
    cin >> startingParts;
    cout << "Sredni czas naprawy [ms]: (50) ";
    cin >> repairingTime;
    cout << "--------------------------------------------------" << endl;
    cout << "Liczba czesci mozliwych do przewiezienia przez dostawce: (50) ";
    cin >> supplyCapabilty;
    cout << "Sredni czas zbierania czesci przez dostawce [ms]: (15) ";
    cin >> takingPartsTime;
    cout << "Czas dostawy [ms]: (35) ";
    cin >> deliveryTime;
    cout << "--------------------------------------------------" << endl;
    cout << "Liczba samochodów serwisowych: (2)";
    cin >> numberOfServiceCar;
    cout << "Sredni czas dotarcia do kolarza [ms]: (50) ";
    cin >> commuteTime;
    cout << "Sredni czas zbierania czesci przez samochod serwisowy [ms]: (15) ";
    cin >> takingPartsByCarTime;

    initscr();
    refresh();

    dataToDisplay = new DisplayData(numberOfServices, numberOfCyclist, numberOfSupplier, numberOfServiceCar);
    thread* cyclistThread = new thread[numberOfCyclist];
    thread* supplierThread = new thread[numberOfSupplier];
    thread* servicesThread = new thread[numberOfServices];
    thread* serviceCarsThread = new thread[numberOfServiceCar];
    thread display(displayIt, numberOfServices, numberOfCyclist, numberOfSupplier, numberOfServiceCar);

    Cyclist** cyclistList = new Cyclist*[numberOfCyclist];
    Base* base = new Base(numberOfServices, numberOfServiceCar, numberOfCyclist, startingParts);
    RepairingPlace* repairingPlace = new RepairingPlace[numberOfServices];


    for (int x = 0; x < numberOfServices; x++) {
        Service* services = new Service(x, base);
        servicesThread[x] = thread(serviceLife, services, repairingPlace, base);
    }
    for (int x = 0; x < numberOfCyclist; x++) {
        Cyclist* cyclists = new Cyclist();
        cyclists->setValue(x, ridingTime, repairingTime, cyclistGoal, cyclistBike);
        cyclistList[x]=cyclists;
        cyclistThread[x] = thread(cyclistLife, cyclists, base, repairingPlace);
    }
    for (int x = 0; x < numberOfSupplier; x++) {
        Supply* suppliers = new Supply(x, supplyCapabilty,deliveryTime, takingPartsTime);
        supplierThread[x] = thread(supplyLife, suppliers, base, repairingPlace);
    }
    for (int x = 0; x < numberOfServiceCar; x++) {
        ServiceCar* serviceCars = new ServiceCar(x, commuteTime, takingPartsByCarTime);
        serviceCarsThread[x] = thread(serviceCarLife, serviceCars, base, cyclistList);
    }

    display.join();
    endwin();
    
}
