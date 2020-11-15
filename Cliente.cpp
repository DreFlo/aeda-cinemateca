
#include "Cliente.h"

Cliente::Cliente(string nam, string cit, unsigned int cel) : name(nam), city(cit), cell(cel) {

}

string Cliente::getName() const {return name;}

string Cliente::getCity() const {return city;}

unsigned int Cliente::getCell() const {return cell;}

bool Cliente::compName(const Cliente &c1, const Cliente &c2) const {
    return (c1.getName() < c2.getName());
}