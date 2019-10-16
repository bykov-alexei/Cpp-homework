#include <iostream>
#include "Rational.h"

using namespace std;

void printFraction(const Rational r) {
    std::cout << r.getNumer() << "/" << r.getDenom() << std::endl;
}

int main() {
    Rational r(2);
    printFraction(r.sqrt());
    return 0;
}