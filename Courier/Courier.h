#ifndef BAKERY_BUSINESS_COURIER_H
#define BAKERY_BUSINESS_COURIER_H

#include "../Order/Order.h"

class Courier {
private:
    int trunkVolume;
    Order* order;
public:
    explicit Courier(int trunkVolume);

    int getTrunkVolume() const;
    Order *getOrder() const;

    void setOrder(Order *order);
};


#endif
