#ifndef BAKERY_BUSINESS_PIZZA_H
#define BAKERY_BUSINESS_PIZZA_H

#include "../Order/Order.h"

class Pizza {
private:
    Order *order;
public:
    explicit Pizza(Order *order);

    Order *getOrder() const;
};


#endif
