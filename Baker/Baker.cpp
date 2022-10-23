#include <thread>
#include <chrono>
#include "Baker.h"

#define nanosecondsInOneSecond 1000000000
#define secondsForOneWorkExperience 3

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

    int delayTimeInSeconds = abs((int) (getWorkExperience() - secondsForOneWorkExperience));
    this_thread::sleep_for(chrono::nanoseconds(delayTimeInSeconds * nanosecondsInOneSecond));

    getOrder()->setStatus(Status::COOKED);
}
