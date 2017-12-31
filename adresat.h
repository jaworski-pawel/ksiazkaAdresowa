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
    Adresat(int _id, int _idUzytkownika, string _imie, string _nazwisko, string _numerTelefonu, string _email, string adres);
    int getId();
    void setId(int _id);
    int getIdUzytkownika();
    void setIdUzytkownika(int _idUzytkownika);
    string getImie();
    void setImie(string _imie);
    string getNazwisko();
    void setNazwisko(string _nazwisko);
    string getNumerTelefonu();
    void setNumerTelefonu(string _numerTelefonu);
    string getEmail();
    void setEmail(string _email);
    string getAdres();
    void setAdres(string _adres);
};

#endif
