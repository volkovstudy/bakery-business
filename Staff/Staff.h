#ifndef BAKERY_BUSINESS_STAFF_H
#define BAKERY_BUSINESS_STAFF_H

#include <vector>
#include "../Baker/Baker.h"
#include "../Courier/Courier.h"

class Staff {
private:
    vector<Baker*> bakers;
    vector<Courier*> couriers;
public:
    Staff();

    void addBaker(Baker* baker);
    vector<Baker*> getBakers();

    void addCourier(Courier* courier);
    vector<Courier*> getCouriers();
};


#endif
