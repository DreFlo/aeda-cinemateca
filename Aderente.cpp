
#include "Aderente.h"

#include <fstream>

Aderente::Aderente(string nam, string cit, unsigned int cel, unsigned int nif, Data bday, int year, float s_m)
            : Cliente(std::move(nam), move(cit), cel), NIF(nif), birthday(bday), adh_year(year), saved_money(s_m) {
}

unsigned int Aderente::getNIF() const {return NIF;}

Data Aderente::getBirthday() const {return birthday;}

int Aderente::getAdhYear() const {return adh_year;}

float Aderente::getSavedMoney() const {return saved_money;}

void Aderente::addSavedMoney(float money) {
    saved_money += money;
}

bool Aderente::operator==(const Aderente &p1) const {
    return (NIF == p1.NIF);
}

bool Aderente::operator<(const Aderente &p1) const {
    return (name < p1.name);
}

istream &operator>>(istream &input, Aderente &p1) {
    string firstname, lastname;
    input >> firstname >> lastname >> p1.city >> p1.cell >> p1.NIF >> p1.birthday >> p1.adh_year
    >> p1.saved_money;
    p1.updateName(firstname + " " + lastname);
    return input;
}

ostream &operator<<(ostream &output, const Aderente &p1) {
    output << p1.name << " " << p1.city << " " << p1.cell << " " << p1.NIF << " " << p1.birthday
           << " " << p1.adh_year << " " << p1.saved_money;
    return output;
}


