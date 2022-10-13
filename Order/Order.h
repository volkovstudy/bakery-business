#ifndef BAKERY_BUSINESS_ORDER_H
#define BAKERY_BUSINESS_ORDER_H

#include "../Client/Client.h"
#include "../Status/Status.h"

class Order {
private:
    Status status;
    Client* client;
    int pizzaAmount;
public:
    Order(Status status, Client *client, int pizzaAmount);

    Status getStatus() const;
    Client *getClient() const;
    int getPizzaAmount() const;
};


#endif
