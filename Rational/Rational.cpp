#include <iostream>
#include <math.h>
#include "Rational.h"

using namespace std;

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

double frexp10(double arg, int & exp) {
    exp = (arg == 0) ? 0 : 1 + (int)std::floor(std::log10(std::fabs(arg) ) );
    return arg * std::pow(10 , -(exp));
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
    long long m, e;
    m = e = *(long long*)&num;
    long long t = 1;

    e = ((e >> 53) & ((t << 10) - 1)) - 512;
    m = !(m & ((t << 53) - 1));
    cout << e << " " << m << endl;
    cout << hex << e <<  " " << hex << m << endl;
    this->numer = m;
    if (e > 0) {
        this->denom = 1 << e;
    } else {
        this->numer *= (1 << e);
    }
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
    this->simplify();
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

bool Rational::operator==(const Rational & other) const {
    Rational r1 = *this;
    Rational r2 = other;
    r1.simplify(); r2.simplify();
    return r1.numer == r2.numer && r1.denom == r2.denom;
}

bool Rational::operator!=(const Rational & other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational & other) const {
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

bool Rational::operator<=(const Rational & other) const {
    return (*this < other) || (*this == other);
}

bool Rational::operator>(const Rational & other) const {
    return !((*this < other || *this == other));
}

bool Rational::operator>=(const Rational & other)  const {
    return !(*this < other);
}

void Rational::simplify() {
    int g = gcd(numer, denom);
    numer /= g;
    denom /= g;
}

Rational Rational::sqrt() {
    if (*this == Rational(0)) {
        return Rational(0);
    }
    Rational x = *this;
    while (x.numer <= 155650 && x.denom <= 155650) {
        x = Rational(1, 2) * (x + *this/x);
    }
    return x;
}

Rational Rational::sqrt(const Rational & a) {
    if (a == Rational(0)) {
        Rational(0);
    }
    Rational x = a;
    while (x.numer <= 65565 && x.denom <= 65535) {
        x = Rational(1, 2) * (x + a/x);
    }
    return x;
}

Rational::operator double() const {
    return (double) this->numer / (double) this->denom;
}

Rational Rational::operator+(int a) const {
    return *this + Rational(a);
}

Rational Rational::operator-(int a) const {
    return *this - Rational(a);
}

Rational Rational::operator*(int a) const {
    return *this * Rational(a);
}

Rational Rational::operator/(int a) const {
    return *this / Rational(a);
}

ostream& operator<<(ostream & out, const Rational r) {
    out << r.getNumer() << "/" << r.getDenom();
    return out;
}

istream& operator>>(istream & in, Rational & r) {
    string line;
    getline(in, line, '\n');
    string num_s = "", den_s = "";
    bool met = false;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '/') {
            met = true;
            continue;
        }
        if (met) {
            if (line[i] >= '0' && line[i] <= '9')
                den_s += line[i];
            else
                throw exception();
        } else {
            if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' && i==0))
                num_s += line[i];
            else
                throw exception();
        }
    }
    r = *(new Rational(atoi(num_s.c_str()), atoi(den_s.c_str())));
    return in;
}




