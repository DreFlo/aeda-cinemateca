//
// Created by andre on 10/14/2020.
//

#include "Hora.h"

Hora::Hora(unsigned int hh, unsigned int mm):hour(hh), minute(mm) {}

Hora::Hora(const Hora &time) {
    setHour(time.getHour());
    setMinute(time.getMinute());
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

void Hora::setTime(unsigned int hh, unsigned int mm) {
    setHour(hh);
    setMinute(mm);
}

void Hora::setTime(const Hora &time) {
    setHour(time.getHour());
    setMinute(time.getMinute());
}

void Hora::setHour(unsigned int newHour) {
    this->hour = newHour;
}

void Hora::setMinute(unsigned int newMin) {
    this->minute = newMin;
}

bool Hora::operator<(const Hora &time) const {
    if (this->hour < time.getHour())
        return true;
    else if (this->hour == time.getHour())
        return this->minute < time.getMinute();
    return false;
}

bool Hora::operator>(const Hora &time) const {
    if (this->hour > time.getHour())
        return true;
    else if (this->hour == time.getHour())
        return this->minute > time.getMinute();
    return false;
}

bool Hora::operator==(const Hora &time) const {
    return this->hour == time.getHour() && this->minute == time.getMinute();
}

ostream &operator<<(ostream &output, const Hora &time) {
    output << time.getHour() << "h" << to_string(time.getMinute()) << "min";
    return output;
}

