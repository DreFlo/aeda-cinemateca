#include "Utils.h"

void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change today - change current day" << endl;
}

void utils::setToday() try{
    cin >> today;
    cout << endl;
    for (auto cine : cinemas)
        cine->MudarDiaAtual(today);
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << INVALID_DATE_MSG;
    setToday();
} catch (ios_base::failure &e) {
    cout  << endl << INVALID_INPUT_MSG;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    setToday();
}

void utils::addEvent() try {
    Evento temp;
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> input;
    cout << endl;
    constructEvent(temp);
    for (auto cine : cinemas) if (cine->getMorada() == input) cine->AdicionarEvento(temp);
} catch (...) {}