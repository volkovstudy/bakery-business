#ifndef BAKERY_BUSINESS_COURIER_H
#define BAKERY_BUSINESS_COURIER_H


class Courier {
private:
    int trunkVolume;
public:
    explicit Courier(int trunkVolume);

    int getTrunkVolume() const;
};


#endif
