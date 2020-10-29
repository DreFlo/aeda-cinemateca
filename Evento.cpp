#include "Evento.h"

#include <utility>

Evento::Evento(string nm, unsigned int mxCp, float prc, const DataEHora& st, const Hora& drtn):
    name(std::move(nm)), maxCapacity(mxCp), price(prc), start(st), duration(drtn),
    IntervaloDeTempo(st, st + drtn) {}

//

string Evento::getName() const {
    return name;
}

unsigned int Evento::getMaxCapacity() const {
    return maxCapacity;
}

float Evento::getPrice() const {
    return price;
}

DataEHora Evento::getStart() const {
    return start;
}

Hora Evento::getDuration() const {
    return duration;
}

void Evento::setName(string nm) {
    name = std::move(nm);
}

void Evento::setMaxCapacity(unsigned int mxCp) {
    maxCapacity = mxCp;
}

void Evento::setPrice(float prc) {
    price = prc;
}

void Evento::setStart(const DataEHora& st) {
    start = st;
}

void Evento::setDuration(const Hora& drtn) {
    duration = drtn;
}