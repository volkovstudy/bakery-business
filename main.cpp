#include <iostream>
#include "Staff/Staff.h"
#include "OrderProcessing/OrderProcessing.h"
#include "Utill/Utill.h"

#define timeBetweenActionsInSeconds 1

using namespace std;

Staff *staff;
Storage *storage;

void initializeStaff();

int main() {
    cout << "Hello! Now you're going to hire your staff." << endl << endl;
    initializeStaff();
    cout << endl;
    staff->printInfo();
    cout << "Storage capacity (pizza amount) is " << storage->getCapacity() << endl << endl;

    cout << "Order some pizza: ";
    int pizzaAmount;
    cin >> pizzaAmount;
    while (pizzaAmount <= 0) {
        cout << endl << "You can order amount of pizza which is greater than 0." << endl;
        cout << "Order some pizza: ";
        cin >> pizzaAmount;
    }
    cout << endl;

    cout << "Who is ordering (your name): ";
    string clientFullname;
    cin >> clientFullname;
    cout << endl;

    Client *client = new Client(clientFullname);
    Order *order = new Order(Status::ACCEPTED, client, pizzaAmount);

    cout << "Your order (#" << order->getId() << ") for " << pizzaAmount << " pizza is ACCEPTED. ";
    cout << "Order is registered in the name of " << clientFullname << ". " << endl;

    OrderProcessing *orderProcessing = new OrderProcessing(staff, storage);

    orderProcessing->cookOrder(order);
    Utill::delay(timeBetweenActionsInSeconds);
    orderProcessing->storeOrder(order);
    Utill::delay(timeBetweenActionsInSeconds);
    orderProcessing->deliverOrders();

    cout << endl << "Thanks for ordering pizza!" << endl;

    return 0;
}

void initializeBakers(int amountOfBakers) {
    srand(time(nullptr));

    for (int i = 0; i < amountOfBakers; ++i) {
        int workExperience = 0 + rand() % 3;
        Baker *baker = new Baker(workExperience);

        staff->addBaker(baker);
    }
}

void initializeCouriers(int amountOfCouriers, int trunkVolume) {
    for (int i = 0; i < amountOfCouriers; ++i) {
        Courier *courier = new Courier(trunkVolume);

        staff->addCourier(courier);
    }
}

void initializeStaff() {
    staff = new Staff();

    cout << "How many bakers do you want to see?" << endl;
    cout << "Amount: ";
    int amountOfBakers;
    cin >> amountOfBakers;
    while (amountOfBakers <= 0) {
        cout << endl << "Wrong. Amount should be greater than 0!" << endl;
        cout << "Amount: ";
        cin >> amountOfBakers;
    }

    cout << endl << "Well. How many couriers?" << endl;
    cout << "Amount: ";
    int amountOfCouriers;
    cin >> amountOfCouriers;
    while (amountOfCouriers <= 0) {
        cout << endl << "Wrong. Amount should be greater than 0!" << endl;
        cout << "Amount: ";
        cin >> amountOfCouriers;
    }

    cout << endl << "How big will their trunk be?" << endl;
    cout << "Capacity (in pizzas): ";
    int trunkVolume;
    cin >> trunkVolume;
    while (trunkVolume <= 0) {
        cout << endl << "Wrong. Capacity should be greater than 0!" << endl;
        cout << "Capacity: ";
        cin >> trunkVolume;
    }

    cout << endl << "Great. How big will your storage be?" << endl;
    cout << "Storage capacity (pizza amount): ";
    int storageCapacity;
    cin >> storageCapacity;
    while (storageCapacity <= 0) {
        cout << endl << "Wrong. Capacity should be greater than 0!" << endl;
        cout << "Capacity: ";
        cin >> storageCapacity;
    }

    storage = new Storage(storageCapacity);

    initializeBakers(amountOfBakers);
    initializeCouriers(amountOfCouriers, trunkVolume);
}
