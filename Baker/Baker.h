#ifndef BAKERY_BUSINESS_BAKER_H
#define BAKERY_BUSINESS_BAKER_H

#include "../Order/Order.h"

class Baker {
private:
    int workExperience;
    Order* order;
public:
    explicit Baker(int workExperience);

    int getWorkExperience() const;
    Order *getOrder() const;

    void setOrder(Order *order);
};


#endif
