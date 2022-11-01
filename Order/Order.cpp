#include "Order.h"
#include <iostream>

#define numbersInOrderId 6

using namespace std;

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

void Order::printStatus() {
    cout << "Order #" << getId() << " is ";
    switch (status) {
        case ACCEPTED:
            cout << "ACCEPTED";
            break;
        case COOKING:
            cout << "COOKING";
            break;
        case COOKED:
            cout << "COOKED";
            break;
        case STORED:
            cout << "STORED";
            break;
        case DELIVERING:
            cout << "DELIVERING";
            break;
        case DELIVERED:
            cout << "DELIVERED";
            break;
    }
    cout << endl;
}
