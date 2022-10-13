#ifndef BAKERY_BUSINESS_ORDER_H
#define BAKERY_BUSINESS_ORDER_H

#include "../Client/Client.h"

class Order {
private:
    Client* client;
    int pizzaAmount;
public:
    Order(Client *client, int pizzaAmount);

    Client *getClient() const;
    int getPizzaAmount() const;
};


#endif
