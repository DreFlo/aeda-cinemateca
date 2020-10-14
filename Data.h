//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    const unsigned int day, month, year;
public:
    /**
     * Class constructor. Initializes day, month and year.
     * @param dd - Day of the date.
     * @param mm - Month of the date.
     * @param yy - Year of the date.
     */
    Data(int dd, int mm, int yy);
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
     * @brief A date is lesser than another if it comes before.
     * @param date - The date to be compared to.
     * @return True if it comes before. False otherwise.
     */
    bool operator<(Data date) const;
    /**
     * @brief A date is greater than another if it comes after.
     * @param date - The date to be compared to.
     * @return True if it comes after. False otherwise.
     */
    bool operator>(Data date) const;
};


#endif //PROJETO_DATA_H
