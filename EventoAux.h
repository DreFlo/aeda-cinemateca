//
// Created by Rafae on 31/12/2020.
//

#ifndef PROJETO_EVENTOAUX_H
#define PROJETO_EVENTOAUX_H

#include "Evento.h"

const Evento Vazio = Evento();

class EventoAux{
public:
    Evento Event;
    /**
     * Default constructor
     */
    EventoAux();
    /**
     * Constructor
     * @param ev - pointer to an event
     */
    EventoAux(Evento ev);
    /**
     * An EventAux is lesser than another if it has less lot, then its alphabetical
     * @return True if it is. False otherwise.
     */
    bool operator<(const EventoAux& EventoAux2) const;
};

#endif //PROJETO_EVENTOAUX_H