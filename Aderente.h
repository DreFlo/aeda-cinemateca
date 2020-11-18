
#ifndef PROJETO_ADERENTE_H
#define PROJETO_ADERENTE_H

#include <string>
#include <iostream>
#include <sstream>

#include "Data.h"
#include "Cliente.h"

using namespace std;

class Aderente: public Cliente{
protected:
    unsigned NIF;
    Data birthday;
    int adh_year;
public:
    /**
     * Class constructor
     * @param nam Name
     * @param cit City
     * @param cel Cellphone number
     * @param nif NIF
     * @param bday Birthday
     * @param year Adhesion year
     */
    Aderente(string nam, string cit, unsigned int cel, unsigned int nif, Data bday, int year);
    /**
     * @return Person's NIF.
     */
    unsigned int getNIF() const;
    /**
     * @return Person's birthday.
     */
    Data getBirthday() const;
    /**
     * @return Year when they joined the organization.
     */
    int getAdhYear() const;
    /**
     * An "Aderente" is greater than another if they've been longer in the organization.
     * @param p1 First person to compare
     * @param p2 Second person to compare
     * @return True if the first person has been in the organization longer than the second person
     */
    bool compYear(const Aderente &p1, const Aderente &p2) const;
    bool compAge(const Aderente &p1, const Aderente &p2) const;
    friend istream& operator>>(istream& input, Aderente &p1);
    friend ostream& operator<<(ostream& output, const Aderente &p1);
};
/*
class InvalidAderente : public InvalidCliente{
    string atribute;
public:
    InvalidAderente(string wrong) : atribute(wrong) {};


};*/

#endif //PROJETO_ADERENTE_H
