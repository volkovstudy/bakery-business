#include "Courier.h"

Courier::Courier(int trunkVolume) : trunkVolume(trunkVolume) {}

int Courier::getTrunkVolume() const {
    return trunkVolume;
}

Order *Courier::getOrder() const {
    return order;
}

void Courier::setOrder(Order *order) {
    Courier::order = order;
}
