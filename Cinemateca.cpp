//
// Created by andre on 10/14/2020.
//

#include "Cinemateca.h"

#include <utility>

DataEHora Cinemateca::hoje = DataEHora();

/*
 * Construtores
 */
Cinemateca::Cinemateca(std::string m, const DataEHora& h){
    morada = std::move(m);
    hoje = h;
}
Cinemateca::Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss){
    morada = std::move(m);
    hoje = h;
    Salas = std::move(ss);
}
Cinemateca::Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss, std::vector<Aderente> as){
    morada = std::move(m);
    hoje = h;
    Salas = std::move(ss);
    Aderentes = std::move(as);
}
Cinemateca::Cinemateca(std::string m, const DataEHora& h, std::vector<Aderente> as){
    morada = std::move(m);
    hoje = h;
    Aderentes = std::move(as);
}


/*
 * Gets
 */
DataEHora Cinemateca::GetHoje(){
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



void Cinemateca::MudarAgora(const DataEHora &h){
    hoje = h;
}


void Cinemateca::AdicionarSala(const Sala &sal){
    Salas.push_back(sal);
}
void Cinemateca::AdicionarSalas(const std::vector<Sala> &sals){
    for(const auto& sala : sals){
        Salas.push_back(sala);
    }
}
void Cinemateca::SetSalas(const std::vector<Sala> &sals){
    Salas = sals;
}

void Cinemateca::AdicionarAderente(const Aderente &aderen){
    Aderentes.push_back(aderen);
}
void Cinemateca::AdicionarAderentes(const std::vector<Aderente> &aderens){
    for(const auto& aderen : aderens){
        Aderentes.push_back(aderen);
    }
}
void Cinemateca::SetAderentes(const std::vector<Aderente> &aderens){
    Aderentes = aderens;
}

void Cinemateca::AdicionarEvento(const Evento &event){
    if(event.getStart() < this->GetHoje()){
        EventosAntigos.push_back(event);
        sort(EventosAntigos.begin(), EventosAntigos.end());
    }
    else if(event.getStart() == this->GetHoje()){
        EventosHoje.push_back(event);
        sort(EventosHoje.begin(), EventosHoje.end());
    }
    else{
        EventosFuturos.push_back(event);
        sort(EventosFuturos.begin(), EventosFuturos.end());
    }
}
void Cinemateca::AdicionarEventos(const std::vector<Evento> &events){
    for(const auto& event : events){
        AdicionarEvento(event);
    }
}
void Cinemateca::SetEventos(const std::vector<Evento> &events){
    EventosAntigos.clear();
    EventosHoje.clear();
    EventosFuturos.clear();
    AdicionarEventos(events);
}

std::vector<Evento> Cinemateca::ProcurarEventosData(const Data &d){
    if(d == hoje.getDate()){
        return GetEventosHoje();
    }

    std::vector<Evento> aux;
    if(d < hoje.getDate()){
        for(const auto& event : EventosAntigos){
            if(event.getStart().getDate() == d){
                aux.push_back(event);
            }
            //Para tornar o codigo mais rapido
            if(event.getStart().getDate() > d){
                break;
            }
        }
    }

    else{
        for(const auto& event : EventosFuturos){
            if(event.getStart().getDate() == d){
                aux.push_back(event);
            }
            //Para tornar o codigo mais rapido
            if(event.getStart().getDate() > d){
                break;
            }
        }
    }
    return aux;
}
std::vector<Evento> Cinemateca::ProcurarEventosDepoisData(const Data &d){
    if(d == hoje){
        return EventosFuturos;
    }

    std::vector<Evento> aux;

    if(d > hoje){
        for(const auto& event : EventosFuturos){
            if(d < event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    else{
        for(const auto& event : EventosHoje){
            aux.push_back(event);
        }
        for(const auto& event : EventosFuturos){
            aux.push_back(event);
        }
        for(const auto& event : EventosAntigos){
            if(d < event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }
    return aux;
}
std::vector<Evento> Cinemateca::ProcurarEventosAntesData(const Data &d){
    if(d == hoje){
        return EventosAntigos;
    }

    std::vector<Evento> aux;

    if(d < hoje){
        for(const auto& event : EventosAntigos){
            if(d > event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    else{
        for(const auto& event : EventosHoje){
            aux.push_back(event);
        }
        for(const auto& event : EventosAntigos){
            aux.push_back(event);
        }
        for(const auto& event : EventosFuturos){
            if(d > event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    return aux;
}

void Cinemateca::LerFicheiroEventos(const std::string& filepath) {
    Evento event;
    ifstream myfile (filepath);

    while(myfile >> event){
        //assumindo que é um evento valido
        AdicionarEvento(event);
    }

    myfile.close();
}

void Cinemateca::EscreverFicheiroEventos(const std::string &filepath) {
    ofstream myfile (filepath);

    if(myfile.is_open()){
        for(const auto& event: EventosAntigos){
            myfile << event;
        }
        for(const auto& event: EventosHoje){
            myfile << event;
        }
        for(const auto& event: EventosFuturos){
            myfile << event;
        }
    }
    else{
        //throw couldn't open file
    }

    myfile.close();
}

void Cinemateca::LerFicheiroAderentes(const std::string &filepath) {
    Aderente aderen("", "", 0, 0, Data(),0);
    ifstream myfile (filepath);

    if(myfile.is_open()){
        while(myfile >> aderen){
            //assumindo que é um Aderente valido
            AdicionarAderente(aderen);
        }
    }
    else{
        //throw could't open file
    }

    myfile.close();
}

void Cinemateca::EscreverFicheiroAderentes(const std::string &filepath) {
    ofstream myfile (filepath);

    if(myfile.is_open()){
        for(const auto& aderen: Aderentes){
            myfile << aderen;
        }
    }
    else{
        //throw couldn't open file
    }

    myfile.close();
}

void Cinemateca::LerFicheiroSalas(const std::string &filepath) {
    Sala sal("", 0);
    ifstream myfile (filepath);

    if(myfile.is_open()){
        while(myfile >> sal){
            //assumindo que é uma sala valida
            AdicionarSala(sal);
        }
    }
    else{
        //throw could't open file
    }

    myfile.close();
}

void Cinemateca::EscreverFicheiroSalas(const std::string &filepath) {
    ofstream myfile (filepath);

    if(myfile.is_open()){
        for(const auto& sal: Salas){
            myfile << sal;
        }
    }
    else{
        //throw couldn't open file
    }

    myfile.close();
}