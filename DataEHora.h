#ifndef PROJETO_DATAEHORA_H
#define PROJETO_DATAEHORA_H

#include "Data.h"
#include "Hora.h"

using namespace std;

class DataEHora: public Data, public Hora{
public:
    DataEHora() = default;
    /**
     * Constructor. Initializes day, month, year, hour, minute.
     * @param dd - Day
     * @param mm - Month
     * @param yy - Year
     * @param hh - Hour
     * @param min - Minute
     */
    DataEHora(int dd, int mm, int yy, int hh, int min);
    /**
     * Copy constructor.
     */
    DataEHora(const DataEHora &dateAndTime);
    /**
     * Sets day, month, year, hour, minute.
     * @param dd - Day
     * @param mm - Month
     * @param yy - Year
     * @param hh - Hour
     * @param min - Minute
     */
    void setDateAndTime(unsigned int dd, unsigned int mm, unsigned int yy,
                        unsigned int hh, unsigned int min);
    /**
     * Sets date and time.
     */
    void setDateAndTime(const DataEHora & dateAndTime);
    /**
     * @return DataEHora object.
     */
    DataEHora getDateAndTime() const;
    /**
     * Adds an Hora object to a DataEHora object.
     * @param time - Duration to add to the date and time.
     * @return End date and time of an event.
     */
    DataEHora operator+(const Hora& time) const;
    /**
    * Checks if a date and time is lesser than another. It is lesser if it comes before.
    * @return True if it is. False otherwise.
    */
    bool operator<(const DataEHora& dateTime) const;
    /**
    * Checks if a date and time is greater than another. It is greater if it comes after.
    * @return True if it is. False otherwise.
    */
    bool operator>(const DataEHora& dateTime) const;
    /**
    * Checks if two DataEHora objects are equal.
    * @return True they are. False otherwise.
    */
    bool operator==(const DataEHora& dateTime) const;
    /**
     * Output operator.
     */
    friend ostream &operator<<(ostream &output, const DataEHora &dateAndTime);
};


#endif //PROJETO_DATAEHORA_H
