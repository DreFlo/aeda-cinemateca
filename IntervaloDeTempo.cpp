//
// Created by andre on 10/15/2020.
//

#include "IntervaloDeTempo.h"

DataEHora IntervaloDeTempo::getStart() const {
    return start;
}

DataEHora IntervaloDeTempo::getEnd() const {
    return end;
}

bool IntervaloDeTempo::operator^(IntervaloDeTempo timeInterval) const {
    return false;
}