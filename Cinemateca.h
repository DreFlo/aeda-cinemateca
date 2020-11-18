//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_CINEMATECA_H
#define PROJETO_CINEMATECA_H

#include "Evento.h"
#include "Aderente.h"
#include "Sala.h"
#include <fstream>

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

    static void MudarAgora(const DataEHora &h);

    void AdicionarSala(const Sala &sal);
    void AdicionarSalas(const std::vector<Sala> &sals);
    void SetSalas(const std::vector<Sala> &sals);

    void AdicionarAderente(const Aderente &aderen);
    void AdicionarAderentes(const std::vector<Aderente> &aderens);
    void SetAderentes(const std::vector<Aderente> &aderens);

    void AdicionarEvento(Evento event);
    void AdicionarEventos(std::vector<Evento> events);
    void SetEventos(std::vector<Evento> events);

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
