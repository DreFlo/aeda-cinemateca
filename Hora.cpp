//
// Created by andre on 10/14/2020.
//

#include "Hora.h"

Hora::Hora(unsigned int hh, unsigned int mm) {
    init(hh, mm);
}

void Hora::init(unsigned int hh, unsigned int mm) {
    if (checkTimeValidity(hh, mm)) {
        hour = hh;
        minute = mm;
    }
    else
        throw invalid_argument("Invalid time");
}

Hora Hora::getTime() const {
    return *this;
}

unsigned int Hora::getHour() const {
    return hour;
}

unsigned int Hora::getMinute() const {
    return minute;
}

bool Hora::operator<(Hora time) const {
    if (this->hour < time.getHour())
        return true;
    else if (this->hour == time.getHour())
        return this->minute < time.getMinute();
    return false;
}

bool Hora::operator>(Hora time) const {
    if (this->hour > time.getHour())
        return true;
    else if (this->hour == time.getHour())
        return this->minute > time.getMinute();
    return false;
}

bool Hora::checkTimeValidity(unsigned int hh, unsigned int mm) {
    return hh < 24 && mm < 60;
}