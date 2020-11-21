
#ifndef CINEMATECA_H_SALA_H
#define CINEMATECA_H_SALA_H

#include <string>
#include <vector>

#include "IntervaloDeTempo.h"
#include "Evento.h"

using namespace std;

class Sala{
    string name;
    int capacity;
public:
    /**
     * Class constructor
     * @param n Name of the room.
     * @param cap Room's capacity.
     */
    Sala(string n, int cap);
    /**
     * @return Room's name.
     */
    string getName() const;
    /**
     * @return Room capacity.
     */
    int getCapacity() const;
    /**
     * Checks if room is available to schedule on a specific time.
     * @param time Time when the event is to be scheduled.
     * @return True if room is available, else false.
     */
    bool checkAvailability(const IntervaloDeTempo time) const;
    /**
     * Adds event to specific room.
     * @param time Time when the event is to be scheduled.
     */
    void addEvent(const IntervaloDeTempo time);
    /**
     * Cancels an event in a specific room.
     * @param time Time of the event to be removed.
     */
    void cancelEvent(const IntervaloDeTempo time);
    /**
     * Changes Sala's name.
     * @param new_name New name for Sala.
     */
    void updateSalaName(string new_name);
    /**
     * Changes Sala's capacity.
     * @param new_cap New capacity.
     */
    void updateSalaCap(int new_cap);
    /**
     * Checks if two sala's are the same by checking their names;
     * @param s1 Sala to compare with.
     * @return True if the same, false otherwise.
     */
    bool operator==(const Sala &s1) const;
    /**
     * Checks if a Sala is less than another by which comes first alphabetically.
     * @param s1 Sala to compare with.
     * @return Ture if it comes before, false otherwise.
     */
    bool operator<(const Sala &s1) const;
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Sala &s1);
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Sala &s1);
private:
    vector<IntervaloDeTempo> ocupacao;
};


class AlreadyScheduled{
    IntervaloDeTempo time;
public:
    AlreadyScheduled(IntervaloDeTempo t) : time(t) {}
    IntervaloDeTempo getTime() const {return time;}
};

class NoEventScheduled{
    IntervaloDeTempo time;
public:
    NoEventScheduled(IntervaloDeTempo t) : time(t) {}
    IntervaloDeTempo getTime() const {return time;}
};


#endif //CINEMATECA_H_SALA_H
