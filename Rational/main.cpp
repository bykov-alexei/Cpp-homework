#include <iostream>
#include "Rational.h"

using namespace std;

void printFraction(const Rational r) {
    std::cout << r.getNumer() << "/" << r.getDenom() << std::endl;
}

int main() {
    Rational r1(2, 3);
    Rational r2(4, 5);

//    printFraction(r1 += r2);
//    printFraction(r1 -= r2);
//    printFraction(r2 *= r1);
//    printFraction(r1 /= r2);
    return 0;
}