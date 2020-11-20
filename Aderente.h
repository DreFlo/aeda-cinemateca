
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
    unsigned int NIF;
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
     * @param s_m Saved money
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
    /**
     * @return Gets the total amount of money they saved by being Aderentes.
     */
    float getSavedMoney() const;
    /**
     * Adds money that was saved to the saved money total.
     * @param money Money to add.
     */
    void addSavedMoney(float money);
    /**
     * Checks if two Aderentes are the same by checking their NIF's.
     * @param p1 Aderente to compare with.
     * @return True if the same, false otherwise.
     */
    bool operator==(const Aderente &p1) const;
    /**
     * Checks if an Aderente is less than another, by checking if it is first by alphabetical order.
     * @param p1 Aderente to compare with.
     * @return True if first, false otherwise.
     */
    bool operator<(const Aderente &p1) const;
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Aderente &p1);
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Aderente &p1);
};

#endif //PROJETO_ADERENTE_H
