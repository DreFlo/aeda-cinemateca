//
// Created by andre on 10/14/2020.
//

#include "Cinemateca.h"

Cinemateca::Cinemateca(std::string m, Data h, std::string f)
{
    morada = m;
    hoje = h;
    ficheiro = f;
}
Cinemateca::Cinemateca(std::string m, Data h, std::string f, std::vector<Sala> ss)
{
    morada = m;
    hoje = h;
    ficheiro = f;
    Salas = ss;
}
Cinemateca::Cinemateca(std::string m, Data h, std::string f, std::vector<Sala> ss, std::vector<Aderente> as)
{
    morada = m;
    hoje = h;
    ficheiro = f;
    Salas = ss;
    Aderentes = as;
}
Cinemateca::Cinemateca(std::string m, Data h, std::string f, std::vector<Aderente> as)
{
    morada = m;
    hoje = h;
    ficheiro = f;
    Aderentes = as;
}

Data Cinemateca::GetHoje(){
    return hoje;
}
std::string Cinemateca::GetMorada(){
    return morada;
}
std::vector<Sala> Cinemateca::Getsalas(){
    return Salas;
}
std::vector<Aderente> Cinemateca::GetAderentes(){
    return Aderentes;
}
std::vector<Evento> Cinemateca::GetEventosAntigos(){
    return EventosAntigos;
}
std::vector<Evento> Cinemateca::GetEventosHoje(){
    return EventosHoje;
}
std::vector<Evento> Cinemateca::GetEventosFuturos(){
    return EventosFuturos;
}


void Cinemateca::MudarDiaAtual(const Data &h)
{
    hoje = h;
}

void Cinemateca::AdicionarSala(const Sala &s)
{
    Salas.push_back(s);
}
void Cinemateca::AdicionarSalas(const std::vector<Sala> ss)
{
    for(auto sala : ss){
        Salas.push_back(sala);
    }
}
void Cinemateca::SetSalas(const std::vector<Sala> ss)
{
    Salas = ss;
}

void Cinemateca::AdicionarAderente(const Aderente a)
{
    Aderentes.push_back(a);
}
void Cinemateca::AdicionarAderentes(std::vector<Aderente> as)
{
    for(auto aderen : as){
        Aderentes.push_back(aderen);
    }
}
void Cinemateca::SetAderentes(const std::vector<Aderente> as)
{
    Aderentes = as;
}

/*
 * to implent
 */
void AdicionarEvento(const Evento &e);
void AdicionarEventos(const std::vector<Evento> &es);
void SetEventos(const std::vector<Evento> &es);

std::vector<Evento> ProcurarEventosData(const Data &d);
std::vector<Evento> ProcurarEventosDepoisData(const Data &d);
std::vector<Evento> ProcurarEventosAntesData(const Data &d);