#include "OrderProcessing.h"
#include <set>

#define startIndex -1

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
    if (((long) couriers.size()) <= nextCourierIndex + 1) {
        nextCourierIndex = 0;
    } else {
        nextCourierIndex++;
    }

    return couriers.at(nextCourierIndex);
}

void makeOrdersDelivered(set<Order *> orders, Storage *storage) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        Order *order = *it;

        if (storage->isOrderFullyDelivered(order)) {
            order->setStatus(Status::DELIVERED);
            order->printStatus();
        }
    }
}

void OrderProcessing::deliverOrders() {
    vector<Courier*> couriers = staff->getCouriers();
    Courier* courier = getNextCourier(couriers);

    set<Order *> orders;
    vector<Pizza *> pizzas;

    for (Pizza *tempPizza = storage->getPizza(); tempPizza != nullptr; tempPizza = storage->getPizza()) {
        Order *order = tempPizza->getOrder();

        if (order->getStatus() != Status::DELIVERING) {
            order->setStatus(Status::DELIVERING);
            order->printStatus();
        }

        if (pizzas.size() == courier->getTrunkVolume()) {
            courier->deliverPizzas(pizzas);
            pizzas = *new vector<Pizza *>;
        }

        pizzas.push_back(tempPizza);

        if (pizzas.size() == courier->getTrunkVolume()) {
            courier->deliverPizzas(pizzas);
            pizzas = *new vector<Pizza *>;
        }

        orders.insert(order);
    }

    if (!pizzas.empty()) {
        courier->deliverPizzas(pizzas);
    }

    makeOrdersDelivered(orders, storage);
}
