//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <iostream>
#include <algorithm>

using namespace std;

class Data {
private:
    unsigned int day, month, year;
public:
    /**
     * Default constructor.
     */
    Data() = default;
    /**
     * Class constructor. Initializes day, month and year.
     * @param dd - Day of the date.
     * @param mm - Month of the date.
     * @param yy - Year of the date.
     */
    Data(unsigned int dd, unsigned int mm, unsigned int yy);
    Data(const Data & date);
    /**
     * Initializes day, month and year.
     * @param dd - Day of the date.
     * @param mm - Month of the date.
     * @param yy - Year of the date.
     */
    void initDate(unsigned int dd, unsigned int mm, unsigned int yy);
    /**
     * @return Returns the date.
     */
    Data getDate() const;
    /**
     * @return The day stored in the date.
     */
    unsigned int getDay() const;
    /**
     * @return The month stored in the date.
     */
    unsigned int getMonth() const;
    /**
     * @return The year stored in the date.
     */
    unsigned int getYear() const;
    /**
     * Changes day value.
     * @param newDay - New day value.
     */
    void setDay(unsigned  int newDay) {
        day = newDay;
    }
    /**
     * Changes month value.
     * @param newMonth - New month value.
     */
    void setMonth(unsigned  int newMonth) {
        month = newMonth;
    }
    /**
     * Changes year value.
     * @param newYear - New year value.
     */
    void setYear(unsigned  int newYear) {
        year = newYear;
    }
    /**
     * A date is lesser than another if it comes before.
     * @param date - The date to be compared to.
     * @return True if it comes before. False otherwise.
     */
    bool operator<(Data date) const;
    /**
     * A date is greater than another if it comes after.
     * @param date - The date to be compared to.
     * @return True if it comes after. False otherwise.
     */
    bool operator>(Data date) const;
    /**
     * Checks if two dates are equal.
     * @return True if they are. False otherwise.
     */
    bool operator==(Data date) const;
};


#endif //PROJETO_DATA_H
