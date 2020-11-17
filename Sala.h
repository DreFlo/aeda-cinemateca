
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
    string city;
public:
    /**
     * Class constructor
     * @param n Name of the room.
     * @param cap Room's capacity.
     * @param cit City where the room is located.
     */
    Sala(string n, int cap, string cit);
    /**
     * @return Room's name.
     */
    string getName() const;
    /**
     * @return Room capacity.
     */
    int getCapacity() const;
    /**
     * @return City where room is located.
     */
    string getCity() const;
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
     * Records event in room's history.
     * @param event Event that occured.
     * @param time Time
     */
    void endEvent(const Evento event, const IntervaloDeTempo time);
private:
    vector<IntervaloDeTempo> ocupacao;
    //vector<Evento, IntervaloDeTempo> pastEvents;
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
