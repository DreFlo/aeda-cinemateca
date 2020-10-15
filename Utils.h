//
// Created by andre on 10/15/2020.
//

#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#include <algorithm>
#include "DataEHora.h"

using namespace std;

/**
 * Checks if the function parameters form a valid time of day.
 * @param hh - Hour of the day. Must be between 0 and 23.
 * @param mm - Minute of the hour. Must be between 0 and 59.
 * @return True if parameters are valid. False otherwise.
 */
bool checkTimeValidity(unsigned int hh, unsigned int mm);
/**
 * Checks if the parameters form a valid date in the gregorian calendar.
 * @param dd - day
 * @param mm - month
 * @param yy - year
 * @return True if date is valid. False otherwise.
 */
bool checkDateValidity(unsigned int dd, unsigned int mm, unsigned int yy);
/**
 * Checks if parameters form valid sate and time
 * @param dd - Day
 * @param mm - Month
 * @param yy - Year
 * @param hh - Hour
 * @param mim - Minute
 * @return True if they do. False otherwise.
 */
bool checkDateAndTimeValidity(unsigned int dd, unsigned int mm, unsigned int yy, unsigned int hh, unsigned int mim);
/**
 * Checks if the parameters form a valid time interval.
 * @param start - Beginnig of the interval.
 * @param end - End of the interval.
 * @return True if they do. False otherwise.
 */
bool checkTimeIntervalValidity(DataEHora start, DataEHora end);


#endif //PROJETO_UTILS_H
