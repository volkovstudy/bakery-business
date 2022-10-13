#include "Courier.h"

Courier::Courier(int trunkVolume) : trunkVolume(trunkVolume) {}

int Courier::getTrunkVolume() const {
    return trunkVolume;
}
