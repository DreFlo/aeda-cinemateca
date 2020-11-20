#ifndef PROJETO_EVENTO_H
#define PROJETO_EVENTO_H

#include <utility>
#include "IntervaloDeTempo.h"
#include "Aderente.h"

using namespace std;

class Evento: public IntervaloDeTempo {
    string name, room = "NULL";
    int maxAttendance, lot = 0;
    float price, total = 0.0;
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
     * @param prc - Event's price of admission.
     * @param st - Event's start date and time.
     * @param drtn - Event's duration.
     * @param mxAtn - Event's maximum capacity (default = 0)
     * @param sala - Event's room (default = "NULL")
     */
    Evento(string nm, float prc, const DataEHora& st, const Hora& drtn, int mxAtn = 0, string sala = "NULL");
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
    int getMaxAttendance() const;
    /**
     * @return Event's price of admission.
     */
    float getPrice() const;
    /**
     * @return Event's duration.
     */
    Hora getDuration() const;
    /**
     * @return The total amount made from the event.
     */
    float getTotal() const;
    /**
     * @return The number of people signed up for the event
     */
    int getLot() const;
    /**
     * Increases Event's attendance and increases total monetary amount made by the Event accordingly
     * @param C Client to sign up
     * @throws EventFull if Event's maximum attendance has alredy been reached
     */
    void signUp(const Cliente & C) noexcept(false);
    /**
     * Increases Event's attendance and increases total monetary amount made by the Event accordingly
     * @param A Adherent to sign up
     * @param free true if Event is free for Adherent
     * @throws EventFull if Event's maximum attendance has alredy been reached
     */
    void signUp(Aderente & A, bool free = false) noexcept(false);
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
    void setMaxAttendance(int mxCp);
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
    string str() const override;
    /**
     * An event is lesser than another if it starts before.
     * @return True if it is. False otherwise.
     */
    bool operator<(Evento & E2) const;
    /**
     * Tests equality.
     */
    bool operator==(Evento & E2) const;
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Evento& event);
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Evento& event);
};

class EventFull: public exception {};

#endif //PROJETO_EVENTO_H
