//
// Created by alexei on 25.11.2019.
//

#ifndef TIME_TIME_H
#define TIME_TIME_H

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

    bool operator>(const Time & other) const;
    bool operator<(const Time & other) const;
    bool operator==(const Time & other) const;
    bool operator!=(const Time & other) const;
    bool operator<=(const Time & other) const;
    bool operator>=(const Time & other) const;

    explicit operator int() const;
    explicit operator float() const;

    float getSeconds() const;
    int getMinutes() const;
    int getHours() const;
};

#endif //TIME_TIME_H
