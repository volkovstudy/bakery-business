#include "Baker.h"
#include "../Utill/Utill.h"
#include <iostream>

#define secondsForOneWorkExperience 3

using namespace std;

Baker::Baker(int workExperience) : workExperience(workExperience) {}

int Baker::getWorkExperience() const {
    return workExperience;
}

Order *Baker::getOrder() const {
    return order;
}

void Baker::setOrder(Order *order) {
    Baker::order = order;
}

void Baker::cook() const {
    getOrder()->setStatus(Status::COOKING);
    getOrder()->printStatus();

    int amountOfPizza = getOrder()->getPizzaAmount();
    for (int i = 0; i < amountOfPizza; ++i) {
        int delayTimeInSeconds = abs((int) (getWorkExperience() - secondsForOneWorkExperience));
        Utill::delay(delayTimeInSeconds);

        cout << "Order #" << getOrder()->getId() << ": Pizza №" << i+1 << " is ready" << endl;
    }

    getOrder()->setStatus(Status::COOKED);
}
