#include "Storage.h"

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
