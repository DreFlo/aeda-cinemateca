#include <iostream>
#include <fstream>
#include "Cinemateca.h"
#include "Utils.h"

using namespace std;

Data today(1, 1, 1);
Cinemateca Lisboa("Lisboa", today, "MORADA"), Porto("Porto", today, "MORADA");

void setToday() try{
    cin >> today;
    Lisboa.MudarDiaAtual(today);
    Porto.MudarDiaAtual(today);
    return;
} catch (InvalidDate &D) {
    cout << D.getDate() << " is an invalid date. Try again." << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    setToday();
}

int main() {
    cout << WELCOME_MSG;
    setToday();
    return 0;
}



