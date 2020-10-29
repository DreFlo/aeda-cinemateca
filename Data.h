#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <regex>


using namespace std;

class Data {
private:
    unsigned int day = 0, month = 0, year = 0;
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
    /**
     * Copy constructor.
     */
    Data(const Data& date);
    /**
     * @return Returns the date.
     */
    const Data& getDate() const;
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
     * Sets day, month and year.
     * @param dd - Day of the date.
     * @param mm - Month of the date.
     * @param yy - Year of the date.
     */
    void setDate(unsigned int dd, unsigned int mm, unsigned int yy);
    /**
     * Sets date
     */
    void setDate(const Data& date);
    /**
     * Sets date from string.
     */
    void setDate(const string& in);
    /**
     * Changes day value.
     * @param newDay - New day value.
     */
    void setDay(unsigned  int newDay);
    /**
     * Changes month value.
     * @param newMonth - New month value.
     */
    void setMonth(unsigned  int newMonth);
    /**
     * Changes year value.
     * @param newYear - New year value.
     */
    void setYear(unsigned  int newYear);
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
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Data& date);
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Data& date);
};


#endif //PROJETO_DATA_H
