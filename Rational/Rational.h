#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iostream>

using namespace std;

int gcd(int a, int b);
double frexp10(double arg, int & exp);

class InvertionError:exception {};
class DivisionByZero:exception {};

class Rational {
    int numer, denom;

public:

    Rational();
    Rational(int number);
    Rational(int num, int den);
    Rational(double num);
    Rational(const Rational & r);

    int getNumer() const;
    int getDenom() const;

    Rational invert() const;

    Rational operator+() const;
    Rational operator-() const;

    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;

    Rational operator+(int) const;
    Rational operator-(int) const;
    Rational operator*(int) const;
    Rational operator/(int) const;

    Rational & operator+=(const Rational &);
    Rational & operator-=(const Rational &);
    Rational & operator*=(const Rational &);
    Rational & operator/=(const Rational &);

    bool operator==(const Rational &) const;
    bool operator!=(const Rational &) const;
    bool operator<(const Rational &) const;
    bool operator<=(const Rational &) const;
    bool operator>(const Rational &) const;
    bool operator>=(const Rational &) const;

    Rational sqrt();
    static Rational sqrt(const Rational &);

    explicit operator double() const;

    void simplify();

};

Rational operator+(int b, Rational & a);

ostream& operator<<(ostream & out, const Rational r);
istream& operator>>(istream & in, Rational & r);


#endif //RATIONAL_RATIONAL_H
