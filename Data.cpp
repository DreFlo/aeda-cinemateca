#include "Data.h"

Data::Data(unsigned int dd, unsigned int mm, unsigned int yy):day(dd), month(mm), year(yy) {}

Data::Data(const Data& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
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
    unsigned temp_d = day, temp_m = month, temp_y = year;
    // Checks if the argument string is well formatted. If not throws invalid_argument.
    regex matchStr("[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]");
    if (!regex_match(in, matchStr)) throw invalid_argument("Input not correctly formatted");
    // Get numbers from string.
    day = stoi(in.substr(0, 2));
    month = stoi(in.substr(3, 2));
    year = stoi(in.substr(6, 4));
    // If argument date is not valid object remains unchanged. Throws InvalidDate.
    if (!this->valid()) {
        Data temp_date = *this;
        day = temp_d;
        month = temp_m;
        year = temp_y;
        throw InvalidDate(temp_date, "Invalid date");
    }
}

void Data::setDay(unsigned int newDay) {
    unsigned int temp = this->day;
    this->day = newDay;
    if (!this->valid()) {
        this->day = temp;
        throw InvalidDate(*this, "Invalid day. Not accepted.");
    }
}

void Data::setMonth(unsigned int newMonth) {
    this->month = newMonth;
}

void Data::setYear(unsigned int newYear) {
    this->year = newYear;
}

bool Data::valid() const{
    unsigned int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    if (month < 1 || month > 12 || year < 0)
        return false;
    else if (year % 4 == 0 && month == 2)
        return day > 0 && day < 30;
    else if (month == 2)
        return day > 0 && day < 29;
    else if (find(longMonths, longMonths + 7, month))
        return day > 0 && day < 32;
    else if (!find(longMonths, longMonths + 7, month))
        return day > 0 && day < 31;
    return false;
}

string Data::str() const {
    stringstream res;
    if (day < 10 && month < 10)
        res << "0" <<  day << "/0" << month << "/" << year;
    else if (day < 10 && month >= 10)
        res << "0" <<  day << "/" << month << "/" << year;
    else if (day >= 10 && month < 10)
        res <<  day << "/0" << month << "/" << year;
    else
        res <<  day << "/" << month << "/" << year;
    return res.str();
}

bool Data::operator<(const Data &date) const noexcept {
    if (this->year < date.year)
        return true;
    else if (this->year == date.year) {
        if (this->month < date.month)
            return true;
        else if (this->month == date.month) {
            return this->day < date.day;
        }
    }
    return false;
}

bool Data::operator>(const Data &date) const noexcept {
    if (this->year > date.year)
        return true;
    else if (this->year == date.year) {
        if (this->month > date.month)
            return true;
        else if (this->month == date.month) {
            return this->day > date.day;
        }
    }
    return false;
}

bool Data::operator==(const Data &date) const noexcept {
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

ostream& operator<<(ostream& output, const Data& date) noexcept{
    output<< date.day << " " << date.month << " " << date.year;
    return output;
}

istream& operator>>(istream& input, Data& date) {
    input >> date.day >> date.month >> date.year;
    if(!date.valid()) throw InvalidDate(date, " <- INVALID DATE");
    return input;
}

Data& Data::getDateRef() {
    return *this;
}
