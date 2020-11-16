#include "Evento.h"

#include <utility>

Evento::Evento(string nm, float prc, const DataEHora& st, const Hora& drtn, int mxAtn):
        name(std::move(nm)), maxAttendance(mxAtn), price(prc), start(st), duration(drtn),
        IntervaloDeTempo(st, st + drtn) {}

string Evento::getName() const {
    return name;
}

string Evento::getRoom() const{
    return room;
}

int Evento::getMaxAttendance() const {
    return maxAttendance;
}

float Evento::getPrice() const {
    return price;
}

Hora Evento::getDuration() const {
    return duration;
}

float Evento::getTotal() const {
    return total;
}

int Evento::getLot() const {
    return lot;
}

void Evento::signUp(const Cliente &C) {
    if (lot == maxAttendance) throw EventFull();
    lot++;
    total += price;
}

void Evento::signUp(const Aderente &A, bool free) {
    if (lot == maxAttendance) throw EventFull();
    lot++;
    if (!free) {
        if (this->start.getYear() - A.getAdhYear() >= 15) total += price * 0.85;
        else total += price * (1 - 0.01 * (this->start.getYear() - A.getAdhYear()));
    }
}

void Evento::setName(string nm) {
    name = std::move(nm);
}

void Evento::setRoom(string rm) {
    room = std::move(rm);
}

void Evento::setMaxAttendance(int mxCp) {
    maxAttendance = mxCp;
}

void Evento::setPrice(float prc) {
    price = prc;
}

void Evento::setStart(const DataEHora& st) {
    start = st;
    this->IntervaloDeTempo::StartDataEHora::setDateAndTime(start);
}

void Evento::setDuration(const Hora& drtn) {
    duration = drtn;
    this->IntervaloDeTempo::EndDataEHora::setDateAndTime(start + duration);
}

string Evento::str() const {
    stringstream res;
    res << "Name: " << name << " Room: " << room << " Admission price: " << price << " Event total: " << total
        << " Maximum Attendance: " << maxAttendance << " Attendance: " << lot
        << " " << start.str() << " " << duration.str();
    return res.str();
}

bool Evento::operator<(Evento &E2) const {
    return this->start < E2.start;
}

ostream& operator<<(ostream& output, const Evento& event) {
    output << event.name << '\t' << event.room << '\t' << event.price << '\t' << event.total
           << '\t' << event.maxAttendance << '\t' << event.lot
           << '\t' << event.start << '\t' << event.duration << '\t' << event.getTimeInterval() << endl;
    return output;
}

istream& operator>>(istream& input, Evento& event) {
    getline(input, event.name, '\t');
    getline(input, event.room, '\t') >> event.price >> event.total >> event.maxAttendance >> event.lot
          >> event.start >> event.duration >> event.getTimeIntervalRef();
    return input;
}