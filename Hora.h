//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_HORA_H
#define PROJETO_HORA_H

#include <stdexcept>

using namespace std;

class Hora {
private:
    unsigned int hour, minute;
public:
    /**
     * Default constructor.
     */
    Hora() = default;
    /**
     * Class constructor. Initializes hour and minute.
     * @param hh - Hour of the time.
     * @param mm - Minute of the time.
     */
    Hora(unsigned int hh, unsigned int mm);
    /**
     * Initializes hour and minute.
     * @param hh - Hour of the time.
     * @param mm - Minute of the time.
     */
    void initTime(unsigned int hh, unsigned int mm);
    /**
     * @return Returns the time
     */
    Hora getTime() const;
    /**
     * @return Returns the hour of the time.
     */
    unsigned int getHour() const;
    /**
     * @return Returns the minute of the time.
     */
    unsigned int getMinute() const;
    /**
     * A time is lesser than another if it comes before.
     * @param time - The time to be compared to.
     * @return True if lesser. False otherwise.
     */
    bool operator<(Hora time) const;
    /**
     * A time is greater than another if it comes after.
     * @param time - The time to be compared to.
     * @return True if greater. False otherwise.
     */
    bool operator>(Hora time) const;
};


#endif //PROJETO_HORA_H
