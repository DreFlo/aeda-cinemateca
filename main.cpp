#include "Utils.h"
#include <windows.h>

using namespace std;
using namespace utils;

string input;
DataEHora today;
vector<Cinemateca *> cinemas;

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
        else if (input == "add event")
            utils::addEvent();
        else {
            cout << input << INVALID_CMD_MSG << endl;
            continue;
        }
    } while (GetAsyncKeyState(VK_ESCAPE) == 0);
    return 0;
}



