#include "Utils.h"

void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "exit - exits the menu" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change present - change current date and time" << endl;
    cout << "add aderente - add a new aderente" << endl;
    cout << "reserve ticket - reserve a ticket to an event" << endl;
    cout << "get events on - print events on a given date" << endl;
    cout << "get events after - print events after a given date" << endl;
    cout << "get events before - print events before a given date" << endl;
    cout << "get events today - print today's events" << endl;
    cout << "get future events - print future events" << endl;
    cout << "get past events - print future events" << endl;
    cout << "get present - prints the current date and time" << endl;
    cout << "get aderentes - get aderentes for a given city" << endl;
    cout << "update event - alter a given event" << endl;
    cout << "remove event - remove a given event" << endl;
    cout << "remove aderente - remove a given aderente" << endl;
    cout << "find aderente - find a given aderente" << endl;
    cout << "update aderente - update a parameter in a specific aderente" << endl;
    cout << "add sala - add a new room" << endl;
    cout << "get salas - print rooms on the screen" << endl;
    cout << "find sala - finds a given room" << endl;
    cout << "update sala - update a parameter in a specific Sala" << endl;
    cout << "add trabalhador - add a new Trabalhador." << endl;
    cout << "update trabalhador - update a parameter in a specific Trabalahdor" << endl;
    cout << "fire trabalhador - fire a Trabalhador" << endl;
    cout << "get trabalhadores - prints the trabalhadores" << endl;
    cout << "Show Bst - prints the BST in a specific way" << endl;
    /*cout << "read file - reads a spefic file and adds what it needs to Cinemateca" << endl;*/
    cout << endl;
}

void utils::setToday() try{
    cout << INNPUT_TODAY_MSG;
    getline(cin, input);
    cout << endl;
    today.setDateAndTime(input);
    for(auto cinematec : cinemas){
        cinematec->MudarAgora(today);
    }
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
    string city;
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> input;
    if (input == "CANCEL") return;
    while (input != "Lisboa" && input != "Porto") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    city = input;
    if (constructEvent(temp) != 0) return;
    findCinemateca(city)->AdicionarEvento(temp);
} catch(Evento &e){
    cout << "EV: " << e.getName() << " already exists." << endl;
    return;
} catch(char const * errormsg) {
    cout << errormsg << endl;
    return;
} catch(ios_base::failure &e) {
    cout  << INVALID_INPUT_MSG << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

int utils::constructEvent(Evento &event) try {
    string room, name, inp;
    DataEHora start;
    Hora duration;
    int attn;
    float prc;
    // EVENT NAME
    cout << "Input event name: ";
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    cout << endl;
    name = input;
    if (name == "CANCEL") return 1;
    event.setName(name);
    // EVENT START
    cout << "Input event's start date and time (dd.mm.yyyy HHhMMmin): ";
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    cout << endl;
    if (input == "CANCEL") return 1;
    start.setDateAndTime(input);
    event.setStart(start);
    // EVENT LENGTH
    cout << "Input event's duration (HHhMMmin): ";
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    cout << endl;
    if (input == "CANCEL") return 1;
    duration.setTime(input);
    event.setDuration(duration);
    cout << "Input event's price of admittance: ";
    cin >> prc;
    event.setPrice(prc);
    cout << "Input event's maximum attendance: ";
    cin >> attn;
    cin.ignore(1000, '\n');
    event.setMaxAttendance(attn);
    if (attn > 0) {
        cout << "Input sala: ";
        while (cin.peek() == '\n') cin.ignore();
        getline(cin, input);
        event.setRoom(input);
    }
    return 0;
} catch (invalid_argument &I) {
    cout << I.what() << endl;
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
    if (name == "Porto") return cinemas[0];
    else if (name == "Lisboa") return cinemas[1];
    else return nullptr;
}

void utils::getEventsOn() try {
    Data date;
    string name;
    vector<Evento> res;
    cout << INPUT_DATE_MSG;
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    cout << "Choose cinemateca: ";
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosData(date);
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << D.getDate().str() << " " << D.getMsg() << endl;
    getEventsOn();
} catch (InvalidTime &T) {
    cout << T.getTime().str() << " " << T.getMsg() << endl;
    getEventsOn();
} catch (invalid_argument &I) {
    cout << I.what() << endl;
    getEventsOn();
} catch (ios_base::failure &e) {
    cout  << INVALID_INPUT_MSG << endl;
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
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    // CHOOSE CINEMATECA
    cout << "Choose cinemateca: ";
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosDepoisData(date);
    // PRINT
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << D.getDate().str() << " " << D.getMsg() << endl;
    getEventsAfter();
} catch (InvalidTime &T) {
    cout << T.getTime().str() << " " << T.getMsg() << endl;
    getEventsAfter();
} catch (invalid_argument &I) {
    cout << I.what() << endl;
    getEventsAfter();
} catch (ios_base::failure &e) {
    cout  << INVALID_INPUT_MSG << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getEventsAfter();
}

void utils::getEventsBefore() try {
    Data date;
    string name;
    vector<Evento> res;
    cout << INPUT_DATE_MSG;
    while (cin.peek() == '\n') cin.ignore();
    getline(cin, input);
    if (input == "CANCEL") return;
    date.setDate(input);
    cout << "Choose cinemateca: ";
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    if (name == "CANCEL") return;
    res = findCinemateca(name)->ProcurarEventosAntesData(date);
    for (const auto& event : res)
        cout << event.str() << endl;
} catch (InvalidDate &D) {
    cout << D.getDate().str() << " " << D.getMsg() << endl;
    getEventsBefore();
} catch (InvalidTime &T) {
    cout << T.getTime().str() << " " << T.getMsg() << endl;
    getEventsBefore();
} catch (invalid_argument &I) {
    cout << I.what() << endl;
    getEventsBefore();
} catch (ios_base::failure &e) {
    cout  << INVALID_INPUT_MSG << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getEventsBefore();
}

void utils::getEventsToday() {
    string name;
    vector<Evento> res;
    // CHOOSE CINEMATECA
    cout << "From which city do you want to get today's events?";
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
    cout << "From which city do you want the future events?";
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    if (name == "CANCEL") return;
    res = findCinemateca(name)->GetEventosFuturos();
    for (const auto& event : res)
        cout << event.str() << endl;
}

void utils::getPastEvents() {
    string name;
    vector<Evento> res;
    // CHOOSE CINEMATECA
    cout << "From which city do you want the past events?";
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

bool utils::validName(string num) {
    if (!((int(num[0]) <= 90) && (int(num[0])) >= 65)){
        cout << "First letter of name needs to be in caps.";
        return false;
    }
    for (int i = 0; i < num.size(); i++){
        if((int(num[i]) >= 48) && (int(num[i]) <= 57)) {
            cout << "No numbers allowed in name.";
            return false;
        }
    }
    return true;
}

string utils::inputName() {
    string f_name, s_name;
    while (true) {
        cout << "Input name: ";
        cin >> f_name >> s_name;
        if (!validName(f_name)) continue;
        if (!validName(s_name)) continue;
        break;
    }
    return (f_name + " " + s_name);
}

string utils::inputCity(bool aderentes) {
    string city;
    while (true) {
        cin.clear();
        if (aderentes) {
            cout << "Input city where person uses the Cinemateca facilities (If both, choose the most used): ";
        }
        else{
            cout << "Input city: ";
        }
        cin >> city;
        if ((city != "Porto") && (city != "Lisboa")){
            cout << "City needs to be either Lisboa or Porto.";
            continue;
        }
        break;
    }
    return city;
}

unsigned int utils::inputNIF() {
    string nif;
    while (true){
        cout << "Input NIF: ";
        cin >> nif;
        if (nif.size() != 9){
            cout << "NIF's size is 9.";
            continue;
        }
        bool valid = true;
        for (int i = 0; i < nif.size(); i++){
            if ((!((int(nif[i]) >= 48) && (int(nif[i]) <= 57))) && (valid == true)){
                cout << "NIF only has digits from 0 to 9.";
                valid = false;
            }
        }
        if(!valid) continue;
        break;
    }
    return stoul(nif);
}

unsigned int utils::inputCell() {
    string cell;
    while (true) {
        cout << "Input cellphone number: ";
        cin >> cell;
        if (cell.size() != 9){
            cout << "Cellphone number has 9 digits.";
            continue;
        }
        if (int(cell[0]) != 57){
            cout << "Cellphone number must start with a 9.";
            continue;
        }
        bool valid = true;
        for (int i = 0; i < cell.size(); i++){
            if ((!((int(cell[i]) >= 48) && (int(cell[i]) <= 57))) && (valid == true)){
                cout << "Cellphone number only has digits from 0 to 9.";
                valid = false;
            }
        }
        if(!valid) continue;
        break;
    }
    return stoul(cell);
}

void utils::addAderente() {
    string name, city, date;
    unsigned int nif, cell;
    name = inputName();
    nif = inputNIF();
    city = inputCity();
    cell = inputCell();
    int day, month, year;
    while (true){
        cout << "Input birthday (dd/mm/yyy): ";
        cin >> date;
        regex matchStr("[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]");
        if(!(regex_match(date, matchStr))){
            cout << "Invalid date.";
            continue;
        }
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));
        if ((day == 0) || (month == 0) || (year == 0)){
            cout << "Invalid Date.";
            continue;
        }
        int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
        if (month < 1 || month > 12 || year < 0){
            cout << "Invalid Date.";
            continue;
        }
        else if (year % 4 == 0 && month == 2)
            if(!(day > 0 && day < 30)){
                cout << "Invalid Date.";
                continue;
            }
        else if (month == 2)
            if(!(day > 0 && day < 29)){
                cout << "Invalid Date.";
                continue;
            }
        else if (find(longMonths, longMonths + 7, month))
            if(!(day > 0 && day < 32)){
                cout << "Invalid Date.";
                continue;
            }
        else if (!find(longMonths, longMonths + 7, month))
            if(!(day > 0 && day < 31)){
                cout << "Invalid Date.";
                continue;
            }
        break;
    }
    Data d1(day, month, year);
    Aderente a1(name, city, cell, nif, d1, today.getYear());
    try{
        findCinemateca(city)->AdicionarAderente(a1);
    } catch (Aderente &ad){
        cout << "Aderente with NIF = " << nif << " already exists with info:" << endl;
        cout << "Name: " << ad.getName() << ", Cell: " << ad.getCell() << endl << "NIF: " << ad.getNIF()
             << ", Birthday: " << ad.getBirthday().getDay() << "/" << ad.getBirthday().getMonth() << "/"
             << ad.getBirthday().getYear() << endl << "Adhesion year: " << ad.getAdhYear() << ", City: Porto"
             << endl << "Money saved: " << ad.getSavedMoney() << "eur." << endl;
        return;
    }
}

void utils::getAderentes() {
    string city, sort;
    bool sor = false;
    while(true){
        cout << "Do you want the Aderentes sorted? (y/n):";
        cin >> sort;
        if (sort == "y") {
            sor = true;
            break;
        }
        else if (sort == "n") break;
        else {
            cout << "Invalid input.";
            continue;
        }
    }
    while(true){
        cout << "Do you want to get Aderentes from Porto, Lisboa or both?";
        cin >> city;
        if (city == "Porto"){
            if (sor) {
                findCinemateca("Porto")->SortAderentes();
            }
            vector<Aderente>aderentes_p = findCinemateca("Porto")->GetAderentes();
            for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                    << ", Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                    << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << ", Money saved: "
                    << it->getSavedMoney() << "eur." << endl << endl;
            }
        }
        else if (city == "Lisboa"){
            if (sor) {
                findCinemateca("Lisboa")->SortAderentes();
            }
            vector<Aderente>aderentes_l = findCinemateca("Lisboa")->GetAderentes();
            for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "eur." << endl << endl;
            }
        }
        else if (city == "both"){
            if (sor) {
                findCinemateca("Porto")->SortAderentes();
                findCinemateca("Lisboa")->SortAderentes();
            }
            vector<Aderente>aderentes_p = findCinemateca("Porto")->GetAderentes();
            vector<Aderente>aderentes_l = findCinemateca("Lisboa")->GetAderentes();
            cout << "Porto:" << endl;
            for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "eur." << endl << endl;
            }
            cout << "Lisboa: " << endl;
            for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "eur." << endl << endl;
            }
        }
        else{
            cout << "Invalid input.";
            continue;
        }
        break;
    }
}

void utils::removeAderente() {
    unsigned int NIF;
    while (true) {
        bool again = false;
        NIF = inputNIF();
        vector<Aderente> aderentes_p = findCinemateca("Porto")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++) {
            if (it->getNIF() == NIF) {
                aderentes_p.erase(it);
                findCinemateca("Porto")->SetAderentes(aderentes_p);
                return;
            }
        }
        vector<Aderente> aderentes_l = findCinemateca("Lisboa")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++) {
            if (it->getNIF() == NIF) {
                aderentes_l.erase(it);
                findCinemateca("Lisboa")->SetAderentes(aderentes_l);
                return;
            }
        }
        string answer;
        while (true) {
            cout << "No Aderente with that NIF found. Write 'CANCEL' to leave or 'again' to try again: ";
            cin >> answer;
            if (answer == "CANCEL") return;
            else if (answer == "again") {
                again = true;
                break;
            } else {
                cout << "Invalid input." << endl;
                continue;
            }
        }
        if (again) continue;
        break;
    }
}

void utils::findAderente() {
    unsigned int NIF;
    while (true) {
        bool again = false;
        NIF = inputNIF();
        vector<Aderente> aderentes_p = findCinemateca("Porto")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++) {
            if (it->getNIF() == NIF) {
                cout << "Name: " << it->getName() << ", Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << ", Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << ", City: Porto"
                     << endl << "Money saved: " << it->getSavedMoney() << "eur." << endl;
                return;
            }
        }
        vector<Aderente> aderentes_l = findCinemateca("Lisboa")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++) {
            if (it->getNIF() == NIF) {
                cout << "Name: " << it->getName() << ", Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << ", Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << ", City: Lisboa"
                     << endl << "Money saved: "<< it->getSavedMoney() << "eur." << endl;
                return;
            }
        }
        string answer;
        while (true) {
            cout << "No Aderente with that NIF found. Write 'CANCEL' to leave or 'again' to try again: ";
            cin >> answer;
            if (answer == "CANCEL") return;
            else if (answer == "again") {
                again = true;
                break;
            } else {
                cout << "Invalid input." << endl;
                continue;
            }
        }
        if (again) continue;
        break;
    }
}

void utils::updateAderente() {
    string city;
    unsigned int NIF;
    Aderente *p1;
    vector<Aderente> *aderentes;
    while (true) {
        bool again = false, found = false;
        NIF = inputNIF();
        vector<Aderente> aderentes_p = findCinemateca("Porto")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++) {
            if (it->getNIF() == NIF) {
                aderentes = &aderentes_p;
                p1 = &(*it);
                found = true;
                city = "Porto";
                break;
            }
        }
        if (!found) {
            vector<Aderente> aderentes_l = findCinemateca("Lisboa")->GetAderentes();
            for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++) {
                if (it->getNIF() == NIF) {
                    aderentes = &aderentes_l;
                    p1 = &(*it);
                    city = "Lisboa";
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
        string answer;
        while (true) {
            cout << "No Aderente with that NIF found. Write 'CANCEL' to leave or 'again' to try again: ";
            cin >> answer;
            if (answer == "CANCEL") return;
            else if (answer == "again") {
                again = true;
                break;
            } else {
                cout << "Invalid input." << endl;
                continue;
            }
        }
        if (again) continue;
        break;
    }
    string atribute;
    while(true){
        cout << "Which atribute do you want to change?";
        cin >> atribute;
        if (atribute == "name"){
            string n_name = inputName();
            (*p1).updateName(n_name);
            findCinemateca(city)->SetAderentes(*aderentes);
            cout << "Aderente updated";
            return;
        }
        else if (atribute == "city"){
            string n_city = inputCity(false);
            if (n_city == (*p1).getCity()){
                cout << "City was already " << n_city << ", so no changes were made.";
                return;
            }
            vector<Aderente>ads;
            if(n_city == "Porto"){
                ads = findCinemateca("Lisboa")->GetAderentes();
                for(vector<Aderente>::iterator it = ads.begin(); it != ads.end(); it++){
                    if (it->getNIF() == NIF){
                        ads.erase(it);
                        findCinemateca("Lisboa")->SetAderentes(ads);
                        break;
                    }
                }
            }
            else {
                ads = findCinemateca("Porto")->GetAderentes();
                for (vector<Aderente>::iterator it = ads.begin(); it != ads.end(); it++) {
                    if (it->getNIF() == NIF) {
                        ads.erase(it);
                        findCinemateca("Porto")->SetAderentes(ads);
                        break;
                    }
                }
            }
            ads = findCinemateca(n_city)->GetAderentes();
            ads.push_back(*p1);
            findCinemateca(n_city)->SetAderentes(ads);
            cout << "Aderente updated.";
            return;
        }
        else if (atribute == "cellphone"){
            unsigned int cell = inputCell();
            (*p1).updateCell(cell);
            findCinemateca(city)->SetAderentes(*aderentes);
            cout << "Aderente updated.";
            return;
        }
        else if ((atribute == "NIF") || (atribute == "nif") || (atribute == "birthday") || (atribute == "adhesion year")
            || (atribute == "saved money")){
            cout << "Those atributes cannot be changed. They are unique to a person.";
            return;
        }
        else{
            cout << "Invalid input." << endl << "The only atributes to be changed are: 'name', 'city' or 'cellphone'."
            << endl;
        }
        while(true){
            string answer;
            cout << "If you want to try and change another, input 'again', else input 'CANCEL': ";
            cin >> answer;
            if (answer == "again"){
                break;
            }
            else if (answer == "CANCEL"){
                return;
            }
            else{
                cout << "Invalid input.";
            }
        }
    }
}

string utils::inputSalaName() {
    string name;
    while(true) {
        cin.clear();
        cin.ignore();
        cout << "What's the Sala's name?";
        getline(cin, name);
        bool valid = true;
        for (int i = 0; i < name.size(); i++) {
            if ((((int(name[i]) >= 48) && (int(name[i]) <= 57))) && (valid == true)) {
                cout << "Numbers aren't allowed in the name.";
                valid = false;
            }
        }
        if (!valid) continue;
        break;
    }
    return name;
}

void utils::addSala() {
    string city, name, cap;
    city = inputCity(false);
    name = inputSalaName();
    while(true){
        cin.clear();
        cout << "What is its capacity?";
        cin >> cap;
        bool valid = true;
        for (int i = 0; i < cap.size(); i++){
            if ((!((int(cap[i]) >= 48) && (int(cap[i]) <= 57))) && (valid == true)){
                cout << "The capacity can only have digits, not other characters.";
                valid = false;
            }
        }
        if(!valid) continue;
        break;
    }
    try{
        Sala s1(name, stoi(cap));
        findCinemateca(city)->AdicionarSala(s1);
    } catch (Sala sal){
        cout << "Sala with name: " << sal.getName() << " and capacity: " << sal.getCapacity() << " already exists.";
        return;
    }
}

void utils::getSalas() {
    string city, sort;
    bool sor = false;
    while(true){
        cout << "Do you want the Salas sorted? (y/n):";
        cin >> sort;
        if (sort == "y") {
            sor = true;
            break;
        }
        else if (sort == "n") break;
        else {
            cout << "Invalid input.";
            continue;
        }
    }
    while(true) {
        cout << "Do you want to get Salas from Porto, Lisboa or both?";
        cin >> city;
        if (city == "Porto"){
            if (sor){
                findCinemateca("Porto")->SortSalas();
            }
            vector<Sala>sP = findCinemateca("Porto")->Getsalas();
            for(vector<Sala>::iterator it = sP.begin(); it != sP.end(); it++){
                cout << "Name: " << (*it).getName() << ", " << "Capacity: " << (*it).getCapacity() << endl;
            }
            break;
        }
        else if (city == "Lisboa"){
            if (sor){
                findCinemateca("Lisboa")->SortSalas();
            }
            vector<Sala>sL = findCinemateca("Lisboa")->Getsalas();
            for(vector<Sala>::iterator it = sL.begin(); it != sL.end(); it++){
                cout << "Name: " << (*it).getName() << ", " << "Capacity: " << (*it).getCapacity() << endl;
            }
            break;
        }
        else if (city == "both"){
            if (sor){
                findCinemateca("Porto")->SortSalas();
                findCinemateca("Lisboa")->SortSalas();
            }
            vector<Sala>sP = findCinemateca("Porto")->Getsalas();
            vector<Sala>sL = findCinemateca("Lisboa")->Getsalas();
            cout << "Porto: " << endl;
            for(vector<Sala>::iterator it = sP.begin(); it != sP.end(); it++){
                cout << "Name: " << (*it).getName() << ", " << "Capacity: " << (*it).getCapacity() << endl;
            }
            cout << "Lisboa: " << endl;
            for(vector<Sala>::iterator it = sL.begin(); it != sL.end(); it++){
                cout << "Name: " << (*it).getName() << ", " << "Capacity: " << (*it).getCapacity() << endl;
            }
            break;
        }
    }
}

void utils::findSala() {
    string city, name;
    while(true) {
        city = inputCity(false);
        name = inputSalaName();
        vector<Sala> salas = findCinemateca(city)->Getsalas();
        for (vector<Sala>::iterator it = salas.begin(); it != salas.end(); it++) {
            if ((*it).getName() == name) {
                cout << "Sala found:" << endl << "Name: " << (*it).getName() << ", Capacity: " << (*it).getCapacity();
                return;
            }
        }
        string answer;
        while(true){
            cout << "No Sala with that name. Input 'again' to try again or 'CANCEL' to leave: ";
            cin >> answer;
            if (answer == "CANCEL") return;
            else if (answer == "again") {
                break;
            } else {
                cout << "Invalid input." << endl;
                continue;
            }
        }
    }
}

void utils::updateSala() {
    string city, name;
    bool sala_found = false;
    vector<Sala> salas;
    Sala *s;
    while(true) {
        city = inputCity(false);
        name = inputSalaName();
        salas = findCinemateca(city)->Getsalas();
        for (vector<Sala>::iterator it = salas.begin(); it != salas.end(); it++) {
            if ((*it).getName() == name) {
                sala_found = true;
                s = &(*it);
            }
        }
        if(sala_found) break;
        bool again = false;
        string answer;
        while(true) {
            cout << "Sala wasn't found. To try again, input 'again', else input 'CANCEL': ";
            cin >> answer;
            if (answer == "again"){
                again = true;
                break;
            }
            else if (answer == "CANCEL"){
                return;
            }
            else{
                cout << "Invalid input.";
            }
        }
        if(again) continue;
        break;
    }
    string atribute;
    while (true){
        cout << "Do you want to change Sala's name or capacity?";
        cin >> atribute;
        if (atribute == "name"){
            string new_name;
            new_name = inputSalaName();
            (*s).updateSalaName(new_name);
            findCinemateca(city)->SetSalas(salas);
            cout << "Sala updated.";
            return;
        }
        else if (atribute == "capacity"){
            string cap;
            while(true){
                cout << "What is its capacity?";
                cin >> cap;
                bool valid_c = true;
                for (int i = 0; i < cap.size(); i++){
                    if ((!((int(cap[i]) >= 48) && (int(cap[i]) <= 57))) && (valid_c == true)){
                        cout << "The capacity can only have digits, not other characters.";
                        valid_c = false;
                    }
                }
                if(!valid_c) continue;
                break;
            }
            (*s).updateSalaCap(stoi(cap));
            findCinemateca(city)->SetSalas(salas);
            cout << "Sala updated.";
            return;
        }
        else{
            cout << "Invalid input.";
            continue;
        }
    }

}

void utils::buyTicket() {
    string city, answer;
    city = inputCity(false);
    vector<Evento>future = findCinemateca(city)->GetEventosFuturos();
    if (future.empty()){
        cout << "There are no scheduled events for the future in " << city << ".";
        return;
    }
    cout << "These are the next events to happen in " << city << ":" << endl;
    for(int i = 0; i < future.size(); i++){
        cout << future[i].getName() << " with " << future[i].getLot() << "/" << future[i].getMaxAttendance() <<
            " people and it costs " << future[i].getPrice() << "eur." << endl;
    }
    bool valid = true, found = false;
    unsigned int NIF;
    string nif;
    Evento *ev;
    while(true) {
        cout << "If you're interested in any, write the name, else write 'CANCEL': ";
        while (cin.peek() == '\n') cin.ignore();
        getline(cin, answer);
        if(answer == "CANCEL") return;
        for (vector<Evento>::iterator it = future.begin(); it != future.end(); it++){
            if ((*it).getName() == answer){
                found = true;
                ev = &(*it);
                if ((*it).getLot() < (*it).getMaxAttendance()){
                    while (true){
                        cout << "Are you an Aderente or not (y/n)?";
                        cin >> answer;
                        if (answer == "y"){
                            bool valid_ad = false;
                            while (true) {
                                NIF = inputNIF();
                                vector<Aderente> ads = findCinemateca(city)->GetAderentes();
                                bool valid_ad = false;
                                for (vector<Aderente>::iterator it = ads.begin(); it != ads.end(); it++) {
                                    if (it->getNIF() == NIF) {
                                        valid_ad = true;
                                        ev ->signUp(*it);
                                        findCinemateca(city)->SetAderentes(ads);
                                        vector<Evento>past = findCinemateca(city)->GetEventosAntigos();
                                        vector<Evento>now = findCinemateca(city)->GetEventosHoje();
                                        for (auto ev: past){
                                            future.push_back(ev);
                                        }
                                        for (auto ev: now){
                                            future.push_back(ev);
                                        }
                                        findCinemateca(city)->SetEventos(future);
                                        cout << "There's a reserved ticket in your name for "
                                        << ev->getPrice() * (1 - 0.01 * (today.getYear() - (*it).getAdhYear()))
                                        << "eur, already with your discount.";
                                        return;
                                    }
                                }
                                if(!valid_ad){
                                    string choice;
                                    while(true) {
                                        cout << "There isn't an Aderente with that NIF registered." << endl <<
                                             "You can write 'CANCEL' to leave and then create an Aderente and comeback or "
                                             "write'Cliente' to buy it without being one." << endl << "Input: ";
                                        cin >> choice;
                                        if (choice == "Cliente"){
                                            answer = "n";
                                            break;
                                        }
                                        else if(choice == "CANCEL"){
                                            return;
                                        }
                                        else{
                                            cout << "Invalid input";
                                            continue;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        if (answer == "n"){
                            cout << "To reserve the ticket, you need to input some information." << endl;
                            string name;
                            unsigned int cell;
                            name = inputName();
                            cell = inputCell();
                            Cliente c1(name, city, cell);
                            ev->signUp(c1);
                            vector<Evento>past = findCinemateca(city)->GetEventosAntigos();
                            vector<Evento>now = findCinemateca(city)->GetEventosHoje();
                            for (auto ev: past){
                                future.push_back(ev);
                            }
                            for (auto ev: now){
                                future.push_back(ev);
                            }
                            findCinemateca(city)->SetEventos(future);
                            cout << "There's a reserved ticket in your name for " << ev->getPrice() << "eur.";
                            return;
                        }
                        if ((answer != "y") && (answer != "n")){
                            cout << "Answer y or n.";
                            continue;
                        }
                    }

                }
                else{
                    cout << "The event is already completely booked.";
                    valid = false;
                }
            }
        }
        if (!found){
            cout << "Invalid name." << endl;
            valid = false;
        }
        if (!valid) continue;
        break;
    }
}
/*
void utils::readfile() {
    std::string city, filepath, typetoread;
    while (true){
        std::cout << "Please input the city: ";
        std::cin >> city;
        if((city == "Porto") || (city == "Lisboa")){
            break;
        }
        else{
            std::cout << "That's not a valid city name, please try again" << std::endl;
            cin.clear();
            city = "";
        }
    }
    while(true){
        std::cout << "Please input the file path: ";
        std::cin >> filepath;
        if(filepath.substr(filepath.length() - 4) == ".txt"){
            break;
        }
        else{
            std::cout << "That's not a valid file path please try again" << std::endl;
            cin.clear();
            filepath = "";
        }
    }
    while (true){
        std::cout << "Please input the type of data to read: ";
        std::cin >> typetoread;
        if((typetoread == "event") || (typetoread == "sala") || (typetoread == "aderente")){
            break;
        }
        else{
            std::cout << "That's not a valid type of data, the options are event, sala or aderente" << std::endl;
            cin.clear();
            typetoread = "";
        }
    }
    if(typetoread == "event"){
        try{
            findCinemateca(city)->LerFicheiroEventos(filepath);
        } catch (std::string &filepat) {
            cout << COULDNT_OPEN_FILE << filepat << std::endl;
        }
    }
    if(typetoread == "sala"){
        try{
            findCinemateca(city)->LerFicheiroSalas(filepath);
        } catch (std::string &filepat) {
            cout << COULDNT_OPEN_FILE << filepat << std::endl;
        }
    }
    if(typetoread == "aderente"){
        try{
            findCinemateca(city)->LerFicheiroAderentes(filepath);
        } catch (std::string &filepat) {
            cout << COULDNT_OPEN_FILE << filepat << std::endl;
        }
    }
}
*/

void utils::avisarAderentes() {
    std::vector<Aderente> AdersM65;
    Data Ha65anos(today.getDay(), today.getMonth(), today.getYear() - 65);
    for(const auto& Ader : cinemas[0]->GetAderentes()){
        if(Ader.getBirthday() < Ha65anos){
            AdersM65.push_back(Ader);
        }
    }
    if(AdersM65.empty()){
        std::cout << "Looks like there's no one that can get a free event " << std::endl;
        return;
    }

    std::vector<Evento> EventsProx8h;
    DataEHora DaquiA8h(today.getDay(), today.getMonth(), today.getYear(), today.getHour() + 8, today.getMinute());
    for(const auto& event : cinemas[0]->GetEventosHoje()){
        if(event.getStart() < DaquiA8h){
            if(((event.getLot()/event.getMaxAttendance()) * 100) < 50){
                EventsProx8h.push_back(event);
            }
        }
    }
    if(EventsProx8h.empty()){
        std::cout << "Looks like there's no events in the next 8 hours" << std::endl;
        return;
    }

    srand(time(NULL) );
    int randomnoofader = rand() % AdersM65.size(), cont = 0;

    for(auto event : EventsProx8h){
        for(auto Ader : AdersM65){
            if(randomnoofader > (AdersM65.size() / 2)){
                if(((event.getLot()/event.getMaxAttendance()) * 100) < 50){
                    event.signUp(Ader, true);
                    cont++;
                }
                else{
                    break;
                }
            }
            randomnoofader = rand() % AdersM65.size();
        }
        std::cout << cont << " person/people over 65 accept the free invite promoted by the CM Porto "
                             "for the following event : " << event.str() << std::endl;
        cont = 0;
    }

    //inputting changes to Cinemateca;
    for(const auto& even : cinemas[0]->GetEventosAntigos()){
        EventsProx8h.push_back(even);
    }
    for(const auto& even : cinemas[0]->GetEventosFuturos()){
        EventsProx8h.push_back(even);
    }
    bool add = true;
    for(const auto& even1 : cinemas[0]->GetEventosHoje()){
        for(const auto& even2 : EventsProx8h){
            if(even1.getName() == even2.getName()){
                add = false;
            }
        }
        if(add){
            EventsProx8h.push_back(even1);
        }
    }
    cinemas[0]->SetEventos(EventsProx8h);
}

void utils::removeEvent() try {
    string name, eventName, eventStart;
    DataEHora eventStartTime;
    vector<Evento> bef, now, af, res;
    int index = -1;
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    cout << "Input event name: ";
    getline(cin, eventName);
    cout << "Input event start date and time (dd.mm.yyyy HHhMMmin): ";
    getline(cin, eventStart);
    eventStartTime.setDateAndTime(eventStart);
    bef = findCinemateca(name)->GetEventosAntigos();
    now = findCinemateca(name)->GetEventosHoje();
    af = findCinemateca(name)->GetEventosFuturos();
    res.insert(res.end(), bef.begin(), bef.end());
    res.insert(res.end(), now.begin(), now.end());
    res.insert(res.end(), af.begin(), af.end());
    for (int i = 0; i < res.size(); i++)
        if (res[i].getName() == eventName && res[i].getStart() == eventStartTime)
            index = i;
    if (index == -1) {
        cout << "Event does not exist\n";
        return;
    }
    res.erase(res.begin()+index);
    findCinemateca(name)->SetEventos(res);
} catch (...) {cout << "An unexpected error occurred.\n"; return;}

void utils::updateEvent() try {
    string name, eventName, eventStart;
    DataEHora eventStartTime;
    vector<Evento> bef, now, af, res;
    Evento newEvent;
    int index = -1;
    cout << CHOOSE_CINEMATECA_MSG;
    cin >> name;
    while (name != "Lisboa" && name != "Porto" && name != "CANCEL") {
        cout << "There are only 'Lisboa' and 'Porto'. " << CHOOSE_CINEMATECA_MSG;
        cin >> input;
    }
    cin.ignore(1000, '\n');
    cout << "Input event name: ";
    getline(cin, eventName);
    cout << "Input event start date and time (dd.mm.yyyy HHhMMmin): ";
    getline(cin, eventStart);
    eventStartTime.setDateAndTime(eventStart);
    bef = findCinemateca(name)->GetEventosAntigos();
    now = findCinemateca(name)->GetEventosHoje();
    af = findCinemateca(name)->GetEventosFuturos();
    res.insert(res.end(), bef.begin(), bef.end());
    res.insert(res.end(), now.begin(), now.end());
    res.insert(res.end(), af.begin(), af.end());
    for (int i = 0; i < res.size(); i++)
        if (res[i].getName() == eventName && res[i].getStart() == eventStartTime)
            index = i;
    if (index == -1) {
        cout << "Event does not exist\n";
        return;
    }
    cout << "Currently the event reads: " << res[index].str() << endl;
    constructEvent(newEvent);
    res[index] = newEvent;
    findCinemateca(name)->SetEventos(res);
} catch (...) {cout << "An unexpected error occurred."; return;}

void utils::addTrabalhador() {
    string city, name, date;
    unsigned int NIF;

    TrabH temp = findCinemateca("Porto")->getHash();

    Trabalhador t("", NIF, "", Data(0, 0, 0), true);

    for(auto trab : temp){
        if (trab == t){
            t = trab;
            break;
        }
    }

    if (t.getName() != ""){
        while(true){
            string answer;
            cout << "Trabalhador with that NIF already exists." << endl <<
            "Do you want to rehire or to type the NIF again? (Rehire/NIF)";
            cin >> answer;

            if (answer == "Rehire" || answer == "rehire"){
                findCinemateca("Porto")->RemoveFromHash(t);
                t.updateWorkStatus(true);
                findCinemateca(("Porto"))->AddToHash(t);
                return;
            }
            else if (answer == "NIF" || answer == "nif"){
                break;
            }
            else{
                cout << "Invalid Input." << endl;
                continue;
            }
        }
    }

    int day, month, year;
    name = inputName();
    city = inputCity(false);
    NIF = inputNIF();
    while (true){
        cout << "Input birthday (dd/mm/yyy): ";
        cin >> date;
        regex matchStr("[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]");
        if(!(regex_match(date, matchStr))){
            cout << "Invalid date.";
            continue;
        }
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));
        if ((day == 0) || (month == 0) || (year == 0)){
            cout << "Invalid Date.";
            continue;
        }
        int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
        if (month < 1 || month > 12 || year < 0){
            cout << "Invalid Date.";
            continue;
        }
        else if (year % 4 == 0 && month == 2)
            if(!(day > 0 && day < 30)){
                cout << "Invalid Date.";
                continue;
            }
            else if (month == 2)
                if(!(day > 0 && day < 29)){
                    cout << "Invalid Date.";
                    continue;
                }
                else if (find(longMonths, longMonths + 7, month))
                    if(!(day > 0 && day < 32)){
                        cout << "Invalid Date.";
                        continue;
                    }
                    else if (!find(longMonths, longMonths + 7, month))
                        if(!(day > 0 && day < 31)){
                            cout << "Invalid Date.";
                            continue;
                        }
        break;
    }
    Trabalhador t1(name, NIF, city, Data(day, month, year), true);
    if (!(findCinemateca("Porto")->AddToHash(t1))){
        cout << "Trabalhador with that NIF already existed." << endl;
    }
}

void utils::changeTrabalhador() {
    unsigned int NIF;

    NIF = inputNIF();

    TrabH temp = findCinemateca("Porto")->getHash();
    Trabalhador t("", NIF, "", Data(0, 0, 0), true);

    for(auto trab : temp){
        if (trab == t){
            t = trab;
            break;
        }
    }

    if(t.getName() == ""){
        cout << "There is no Trabalahdor with that NIF." << endl;
    }
    else{
        while(true) {
            string atribute;
            cout << "Which atribute do you want to change? ";
            cin >> atribute;
            if (atribute == "Name" || atribute == "name") {
                findCinemateca("Porto")->RemoveFromHash(t);
                string new_name = inputName();
                t.updateName(new_name);
                findCinemateca(("Porto"))->AddToHash(t);
                return;
            } else if (atribute == "City" || atribute == "city") {
                findCinemateca("Porto")->RemoveFromHash(t);
                string city = inputCity(false);
                t.updateCity(city);
                findCinemateca(("Porto"))->AddToHash(t);
                return;
            } else {
                cout << "Invalid input." << endl;
            }
            while (true) {
                string answer;
                cout << "If you want to try and change another, input 'again', else input 'CANCEL': ";
                cin >> answer;
                if (answer == "again") {
                    break;
                } else if (answer == "CANCEL") {
                    return;
                } else {
                    cout << "Invalid input.";
                }
            }
        }
    }
}

void utils::fireTrabalhador() {
    unsigned int NIF;
    while(true) {
        TrabH temp = findCinemateca("Porto")->getHash();
        Trabalhador t("", NIF, "", Data(0, 0, 0), true);

        for(auto trab : temp){
            if (trab == t){
                t = trab;
                break;
            }
        }

        if (t.getName() != "") {
            findCinemateca("Porto")->RemoveFromHash(t);
            t.updateWorkStatus(true);
            findCinemateca(("Porto"))->AddToHash(t);
            return;
        } else {
            cout << "Worker with that NIF does not exist." << endl;
            while (true) {
                string answer;
                cout << "If you want to try and change another, input 'again', else input 'CANCEL': ";
                cin >> answer;
                if (answer == "again") {
                    break;
                } else if (answer == "CANCEL") {
                    return;
                } else {
                    cout << "Invalid input.";
                }
            }
        }
    }
}

void utils::getTrabalhadores() {
    bool all;

    while (true) {
        string answer;
        cout << "Do you want the Trabalhadores currently working or all of them (All/Current)? ";
        cin >> answer;
        if (answer == "All" || answer == "all"){
            all = true;
            break;
        }
        else if (answer == "Current" || answer == "current"){
            all = false;
            break;
        }
        else{
            cout << "Invalid Input." << endl;
        }
        while(true){
            string answer;
            cout << "If you want to try and change another, input 'again', else input 'CANCEL': ";
            cin >> answer;
            if (answer == "again"){
                break;
            }
            else if (answer == "CANCEL"){
                return;
            }
            else{
                cout << "Invalid input.";
            }
        }
    }

    string city;
    while(true){
        cout << "Do you want to get the Trabalhadores from 'Lisboa', 'Porto' or 'both'? ";
        cin >> city;
        if (city != "Lisboa" && city != "Porto" && city != "both"){
            while(true) {
                string answer;
                cout << "If you want to try and change another, input 'again', else input 'CANCEL': ";
                cin >> answer;
                if (answer == "again") {
                    break;
                } else if (answer == "CANCEL") {
                    return;
                } else {
                    cout << "Invalid input.";
                }
            }
        }
        else{
            break;
        }
    }

    TrabH temp = findCinemateca("Porto")->getHash();
    
    for(auto trab : temp){
        if (city != "both"){
            if(trab.getCity() == city) {
                if (all) {
                    cout << "Name: " << trab.getName() << ", " << "NIF: " << trab.getNIF() << endl << "Birthday: " <<
                         trab.getBirthday().getDay() << "/" << trab.getBirthday().getMonth() << "/" <<
                         trab.getBirthday().getYear();
                    if (trab.getWorkingStatus()) {
                        cout << ", Working: true" << trab.getWorkingStatus() << endl << endl;
                    } else {
                        cout << ", Working: false" << trab.getWorkingStatus() << endl << endl;
                    }
                }
            }
            else{
                if (trab.getWorkingStatus()){
                    cout << "Name: " << trab.getName() << ", " << "NIF: " << trab.getNIF() << endl << "Birthday: " <<
                     trab.getBirthday().getDay() << "/" << trab.getBirthday().getMonth() << "/" <<
                     trab.getBirthday().getYear() << ", Working: true" << endl << endl;
                }
            }
        }
        else{
            if (all) {
                cout << "Name: " << trab.getName() << ", " << "NIF: " << trab.getNIF() << endl << "Birthday: " <<
                     trab.getBirthday().getDay() << "/" << trab.getBirthday().getMonth() << "/" <<
                     trab.getBirthday().getYear() << ", Working: ";
                if(trab.getWorkingStatus()){
                    cout << "true";
                }
                else{
                    cout << "false";
                }
                cout << endl << "City: " << trab.getCity() << endl << endl;
            }
            else{
                if(trab.getWorkingStatus()){
                    cout << "Name: " << trab.getName() << ", " << "NIF: " << trab.getNIF() << endl << "Birthday: " <<
                         trab.getBirthday().getDay() << "/" << trab.getBirthday().getMonth() << "/" <<
                         trab.getBirthday().getYear() << ", Working: true" << endl << "City: " <<
                         trab.getCity() << endl << endl;
                }
            }
        }
    }
}

void utils::getTopEvent() {
    string name;
    cin >> name;
    if(name != "Porto" && name != "Lisboa") return;
    findCinemateca(name)->createEventHeap();
    cout << endl << findCinemateca(name)->getTopEvent().str() << endl;
}

void utils::getTopEventBetween() try {
    string name;
    float min, max;
    cin >> name >> min >> max;
    if(name != "Porto" && name != "Lisboa") return;
    findCinemateca(name)->createEventHeap();
    cout << endl << findCinemateca(name)->getTopEventByPrice(min, max).str() << endl;
} catch(NoEventPricedBetween &N) {
    cout << "There are no events priced between " << N.getPriceRange().first << " and " << N.getPriceRange().second << endl;
}

void utils::ShowBst() {
    string city;
    do{
        city = "";
        cout << endl << "Please input the city of your choice: ";
        cin >> city;
        if(city != "Porto" && city != "Lisboa"){
            cout << "That's not a valid city, please try again \n"
                    "(type CANCEL to go to the previous menu)" << endl;
        }
        if(city == "CANCEL") return;
        cin.ignore();

    }while(city != "Porto" && city != "Lisboa");

    auto BstEventosAder = cinemas[0]->getBst();
    if(city == "Porto") {
        cinemas[0]->BstGenerateBstFromEvents();
        BstEventosAder = cinemas[0]->getBst();
    }
    if(city == "Lisboa"){
        cinemas[1]->BstGenerateBstFromEvents();
        BstEventosAder = cinemas[1]->getBst();
    }

    string showorder;
    do{
        showorder = "";
        cout << endl << "How would you like to see the BST? \n"
                        "InOrder PostOrder PreOrder: ";
        cin >> showorder;
        if(showorder != "InOrder" && showorder != "PostOrder" && showorder != "PreOrder"){
            cout << "That's not a valid way to traverse a BST!";
        }
        cin.ignore();
    }while(showorder != "InOrder" && showorder != "PostOrder" && showorder != "PreOrder");


    if(showorder == "InOrder"){
        BSTItrIn<EventoAux> BstItr_InOrder(BstEventosAder);
        while( !BstItr_InOrder.isAtEnd()){
            cout << (&BstItr_InOrder)->retrieve().Event.str() << endl ;
            BstItr_InOrder.advance();
        }
    }
    if(showorder == "PostOrder"){
        BSTItrPost<EventoAux> BstItr_PostOrder(BstEventosAder);
        while( !BstItr_PostOrder.isAtEnd()){
            cout << (&BstItr_PostOrder)->retrieve().Event.str() << endl ;
            BstItr_PostOrder.advance();
        }
    }
    if(showorder == "PreOrder"){
        BSTItrPre<EventoAux> BstItr_PreOrder(BstEventosAder);
        while( !BstItr_PreOrder.isAtEnd()){
            cout << (&BstItr_PreOrder)->retrieve().Event.str() << endl ;
            BstItr_PreOrder.advance();
        }
    }
    cout << endl;
}
