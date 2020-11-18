
#include "Cliente.h"

Cliente::Cliente(string nam, string cit, unsigned int cel) : name(nam), city(cit), cell(cel) {}

string Cliente::getName() const {return name;}

string Cliente::getCity() const {return city;}

unsigned int Cliente::getCell() const {return cell;}

bool Cliente::compName(const Cliente &c1, const Cliente &c2) const {
    return (c1.name < c2.name);
}

bool Cliente::compCell(const Cliente &c1, const Cliente &c2) const {
    return (c1.cell < c2.cell);
}

bool Cliente::operator==(const Cliente &p1) const {
    return (cell == p1.cell);
}

bool Cliente::operator<(const Cliente &c1) const {
    return (name < c1.name);
}
