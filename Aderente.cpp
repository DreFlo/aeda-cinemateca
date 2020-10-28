
#include "Aderente.h"

Aderente::Aderente(string n, unsigned int nif, Data bday, int year) : name(n), NIF(nif), birthday(bday), add_year(year){}

string Aderente::getName() const {return name;}

unsigned Aderente::getNIF() const {return NIF;}

Data Aderente::getBirthday() const {return birthday;}

int Aderente::getAddYear() const {
    return 0;
}
