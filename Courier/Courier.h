#ifndef BAKERY_BUSINESS_COURIER_H
#define BAKERY_BUSINESS_COURIER_H

#include "../Order/Order.h"

class Courier {
private:
    int trunkVolume;
public:
    Courier(int trunkVolume);

    void deliverOrders(vector<Order *> orders);

    int getTrunkVolume() const;
};


#endif
