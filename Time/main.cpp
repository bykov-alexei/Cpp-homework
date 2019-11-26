#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    string input;// = "AB.10";
    getline(cin,input);
    cout << is_number(input) << endl;
    return 0;
}