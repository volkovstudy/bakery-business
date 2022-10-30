#include "Staff.h"
#include <iostream>

using namespace std;

Staff::Staff() = default;

void Staff::addBaker(Baker *baker) {
    bakers.push_back(baker);
}

vector<Baker *> Staff::getBakers() {
    return bakers;
}

void Staff::addCourier(Courier *courier) {
    couriers.push_back(courier);
}

vector<Courier *> Staff::getCouriers() {
    return couriers;
}

void printBakers(vector<Baker *> bakers) {
    for (int i = 0; i < bakers.size(); ++i) {
        cout << i + 1 << ". Work experience (years) = " << bakers.at(i)->getWorkExperience() << endl;
    }
}

void printCouriers(vector<Courier *> couriers) {
    for (int i = 0; i < couriers.size(); ++i) {
        cout << i + 1 << ". Trunk volume = " << couriers.at(i)->getTrunkVolume() << endl;
    }
}

void Staff::printInfo() {
    cout << "Your staff is:" << endl;

    cout << "Bakers (" << bakers.size() << "): " << endl;
    printBakers(bakers);

    cout << "Couriers (" << couriers.size() << "): " << endl;
    printCouriers(couriers);

    cout << endl;
}
