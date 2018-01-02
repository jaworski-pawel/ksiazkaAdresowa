#include <iostream>
#include "adresat.h"

using namespace std;

Adresat::Adresat(int id, int idUzytkownika, string imie, string nazwisko, string numerTelefonu, string email, string adres)
{
    this -> id = id;
    this -> idUzytkownika = idUzytkownika;
    this -> imie = imie;
    this -> nazwisko = nazwisko;
    this -> numerTelefonu = numerTelefonu;
    this -> email = email;
    this -> adres = adres;
}

int Adresat::getId()
{
    return id;
}

void Adresat::setId(int id)
{
    this -> id = id;
}

int Adresat::getIdUzytkownika()
{
    return idUzytkownika;
}

void Adresat::setIdUzytkownika(int idUzytkownika)
{
    this -> idUzytkownika = idUzytkownika;
}

string Adresat::getImie()
{
    return imie;
}

void Adresat::setImie(string imie)
{
    this -> imie = imie;
}

string Adresat::getNazwisko()
{
    return nazwisko;
}

void Adresat::setNazwisko(string nazwisko)
{
    this -> nazwisko = nazwisko;
}

string Adresat::getNumerTelefonu()
{
    return numerTelefonu;
}

void Adresat::setNumerTelefonu(string numerTelefonu)
{
    this -> numerTelefonu = numerTelefonu;
}

string Adresat::getEmail()
{
    return email;
}

void Adresat::setEmail(string email)
{
    this -> email = email;
}

string Adresat::getAdres()
{
    return adres;
}

void Adresat::setAdres(string adres)
{
    this -> adres = adres;
}
