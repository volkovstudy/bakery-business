#include "Courier.h"

using namespace std;

Courier::Courier(int trunkVolume) : trunkVolume(trunkVolume) {}

int Courier::getTrunkVolume() const {
    return trunkVolume;
}

void Courier::deliverOrders(vector<Order *> orders) {
    for (int i = 0; i < orders.size(); ++i) {
        Order *order = orders.at(i);

        order->setStatus(Status::DELIVERING);
        order->printStatus();

        order->setStatus(Status::DELIVERED);
        order->printStatus();
    }
}
