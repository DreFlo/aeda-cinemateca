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

bool IntervaloDeTempo::operator^(const IntervaloDeTempo& timeInterval) const {
    return (this->getStart() < timeInterval.getStart() && this->getEnd() < timeInterval.getStart()) ||
           this->getStart() > timeInterval.getEnd();
}

bool IntervaloDeTempo::operator==(const IntervaloDeTempo& timeInterval) const {
    return this->getStart() == timeInterval.getStart() && this->getEnd() == timeInterval.getEnd();
}

ostream &operator<<(ostream &output, const IntervaloDeTempo &timeInterval) {
    output << "start - " << timeInterval.getStart() << " end - " << timeInterval.getEnd();
    return output;
}
