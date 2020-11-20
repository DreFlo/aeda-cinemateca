
#ifndef PROJETO_CLIENTE_H
#define PROJETO_CLIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Cliente{
protected:
    string name, city;
    unsigned int cell;
public:
    /**
     * Class constructor
     * @param nam Name
     * @param cit City
     * @param cel Cellphone number
     */
    Cliente(string nam, string cit, unsigned int cel);
    /**
     * @return Person's name.
     */
    string getName() const;
    /**
     * @return City where they live in.
     */
    string getCity() const;
    /**
     * @return Cellphone number.
     */
    unsigned int getCell() const;
    /**
     * Changes Cliente's name.
     * @param new_name New name.
     */
    void updateName(string new_name);
    /**
     * Changes Cliente's city.
     * @param new_city New city.
     */
    void updateCity(string new_city);
    /**
     * Change Cliente's cellphone number.
     * @param new_cell New cellphone number.
     */
    void updateCell(unsigned int new_cell);
    /**
     * Checks if two Clientes are equal, by checking their cellphone numbers.
     * @param c1 Cliente to compare with.
     * @return True if they are equal, false otherwise.
     */
    bool operator==(const Cliente &c1) const;
    /**
     * Checks if a cliente is lesser than another by alphabetical order of their names.
     * @param c1 Cliente to compare with.
     * @return True if it comes before, false otherwise.
     */
    bool operator<(const Cliente &c1) const;
};


#endif //PROJETO_CLIENTE_H
