#include "OrderProcessing.h"

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
        vector<Pizza *> pizzas;

        Order *tempOrder = storage->getOrder();
        while (tempOrder != nullptr) {
            tempOrder->setStatus(Status::DELIVERING);
            tempOrder->printStatus();

            for (int j = 0; j < tempOrder->getPizzaAmount(); ++j) {
                if (pizzas.size() == courier->getTrunkVolume()) {
                    courier->deliverPizzas(pizzas);
                    pizzas = *new vector<Pizza *>;
                }

                Pizza *pizza = new Pizza(tempOrder);
                pizzas.push_back(pizza);
            }

            if (pizzas.size() == courier->getTrunkVolume()) {
                courier->deliverPizzas(pizzas);
            }

            orders.push_back(tempOrder);
            tempOrder = storage->getOrder();
        }

        for (int i = 0; i < orders.size(); ++i) {
            Order order = *orders.at(i);

            order.setStatus(Status::DELIVERED);
            order.printStatus();
        }
    }
}
