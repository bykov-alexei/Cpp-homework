#include <iostream>
#include "Time.h"

using namespace std;

Time & enter() {
    Time & t1 = *(new Time());
    cout << "Enter time in format HH:MM:SS" << endl;
    while (true) {
        try {
            cin >> t1;
            break;
        } catch (WrongValues) {
            cout << "Error. Try again." << endl;
        }
    }
    return t1;
}

int main() {
    Time t1, t2;
    t1 = enter();
    t2 = enter();
    cout << "First: " << t1 << endl;
    cout << "Second: " << t2 << endl;
    cout << "Sum: " << t1 + t2 << endl;
    cout << "Difference " << t1 - t2 << endl;
    return 0;
}