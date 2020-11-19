#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#include <algorithm>
#include "Cinemateca.h"
#include "Data.h"

#define WELCOME_MSG "Welcome!"
#define INNPUT_TODAY_MSG "Please input the present date and time (dd.mm.yyyy HHhMMmin): "
#define CHOOSE_CINEMATECA_MSG "To which cinema would you like to add an event? "
#define INPUT_DATE_MSG "Please input the date (dd.mm.yyyy): "
#define INVALID_INPUT_MSG "Invalid input"
#define INVALID_DATE_MSG " is not a valid date in the gregorian calendar. Try again [dd mm yy]: "
#define INVALID_CMD_MSG " is not a specified command. Type 'help' to get command list and description."
#define GET_CMD_MSG "What would you like to do?  "

using namespace std;

extern string input;
extern DataEHora today;
extern vector<Cinemateca *> cinemas;

namespace utils {
    /**
     * Prints commands on the screen.
     */
    void printHelp();
    /**
     * Change today date and time
     */
    void setToday();
    /**
     * Add an event to a cinemateca
     */
    void addEvent();
    /**
     * User friendly way to specify argument event's parameters
     * @param event event to construct
     * @return 0 if no errors, 1 if errors occurred
     */
    int constructEvent(Evento & event);
    /**
     * Finds cinema in cinemas
     * @param name cinema to find
     * @return pointer to named cinema
     */
    Cinemateca * findCinemateca(const string & name);
    /**
     * Get events for a given date
     */
    void getEventsOn();
    /**
     * Get events after a given date
     */
    void getEventsAfter();
    /**
     * Get events before a given date
     */
    void getEventsBefore();
    /**
     * Get today's events;
     */
    void getEventsToday();
    /**
     * Get future events
     */
    void getFutureEvents();
    /**
     * Get past events
     */
    void getPastEvents();
    /**
     * Checks if name is valid.
     * @param num Name
     * @return True if valid, else false
     */
    bool validName(string num);
    /**
     * Add an Aderente
     */
    void addAderente();
    void addCliente();
    /**
     * Gets info to buy ticket
     * @return True if ticket was bought, false otherwise.
     */
    bool creditInfo();
    bool purchaseAderente();
    /**
     * Buy ticket to specific event.
     */
    void buyTicket();
}

#endif //PROJETO_UTILS_H
