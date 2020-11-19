//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_CINEMATECA_H
#define PROJETO_CINEMATECA_H

#include "Evento.h"
#include "Aderente.h"
#include "Sala.h"
#include <fstream>

#define PLANNING2FAR_AHEAD "You are trying to schedule an event way too far ahead from today. \nWe can only schedule your event up to a year from now, \nConsider waiting some time"
#define NO_SPACE_NOR_TIME "It is going to be impossible to schedule your event since there is no room nor time slot available"
#define NO_TIME_AVAILABLE "It is going to be impossible to schedule your event since there is no room available"
#define NO_SPACE_AVAILABLE "It is going to be impossible to schedule your event since there is no time slot available"
#define NO_EVENTS_THERE_FUTURE "Looks like there is no events schedule for that time interval \nYou can be de first ;)"
#define NO_EVENTS_THERE_PAST "Looks like there is no events schedule for that time interval"
#define COULDNT_OPEN_FILE "Well that file path doesn't exist \nFor reference the file path was: "

using namespace std;

class Cinemateca {
    static DataEHora hoje;
    std::string morada;
    std::vector<Sala> Salas;
    std::vector<Aderente> Aderentes;
    std::vector<Evento> EventosAntigos;
    std::vector<Evento> EventosHoje;
    std::vector<Evento> EventosFuturos;

public:
    Cinemateca(std::string m, const DataEHora& h);
    Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss);
    Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss, std::vector<Aderente> as);
    Cinemateca(std::string m, const DataEHora& h, std::vector<Aderente> as);

    static DataEHora GetHoje();
    std::string GetMorada();
    std::vector<Sala> Getsalas();
    std::vector<Aderente> GetAderentes();
    std::vector<Evento> GetEventosAntigos();
    std::vector<Evento> GetEventosHoje();
    std::vector<Evento> GetEventosFuturos();

    void MudarAgora(const DataEHora &h);

    void AdicionarSala(const Sala &sal);
    void AdicionarSalas(const std::vector<Sala> &sals);
    void SetSalas(const std::vector<Sala> &sals);
    void SortSalas();

    void AdicionarAderente(const Aderente &aderen);
    void AdicionarAderentes(const std::vector<Aderente> &aderens);
    void SetAderentes(const std::vector<Aderente> &aderens);
    void SortAderentes();

    void AdicionarEvento(Evento event);
    void AdicionarEventos(std::vector<Evento> events);
    void SetEventos(std::vector<Evento> events);
    void SortEventos();

    std::vector<Evento> ProcurarEventosData(const Data &d);
    std::vector<Evento> ProcurarEventosDepoisData(const Data &d);
    std::vector<Evento> ProcurarEventosAntesData(const Data &d);

    void LerFicheiroEventos(const std::string& filepath);
    void EscreverFicheiroEventos(const std::string& filepath);

    void LerFicheiroAderentes(const std::string& filepath);
    void EscreverFicheiroAderentes(const std::string& filepath);

    void LerFicheiroSalas(const std::string& filepath);
    void EscreverFicheiroSalas(const std::string& filepath);
};


#endif //PROJETO_CINEMATECA_H
