//
// Created by andre on 10/15/2020.
//

#include "Utils.h"

bool checkTimeValidity(unsigned int hh, unsigned int mm) {
    return hh < 24 && mm < 60;
}

bool checkDateValidity(unsigned int dd, unsigned int mm, unsigned int yy) {
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

bool checkDateAndTimeValidity(unsigned int dd, unsigned int mm, unsigned int yy, unsigned int hh, unsigned int min) {
    return checkDateValidity(dd, mm, yy) && checkTimeValidity(hh, min);
}

bool checkTimeIntervalValidity(DataEHora start, DataEHora end) {
    return start > end;
}