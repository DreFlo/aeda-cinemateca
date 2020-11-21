
#include "Sala.h"

Sala::Sala(string n, int cap) : name(n), capacity(cap) {}

string Sala::getName() const {return name;}

int Sala::getCapacity() const {return capacity;}

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

void Sala::updateSalaName(string new_name) {
    name = new_name;
}

void Sala::updateSalaCap(int new_cap) {
    capacity = new_cap;
}

bool Sala::operator==(const Sala &s1) const {
    return (name == s1.name);
}

bool Sala::operator<(const Sala &s1) const {
    return (capacity < s1.capacity);
}

istream &operator>>(istream &input, Sala &s1) {
    getline(input, s1.name, '\t') >> s1.capacity;
    return input;
}

ostream &operator<<(ostream &output, const Sala &s1) {
    output << s1.name << '\t' << s1.capacity;
    return output;
}


