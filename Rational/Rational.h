#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

int gcd(int a, int b);

class InvertionError {};
class DivisionByZero {};

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

    Rational & operator+=(const Rational &);
    Rational & operator-=(const Rational &);
    Rational & operator*=(const Rational &);
    Rational & operator/=(const Rational &);

    bool operator==(const Rational &);
    bool operator!=(const Rational &);
    bool operator<(const Rational &);
    bool operator<=(const Rational &);
    bool operator>(const Rational &);
    bool operator>=(const Rational &);

    Rational sqrt();
    static Rational sqrt(const Rational &);

    void simplify();

};


#endif //RATIONAL_RATIONAL_H
