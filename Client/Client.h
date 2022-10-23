#ifndef BAKERY_BUSINESS_CLIENT_H
#define BAKERY_BUSINESS_CLIENT_H

#include <string>
#include <vector>

using namespace std;

class Client {
private:
    std::string fullName;
public:
    explicit Client(string fullName);

    const string &getFullName() const;
};


#endif
