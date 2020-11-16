
#include "Aderente.h"

#include <utility>
#include <fstream>

Aderente::Aderente(string nam, string cit, unsigned int cel, unsigned int nif, Data bday, int year)
            : Cliente(std::move(nam), move(cit), cel), NIF(nif), birthday(bday), adh_year(year){
    string info;
    info = name + " " + city + " " + to_string(cell) + " " + to_string(NIF) + " " + to_string(bday.getDay()) +
            to_string(bday.getMonth()) + to_string(bday.getYear()) + " " + to_string(adh_year);
    ofstream out;
    out.open("Aderentes.txt", ios::app);
    out << info;
    out.close();
}

unsigned int Aderente::getNIF() const {return NIF;}

Data Aderente::getBirthday() const {return birthday;}

int Aderente::getAdhYear() const {return adh_year;}



/*
void Aderente::addAderente() {
    string t_name, t_city, t_bday;
    unsigned int t_cell, t_nif;
    int t_year;
    char c;
    cout << "Name (first and last): ";
    cin >> t_name;
    int n_spaces = 0;
    for (int i = 0; i < t_name.size(); i++){
        if (t_name[i] == 32){
            if (n_spaces == 0) {n_spaces++;}

        }
        if(((int(t_name[i]) <= 90) && (int(t_name[i]) >= 65)) || ((int(t_name[i]) <= 122) && (int(t_name[i]) >= 97))){}
    }

}*/

bool Aderente::compYear(const Aderente &p1, const Aderente &p2) const {
    return (p1.adh_year < p2.adh_year);
}

bool Aderente::compAge(const Aderente &p1, const Aderente &p2) const {
    return (p1.birthday < p2.birthday);
}

vector<Aderente> readAderente(){
    vector<Aderente> aderentes;
    string line;
    ifstream in("Aderentes.txt");
    while(getline(in, line)){
        istringstream lin(line);
        string a, b, c, d, e, f;
        unsigned int c1, d1;
        lin >> a >> b >> c >> d >> e >> f;
        Data d_temp(stoul(e.substr(0, 2)), stoul(e.substr(2, 2)),
                    stoul(e.substr(4, 4)));
        Aderente a_temp(a, b, stoul(c), stoul(d), d_temp, stoi(f));
        aderentes.push_back(a_temp);
    }
    in.close();
    return aderentes;
}

