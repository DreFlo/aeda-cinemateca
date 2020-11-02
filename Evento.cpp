#include "Evento.h"

#include <utility>

Evento::Evento(string nm, unsigned int mxCp, float prc, const DataEHora& st, const Hora& drtn):
        name(std::move(nm)), maxAttendance(mxCp), price(prc), start(st), duration(drtn),
        IntervaloDeTempo(st, st + drtn) {}

string Evento::getName() const {
    return name;
}

string Evento::getRoom() const{
    return room;
}

unsigned int Evento::getMaxAttendance() const {
    return maxAttendance;
}

float Evento::getPrice() const {
    return price;
}

Hora Evento::getDuration() const {
    return duration;
}

void Evento::setName(string nm) {
    name = std::move(nm);
}

void Evento::setRoom(string rm) {
    room = std::move(rm);
}

void Evento::setMaxAttendance(unsigned int mxCp) {
    maxAttendance = mxCp;
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

string Evento::str() const {
    stringstream res;
    res << name << " " << room << " " << maxAttendance << " " << price << " " << start.str() << " " << duration.str();
    return res.str();
}

ostream& operator<<(ostream& output, const Evento& event) {
    output << event.getName() << " " << event.getRoom() << " " << event.getPrice() << " " << event.getMaxAttendance()
           << " " << event.getStart() << " " << event.getDuration() << " " << event.getTimeInterval() << endl;
    return output;
}

istream& operator>>(istream& input, Evento& event) {
    input >> event.name >> event.room >> event.price >> event.maxAttendance >> event.start >> event.duration
          >> event.getTimeIntervalRef();
    return input;
}