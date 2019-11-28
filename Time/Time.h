//
// Created by alexei on 25.11.2019.
//

#ifndef TIME_TIME_H
#define TIME_TIME_H
#include <iostream>
#include <string>
using namespace std;

class WrongValues {};

class Time {
    int hours, minutes;
    float seconds;

public:
    Time();
    explicit Time(float seconds);
    Time(int hours, int minutes, float seconds);
    Time(const Time & time);

    Time operator+(const Time & other) const;
    Time operator-(const Time & other) const;

    explicit operator int() const;
    explicit operator float() const;

    float getSeconds() const;
    int getMinutes() const;
    int getHours() const;

};

std::ostream& operator<<(std::ostream & out, const Time & t);
istream& operator>>(istream & in, Time & t);

bool is_number(const string & str);

#endif //TIME_TIME_H
