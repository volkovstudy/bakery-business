#include "Client.h"

#include <utility>

Client::Client(string fullName) : fullName(std::move(fullName)) {}

const string &Client::getFullName() const {
    return fullName;
}
