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
     * @param dd Day
     * @param mm Month
     * @param yy Year
     * @param hh Hour
     * @param min Minute
     */
    DataEHora(int dd, int mm, int yy, int hh, int min);
    /**
     * Copy constructor.
     */
    DataEHora(const DataEHora &dateAndTime);
    /**
     * Sets day, month, year, hour, minute.
     * @param dd Day
     * @param mm Month
     * @param yy Year
     * @param hh Hour
     * @param min Minute
     * @throws InvalidDate if parameter date is not valid in the gregorian calendar
     * @throws InvalidTime if time formed by parameters is not valid
     */
    void setDateAndTime(int dd, int mm, int yy, int hh, int min) noexcept(false);
    /**
     * Sets date and time.
     * @throws InvalidDate if parameter's date is not valid in the gregorian calendar
     * @throws InvalidTime if parameter time is not valid
     */
    void setDateAndTime(const DataEHora & dateAndTime) noexcept(false);
    /**
     * Sets date and time from string.
     * @throws invalid_argument if parameter string is not properly formatted (dd/mm/yyyy HHhMMmin)
     * @throws InvalidDate if parameter's date is not valid in the gregorian calendar
     * @throws InvalidTime if parameter's time is not valid
     */
    void setDateAndTime(const string &in) noexcept(false);
    /**
     * @return DataEHora object.
     */
    DataEHora getDateAndTime() const;
    /**
     * @return Returns reference to itself.
     */
    DataEHora& getDateAndTimeRef();
    /**
     * Checks if date and time are valid.
     * @return True if they are. False otherwise.
     */
    bool valid() const override;
    /**
     * @return Returns formatted string with the date and time.
     */
    string str() const override;
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
    friend ostream& operator<<(ostream& output, const DataEHora& dateAndTime);
    /**
     * Input operator
     * @throws InvalidDate if input is not a valid date in the gregorian calendar
     * @throws InvalidTime if input is not a valid time
     */
    friend istream& operator>>(istream& input, DataEHora& dateAndTime) noexcept(false);
};


#endif //PROJETO_DATAEHORA_H
