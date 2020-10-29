#ifndef PROJETO_EVENTO_H
#define PROJETO_EVENTO_H

#include <utility>
#include "IntervaloDeTempo.h"

using namespace std;

class Evento: public IntervaloDeTempo {
    string name;
    unsigned int maxCapacity{};
    float price{};
    DataEHora start;
    Hora duration;
public:
    /**
     * Default constructor.
     */
    Evento() = default;
    /**
     * Constructor.
     * @param nm - Event's name.
     * @param mxCp - Event's maximum capacity.
     * @param prc - Event's price of admission.
     * @param st - Event's start date and time.
     * @param drtn - Event's duration.
     */
    Evento(string nm, unsigned int mxCp, float prc, const DataEHora& st, const Hora& drtn);
    /**
     * Copy constructor.
     */
    Evento(const Evento& newEvent);
    /**
     * @return Event's name.
     */
    string getName() const;
    /**
     * @return Event's maximum capacity.
     */
    unsigned int getMaxCapacity() const;
    /**
     * @return Event's price of admission.
     */
    float getPrice() const;
    /**
     * @return Event's start date and time.
     */
    DataEHora getStart() const;
    /**
     * @return Event's duration.
     */
    Hora getDuration() const;
    /**
     * Changes event's name.
     */
    void setName(string nm);
    /**
     * Changes event's maximum capacity.
     */
    void setMaxCapacity(unsigned int mxCp);
    /**
     * Changes event's price of admission.
     */
    void setPrice(float prc);
    /**
     * Changes event's start date and time.
     */
    void setStart(const DataEHora& st);
    /**
     * Changes event's duration.
     */
    void setDuration(const Hora& drtn);
};


#endif //PROJETO_EVENTO_H
