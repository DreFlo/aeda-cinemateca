#ifndef PROJETO_HORA_H
#define PROJETO_HORA_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include <utility>

using namespace std;

class InvalidTime;

class Hora {
private:
    int hour = 0, minute = 0;
public:
    /**
     * Default constructor.
     */
    Hora() = default;
    /**
     * Class constructor. Initializes hour and minute. Does not have to be a valid time.
     * @param hh Hour
     * @param mm Minute
     */
    Hora(int hh, int mm);
    /**
     * Copy constructor. Parameter does not have to be a valid time.
     */
    Hora(const Hora &time);
    /**
     * @return Returns the time
     */
    Hora getTime() const;
    /**
     * @return Returns a reference to the object.
     */
    Hora& getTimeRef();
    /**
     * @return Returns the hour of the time.
     */
    int getHour() const;
    /**
     * @return Returns the minute of the time.
     */
    int getMinute() const;
    /**
     * Sets hour and minute.
     * @param hh Hour
     * @param mm Minute
     * @throws InvalidTime if time formed by parameters is not valid
     */
    void setTime(int hh, int mm) noexcept(false);
    /**
     * Sets time.
     * @throws InvalidTime if parameter time is not valid
     */
    void setTime(const Hora& time) noexcept(false);
    /**
     * Sets date from string.
     * @throws invalid_argument if parameter in is not correctly formatted (HHhMMmin)
     * @throws InvalidTime if parameter time is not valid
     */
    void setTime(const string& in) noexcept(false);
    /**
    * Changes hour value.
    * @param newHour new hour value
    * @throws InvalidTime if parameter does not form a valid time
    */
    void setHour(int newHour) noexcept(false);
    /**
    * Changes minute value.
    * @param newMin new min value
    * @throws InvalidTime if parameter does not form a valid time
    */
    void setMinute(int newMin) noexcept(false);
    /**
     * Checks if time is valid.
     * @return True if it is. False otherwise.
     */
    virtual bool valid() const;
    /**
     * @return Returns a formatted string with the time.
     */
    virtual string str() const;
    /**
     * A time is lesser than another if it comes before.
     * @return True if lesser. False otherwise.
     */
    bool operator<(const Hora &time) const;
    /**
     * A time is greater than another if it comes after.
     * @return True if greater. False otherwise.
     */
    bool operator>(const Hora &time) const;
    /**
     * Checks if two times are equal.
     * @return True if they are. False otherwise.
     */
    bool operator==(const Hora &time) const;
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Hora& time);
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Hora& time) noexcept(false);
};

class InvalidTime: public exception {
    const Hora time;
    const string msg;
public:
    InvalidTime(const Hora &T, string M):time(T), msg(std::move(M)) {}
    const Hora & getTime() { return time; }
    string getMsg() { return msg; }
};

#endif //PROJETO_HORA_H
