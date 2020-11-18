
#include "Aderente.h"

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

bool Aderente::operator==(const Aderente &p1) const {
    return (NIF == p1.NIF);
}

bool Aderente::operator<(const Aderente &p1) const {
    return (name < p1.name);
}

istream &operator>>(istream &input, Aderente &p1) {
    string a, b, c, d, e, f, g;
    input >> a >> b >> c >> d >> e >> f >> g;
    Data d_temp(stoul(f.substr(0, 2)), stoul(f.substr(2, 2)),
                stoul(f.substr(4, 4)));
    p1.name = (a + " " + b);
    p1.city = c;
    p1.cell = stoul(d);
    p1.NIF = stoul(e);
    p1.birthday = d_temp;
    p1.adh_year = stoi(g);
    return input;
}

ostream &operator<<(ostream &output, const Aderente &p1) {
    output << p1.name << " " << p1.city << " " << p1.cell << " " << p1.NIF << " " << p1.birthday.getDay() <<
            p1.birthday.getMonth() << p1.birthday.getYear() << " " << p1.adh_year;
    return output;
}


