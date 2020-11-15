//
// Created by andre on 10/15/2020.
//

#include "Utils.h"

void utils::printHelp() {
    cout << "help - get commands and descriptions" << endl;
    cout << "add event - add an event to a cinema" << endl;
    cout << "change today - change current day" << endl;
}

bool utils::CompararEventos(const Evento e1, const Evento e2){
    return(e1.getStart() < e2.getStart());
}