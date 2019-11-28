//
// Created by alexei on 25.11.2019.
//

#include "Time.h"
#include <math.h>
#include <iomanip>

Time::Time() {
    this->seconds = 0.0;
    this->minutes = 0;
    this->hours = 0;
}

Time::Time(float seconds) {
    int hours = ((int) seconds) / 3600;
    int minutes = (((int) abs(seconds)) / 60) % 60;
    this->seconds = abs(seconds) - minutes * 60 - abs(hours) * 3600;
    this->minutes = minutes;
    this->hours = hours;
}

Time::Time(int hours, int minutes, float seconds) {
    if (seconds < 0 || seconds >= 60 ||
            minutes < 0 || minutes >= 60)
        throw WrongValues();

    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

Time::Time(const Time & t) {
    this->hours = t.getHours();
    this->minutes = t.getMinutes();
    this->seconds = t.getSeconds();
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


float Time::getSeconds() const{
    return this->seconds;
}

int Time::getMinutes() const{
    return this->minutes;
}

int Time::getHours() const {
    return this->hours;
}

bool is_number(const string & str) {
    int point = 0;

    bool started = false;
    bool warn = false;

    for (char ch : str) {
        if (ch == ' ') {
            if (started) {
                warn = true;
            }
        } else {
            if (warn) {
                return false;
            }

            started= true;
            if (ch == '.') {
                started = true;
                point += 1;
            } else if (!(ch >= '0' && ch <= '9')) {
                return false;
            }
        }
    }
    return point <= 1;
}

ostream& operator<<(ostream & out, const Time & t) {
    out << setw(2) << setfill('0') << t.getHours() << ":" << setw(2) << setfill('0') << t.getMinutes()
                << ":" << setw(2) << setfill('0') << t.getSeconds() << endl;
    return out;
}

istream& operator>>(istream & in, Time & t) {
    int hours, minutes;
    float seconds;

    string line;
    getline(in, line, '\n');

    int c = 0;
    string num = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ':' or i == line.size() - 1) {
            if (c == 0) {
                if (!is_number(num))
                    throw WrongValues();
                hours = atoi(num.c_str());
                num = "";
            } else if (c == 1) {
                if (!is_number(num))
                    throw WrongValues();
                minutes = atoi(num.c_str());
                num = "";
            } else if (c == 2) {
                if (!is_number(num))
                    throw WrongValues();
                num += line[i];
                seconds = atof(num.c_str());
                num = "";
            }
            c++;
        } else {
            num += line[i];
        }
    }
    t = Time(hours, minutes, seconds);
    return in;
}
