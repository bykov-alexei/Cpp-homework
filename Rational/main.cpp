#include <iostream>
#include <math.h>
#include "Rational.h"

using namespace std;

Rational & enter() {
    Rational & a = *(new Rational());
    while (true) {
        try {
            cout << "Enter number in format num/den" << endl;
            cin >> a;
            break;
        } catch (DivisionByZero) {
            cout << "Try again" << endl;
        }
        catch (exception) {
            cout << "Try again" << endl;
        }
    }
    return a;
}

int main() {
    Rational a, b, c;
    a = enter();
    b = enter();
    c = enter();
    cout << a << " " << b << " " << c << endl;
    Rational d = b*b - a * c * 4;
//    Rational d = b*b - 4 * a * c;
    cout << d << endl;
    cout << d.sqrt() << endl;
    Rational x1 = (-b + d.sqrt()) / (a*2);
    Rational x2 = (-b - d.sqrt()) / (a*2);
    cout << x1 << " " << x2 << endl;
//    cout << a.sqrt() << " " << b.sqrt() << endl;
    cout << (double) x1 << " " << (double) x2 << endl;
    return 0;
}