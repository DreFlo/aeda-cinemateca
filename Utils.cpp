#include "Utils.h"

// IMPLEMENTEM OUTRAS CENAS A VONTADE. PLS ADICIONEM OS COMANDOS NO MAIN E NO PRINT HELP.


void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change present - change current date and time" << endl;
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

void utils::addAderente() {
    string f_name, s_name, city, cell, nif, date;
    while (true) {
        cout << "Input name: ";
        cin >> f_name >> s_name;
        if (!validName(f_name)) continue;
        if (!validName(s_name)) continue;
        break;
    }
    while (true) {
        cout << "Input city where person uses the Cinemateca facilities (If both, choose the most used): ";
        cin >> city;
        if ((city != "Porto") && (city != "Lisboa")){
            cout << "City needs to be either Lisboa or Porto.";
            continue;
        }
        break;
    }
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
    int day, month, year;
    while (true){
        cout << "Input birthday (dd mm yyyy): ";
        cin >> day >> month >> year;
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
    Aderente a1(f_name + " " + s_name, city, stoul(cell), stoul(nif), d1, 2020);
    try{
        findCinemateca(city)->AdicionarAderente(a1);
    } catch (Aderente &ad){
        cout << "Aderente already exists.";
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
            sor == true;
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
                    << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                    << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                    << it->getSavedMoney() << "€" << endl;
            }
        }
        if (city == "Lisboa"){
            if (sor) {
                findCinemateca("Lisboa")->SortAderentes();
            }
            vector<Aderente>aderentes_l = findCinemateca("Lisboa")->GetAderentes();
            for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "€" << endl;
            }
        }
        if (city == "both"){
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
                     << it->getSavedMoney() << "€" << endl;
            }
            cout << "Lisboa: " << endl;
            for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++){
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "€" << endl;
            }
        }
        else{
            cout << "Invalid input.";
            continue;
        }
    }
}

void utils::removeAderente() {
    string nif;
    while (true) {
        bool again = false;
        while (true) {
            cout << "What is the Aderente's NIF? ";
            cin >> nif;
            if (nif.size() != 9) {
                cout << "NIF's size is 9.";
                continue;
            }
            bool valid = true;
            for (int i = 0; i < nif.size(); i++) {
                if ((!((int(nif[i]) >= 48) && (int(nif[i]) <= 57))) && (valid == true)) {
                    cout << "NIF only has digits from 0 to 9.";
                    valid = false;
                }
            }
            if (!valid) continue;
            break;
        }
        unsigned int NIF = stoul(nif);
        vector<Aderente> aderentes_p = findCinemateca("Porto")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++) {
            if (it->getNIF() == NIF) {
                findCinemateca("Porto")->GetAderentes().erase(it);
                return;
            }
        }
        vector<Aderente> aderentes_l = findCinemateca("Lisboa")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++) {
            if (it->getNIF() == NIF) {
                findCinemateca("Lisboa")->GetAderentes().erase(it);
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
    string nif;
    while (true) {
        bool again = false;
        while (true) {
            cout << "What is the Aderente's NIF? ";
            cin >> nif;
            if (nif.size() != 9) {
                cout << "NIF's size is 9.";
                continue;
            }
            bool valid = true;
            for (int i = 0; i < nif.size(); i++) {
                if ((!((int(nif[i]) >= 48) && (int(nif[i]) <= 57))) && (valid == true)) {
                    cout << "NIF only has digits from 0 to 9.";
                    valid = false;
                }
            }
            if (!valid) continue;
            break;
        }
        unsigned int NIF = stoul(nif);
        vector<Aderente> aderentes_p = findCinemateca("Porto")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_p.begin(); it != aderentes_p.end(); it++) {
            if (it->getNIF() == NIF) {
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "€" << endl;
                return;
            }
        }
        vector<Aderente> aderentes_l = findCinemateca("Lisboa")->GetAderentes();
        for (vector<Aderente>::iterator it = aderentes_l.begin(); it != aderentes_l.end(); it++) {
            if (it->getNIF() == NIF) {
                cout << "Name: " << it->getName() << ", " << "Cell: " << it->getCell() << endl << "NIF: " << it->getNIF()
                     << "Birthday: " << it->getBirthday().getDay() << "/" << it->getBirthday().getMonth() << "/"
                     << it->getBirthday().getYear() << endl << "Adhesion year: " << it->getAdhYear() << "Money saved: "
                     << it->getSavedMoney() << "€" << endl;
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

void utils::addSala() {
    string city, name, cap;
    while (true) {
        cout << "To which city do you want to add it? ";
        cin >> city;
        if ((city != "Porto") && (city != "Lisboa")) {
            cout << "City needs to be either Lisboa or Porto.";
            continue;
        }
        break;
    }
    while(true) {
        cout << "What's its name?";
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
    while(true){
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
    } catch (Sala s){
        cout << "Sala already exists.";
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
            sor == true;
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
        }
        else if (city == "Lisboa"){
            if (sor){
                findCinemateca("Lisboa")->SortSalas();
            }
            vector<Sala>sL = findCinemateca("Lisboa")->Getsalas();
            for(vector<Sala>::iterator it = sL.begin(); it != sL.end(); it++){
                cout << "Name: " << (*it).getName() << ", " << "Capacity: " << (*it).getCapacity() << endl;
            }
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
        }
    }
}

void utils::findSala() {
    string city, name;
    while (true) {
        cout << "Do you want to find a Sala in Porto or Lisboa?";
        cin >> city;
        if ((city != "Porto") && (city != "Lisboa")){
            cout << "They only exists in Porto os Lisboa";
            continue;
        }
        break;
    }
    while (true){
        cout << "What's its name?";
        getline(cin, name);
        bool valid = true;
        for (int i = 0; i < name.size(); i++) {
            if ((((int(name[i]) >= 48) && (int(name[i]) <= 57))) && (valid == true)) {
                cout << "Salas don't have numbers in their names.";
                valid = false;
            }
        }
        if (!valid) continue;
        break;
    }
    vector<Sala>salas = findCinemateca(city)->Getsalas();
    for (vector<Sala>::iterator it = salas.begin(); it != salas.end(); it++){
        if ((*it).getName() == name){
            cout << "Sala found:" << endl << "Name: " << (*it).getName() << ", Capacity: " << (*it).getCapacity();
        }
    }
}

bool utils::creditInfo() {
    return true;
}


void utils::buyTicket() {
    string city, answer;
    while (true) {
        cout << "Do you want to see the events from which city?";
        cin >> city;
        if ((city != "Porto") && (city != "Lisboa")){
            cout << "City needs to be either Lisboa or Porto.";
            continue;
        }
        break;
    }
    vector<Evento>future = findCinemateca(city)->GetEventosFuturos();
    if (future.size() == 0){
        cout << "There are no scheduled events for the future in " << city << ".";
        return;
    }
    cout << "These are the next events to happen in " << city << "." << endl;
    for(int i = 0; i < future.size(); i++){
        cout << future[i].getName() << " with " << future[i].getLot() << "/" << future[i].getMaxAttendance() <<
            " people and it costs " << future[i].getPrice() << "€." << endl;
    }
    bool valid = true, buy = false, cl = false;
    string nif;
    Cliente *c;
    Evento *ev;
    Aderente *ad;
    while(true) {
        cout << "If you're interested in any, write the name, else write 'CANCEL': ";
        getline(cin, answer);
        if(answer == "CANCEL") return;
        for (vector<Evento>::iterator it = future.begin(); it != future.end(); it++){
            if ((*it).getName() == answer){
                *ev = *it;
                if ((*it).getLot() < (*it).getMaxAttendance()){
                    while (true){
                        cout << "Are you an Aderente or not (y/n)?";
                        cin >> answer;
                        if (answer == "y"){
                            bool valid_ad = false;
                            while (true) {
                                cout << "Input NIF: ";
                                cin >> nif;
                                if (nif.size() != 9) {
                                    cout << "NIF's size is 9.";
                                    continue;
                                }
                                bool valid_nif = true;
                                for (int i = 0; i < nif.size(); i++) {
                                    if ((!((int(nif[i]) >= 48) && (int(nif[i]) <= 57))) && (valid == true)) {
                                        cout << "NIF only has digits from 0 to 9.";
                                        valid_nif = false;
                                    }
                                }
                                if (!valid_nif) continue;
                                vector<Aderente> ads = findCinemateca(city)->GetAderentes();
                                bool valid_ad = false;
                                for (vector<Aderente>::iterator it = ads.begin(); it != ads.end(); it++) {
                                    if (it->getNIF() == stoul(nif)) {
                                        valid_ad = true;
                                        buy = true;
                                        *ad = *it;
                                        break;
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
                            cout << "To buy the ticket, you need to input some information." << endl;
                            string f_name, s_name, cell;
                            while (true) {
                                cout << "Input name: ";
                                cin >> f_name >> s_name;
                                if (!validName(f_name)) continue;
                                if (!validName(s_name)) continue;
                                break;
                            }
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
                                for (int i = 0; i < cell.size(); i++){
                                    bool valid = true;
                                    if (!((int(cell[i]) >= 48) && (int(cell[i]) <= 57))){
                                        cout << "Cellphone number only has digits from 0 to 9.";
                                        valid = false;
                                    }
                                    if (!valid) continue;
                                }
                                break;
                            }
                            Cliente c1(f_name + " " + s_name, city, stoul(cell));
                            *c = c1;
                            buy = true;
                            cl = true;
                            break;
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
            else{
                cout << "Invalid name";
                valid = false;
            }
        }
        if (!valid) continue;
        break;
    }
    if (!buy) return;
    if (!creditInfo()) return;
    if (cl){
        ev->signUp(*c);
    }
    else{
        ev->signUp(*ad);
    }
}