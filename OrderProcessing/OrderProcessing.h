#ifndef BAKERY_BUSINESS_ORDERPROCESSING_H
#define BAKERY_BUSINESS_ORDERPROCESSING_H

#include "../Staff/Staff.h"
#include "../Storage/Storage.h"

class OrderProcessing {
private:
    Staff* staff;
    Storage* storage;
public:
    OrderProcessing(Staff *staff, Storage *storage);

    void cookOrder(Order* order);
    bool storeOrder(Order* order);
    void deliverOrders();
};


#endif
