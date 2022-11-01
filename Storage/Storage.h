#ifndef BAKERY_BUSINESS_STORAGE_H
#define BAKERY_BUSINESS_STORAGE_H

#include <vector>
#include "../Order/Order.h"

class Storage {
private:
    int capacity;
    int occupancy{};
    vector<Order*> orders;
public:
    explicit Storage(int capacity);

    void addOrder(Order *order);

    int getCapacity() const;
    int getOccupancy() const;
    Order* getOrder();
};


#endif
