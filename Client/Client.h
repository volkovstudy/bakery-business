#ifndef BAKERY_BUSINESS_CLIENT_H
#define BAKERY_BUSINESS_CLIENT_H

#include <string>

using namespace std;

class Client {
private:
    string fullName;
public:
    explicit Client(const string &fullName);

    const string &getFullName() const;
};


#endif
