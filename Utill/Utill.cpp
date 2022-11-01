#include "Utill.h"
#include <thread>
#include <chrono>

#define nanosecondsInOneSecond 1000000000

using namespace std;

void Utill::delay(int seconds) {
    long delayTimeInNanoseconds = seconds * ((long) nanosecondsInOneSecond);
    this_thread::sleep_for(chrono::nanoseconds(delayTimeInNanoseconds));
}
