//
// Created by andre on 10/14/2020.
//

#include "Data.h"

Data::Data(unsigned int dd, unsigned int mm, unsigned int yy):day(dd), month(mm), year(yy) {}

void Data::initDate(unsigned int dd, unsigned int mm, unsigned int yy) {
    day = dd;
    month = mm;
    year = yy;
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

bool Data::operator<(Data date) const{
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

bool Data::operator>(Data date) const {
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

bool Data::operator==(Data date) const {
    return this->day == date.getDay() && this->month == date.getMonth() && this->year == date.getYear();
}