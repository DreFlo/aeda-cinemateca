#include "IntervaloDeTempo.h"

StartDataEHora::StartDataEHora(const DataEHora &dataEHora):DataEHora(dataEHora) {}

EndDataEHora::EndDataEHora(const DataEHora &dataEHora):DataEHora(dataEHora) {}

IntervaloDeTempo::IntervaloDeTempo(const DataEHora& st, const DataEHora& ed):StartDataEHora(st), EndDataEHora(ed) {}

void IntervaloDeTempo::set(const DataEHora& st, const DataEHora& ed) {
    StartDataEHora::setDateAndTime(st);
    EndDataEHora::setDateAndTime(ed);
}

DataEHora IntervaloDeTempo::getStart() const {
    return StartDataEHora::getDateAndTime();
}

DataEHora IntervaloDeTempo::getEnd() const {
    return EndDataEHora::getDateAndTime();
}

IntervaloDeTempo IntervaloDeTempo::getTimeInterval() const {
    return *this;
}

IntervaloDeTempo& IntervaloDeTempo::getTimeIntervalRef() {
    return *this;
}

bool IntervaloDeTempo::valid() const {
    return StartDataEHora::valid() && EndDataEHora::valid() && this->getStart() > this->getEnd();
}

string IntervaloDeTempo::str() const {
    return "start - " + StartDataEHora::str() + " end - " + EndDataEHora::str();
}

bool IntervaloDeTempo::operator^(const IntervaloDeTempo& timeInterval) const {
    return (this->getStart() < timeInterval.getStart() && this->getEnd() < timeInterval.getStart()) ||
           this->getStart() > timeInterval.getEnd();
}

bool IntervaloDeTempo::operator==(const IntervaloDeTempo& timeInterval) const {
    return this->getStart() == timeInterval.getStart() && this->getEnd() == timeInterval.getEnd();
}

ostream& operator<<(ostream& output, const IntervaloDeTempo& timeInterval) {
    output << timeInterval.getStart() << " " << timeInterval.getEnd();
    return output;
}

istream& operator>>(istream& input, IntervaloDeTempo& timeInterval) {
    input >> timeInterval.StartDataEHora::getDateAndTimeRef() >> timeInterval.EndDataEHora::getDateAndTimeRef();
    if (!timeInterval.valid()) throw InvalidTimeInterval();
    return input;
}
