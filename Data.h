#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <regex>


using namespace std;

class InvalidDate;

class Data {
private:
    int day = 0, month = 0, year = 0;
public:
    /**
     * Default constructor.
     */
    Data() = default;
    /**
     * Class constructor. Initializes day, month and year. Parameters do not have to form a valid date
     * @param dd Day
     * @param mm Month
     * @param yy Year
     */
    Data(int dd, int mm, int yy);
    /**
     * Copy constructor. Parameter does not have to be a valid date.
     */
    Data(const Data& date);
    /**
     * @return Returns the date.
     */
    Data getDate() const;
    /**
     * @return Return's a reference to the object
     */
    Data& getDateRef();
    /**
     * @return The day stored in the date.
     */
    int getDay() const;
    /**
     * @return The month stored in the date.
     */
    int getMonth() const;
    /**
     * @return The year stored in the date.
     */
    int getYear() const;
    /**
     * Sets day, month and year.
     * @param dd Day
     * @param mm Month
     * @param yy Year
     * @throws InvalidDate if parameter date is not valid in the gregorian calendar
     */
    void setDate(int dd, int mm, int yy) noexcept(false);
    /**
     * Sets date
     * @throws InvalidDate if parameter date is not valid in the gregorian calendar
     */
    void setDate(const Data& date) noexcept(false);
    /**
     * Sets date from string.
     * @throws invalid_argument if parameter string is not properly formatted (dd/mm/yyyy)
     * @throws InvalidDate if parameter date is not valid in the gregorian calendar
     */
    void setDate(const string& in) noexcept(false);
    /**
     * Changes day value.
     * @param newDay new day value
     * @throws InvalidDate if newDay does not form a valid date
     */
    void setDay(int newDay) noexcept(false);
    /**
     * Changes month value.
     * @param newMonth new month value
     * @throws InvalidDate if newMonth does not form a valid date
     */
    void setMonth(int newMonth) noexcept(false);
    /**
     * Changes year value.
     * @param newYear new year value
     * @throws InvalidDate if newYear does not form a valid date
     */
    void setYear(int newYear) noexcept(false);
    /**
     * Checks if date is valid in the gregorian calendar.
     * @return True if it is. False otherwise.
     */
    virtual bool valid() const;
    /**
     * @return Formatted string with the date.
     */
    virtual string str() const;
    /**
     * A date is lesser than another if it comes before.
     * @param date - The date to be compared to.
     * @return True if it comes before. False otherwise.
     */
    bool operator<(const Data& date) const;
    /**
     * A date is greater than another if it comes after.
     * @param date - The date to be compared to.
     * @return True if it comes after. False otherwise.
     */
    bool operator>(const Data& date) const;
    /**
     * Checks if two dates are equal.
     * @return True if they are. False otherwise.
     */
    bool operator==(const Data& date) const;
    /***
     * Adds up to the next month's number of days to a date.
     * @param no_days number of days to be added.
     * @return A Data object with the result.
     */
    Data operator+(int no_days) const noexcept(false);
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Data& date);
    /**
     * Input operator.
     * @throws InvalidDate if input is not a valid date in the gregorian calendar.
     */
    friend istream& operator>>(istream& input, Data& date) noexcept(false);
};

class InvalidDate: public exception {
    const Data date;
    const string msg;
public:
    explicit InvalidDate(const Data &D, string M):date(D), msg(std::move(M)) {}
    const Data & getDate() { return date; }
    string getMsg() { return msg; }
};

#endif //PROJETO_DATA_H
