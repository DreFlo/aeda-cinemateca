#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#include <algorithm>
#include "Cinemateca.h"

#define WELCOME_MSG "Welcome! Please input today's date [dd mm yy]: "
#define CHOOSE_CINEMATECA_MSG "To which cinema would you like to add an event? "
#define INVALID_INPUT_MSG "Invalid input. Try again [dd mm yy]: "
#define INVALID_DATE_MSG " is not a valid date in the gregorian calendar. Try again [dd mm yy]: "
#define INVALID_CMD_MSG " is not a specified command. Type 'help' to get command list and description."
#define GET_CMD_MSG "What would you like to do? "

using namespace std;

string input;
Data today;
vector<Cinemateca *> cinemas;

namespace utils {
    void printHelp();
    void setToday();
    void addEvent();
    void constructEvent(Evento & event);
}

#endif //PROJETO_UTILS_H
