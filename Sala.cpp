
#include "Sala.h"

Sala::Sala(string n, int cap, string cit) : name(n), capacity(cap), city(cit) {}

string Sala::getName() const {return name;}

int Sala::getCapacity() const {return capacity;}

string Sala::getCity() const {return city;}

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

void Sala::cancelEvent(const IntervaloDeTempo time) {
    if (checkAvailability(time)) throw NoEventScheduled(time);
    for (vector<IntervaloDeTempo>::iterator it = availability.begin(); it != availability.end(); it++){
        if ((*it) == time){
            availability.erase(it);
        }
    }
}


