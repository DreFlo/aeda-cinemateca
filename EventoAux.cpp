//
// Created by Rafae on 31/12/2020.
//

#include "EventoAux.h"

EventoAux::EventoAux() {
    Event = &Vazio;
}

EventoAux::EventoAux(const Evento *ev) {
    Event = ev;
}

bool EventoAux::operator<(const EventoAux &EventoAux2) const {
    if(this->Event->getLot() == EventoAux2.Event->getLot()) return this->Event->getRoom() < EventoAux2.Event->getRoom();
    return this->Event->getLot() < EventoAux2.Event->getLot();
}