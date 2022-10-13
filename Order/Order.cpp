#include "Order.h"

Status Order::getStatus() const {
    return status;
}

Client *Order::getClient() const {
    return client;
}

int Order::getPizzaAmount() const {
    return pizzaAmount;
}

Order::Order(Status status, Client *client, int pizzaAmount) : status(status), client(client),
                                                               pizzaAmount(pizzaAmount) {}
