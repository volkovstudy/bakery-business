#include "Order.h"

#define numbersInOrderId 6

int idGenerator = 1;

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
                                                               pizzaAmount(pizzaAmount) {
    id = idGenerator++;
}

void Order::setStatus(Status status) {
    Order::status = status;
}

string Order::getId() {
    string result = "";

    int amountOfNumbersInId = 1;
    int tempId = id;
    while (tempId /= 10) ++amountOfNumbersInId;

    int amountOfZerosInResult = numbersInOrderId - amountOfNumbersInId;
    for (int i = 0; i < amountOfZerosInResult; ++i) {
        result += "0";
    }

    result += to_string(id);

    return result;
}
