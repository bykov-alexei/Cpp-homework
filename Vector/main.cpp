#include <iostream>
#include "Vector.h"

void printVector(const Vector & v) {
    std::cout << v.length() << " array: ";
    for (int i = 0; i < v.length(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Vector v(0);
    Vector nv(5);
    nv.push_back(2); nv.push_back(3); nv.push_back(5);
    printVector(v);
    v.push_back(12);
    printVector(v);
    v.push_back(123);
    printVector(v);
    v.push_back(321);
    printVector(v);
    v.push_front(888);
    printVector(v);
    v.remove(2);
    printVector(v);


    v.extend(1, nv);
    printVector(nv);
    printVector(v);
    return 0;
}