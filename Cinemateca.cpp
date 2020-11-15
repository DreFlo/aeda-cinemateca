//
// Created by andre on 10/14/2020.
//

#include "Cinemateca.h"

DataEHora Cinemateca::hoje = DataEHora();

/*
 * Construtores
 */
Cinemateca::Cinemateca(std::string m, const DataEHora& h){
    morada = m;
    hoje = h;
}
Cinemateca::Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss){
    morada = m;
    hoje = h;
    Salas = ss;
}
Cinemateca::Cinemateca(std::string m, const DataEHora& h, std::vector<Sala> ss, std::vector<Aderente> as){
    morada = m;
    hoje = h;
    Salas = ss;
    Aderentes = as;
}
Cinemateca::Cinemateca(std::string m, DataEHora h, std::vector<Aderente> as){
    morada = m;
    hoje = h;
    Aderentes = as;
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


void Cinemateca::AdicionarSala(const Sala &s){
    Salas.push_back(s);
}
void Cinemateca::AdicionarSalas(const std::vector<Sala> &ss){
    for(auto sala : ss){
        Salas.push_back(sala);
    }
}
void Cinemateca::SetSalas(const std::vector<Sala> &ss){
    Salas = ss;
}

void Cinemateca::AdicionarAderente(const Aderente &a){
    Aderentes.push_back(a);
}
void Cinemateca::AdicionarAderentes(const std::vector<Aderente> &as){
    for(auto aderen : as){
        Aderentes.push_back(aderen);
    }
}
void Cinemateca::SetAderentes(const std::vector<Aderente> &as){
    Aderentes = as;
}

void Cinemateca::AdicionarEvento(const Evento &e){
    if(e.getStart() < this->GetHoje()){
        EventosAntigos.push_back(e);
        sort(EventosAntigos.begin(), EventosAntigos.end(), utils::CompararEventos);
    }
    else if(e.getStart() == this->GetHoje()){
        EventosHoje.push_back(e);
        sort(EventosHoje.begin(), EventosHoje.end(), utils::CompararEventos);
    }
    else{
        EventosFuturos.push_back(e);
        sort(EventosFuturos.begin(), EventosFuturos.end(), utils::CompararEventos);
    }
}
void Cinemateca::AdicionarEventos(const std::vector<Evento> &es){
    for(auto e : es){
        AdicionarEvento(e);
    }
}
void Cinemateca::SetEventos(const std::vector<Evento> &es){
    EventosAntigos.clear();
    EventosHoje.clear();
    EventosFuturos.clear();
    AdicionarEventos(es);
}

std::vector<Evento> Cinemateca::ProcurarEventosData(const Data &d){
    if(d == hoje.getDate()){
        return GetEventosHoje();
    }

    std::vector<Evento> aux;
    if(d < hoje.getDate()){
        for(auto event : EventosAntigos){
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
        for(auto event : EventosFuturos){
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
        for(auto event : EventosFuturos){
            if(d < event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    else{
        for(auto event : EventosHoje){
            aux.push_back(event);
        }
        for(auto event : EventosFuturos){
            aux.push_back(event);
        }
        for(auto event : EventosAntigos){
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
        for(auto event : EventosAntigos){
            if(d > event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    else{
        for(auto event : EventosHoje){
            aux.push_back(event);
        }
        for(auto event : EventosAntigos){
            aux.push_back(event);
        }
        for(auto event : EventosFuturos){
            if(d > event.getStart().getDate()){
                aux.push_back(event);
            }
        }
    }

    return aux;
}

