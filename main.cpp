#include "Utils.h"
#include <windows.h>

using namespace std;
using namespace utils;

string input;
DataEHora today;
vector<Cinemateca *> cinemas;

int main() {
    stringstream res;
    Evento temp("idk a name", 2.7, DataEHora(15, 3, 2001, 13, 1), Hora(2, 0), 200), temp2;
    res << temp;
    try {
    res >> temp2; } catch (InvalidTime &D) { cout << D.getTime().valid() << '\t' << D.getTime().str() << endl;}
    catch (InvalidDate &D) { cout << D.getDate().valid() << '\t' << D.getDate().str() << endl; }
    cout << temp2;
    /*
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
        else if (input == "add event")
            utils::addEvent();
        else {
            cout << input << INVALID_CMD_MSG << endl;
            continue;
        }
    } while (GetAsyncKeyState(VK_ESCAPE) == 0);
    return 0;
     */
}



