#include "Storage.h"

#define endValue -1

Storage::Storage(int capacity) : capacity(capacity) {
    occupancy = 0;
}

int Storage::getCapacity() const {
    return capacity;
}

void Storage::addOrder(Order *order) {
    if (occupancy < getCapacity()) {
        orders.push_back(order);
        order->setStatus(Status::STORED);
        occupancy++;
    }
}

Order *Storage::getOrder() {
    int lastOrderIndex;
    if (orders.empty()) {
        occupancy = 0;
        return nullptr;
    } else {
        lastOrderIndex = (int) orders.size() - 1;
    }

    Order* order = orders.at(lastOrderIndex);

    orders.pop_back();

    --occupancy;

    return order;
}

int Storage::getOccupancy() const {
    return occupancy;
}

void Storage::addPizza(Pizza *pizza) {
    Order *order = pizza->getOrder();

    /*
     * Order for 2 pizzas
     * Storage capacity = 1
     * Storage occupancy = 0
     *
     * 1. pair is null
     * 1.1 pair should be 1/2
     * 2. orders delivering...
     * 2.1 map is NOT cleared
     * 3. Add new pizza
     *
     * When returning pizza for delivering, should be returned with pair.second != -1
     */

    // <stored> <need to be stored>
    pair<int, int> *pizzaStatus = &pizzas[order];

    bool isPairNull = pizzaStatus->first == 0 && pizzaStatus->second == 0;
    if (isPairNull) {
        pizzaStatus->first = 1;
        pizzaStatus->second = order->getPizzaAmount();

        ++occupancy;
    } else if (pizzaStatus->second != endValue) {
        bool isPairFull = pizzaStatus->first == pizzaStatus->second;
        if (isPairFull) return;

        pizzaStatus->first = pizzaStatus->first + 1;

        ++occupancy;
    }
}

Pizza *Storage::getPizza() {
    Pizza *result = nullptr;

    auto iterator = pizzas.begin();
    while (iterator != pizzas.end()) {
        pair<int, int> *p = &(iterator->second);

        if (p->second == endValue) {
            iterator++;
            continue;
        }

        Order *order = iterator->first;
        Pizza *pizza = new Pizza(order);

        result = pizza;

        p->first = p->first - 1;
        p->second = p->second - 1;

        if (p->second == 0) p->second = endValue;

        --occupancy;

        break;
    }

    return result;
}

bool Storage::isFull() {
    return occupancy == capacity;
}
