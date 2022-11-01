#include "Courier.h"
#include "../Utill/Utill.h"
#include <iostream>
#include <map>

#define timeWhileDeliveringInSeconds 3

using namespace std;

Courier::Courier(int trunkVolume) : trunkVolume(trunkVolume) {}

int Courier::getTrunkVolume() const {
    return trunkVolume;
}

void Courier::deliverPizzas(vector<Pizza *> pizzas) {
    map<Order *, int> orders;

    for (int i = 0; i < pizzas.size(); ++i) {
        Order *order = pizzas.at(i)->getOrder();

        int valueInMap = orders[order];
        if (valueInMap < 0)
            valueInMap = 0;

        orders[order] = ++valueInMap;
    }

    for (auto i = orders.begin(); i != orders.end(); ++i) {
        Order *order = i->first;
        int pizzaAmount = i->second;

        cout << "Order #" << order->getId() << ": Delivering " << pizzaAmount << " pizza" << endl;
        Utill::delay(timeWhileDeliveringInSeconds);
        cout << "Order #" << order->getId() << ": Delivered " << pizzaAmount << " pizza" << endl;
    }
}
