#include "Order.h"

Order::Order(Client *client, int pizzaAmount) : client(client), pizzaAmount(pizzaAmount) {}

Client *Order::getClient() const {
    return client;
}

int Order::getPizzaAmount() const {
    return pizzaAmount;
}
