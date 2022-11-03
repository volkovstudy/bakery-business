#ifndef BAKERY_BUSINESS_STORAGE_H
#define BAKERY_BUSINESS_STORAGE_H

#include <vector>
#include <map>
#include "../Pizza/Pizza.h"
#include "../Order/Order.h"

class Storage {
private:
    int capacity;
    int occupancy;
    vector<Order*> orders;
    map<Order *, pair<int, int>> pizzas;
public:
    explicit Storage(int capacity);

    bool isFull();
    bool isOrderFullyDelivered(Order *order);

    void addOrder(Order *order);
    void addPizza(Pizza *pizza);

    int getCapacity() const;
    int getOccupancy() const;
    Order* getOrder();
    Pizza *getPizza();
};


#endif
