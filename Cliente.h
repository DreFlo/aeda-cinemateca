
#ifndef PROJETO_CLIENTE_H
#define PROJETO_CLIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Cliente{
protected:
    string name, city;
    unsigned cell;
public:
    /**
     * Class constructor
     * @param nam Name
     * @param cit City
     * @param cel Cellphone number
     */
    Cliente(string nam, string cit, unsigned cel);
    /**
     * @return Person's name.
     */
    string getName() const;
    /**
     * @return City where they live in.
     */
    string getCity() const;
};

#endif //PROJETO_CLIENTE_H
