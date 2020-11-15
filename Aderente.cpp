
#include "Aderente.h"

#include <utility>
#include <fstream>

Aderente::Aderente(string nam, string cit, unsigned int cel, unsigned int nif, Data bday, int year)
            : Cliente(std::move(nam), move(cit), cel), NIF(nif), birthday(bday), adh_year(year){
    string info;
    info = name + " " + city + " " + to_string(cell) + " " + to_string(NIF) + " " + to_string(bday.getDay()) +
            to_string(bday.getMonth()) + to_string(bday.getYear()) + " " + to_string(adh_year);
    ofstream out;
    out.open("Aderentes.txt", ios::app);
    out << info;
    out.close();
}

unsigned int Aderente::getNIF() const {return NIF;}

Data Aderente::getBirthday() const {return birthday;}

int Aderente::getAdhYear() const {return adh_year;}

bool Aderente::compYear(const Aderente &p1, const Aderente &p2) const {
    return (p1.adh_year < p2.adh_year);
}




