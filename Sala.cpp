
#include "Sala.h"

/**
 * Inicializador da classe.
 */
Sala::Sala(string n, int cap) : name(n), capacity(cap) {}

/**
 * @return Nome da sala.
 */
string Sala::getName() const {return name;}

/**
 * @return Capacidade da sala.
 */
int Sala::getCapacity() const {return capacity;}

/**
 * Verifica se sala está disponivel num certo intervalo de tempo.
 * @param time - Intervalo de tempo a verificar.
 * @return True se sala estiver disponivel.
 */
bool Sala::checkAvailability(const IntervaloDeTempo time) const {
    for (int i = 0; i < availability.size(); i++){
        if (availability[i]^time){
            return false;
        }
    }
    return true;
}

void Sala::addEvent(const IntervaloDeTempo time) {
    if (!checkAvailability(time)) throw  AlreadyScheduled(time);
    availability.push_back(time);
}

void Sala::removeEvent(const IntervaloDeTempo time) {
    if (checkAvailability(time)) throw NoEventScheduled(time);
    for (vector<IntervaloDeTempo>::iterator it = availability.begin(); it != availability.end(); it++){
        if ((*it) == time){
            availability.erase(it);
        }
    }
}


