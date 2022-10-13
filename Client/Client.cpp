#include "Client.h"

Client::Client(const string &fullName) : fullName(fullName) {}

const string &Client::getFullName() const {
    return fullName;
}
