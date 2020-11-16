
#include "Cliente.h"

Cliente::Cliente(string nam, string cit, unsigned int cel) : name(nam), city(cit), cell(cel) {

}

string Cliente::getName() const {return name;}

string Cliente::getCity() const {return city;}

unsigned int Cliente::getCell() const {return cell;}
 /*
string Cliente::addName() const {
    string t_name;
    int n_spaces = 0;
    cout << "Name (First Last): ";
    cin >> t_name;
    for (int i = 0; i < t_name.size(); i++){
        if (t_name[i] == 32){
            if (n_spaces == 0) {n_spaces++;}
            else throw
        }
        if(((int(t_name[i]) <= 90) && (int(t_name[i]) >= 65)) || ((int(t_name[i]) <= 122) && (int(t_name[i]) >= 97))){}
    }
}*/

bool Cliente::compName(const Cliente &c1, const Cliente &c2) const {
    return (c1.getName() < c2.getName());
}