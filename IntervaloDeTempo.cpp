//
// Created by andre on 10/15/2020.
//

#include "IntervaloDeTempo.h"

IntervaloDeTempo::IntervaloDeTempo(DataEHora st, DataEHora ed):start(st), end(ed) {}

void IntervaloDeTempo::init(DataEHora st, DataEHora ed) {
    start = st;
    end = ed;
}

DataEHora IntervaloDeTempo::getStart() const {
    return start;
}

DataEHora IntervaloDeTempo::getEnd() const {
    return end;
}

bool IntervaloDeTempo::operator^(IntervaloDeTempo timeInterval) const {
    return (this->start < timeInterval.getStart() && this->end < timeInterval.getStart()) ||
           this->start > timeInterval.getEnd();
}