//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_DATAEHORA_H
#define PROJETO_DATAEHORA_H

#include "Data.h"
#include "Hora.h"

using namespace std;

class DataEHora: public Data, Hora{
public:
    /**
     * Constructor. Initializes day, month, year, hour, minute.
     * @param dd
     * @param mm
     * @param yy
     * @param hh
     * @param min
     */
    DataEHora(int dd, int mm, int yy, int hh, int min);
    /**
     * Adds an Hora object to a DataEHora object.
     * @param time - Duration to add to the date and time.
     * @return End date and time of an event.
     */
    DataEHora operator+(Hora time) const;
    /**
    * Checks if a date and time is lesser than another. It is lesser if it comes before.
    * @return True if it is. False otherwise.
    */
    bool operator<(DataEHora dateTime) const;
    /**
    * Checks if a date and time is greater than another. It is greater if it comes after.
    * @return True if it is. False otherwise.
    */
    bool operator>(DataEHora dateTime) const;
};


#endif //PROJETO_DATAEHORA_H
