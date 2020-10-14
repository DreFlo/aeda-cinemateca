//
// Created by andre on 10/14/2020.
//

#include "Data.h"

Data::Data(int dd, int mm, int yy):day(dd), month(mm), year(yy) {}

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