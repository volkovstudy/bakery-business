#ifndef BAKERY_BUSINESS_ORDER_H
#define BAKERY_BUSINESS_ORDER_H

#include "../Client/Client.h"
#include "../Status/Status.h"

class Order {
private:
    int id;
    Status status;
    Client* client;
    int pizzaAmount;
public:
    Order(Status status, Client *client, int pizzaAmount);

    void printStatus();

    Status getStatus() const;
    Client *getClient() const;
    int getPizzaAmount() const;
    string getId();

    void setStatus(Status status);
};


#endif
