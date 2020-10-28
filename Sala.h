
#ifndef CINEMATECA_H_SALA_H
#define CINEMATECA_H_SALA_H

#include <string>
#include <vector>

#include "IntervaloDeTempo.h"

using namespace std;

class Sala{
    string name;
    int capacity;
public:
    Sala(string n, int cap);
    string getName() const;
    int getCapacity() const;
    bool checkAvailability(const IntervaloDeTempo time) const;
    void addEvent(const IntervaloDeTempo time);
    void removeEvent(const IntervaloDeTempo time);
private:
    vector<IntervaloDeTempo> availability;
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
