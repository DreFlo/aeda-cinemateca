#include <iostream>
#include <fstream>
#include "Cinemateca.h"
#include "Utils.h"
#include <windows.h>

using namespace std;

string input;
Data today;
//Cinemateca Lisboa("Lisboa", today, "MORADA"), Porto("Porto", today, "MORADA");

void setToday() try{
    cin >> today;
    cout << endl;/*
    Lisboa.MudarDiaAtual(today);
    Porto.MudarDiaAtual(today);*/
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << INVALID_DATE_MSG;
    setToday();
} catch (ios_base::failure &e) {
    cout  << endl << INVALID_INPUT_MSG;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    setToday();
}

int main() {
    // Any input that would turn cin.fail() true throws an exception of type ios_base::failure.
    cin.exceptions(ios_base::failbit | ios_base::badbit);
    cout << WELCOME_MSG;
    setToday();
    do {
        cout << GET_CMD_MSG;
        cin >> input;
        if (input == "help")
            utils::printHelp();
        else if (input == "exit")
            break;
        else {
            cout << input << INVALID_CMD_MSG << endl;
            continue;
        }
    } while (GetAsyncKeyState(VK_ESCAPE) == 0);
    return 0;
}



