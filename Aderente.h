
#ifndef PROJETO_ADERENTE_H
#define PROJETO_ADERENTE_H

#include <string>
#include <iostream>

#include "Data.h"

using namespace std;

class Aderente {
    string name;
    unsigned NIF;
    Data birthday;
    int add_year;
public:
    Aderente(string n, unsigned nif, Data bday, int year);
    string getName() const;
    unsigned getNIF() const;
    Data getBirthday() const;
    int getAddYear() const;
};


#endif //PROJETO_ADERENTE_H
