#include "Baker.h"

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
