
#include "Aderente.h"

#include <utility>

Aderente::Aderente(string nam, string cit, unsigned cel, unsigned nif, Data bday, int year)
            : Cliente(std::move(nam), move(cit), cel), NIF(nif), birthday(bday), adh_year(year){}

unsigned Aderente::getNIF() const {return NIF;}

Data Aderente::getBirthday() const {return birthday;}

int Aderente::getAdhYear() const {return adh_year;}

bool Aderente::compYear(Aderente p1, Aderente p2) const {
    return (p1.adh_year < p2.adh_year);
}
