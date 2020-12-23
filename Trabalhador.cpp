
#include "Trabalhador.h"

Trabalhador::Trabalhador(string nm, unsigned int nif, string cit, Data bday, bool work) : name(move(nm)), NIF(nif),
                            city(move(cit)), birthday(bday), working(work) {
}

string Trabalhador::getName() const{
    return name;
}

unsigned int Trabalhador::getNIF() const{
    return NIF;
}

string Trabalhador::getCity() const{
    return city;
}

Data Trabalhador::getBirthday() const{
    return birthday;
}

bool Trabalhador::getWorkingStatus() const {
    return working;
}

void Trabalhador::updateName(string newname) {
    name = newname;
}

void Trabalhador::updateCity(string n_city) {
    city = n_city;
}

void Trabalhador::updateWorkStatus(bool work) {
    working = work;
}

bool Trabalhador::operator==(const Trabalhador &t1) {
    return NIF == t1.getNIF();
}

istream &operator>>(istream &input, Trabalhador &t) {
    string firstname, lastname, b_work;
    input >> firstname >> lastname >> t.city >> t.NIF >> t.birthday >> b_work;
    t.updateName(firstname + " " + lastname);
    if (b_work == "true"){
        t.updateWorkStatus(true);
    }
    else{
        t.updateWorkStatus(false);
    }
    return input;
}

ostream &operator<<(ostream &output, const Trabalhador &t) {
    string work;
    if (t.working){
        work = "true";
    }
    else{
        work = "false";
    }
    output << t.name << " " << t.city << " " << t.NIF << " " << t.birthday << " " << work;
    return output;
}


