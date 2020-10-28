//
// Created by andre on 10/14/2020.
//

#include "DataEHora.h"

DataEHora::DataEHora(int dd, int mm, int yy, int hh, int min):Data(dd, mm, yy), Hora(hh, min) {}

DataEHora::DataEHora(const DataEHora &dateAndTime):Data(dateAndTime.getDate()), Hora(dateAndTime.getTime()) {}

void DataEHora::initDateAndTime(int dd, int mm, int yy, int hh, int min) {
    this->initTime(hh, min);
    this->initDate(dd, mm, yy);
}

bool DataEHora::operator<(DataEHora dateTime) const {
    if (this->getDate() < dateTime.getDate())
        return true;
    else if (this->getDate() == dateTime.getDate())
        return this->getTime() < dateTime.getTime();
    return false;
}

bool DataEHora::operator>(DataEHora dateTime) const {
    if (this->getDate() > dateTime.getDate())
        return true;
    else if (this->getDate() == dateTime.getDate())
        return this->getTime() > dateTime.getTime();
    return false;
}

bool DataEHora::operator==(DataEHora dateTime) const {
    return this->getDate() == dateTime.getDate() && this->getTime() == dateTime.getTime();
}

DataEHora DataEHora::operator+(Hora time) const {
    DataEHora result;
    unsigned int resMin, resHour, resDay = this->getDay(), resMonth = this->getMonth(), resYear = this->getYear();
    unsigned int longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    //Get correct hour and minute of the result.
    resMin = (this->getMinute() + time.getMinute()) % 60;
    resHour = (this->getHour() + time.getHour() + ((this->getMinute() + time.getMinute()) / 60)) % 24;
    //Get correct day, month, year.
    resDay += (this->getHour() + time.getHour() + ((this->getMinute() + time.getMinute()) / 60)) / 24;
    if (resMonth == 2 && resYear % 4 == 0 && resDay > 29) {
        resMonth++;
        resDay -= 29;
    }
    else if (resMonth == 2 && resYear % 4 == 1 && resDay > 28) {
        resMonth++;
        resDay -= 28;
    }
    else if (find(longMonths, longMonths + 7, resMonth) && resDay > 31) {
        resMonth++;
        resDay -= 31;
    }
    else if (!find(longMonths, longMonths + 7, resMonth) && resDay > 30) {
        resMonth++;
        resDay -= 30;
    }
    if (resMonth > 12) {
        resYear++;
        resMonth -= 12;
        resDay -= 31;
    }
    //Init result.
    result.initDateAndTime(resDay, resMonth, resYear, resHour, resMin);
    return result;
}


