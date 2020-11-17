
#include "Sala.h"

Sala::Sala(string n, int cap, string cit) : name(n), capacity(cap), city(cit) {}

string Sala::getName() const {return name;}

int Sala::getCapacity() const {return capacity;}

string Sala::getCity() const {return city;}

bool Sala::checkAvailability(const IntervaloDeTempo time) const {
    for (int i = 0; i < ocupacao.size(); i++){
        if (ocupacao[i]^time){
            return false;
        }
    }
    return true;
}

void Sala::addEvent(const IntervaloDeTempo time) {
    if (!checkAvailability(time)) throw  AlreadyScheduled(time);
    ocupacao.push_back(time);
}

void Sala::cancelEvent(const IntervaloDeTempo time) {
    if (checkAvailability(time)) throw NoEventScheduled(time);
    for (vector<IntervaloDeTempo>::iterator it = ocupacao.begin(); it != ocupacao.end(); it++){
        if ((*it) == time){
            ocupacao.erase(it);
        }
    }
}


