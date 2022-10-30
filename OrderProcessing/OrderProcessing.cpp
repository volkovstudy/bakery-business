#include "OrderProcessing.h"
#include <iostream>

#define startIndex -1

using namespace std;

OrderProcessing::OrderProcessing(Staff *staff, Storage *storage) : staff(staff), storage(storage) {}

int nextBakerIndex = startIndex;
int nextCourierIndex = startIndex;

Baker* getNextBaker(vector<Baker*> bakers) {
    if (bakers.size() <= nextBakerIndex) {
        nextBakerIndex = 0;
    } else {
        nextBakerIndex++;
    }

    return bakers.at(nextBakerIndex);
}

void OrderProcessing::cookOrder(Order *order) {
    if (order->getStatus() != Status::ACCEPTED) return;

    vector<Baker*> bakers = staff->getBakers();
    Baker* baker = getNextBaker(bakers);

    baker->setOrder(order);
    baker->cook();

    if (order->getStatus() == Status::COOKED) {
        cout << "Order #" << order->getId() << " is " << order->getStatus() << endl;
    }
}

bool OrderProcessing::storeOrder(Order *order) {
    if (order->getStatus() != Status::COOKED) return false;

    storage->addOrder(order);

    if (order->getStatus() != Status::STORED) return false;

    cout << "Order #" << order->getId() << " is " << order->getStatus() << endl;

    return true;
}

Courier* getNextCourier(vector<Courier*> couriers) {
    if (couriers.size() <= nextCourierIndex) {
        nextCourierIndex = 0;
    } else {
        nextCourierIndex++;
    }

    return couriers.at(nextCourierIndex);
}

void OrderProcessing::deliverOrders() {
    vector<Courier*> couriers = staff->getCouriers();
    Courier* courier = getNextCourier(couriers);

    courier->takeAndDeliverOrders();
}
