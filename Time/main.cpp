#include <iostream>
#include "Time.h"

using namespace std;

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


int main() {
    string input;// = "AB.10";
    getline(cin,input);
    cout << is_number(input) << endl;
    return 0;
}