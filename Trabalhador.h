
#ifndef PROJETO_TRABALHADOR_H
#define PROJETO_TRABALHADOR_H

#include "string"
#include "Data.h"
#include <fstream>

using namespace std;

class Trabalhador{
    string name;
    unsigned int NIF;
    string city;
    Data birthday;
    bool working;
public:
    /**
     * Class constructor
     * @param nm - Name
     * @param nif - NIF
     * @param cit - City
     * @param bday - Birthday
     * @param work - Wether they are currently working or not
     */
    Trabalhador(string nm, unsigned int nif, string cit, Data bday, bool work = true);
    /**
     * @return Name
     */
    string getName() const;
    /**
     * @return NIF
     */
    unsigned int getNIF() const;
    /**
     * @return City were they work or last city were they did work
     */
    string getCity() const;
    /**
     * @return Birthday
     */
    Data getBirthday() const;
    /**
     * @return True if currently working, false otherwise
     */
    bool getWorkingStatus() const;
    /**
     * Updates the name of the Trabalhador
     * @param newname - New name
     */
    void updateName(string newname);
    /**
     * Updates the city of the Trabalhador
     * @param n_city - New City
     */
    void updateCity(string n_city);
    /**
     * Updates the work parameter of the Trabalhador
     * @param work - True if currently working, false otherwise
     */
    void updateWorkStatus(bool work);
    /**
     * Checks if two Trabalhadores are the same by their NIF
     * @param t1 - Trabalhador to compare with
     * @return True if same NIF, false otherwise
     */
    bool operator==(const Trabalhador &t1);
    /**
     * Input operator.
     */
    friend istream& operator>>(istream& input, Trabalhador &t);
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const Trabalhador &t);
};

#endif //PROJETO_TRABALHADOR_H