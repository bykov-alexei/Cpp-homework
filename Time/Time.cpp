//
// Created by alexei on 25.11.2019.
//

#include "Time.h"
#include <math.h>

Time::Time() {
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}

Time::Time(float seconds) {
    int hours = ((int) seconds) / 3600;
    int minutes = (((int) seconds) / 60) % 60;
    this->seconds = seconds - minutes * 60 - hours * 3600;
    this->minutes = minutes;
    this->hours = hours;
}

Time::Time(int hours, int minutes, float seconds) {
    if (seconds < 0 || seconds >= 60 ||
            minutes < 0 || minutes >= 60 ||
            hours < 0 || hours >= 24)
        throw WrongValues();

    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

Time Time::operator+(const Time &other) const {
    auto t1 = (float) *this;
    auto t2 = (float) other;
    return *(new Time(t1 + t2));
}

Time::operator int() const {
    return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

Time::operator float() const {
    return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

Time Time::operator-(const Time &other) const {
    float dt = abs((float) *this) - ((float) other);
    return *(new Time(dt));
}

bool Time::operator<(const Time &other) const {
    float t1 = (float) *this;
    float t2 = (float) other;
    return t1 < t2;
}

bool Time::operator==(const Time &other) const {
    float t1 = (float) *this;
    float t2 = (float) other;
    return t1 == t2;
}

bool Time::operator>(const Time & other) const {
    return !(*this == other) || !(*this < other);
}

bool Time::operator>=(const Time & other) const {
    return !(*this < other);
}

bool Time::operator<=(const Time & other) const {
    return (*this == other) || (*this < other);
}

bool Time::operator!=(const Time & other) const {
    return !(*this == other);
}

Time::Time(const Time &time) {
    this->seconds = time.getSeconds();
    this->minutes = time.getMinutes();
    this->hours = time.getHours();
}

float Time::getSeconds() const{
    return this->seconds;
}

int Time::getMinutes() const{
    return this->minutes;
}

int Time::getHours() const {
    return this->hours;
}
