
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
    float saved_money;
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
    Aderente(string nam, string cit, unsigned int cel, unsigned int nif, Data bday, int year, float s_m= 0);
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
    float getSavedMoney() const;
    void addSavedMoney(float money);
    bool operator==(const Aderente &p1) const;
    bool operator<(const Aderente &p1) const;
    friend istream& operator>>(istream& input, Aderente &p1);
    friend ostream& operator<<(ostream& output, const Aderente &p1);
};


};*/

#endif //PROJETO_ADERENTE_H
