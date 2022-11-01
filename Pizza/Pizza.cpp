#include "Pizza.h"

Pizza::Pizza(Order *order) : order(order) {}

Order *Pizza::getOrder() const {
    return order;
}
