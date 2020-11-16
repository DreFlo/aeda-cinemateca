#include "Utils.h"

void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change today - change current day" << endl;
}

void utils::setToday() try{
    cout << INNPUT_TODAY_MSG;
    getline(cin, input);
    cout << endl;
    today.setDateAndTime(input);
    Cinemateca::MudarAgora(today);
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << D.getMsg();
    setToday();
} catch (InvalidTime &T) {
    cout << endl << T.getTime().str() << T.getMsg();
    setToday();
} catch (invalid_argument &I) {
    cout << endl << I.what();
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
    decapitalize(input);
    while (input != "lisboa" && input != "porto") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    constructEvent(temp);
    findCinemateca(input)->AdicionarEvento(temp);
} catch (...) {}

void utils::constructEvent(Evento &event) {

}

Cinemateca * utils::findCinemateca(const string &name) {
    for (auto cine : cinemas)
        if (cine->GetMorada() == name)
            return cine;
    return nullptr;
}

void utils::decapitalize(string name) {
    for (char & i : name) {
        i = ::tolower(i);
    }
}