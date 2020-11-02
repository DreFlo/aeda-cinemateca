#include <iostream>
#include <fstream>
#include "Cinemateca.h"
#include "Utils.h"

using namespace std;

Data today;

int main() {
    cout << WELCOME_MSG;
    cin >> today;
    cout << endl;
    while (cin.fail() || !today.valid()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << INVALID_DATE_INPUT;
        cin >> today;
        cout << endl;
    }
    return 0;
}



