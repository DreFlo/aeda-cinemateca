//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_HORA_H
#define PROJETO_HORA_H

using namespace std;

class Hora {
private:
    const unsigned int hour, minute;
public:
    /**
     * Class constructor. Initializes hour and minute.
     * @param hh
     * @param mm
     */
    Hora(int hh, int mm);
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
