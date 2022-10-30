#include "Courier.h"
#include <iostream>

using namespace std;

Courier::Courier(int trunkVolume, Storage *storage) : trunkVolume(trunkVolume), storage(storage) {}

int Courier::getTrunkVolume() const {
    return trunkVolume;
}

void Courier::takeAndDeliverOrders() {
    vector<Order*> orders;

    for (int i = 0; i < trunkVolume; ++i) {
        Order* order = storage->getOrder();

        if (order == nullptr) break;

        order->setStatus(Status::DELIVERING);

        orders.push_back(order);

        cout << "Order #" << order->getId() << " is DELIVERING" << endl;
    }

    if (orders.empty()) return;

    for (int i = (int) orders.size() - 1; i >= 0; ++i) {
        Order *order = orders.at(i);

        order->setStatus(Status::DELIVERED);

        orders.pop_back();

        cout << "Order #" << order->getId() << " is DELIVERED" << endl;
    }
}
