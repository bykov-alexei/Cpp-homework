#include <iostream>
#include "Rational.h"

int abs(int a) {
    return (a < 0) ? -a : a;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a < b) {
        int t = b;
        b = a;
        a = t;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(int number) {
    numer = number;
    denom = 1;
}

Rational::Rational(double num) {
    //TODO: write
}

Rational::Rational(int num, int den) {
    if (den == 0)
        throw DivisionByZero();

    numer = num;
    denom = den;
    if (den < 0) {
        numer = -numer;
        denom = -denom;
    }
}

Rational::Rational(const Rational &r) {
    this->numer = r.getNumer();
    this->denom = r.getDenom();
}

int Rational::getNumer() const{
    return this->numer;
}

int Rational::getDenom() const {
    return this->denom;
}

Rational Rational::invert() const {
    if (numer == 0)
        throw InvertionError();

    int num = (this->numer < 0) ? -this->denom : this->denom;
    int den = abs(this->numer);
    auto * r = new Rational(num, den);
    return *r;
}

Rational Rational::operator+() const {
    auto * r = new Rational(*this);
    return *r;
}

Rational Rational::operator-() const {
    auto * r = new Rational(*this);
    r->numer = -r->numer;
    return *r;
}

void Rational::simplify() {
    int g = gcd(numer, denom);
    numer /= g;
    denom /= g;
}

Rational Rational::operator+(const Rational & other) const {
    int g = gcd(other.denom, this->denom);
    int lcd = other.denom * this->denom / g;
    int f2 = lcd / other.denom;
    int f1 = lcd / this->denom;
    auto * res = new Rational(f1 * this->numer + f2 * other.numer, lcd);
    res->simplify();
    return *res;
}

Rational Rational::operator-(const Rational & other) const {
    return *this + (-other);
}

Rational Rational::operator*(const Rational & other) const {
    int num = this->numer * other.numer;
    int den = this->denom * other.denom;
    Rational * res = new Rational(num, den);
    res->invert();
    res->simplify();
    return *res;
}

Rational Rational::operator/(const Rational & other) const {
    Rational res = (*this)*other.invert();
    res.simplify();
    return res;
}

Rational & Rational::operator+=(const Rational & other) {
    int g = gcd(other.denom, this->denom);
    int lcd = other.denom * this->denom / g;
    int f2 = lcd / other.denom;
    int f1 = lcd / this->denom;
    this->numer = f1 * this->numer + f2 * other.numer;
    this->denom = lcd;
    this->simplify();
    return *this;
}

Rational & Rational::operator-=(const Rational & other) {
    return *this += (-other);
}

Rational & Rational::operator*=(const Rational & other) {
    this->numer *= other.numer;
    this->denom *= other.denom;
    this->simplify();
    return *this;
}

Rational & Rational::operator/=(const Rational & other) {
    return *this *= other.invert();
}

bool Rational::operator==(const Rational & other) {
    Rational r1 = *this;
    Rational r2 = other;
    r1.simplify(); r2.simplify();
    return r1.numer == r2.numer && r1.denom == r2.denom;
}

bool Rational::operator!=(const Rational & other) {
    return !(*this == other);
}

bool Rational::operator<(const Rational & other) {
    Rational r1 = *this;
    Rational r2 = other;
    int g = gcd(r1.denom, r2.denom);
    int lcd = r1.denom * r2.denom / g;
    int f1 = r2.denom / g;
    int f2 = r1.denom / g;
    Rational br1(f1 * r1.numer, f1 * r1.denom);
    Rational br2(f2 * r2.numer, f2 * r2.denom);
    return br1.numer < br2.numer;
}

bool Rational::operator<=(const Rational & other) {
    return (*this < other) || (*this == other);
}

bool Rational::operator>(const Rational & other) {
    return !((*this < other || *this == other));
}

bool Rational::operator>=(const Rational & other) {
    return !(*this < other);
}




