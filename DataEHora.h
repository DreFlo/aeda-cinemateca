//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_DATAEHORA_H
#define PROJETO_DATAEHORA_H

#include "Data.h"
#include "Hora.h"

using namespace std;

class DataEHora {
private:
    const Data date;
    const Hora time;
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

};


#endif //PROJETO_DATAEHORA_H
