#include "Storage.h"

Storage::Storage(int capacity) : capacity(capacity) {}

int Storage::getCapacity() const {
    return capacity;
}

void Storage::addOrder(Order *order) {
    if (occupancy < getCapacity()) {
        orders.push_back(order);
        order->setStatus(Status::STORED);
    }
}

Order *Storage::getOrder() {
    int lastOrderIndex;
    if (orders.empty()) {
        return nullptr;
    } else {
        lastOrderIndex = (int) orders.size() - 1;
    }

    Order* order = orders.at(lastOrderIndex);

    orders.pop_back();

    return order;
}

int Storage::getOccupancy() const {
    return occupancy;
}
