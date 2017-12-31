#include <iostream>
#include "adresat.h"

using namespace std;

Adresat::Adresat(int _id, int _idUzytkownika, string _imie, string _nazwisko, string _numerTelefonu, string _email, string _adres)
{
    id = _id;
    idUzytkownika = _idUzytkownika;
    imie = _imie;
    nazwisko = _nazwisko;
    numerTelefonu = _numerTelefonu;
    email = _email;
    adres = _adres;
}

int Adresat::getId()
{
    return id;
}

void Adresat::setId(int _id)
{
    id = _id;
}

int Adresat::getIdUzytkownika()
{
    return idUzytkownika;
}

void Adresat::setIdUzytkownika(int _idUzytkownika)
{
    idUzytkownika = _idUzytkownika;
}

string Adresat::getImie()
{
    return imie;
}

void Adresat::setImie(string _imie)
{
    imie = _imie;
}

string Adresat::getNazwisko()
{
    return nazwisko;
}

void Adresat::setNazwisko(string _nazwisko)
{
    nazwisko = _nazwisko;
}

string Adresat::getNumerTelefonu()
{
    return numerTelefonu;
}

void Adresat::setNumerTelefonu(string _numerTelefonu)
{
    numerTelefonu = _numerTelefonu;
}

string Adresat::getEmail()
{
    return email;
}

void Adresat::setEmail(string _email)
{
    email = _email;
}

string Adresat::getAdres()
{
    return adres;
}

void Adresat::setAdres(string _adres)
{
    adres = _adres;
}
