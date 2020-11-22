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
     *
     * Done ;)
     */
    cout << WELCOME_MSG;
    utils::setToday();
    try {
        Cinemateca Porto("Porto", today);
        Cinemateca Lisboa("Lisboa", today);
        Porto.LerFicheiroAderentes("AderentesPorto.txt");
        Porto.LerFicheiroSalas("SalasPorto.txt");
        Porto.LerFicheiroEventos("EventosPorto.txt");
        Lisboa.LerFicheiroAderentes("AderentesLisboa.txt");
        Lisboa.LerFicheiroSalas("SalasLisboa.txt");
        Lisboa.LerFicheiroEventos("EventosLisboa.txt");
        cinemas.push_back(&Porto);
        cinemas.push_back(&Lisboa);
        utils::avisarAderentes();
    }
    catch (char const * errormsg) {cout << errormsg;}
    while (true) {
        cout << GET_CMD_MSG;
        getline(cin, input);
        if (input == "help")
            utils::printHelp();
        else if (input == "exit")
            break;
        else if (input == "change present"){
            utils::setToday();
            utils::avisarAderentes();
        }
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
        else if (input == "remove event")
            utils::removeEvent();
        else if (input == "update event")
            utils::updateEvent();
        else if (input == "get present")
            cout << today.str() << endl;
        else if (input == "add aderente")
            utils::addAderente();
        else if (input == "buy ticket")
            utils::buyTicket();
        else if (input == "get aderentes")
            utils::getAderentes();
        else if (input == "remove aderente")
            utils::removeAderente();
        else if (input == "find aderente")
            utils::findAderente();
        else if (input == "update aderente")
            utils::updateAderente();
        else if (input == "add sala")
            utils::addSala();
        else if (input == "get salas")
            utils::getSalas();
        else if (input == "find sala")
            utils::findSala();
        else if (input == "update sala")
            utils::updateSala();
        /*
        else if (input == "read file")
            utils::readfile();*/
        else {
            cout << input << INVALID_CMD_MSG << endl;
            continue;
        }
        cout << endl;
        cin.ignore();
    }
    cout << "Would you like to store changes? (Yes/No) ";
    cin >> input;
    if (input == "Yes") {
        cinemas[0]->EscreverFicheiroSalas("SalasPorto.txt");
        cinemas[0]->EscreverFicheiroAderentes("AderentesPorto.txt");
        cinemas[0]->EscreverFicheiroEventos("EventosPorto.txt");

        cinemas[1]->EscreverFicheiroSalas("SalasLisboa.txt");
        cinemas[1]->EscreverFicheiroAderentes("AderentesLisboa.txt");
        cinemas[1]->EscreverFicheiroEventos("EventosLisboa.txt");
    }
    return 0;
}



