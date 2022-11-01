#include "Baker.h"
#include "../Utill/Utill.h"

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
    Utill::delay(delayTimeInSeconds);

    getOrder()->setStatus(Status::COOKED);
}
