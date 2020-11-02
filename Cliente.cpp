
#include "Cliente.h"

Cliente::Cliente(string nam, string cit, unsigned cel) : name(nam), city(cit), cell(cel) {}

string Cliente::getName() const {return name;}

string Cliente::getCity() const {return city;}
