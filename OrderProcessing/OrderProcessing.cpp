#include "OrderProcessing.h"

#define startIdForBaker -1

OrderProcessing::OrderProcessing(Staff *staff, Storage *storage) : staff(staff), storage(storage) {}

int nextBakerIndex = startIdForBaker;

Baker* getNextBaker(vector<Baker*> bakers) {
    if (bakers.size() <= nextBakerIndex) {
        nextBakerIndex = 0;
    } else {
        nextBakerIndex++;
    }

    return bakers.at(nextBakerIndex);
}

void OrderProcessing::cookOrder(Order *order) {
    if (order->getStatus() != Status::ACCEPTED) return;

    vector<Baker*> bakers = staff->getBakers();
    Baker* baker = getNextBaker(bakers);

    baker->setOrder(order);
    baker->cook();
}
