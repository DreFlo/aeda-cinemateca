//
// Created by andre on 10/14/2020.
//

#include "DataEHora.h"

DataEHora::DataEHora(int dd, int mm, int yy, int hh, int min):Data(dd, mm, yy), Hora(hh, min) {}

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
    unsigned int resMin, resHour, resDay = this->getDay(), resMonth, resYear;
    resMin = (this->getMinute() + time.getMinute()) % 60;
    resHour = (this->getHour() + time.getHour() + ((this->getMinute() + time.getMinute()) / 60)) % 24;
    resDay += (this->getHour() + time.getHour() + ((this->getMinute() + time.getMinute()) / 60)) / 24;


}