
#include "Cliente.h"

Cliente::Cliente(string nam, string cit, unsigned int cel) : name(nam), city(cit), cell(cel) {}

string Cliente::getName() const {return name;}

string Cliente::getCity() const {return city;}

unsigned int Cliente::getCell() const {return cell;}

void Cliente::updateName(string new_name) {
    name = new_name;
}

void Cliente::updateCity(string new_city) {
    city = new_city;
}

void Cliente::updateCell(unsigned int new_cell) {
    cell = new_cell;
}

bool Cliente::operator==(const Cliente &p1) const {
    return (cell == p1.cell);
}

bool Cliente::operator<(const Cliente &c1) const {
    return (name < c1.name);
}
