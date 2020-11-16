//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_CINEMATECA_H
#define PROJETO_CINEMATECA_H

#include "Evento.h"
#include "Aderente.h"
#include "Sala.h"

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
    Cinemateca(std::string m, DataEHora h, std::vector<Aderente> as);

    static DataEHora GetHoje();
    std::string GetMorada();
    std::vector<Sala> Getsalas();
    std::vector<Aderente> GetAderentes();
    std::vector<Evento> GetEventosAntigos();
    std::vector<Evento> GetEventosHoje();
    std::vector<Evento> GetEventosFuturos();

    static void MudarAgora(const DataEHora &h);

    void AdicionarSala(const Sala &s);
    void AdicionarSalas(const std::vector<Sala> &ss);
    void SetSalas(const std::vector<Sala> &ss);

    void AdicionarAderente(const Aderente &a);
    void AdicionarAderentes(const std::vector<Aderente> &as);
    void SetAderentes(const std::vector<Aderente> &as);

    void AdicionarEvento(const Evento &e);
    void AdicionarEventos(const std::vector<Evento> &es);
    void SetEventos(const std::vector<Evento> &es);

    std::vector<Evento> ProcurarEventosData(const Data &d);
    std::vector<Evento> ProcurarEventosDepoisData(const Data &d);
    std::vector<Evento> ProcurarEventosAntesData(const Data &d);
};


#endif //PROJETO_CINEMATECA_H
