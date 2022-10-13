#ifndef BAKERY_BUSINESS_CLIENT_H
#define BAKERY_BUSINESS_CLIENT_H

#include <string>
#include <vector>
#include "../Order/Order.h"

using namespace std;

class Client {
private:
    string fullName;
    vector<Order> orders;
public:
    Client(const string &fullName, const vector<Order> &orders);

    const string &getFullName() const;
    const vector<Order> &getOrders() const;
};


#endif
