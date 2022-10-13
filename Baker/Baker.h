#ifndef BAKERY_BUSINESS_BAKER_H
#define BAKERY_BUSINESS_BAKER_H


class Baker {
private:
    int workExperience;
public:
    explicit Baker(int workExperience);

    int getWorkExperience() const;
};


#endif
