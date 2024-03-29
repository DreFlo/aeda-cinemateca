#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#include <algorithm>
#include "Cinemateca.h"
#include "Data.h"
#include <random>

#define WELCOME_MSG "Welcome!"
#define INNPUT_TODAY_MSG "Please input the present date and time (dd.mm.yyyy HHhMMmin): "
#define CHOOSE_CINEMATECA_MSG "To which cinema would you like to add an event? "
#define INPUT_DATE_MSG "Please input the date (dd.mm.yyyy): "
#define INVALID_INPUT_MSG "Invalid input"
#define INVALID_DATE_MSG " is not a valid date in the gregorian calendar. Try again [dd mm yy]: "
#define INVALID_CMD_MSG " is not a specified command. Type 'help' to get command list and description."
#define GET_CMD_MSG "What would you like to do? "

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
     * Gets a name for someone.
     * @return Name.
     */
    string inputName();
    /**
     * Gets chosen city from Porto or Lisboa.
     * @param aderentes Whether it is for an Aderente or not.
     * @return City.
     */
    string inputCity(bool aderentes = true);
    /**
     * Gets NIF for a person.
     * @return NIF.
     */
    unsigned int inputNIF();
    /**
     * Gets a person's cellphone number.
     * @return Cellphone number.
     */
    unsigned int inputCell();
    /**
     * Add an Aderente
     */
    void addAderente();
    /**
     * Prints Aderentes on screen in a specific city or both.
     */
    void getAderentes();
    /**
     * Removes a specific Aderente
     */
    void removeAderente();
    /**
     * Finds a specific Aderente.
     */
    void findAderente();
    /**
     * Changes one of Aderente's atributes;
     */
    void updateAderente();
    /**
     * Gets a name for a Sala.
     * @return Sala's name.
     */
    string inputSalaName();
    /**
     * Add a Sala to a city.
     */
    void addSala();
    /**
     * Prints Salas on screen for a specific city or both.
     */
    void getSalas();
    /**
     * Finds a specific Sala.
     */
    void findSala();
    /**
     * Changes one of Sala's atributes.
     */
    void updateSala();
    /**
     * Reserve ticket to specific event.
     */
    void buyTicket();
    /**
     * Reads a specific file and adds what it needs to a Cinemateca.
     */
     void readfile();
     /**
      * Warns aderentes over 65 years old that they can go to an event for free
      */
     void avisarAderentes();
    /**
     * Remove given event.
     */
    void removeEvent();
    /**
     * Alter a given event
     */
    void updateEvent();
    /**
     * Add a Trabalhador
     */
    void addTrabalhador();
    /**
     * Alter an atribute from a Trabalhador
     */
    void changeTrabalhador();
    /**
     * Fires a Trabalhador, by making it's work parameter equal to false
     */
    void fireTrabalhador();
    /**
     * Prints the Trabalhadores
     */
    void getTrabalhadores();
    /**
     * Prints top event
     */
    void getTopEvent();
    /**
     * Prints top event in a price renge
     */
    void getTopEventBetween();
    /**
     * Let's the user choose which way to traverse the BST and prints it
     */
    void ShowBst();
}

#endif //PROJETO_UTILS_H
