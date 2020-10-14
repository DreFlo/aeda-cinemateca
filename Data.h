//
// Created by andre on 10/14/2020.
//

#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    const unsigned int day, month, year;
public:
    Data(int dd, int mm, int yy);
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
};


#endif //PROJETO_DATA_H
