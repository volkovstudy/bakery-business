#ifndef BAKERY_BUSINESS_COURIER_H
#define BAKERY_BUSINESS_COURIER_H

#include "../Storage/Storage.h"

class Courier {
private:
    int trunkVolume;
    Storage* storage;
public:
    Courier(int trunkVolume, Storage *storage);

    void takeAndDeliverOrders();

    int getTrunkVolume() const;
};


#endif
