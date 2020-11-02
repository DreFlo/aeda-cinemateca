#include "Data.h"

Data::Data(unsigned int dd, unsigned int mm, unsigned int yy):day(dd), month(mm), year(yy) {}

Data::Data(const Data& date) {
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

void Data::setDate(const string& in) {
    unsigned int dd, mm, yy;
    regex matchStr("[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]");
    if (!regex_match(in, matchStr))
        throw invalid_argument("Input not correctly formatted");
    dd = stoi(in.substr(0, 2));
    mm = stoi(in.substr((3, 2)));
    yy = stoi(in.substr(6, 4));
    this->setDate(dd, mm, yy);
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

ostream& operator<<(ostream& output, const Data& date) {
    /*
    if (date.getDay() < 10 && date.getMonth() < 10)
        output << "0" <<  date.getDay() << "/0" << date.getMonth() << "/" << date.getYear();
    else if (date.getDay() < 10 && date.getMonth() >= 10)
        output << "0" <<  date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    else if (date.getDay() >= 10 && date.getMonth() < 10)
        output <<  date.getDay() << "/0" << date.getMonth() << "/" << date.getYear();
    else
        output <<  date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
        */
    output<< date.getDay() << " " << date.getMonth() << " " << date.getYear();
    return output;
}

istream& operator>>(istream& input, Data& date) {
    input >> date.day >> date.month >> date.year;
    return input;
}

Data& Data::getDateRef() {
    return *this;
}