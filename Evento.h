#ifndef PROJETO_EVENTO_H
#define PROJETO_EVENTO_H

#include <utility>
#include "IntervaloDeTempo.h"
#include "Aderente.h"

using namespace std;

class Evento: public IntervaloDeTempo {
    string name, room = "NULL";
    unsigned int maxAttendance{};
    float price{}, total = 0;
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
     * @return Event's name.
     */
    string getName() const;
    /**
     * @return Event's room.
     */
    string getRoom() const;
    /**
     * @return Event's maximum capacity.
     */
    unsigned int getMaxAttendance() const;
    /**
     * @return Event's price of admission.
     */
    float getPrice() const;
    /**
     * @return Event's duration.
     */
    Hora getDuration() const;
    /**
     * Changes event's name.
     */
    void setName(string nm);
    /**
     * Changes event's room.
     */
    void setRoom(string rm);
    /**
     * Changes event's maximum capacity.
     */
    void setMaxAttendance(unsigned int mxCp);
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
    /**
     * @return Returns formatted string with the event.
     */
    string str() const noexcept override;
    bool operator<(Evento & E2) const;
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Evento& event) noexcept;
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Evento& event);
};

#endif //PROJETO_EVENTO_H
