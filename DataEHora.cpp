//
// Created by andre on 10/14/2020.
//

#include "DataEHora.h"

DataEHora::DataEHora(int dd, int mm, int yy, int hh, int min):Data(dd, mm, yy), Hora(hh, min) {}

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