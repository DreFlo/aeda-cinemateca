//
// Created by andre on 10/14/2020.
//

#include "Hora.h"

Hora::Hora(unsigned int hh, unsigned int mm):hour(hh), minute(mm) {}

Hora::Hora(const Hora &time) {
    this->hour = time.getHour();
    this->minute = time.getMinute();
}

void Hora::initTime(unsigned int hh, unsigned int mm) {
    hour = hh;
    minute = mm;
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

bool Hora::operator==(Hora time) const {
    return this->hour == time.getHour() && this->minute == time.getMinute();
}