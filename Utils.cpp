#include "Utils.h"

// IMPLEMENTEM OUTRAS CENAS A VONTADE. PLS ADICIONEM OS COMANDOS NO MAIN E NO PRINT HELP.


void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change present - change current date and time" << endl;
    // DIOGUINHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    cout << "add aderente - add a new aderente" << endl;
    // HMMMMM ACHO QUE ESTA E DA CINEMATECA
    cout << "sign up - sign cliente or aderente to an event" << endl;
    cout << "get events on - print events on a given date" << endl;
    cout << "get events after - print events after a given date" << endl;
    cout << "get events before - print events before a given date" << endl;
    cout << "get events today - print today's events" << endl;
    cout << "get future events - print future events" << endl;
    cout << "get past events - print future events" << endl;
    cout << "get present - prints the current date and time" << endl;
}

void utils::setToday() try{
    cout << INNPUT_TODAY_MSG;
    getline(cin, input);
    cout << endl;
    today.setDateAndTime(input);
    Cinemateca::MudarAgora(today);
} catch (InvalidDate &D) {
    cout << D.getDate().str() << " " << D.getMsg() << endl;
    setToday();
} catch (InvalidTime &T) {
    cout << T.getTime().str() << " " << T.getMsg() << endl;
    setToday();
} catch (invalid_argument &I) {
    cout << I.what() << endl;
    setToday();
} catch (ios_base::failure &e) {
    cout  << INVALID_INPUT_MSG << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    setToday();
}

void utils::addEvent() try {
    Evento temp;
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> input;
    if (input == "CANCEL") return;
    while (input != "Lisboa" && input != "Porto") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (constructEvent(temp) != 0) return;
    findCinemateca(input)->AdicionarEvento(temp);
} catch (...) {} // PLS TRATEM DOS CATCHES QUE ACHO QUE DEVE HAVER TANTO DA CINEMATECA
//COMO DA SALA DE HOUVER CONFLITO ENTRE DOIS EVENTOS

// TA A DAR ME UM BUG BOE ESQUISITO NESTA. JA QUERO MATAR UM PORCO
int utils::constructEvent(Evento &event) try {
    string room, name;
    DataEHora start;
    Hora duration;
    int attn;
    // EVENT NAME
    cout << "Input event name: ";
    getline(cin, input);
    cout << endl;
    name = input;
    if (name == "CANCEL") return 1;
    event.setName(name);
    // EVENT ROOM
    cout << "Input event room: ";
    getline(cin, input);
    cout << endl;
    room = input;
    if (room == "CANCEL") return 1;
    event.setRoom(room);
    // EVENT START
    cout << "Input event's start date and time (dd.mm.yyyy HHhMMmin): ";
    getline(cin, input);
    cout << endl;
    if (input == "CANCEL") return 1;
    start.setDateAndTime(input);
    event.setStart(start);
    // EVENT LENGTH
    cout << "Input event's duration (HHhMMmin): ";
    getline(cin, input);
    cout << endl;
    if (input == "CANCEL") return 1;
    duration.setTime(input);
    event.setDuration(duration);
    cout << "Input event's maximum attendance: ";
    cin >> attn;
    event.setMaxAttendance(attn);
    return 0;
} catch (invalid_argument &I) {
    return 1;
} catch (InvalidDate &D) {
    cout << D.getDate() << D.getMsg() << endl;
    return 1;
} catch (InvalidTime &T) {
    cout << T.getTime() << T.getMsg() << endl;
    return 1;
} catch (...) {
    return 1;
}

Cinemateca * utils::findCinemateca(const string &name) {
    for (auto cine : cinemas)
        if (cine->GetMorada() == name)
            return cine;
    return nullptr;
}

void utils::getEventsOn() try {
    Data date;
    string name;
    vector<Evento> res;
    cout << INPUT_DATE_MSG;
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosData(date);
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << D.getMsg();
    setToday();
} catch (InvalidTime &T) {
    cout << endl << T.getTime().str() << T.getMsg();
    getEventsOn();
} catch (invalid_argument &I) {
    cout << endl << I.what();
    getEventsOn();
} catch (ios_base::failure &e) {
    cout  << endl << INVALID_INPUT_MSG;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getEventsOn();
}

void utils::getEventsAfter() try {
    Data date;
    string name;
    vector<Evento> res;
    // INPUT DATE
    cout << INPUT_DATE_MSG;
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    // CHOOSE CINEMATECA
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosDepoisData(date);
    // PRINT
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << D.getMsg();
    setToday();
} catch (InvalidTime &T) {
    cout << endl << T.getTime().str() << T.getMsg();
    getEventsAfter();
} catch (invalid_argument &I) {
    cout << endl << I.what();
    getEventsAfter();
} catch (ios_base::failure &e) {
    cout  << endl << INVALID_INPUT_MSG;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getEventsAfter();
}

void utils::getEventsBefore() try {
    Data date;
    string name;
    vector<Evento> res;
    cout << INPUT_DATE_MSG;
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosAntesData(date);
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << endl << D.getDate().str() << D.getMsg();
    setToday();
} catch (InvalidTime &T) {
    cout << endl << T.getTime().str() << T.getMsg();
    getEventsBefore();
} catch (invalid_argument &I) {
    cout << endl << I.what();
    getEventsBefore();
} catch (ios_base::failure &e) {
    cout  << endl << INVALID_INPUT_MSG;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getEventsBefore();
}

void utils::getEventsToday() {
    string name;
    vector<Evento> res;
    // CHOOSE CINEMATECA
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->GetEventosHoje();
    for (const auto& event : res)
        cout << event.str() << endl;
}

void utils::getFutureEvents() {
    string name;
    vector<Evento> res;
    // CHOOSE CINEMATECA
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->GetEventosFuturos();
    for (const auto& event : res)
        cout << event.str() << endl;
}

void utils::getPastEvents() {
    string name;
    vector<Evento> res;
    // CHOOSE CINEMATECA
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    if (name == "CANCEL") return;
    res = findCinemateca(name)->GetEventosAntigos();
    for (const auto& event : res)
        cout << event.str() << endl;
}