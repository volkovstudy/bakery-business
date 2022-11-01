#include "OrderProcessing.h"

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

    order->printStatus();
}

bool OrderProcessing::storeOrder(Order *order) {
    if (order->getStatus() != Status::COOKED) return false;

    storage->addOrder(order);

    if (order->getStatus() != Status::STORED) return false;

    order->printStatus();

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

    while (storage->getOccupancy() != 0) {
        vector<Order *> orders;

        Order *tempOrder = storage->getOrder();
        for (int i = 0; i < courier->getTrunkVolume() && tempOrder != nullptr; ++i) {
            orders.push_back(tempOrder);

            tempOrder = storage->getOrder();
        }

        courier->deliverOrders(orders);
    }
}
