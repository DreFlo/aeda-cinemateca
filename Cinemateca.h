//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_CINEMATECA_H
#define PROJETO_CINEMATECA_H

#include "Evento.h"
#include "Aderente.h"
#include "Sala.h"
#include "Trabalhador.h"
#include <fstream>
#include <queue>
#include <unordered_set>

#define PLANNING2FAR_AHEAD "You are trying to schedule an event way too far ahead from today. \nWe can only schedule your event up to a year from now, \nConsider waiting some time"
#define NO_SPACE_NOR_TIME "It is going to be impossible to schedule your event since there is no room nor time slot available"
#define NO_TIME_AVAILABLE "It is going to be impossible to schedule your event since there is no room available"
#define NO_SPACE_AVAILABLE "It is going to be impossible to schedule your event since there is no time slot available"
#define NO_EVENTS_THERE_FUTURE "Looks like there is no events schedule for that time interval \nYou can be de first ;)"
#define NO_EVENTS_THERE_PAST "Looks like there is no events schedule for that time interval"
#define COULDNT_OPEN_FILE "Well that file path doesn't exist \nFor reference the file path was: "

using namespace std;

struct TrabHashS{
    int operator() (const Trabalhador &t) const{
        int v;
        for (auto num : to_string(t.getNIF())){
            v = 37 * v + num;
        }
        return v;
    }
    bool operator() (const Trabalhador &t1, const Trabalhador &t2) const{
        return t1.getNIF() == t2.getNIF();
    }
};

typedef unordered_set<Trabalhador, TrabHashS, TrabHashS> TrabH;

class Cinemateca {
    static DataEHora hoje;
    std::string morada;
    std::vector<Sala> Salas;
    std::vector<Aderente> Aderentes;
    std::vector<Evento> EventosAntigos;
    std::vector<Evento> EventosHoje;
    std::vector<Evento> EventosFuturos;
    std::priority_queue<Evento, vector<Evento>, CmpAvgReview> EventsByAvgReview;
    static TrabH Trabs;
public:
    /**
     * Constructor.
     * @param m - Cinemateca's address
     * @param h - Current Date and Time
     */
    Cinemateca(std::string m, const DataEHora& h);
    /**
     * Constructor.
     * @param m - Cinemateca's address
     * @param h - Current Date and Time
     * @param ss - Vector of room(s) (Sala) to begin with
     */
    Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss);
    /**
     * Constructor.
     * @param m - Cinemateca's address
     * @param h - Current Date and Time
     * @param ss - Vector of room(s) (Sala) to begin with
     * @param as - Vector of Adherent(s) (Aderente) to begin with
     */
    Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss, std::vector<Aderente> as);
    /**
     * Constructor.
     * @param m - Cinemateca's address
     * @param h - Current Date and Time
     * @param as - Vector of Adherent(s) (Aderente) to begin with
     */
    Cinemateca(std::string m, const DataEHora& h, std::vector<Aderente> as);
    /**
     * @returns Current Date and Time
     */
    static DataEHora GetHoje();
    /**
     * @returns Cinemateca's address
     */
    std::string GetMorada();
    /**
     * @returns Cinemateca's rooms
     */
    std::vector<Sala> Getsalas();
    /**
     * @returns Cinemateca's current Aderente(s)
     */
    std::vector<Aderente> GetAderentes();
    /**
     * @returns Cinemateca's old events
     */
    std::vector<Evento> GetEventosAntigos();
    /**
     * @returns Cinemateca's events for today
     */
    std::vector<Evento> GetEventosHoje();
    /**
     * @returns Cinemateca's future events
     */
    std::vector<Evento> GetEventosFuturos();
    /**
     * @brief Shows the event heap on screen
     */
    void printEventHeap();
    /**
     * @brief Get best reviewed event
     * @return Returns best reviewed event
     */
    Evento getTopEvent();
    /**
     * @brief Get best reviewed event priced at certain range
     * @param min minimum price
     * @param max maximum price
     * @return Return best event
     * @throws NoEventPricedBetween if there is no event in range
     */
    Evento getTopEventByPrice(float min, float max) noexcept(false);
    /**
     * @brief Fills the event heap
     */
    void createEventHeap();
    /**
     * Changes the current Date and Time and moves events to the correct vector
     * @param h - Date and Time to chance to
     */
    void MudarAgora(const DataEHora &h);
    /**
     * Adds a room (Sala) to the Cinemateca
     * @param sal - room (Sala) to add to Cinemateca
     * @throw sal - if there are 2 equal rooms (Sala)
     */
    void AdicionarSala(const Sala &sal);
    /**
     * Adds a vector of room(s) (Sala) to the Cinemateca
     * @param sals - room(s) (Sala) to add to Cinemateca
     */
    void AdicionarSalas(const std::vector<Sala> &sals);
    /**
     * Sets the rooms (Sala) of Cinemateca
     * @param sals - room(s) (Sala) that Cinemateca has now
     */
    void SetSalas(const std::vector<Sala> &sals);
    /**
     * Sorts Cinemateca's vector of room(s) (Sala)
     */
    void SortSalas();
    /**
     * Adds a Adherent (Aderente) to the Cinemateca
     * @param aderen - Adherent (Aderente) to add to Cinemateca
     * @throw aderen - if there are 2 equal Adherents (Aderente)
     */
    void AdicionarAderente(const Aderente &aderen);
    /**
     * Adds a vector of Adherent (Aderente) to the Cinemateca
     * @param aderens - Adherent(s) (Aderente) to add to Cinemateca
     */
    void AdicionarAderentes(const std::vector<Aderente> &aderens);
    /**
     * Sets the Adherents (Aderente) of Cinemateca
     * @param aderens - Adherent(s) (Aderente) that Cinemateca has now
     */
    void SetAderentes(const std::vector<Aderente> &aderens);
    /**
     * Sorts Cinemateca's vector of Adherent(s) (Aderente)
     */
    void SortAderentes();
    /**
     * Adds an Event (Evento) to the Cinemateca
     * @param event - event (Evento) to add to Cinemateca
     * @throw PLANNING2FAR_AHEAD - if the event to add is further than a year away
     * @throw event - if there are 2 equal Events (Evento)
     */
    void AdicionarEvento(Evento event);
    /**
     * Adds a vector of Events (Evento) to Cinemateca
     * @param events - Events (Evento) to add to Cinemateca
     */
    void AdicionarEventos(std::vector<Evento> events);
    /**
     * Sets the Events (Evento) of Cinemateca
     * @param events - Events (Evento) that Cinemateca has now
     */
    void SetEventos(std::vector<Evento> events);
    /**
     * Sorts Cinemateca's vector of  Events (Evento)
     */
    void SortEventos();
    /**
     * Searches for the Events of a specific Date (Data)
     * @param d - The Date (Data) to search events
     * @return A sorted vector of Events (Evento) from the given date
     */
    std::vector<Evento> ProcurarEventosData(const Data &d);
    /**
     * Searches for the Events after a specific Date (Data)
     * @param d - The Date (Data) after which to search events
     * @return A sorted vector of Events (Evento) after the given date
     * @throw NO_EVENTS_THERE_FUTURE if there weren't any events (Evento) after the given Date (Data)
     */
    std::vector<Evento> ProcurarEventosDepoisData(const Data &d);
    /**
     * Searches for the Events before a specific Date (Data)
     * @param d - The Date (Data) before which to search events
     * @return A sorted vector of Events (Evento) before the given date
     * @throw NO_EVENTS_THERE_PAST if there weren't any events (Evento) before the given Date (Data)
     */
    std::vector<Evento> ProcurarEventosAntesData(const Data &d);
    /**
     * Reads a .txt file of Events (Evento) and adds them to Cinemateca
     * @param filepath - the file path for the file from which to read Events (Evento)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void LerFicheiroEventos(const std::string& filepath);
    /**
     * Writes to a .txt file the Events (Evento) of Cinemateca
     * @param filepath - the file path for the file to write Cinemateca's Events (Evento)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void EscreverFicheiroEventos(const std::string& filepath);
    /**
     * Reads a .txt file of Adherent (Aderente) and adds them to Cinemateca
     * @param filepath - the file path for the file from which to read Adherents (Aderente)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void LerFicheiroAderentes(const std::string& filepath);
    /**
     * Writes to a .txt file the Adherents (Aderente) of Cinemateca
     * @param filepath - the file path for the file to write Cinemateca's Adherent (Aderente)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void EscreverFicheiroAderentes(const std::string& filepath);
    /**
     * Reads a .txt file of rooms (Sala) and adds them to Cinemateca
     * @param filepath - the file path for the file from which to read rooms (Sala)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void LerFicheiroSalas(std::string filepath);
    /**
     * Writes to a .txt file the rooms (Sala) of Cinemateca
     * @param filepath - the file path for the file to write Cinemateca's rooms (Sala)
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void EscreverFicheiroSalas(const std::string& filepath);
    /**
     * Add element to hash table
     * @param t - Trabalhador to add
     * @return true if successful, else false
     */
    bool AddToHash(Trabalhador &t);
    /**
     * Remove element from hash table
     * @param t - element to remove
     */
    void RemoveFromHash(Trabalhador &t);
    /**
     * Gets the Hash table
     * @return Hash table
     */
    TrabH& getHash();
    /**
     * Writes to a .txt file the Trabalhadores in the hash table Trabs
     * @param filepath - the file path for the file to write the Trabalhadores
     * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
     */
    void EscreverHash(const string& filepath);
    /**
    * Reads a .txt file of Trabalhadores
    * @param filepath - the file path for the file from which to the Trabalhadores
    * @throw COULDNT_OPEN_FILE + filepath if the file couldn't be open
    */
    void LerHash(string filepath);
};

class NoEventPricedBetween {
public:
    const float min, max;
    NoEventPricedBetween(float m, float M):min(m), max(M) {}
    pair<int, int> getPriceRange() { return make_pair(min, max); }
};

#endif //PROJETO_CINEMATECA_H
