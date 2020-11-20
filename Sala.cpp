
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
    string s;
    int pos = 0;
    getline(input, s);
    for (int i = 0; i < s.size(); i++){
        if ((int(s[i]) >= 48) && (int(s[i]) <= 57)){
            if (pos = 0) {pos = i;}
            break;
        }
    }
    s1.capacity = stoi(s.substr(pos, (s.size() - pos)));
    s1.name = s.substr(0, pos);
    return input;
}

ostream &operator<<(ostream &output, const Sala &s1) {
    output << s1.name << " " << s1.capacity;
    return output;
}


