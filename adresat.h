#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id, int idUzytkownika, string imie, string nazwisko, string numerTelefonu, string email, string adres);
    int getId();
    void setId(int id);
    int getIdUzytkownika();
    void setIdUzytkownika(int idUzytkownika);
    string getImie();
    void setImie(string imie);
    string getNazwisko();
    void setNazwisko(string nazwisko);
    string getNumerTelefonu();
    void setNumerTelefonu(string numerTelefonu);
    string getEmail();
    void setEmail(string email);
    string getAdres();
    void setAdres(string adres);
};

#endif
