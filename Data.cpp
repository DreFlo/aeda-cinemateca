#include "Data.h"

Data::Data(int dd, int mm, int yy):day(dd), month(mm), year(yy) {}

Data::Data(const Data& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Data Data::getDate() const {
    return *this;
}

int Data::getDay() const {
    return day;
}

int Data::getMonth() const {
    return month;
}

int Data::getYear() const {
    return year;
}

void Data::setDate(int dd, int mm, int yy) {
    if (!Data(dd, mm, yy).valid()) throw InvalidDate(Data(dd, mm, yy), "Invalid argument date");
    this->day = dd;
    this->month = mm;
    this->year = yy;
}

void Data::setDate(const Data &date) {
    setDate(date.day, date.month, date.year);
}

void Data::setDate(const string& in) {
    int temp_d, temp_m, temp_y;
    // Checks if the argument string is well formatted. If not throws invalid_argument.
    regex matchStr("[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]");
    if (!regex_match(in, matchStr)) throw invalid_argument("Input not correctly formatted");
    // Get numbers from string.
    temp_d = stoi(in.substr(0, 2));
    temp_m = stoi(in.substr(3, 2));
    temp_y = stoi(in.substr(6, 4));
    // If argument date is not valid object remains unchanged. Throws InvalidDate.
    this->setDate(temp_d, temp_m, temp_y);
}

void Data::setDay(int newDay) {
    if (!Data(newDay, this->month, this->year).valid())
        throw InvalidDate(Data(newDay, this->month, this->year), "Invalid day. Not accepted.");
    this->day = newDay;
}

void Data::setMonth(int newMonth) {
    if (!Data(this->day, newMonth, this->year).valid())
        throw InvalidDate(Data(this->day, newMonth, this->year), "Invalid month. Not accepted.");
    this->month = newMonth;
}

void Data::setYear(int newYear) {
    if (!Data(this->day, this->month, newYear).valid())
        throw InvalidDate(Data(this->day, this->month, newYear), "Invalid year. Not accepted.");
    this->year = newYear;
}

bool Data::valid() const {
    int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
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

bool Data::operator<(const Data &date) const {
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

bool Data::operator>(const Data &date) const {
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

bool Data::operator==(const Data &date) const {
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

Data Data::operator+(const int no_days) const noexcept(false){
    Data res;
    int res_day = this->day + no_days, res_month = this->month, res_year = this->year;
    int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    // Get correct day, month, year.
    if (res_month == 2 && res_year % 4 == 0 && res_day > 29) {
        res_month++;
        res_day -= 29;
    }
    else if (res_month == 2 && res_year % 4 == 1 && res_day > 28) {
        res_month++;
        res_day -= 28;
    }
    else if (find(longMonths, longMonths + 7, res_month) && res_day > 31) {
        res_month++;
        res_day -= 31;
    }
    else if (!find(longMonths, longMonths + 7, res_month) && res_day > 30) {
        res_month++;
        res_day -= 30;
    }
    if (res_month > 12) {
        res_year++;
        res_month -= 12;
        res_day -= 31;
    }
    // Set and return result
    res.setDate(res_day, res_month, res_year);
    if (!res.valid()) throw InvalidDate(res, "Can't execute addition");
    return res;
}

ostream& operator<<(ostream& output, const Data& date) {
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
