#ifndef BAKERY_BUSINESS_COURIER_H
#define BAKERY_BUSINESS_COURIER_H

#include "../Pizza/Pizza.h"

class Courier {
private:
    int trunkVolume;
public:
    Courier(int trunkVolume);

    void deliverPizzas(vector<Pizza *> pizzas);

    int getTrunkVolume() const;
};


#endif
