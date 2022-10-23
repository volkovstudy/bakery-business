#include "Staff.h"

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
