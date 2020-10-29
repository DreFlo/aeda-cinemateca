#include "Data.h"

Data::Data(unsigned int dd, unsigned int mm, unsigned int yy):day(dd), month(mm), year(yy) {}

Data::Data(const Data &date) {
    this->day = date.getYear();
    this->month = date.getMonth();
    this->year = date.getYear();
}


Data Data::getDate() const {
    return *this;
}

unsigned int Data::getDay() const {
    return day;
}

unsigned int Data::getMonth() const {
    return month;
}

unsigned int Data::getYear() const {
    return year;
}

void Data::setDate(unsigned int dd, unsigned int mm, unsigned int yy) {
    setDay(dd);
    setMonth(mm);
    setYear(yy);
}

void Data::setDate(const Data &date) {
    setDay(date.getDay());
    setMonth(date.getMonth());
    setYear(date.getYear());
}

void Data::setDay(unsigned int newDay) {
    this->day = newDay;
}

void Data::setMonth(unsigned int newMonth) {
    this->month = newMonth;
}

void Data::setYear(unsigned int newYear) {
    this->year = newYear;
}

bool Data::operator<(const Data &date) const{
    if (this->year < date.getYear())
        return true;
    else if (this->year == date.getYear()) {
        if (this->month < date.getMonth())
            return true;
        else if (this->month == date.getMonth()) {
            return this->day < date.getDay();
        }
    }
    return false;
}

bool Data::operator>(const Data &date) const {
    if (this->year > date.getYear())
        return true;
    else if (this->year == date.getYear()) {
        if (this->month > date.getMonth())
            return true;
        else if (this->month == date.getMonth()) {
            return this->day > date.getDay();
        }
    }
    return false;
}

bool Data::operator==(const Data &date) const {
    return this->day == date.getDay() && this->month == date.getMonth() && this->year == date.getYear();
}

ostream &operator<<(ostream &output, const Data &date) {
    output << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return output;
}
