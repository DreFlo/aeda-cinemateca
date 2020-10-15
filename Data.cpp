//
// Created by andre on 10/14/2020.
//

#include "Data.h"

Data::Data(unsigned int dd, unsigned int mm, unsigned int yy) {
    init(dd, mm, yy);
}

void Data::init(unsigned int dd, unsigned int mm, unsigned int yy) {
    if (checkDateValidity(dd, mm, yy)) {
        day = dd;
        month = mm;
        year = yy;
    }
    else
        throw invalid_argument("Invalid date");
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

bool Data::checkDateValidity(unsigned int dd, unsigned int mm, unsigned int yy) {
    unsigned int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    if (yy % 4 == 0 && mm == 2)
        return dd > 0 && dd < 30;
    else if (yy % 4 != 0 && mm == 2)
        return dd > 0 && dd < 29;
    else if (find(longMonths, longMonths + 7, mm))
        return dd > 0 && dd < 32;
    else if (!find(longMonths, longMonths + 7, mm))
        return dd > 0 && dd < 31;
    return false;
}