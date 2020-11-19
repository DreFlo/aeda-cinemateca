#include "Utils.h"

using namespace std;

string input;
DataEHora today;
vector<Cinemateca *> cinemas;

int main() {
    // Any input that would turn cin.fail() true throws an exception of type ios_base::failure.
    cin.exceptions(ios_base::failbit | ios_base::badbit);
    /*
     * N FAÇO A MINIMA DE COMO DAR LOAD DA CINEMATECA
     * INICIALIZEM OS OBJS DAS DUAS AQUI E DEEM PUSH_BACK DOS PTRS PRA O CINEMAS
     */
    cout << WELCOME_MSG;
    utils::setToday();
    while (true) {
        cout << GET_CMD_MSG;
        getline(cin, input);
        if (input == "help")
            utils::printHelp();
        else if (input == "exit")
            break;
        else if (input == "change present")
            utils::setToday();
        else if (input == "add event")
            utils::addEvent();
        else if (input == "get events on")
            utils::getEventsOn();
        else if (input == "get events after")
            utils::getEventsAfter();
        else if (input == "get events before")
            utils::getEventsBefore();
        else if (input == "get events today")
            utils::getEventsToday();
        else if (input == "get future events")
            utils::getFutureEvents();
        else if (input == "get past events")
            utils::getPastEvents();
        else if (input == "get present")
            cout << today.str() << endl;
        else if (input == "add aderente")
            utils::addAderente();
        else if (input == "buy ticket")
            utils::buyTicket();
        else {
            cout << input << INVALID_CMD_MSG << endl;
            continue;
        }
    }
    cout << "Would you like to store changes? (Yes/No) ";
    cin >> input;
    if (input == "Yes") {
        // Aqui e para guardar idk how to do that
    }
    return 0;
}



