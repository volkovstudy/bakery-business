#include "Client.h"

Client::Client(const string &fullName, const vector<Order> &orders) : fullName(fullName), orders(orders) {}

const string &Client::getFullName() const {
    return fullName;
}

const vector<Order> &Client::getOrders() const {
    return orders;
}
