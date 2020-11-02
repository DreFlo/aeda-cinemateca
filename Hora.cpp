#include "Hora.h"

Hora::Hora(unsigned int hh, unsigned int mm):hour(hh), minute(mm) {}

Hora::Hora(const Hora &time) {
    setHour(time.getHour());
    setMinute(time.getMinute());
}

Hora Hora::getTime() const {
    return *this;
}

Hora& Hora::getTimeRef() {
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

void Hora::setTime(const string& in) {
    unsigned int hh, min;
    regex matchStr("[0-9][0-9]h[0-9][0-9]min");
    if (!regex_match(in, matchStr))
        throw invalid_argument("Input not correctly formatted");
    hh = stoi(in.substr(0, 2));
    min = stoi(in.substr(3, 2));
    this->setTime(hh, min);
}

void Hora::setHour(unsigned int newHour) {
    this->hour = newHour;
}

void Hora::setMinute(unsigned int newMin) {
    this->minute = newMin;
}

bool Hora::valid() const {
    return hour < 24 && minute < 60;
}

string Hora::str() const {
    stringstream res;
    if (hour < 10 && minute < 10)
        res << "0" << hour << "h" << "0" << minute << "min";
    else if (hour < 10 && minute >= 10)
        res << "0" << hour << "h" << minute << "min";
    else if (hour >= 10 && minute < 10)
        res << hour << "h" << "0" << minute << "min";
    else
        res << hour << "h" << minute << "min";
    return res.str();
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

ostream& operator<<(ostream& output, const Hora &time) {
    /*

    */
    output << time.getHour() << " " << time.getMinute();
    return output;
}

istream& operator>>(istream& input, Hora& time) {
    string in;
    input >> time.hour >> time.minute;
    return input;
}
