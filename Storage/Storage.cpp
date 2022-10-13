#include "Storage.h"

Storage::Storage(int capacity) : capacity(capacity) {}

int Storage::getCapacity() const {
    return capacity;
}

const vector<Order*> &Storage::getOrders() const {
    return orders;
}

void Storage::addOrder(Order *order) {
    if (occupancy < getCapacity()) {
        orders.push_back(order);
    }
}
