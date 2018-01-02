#include <iostream>
#include "uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik(int id, string login, string haslo)
{
    this -> id = id;
    this -> login = login;
    this -> haslo = haslo;
}

int Uzytkownik::getId()
{
    return id;
}

void Uzytkownik::setId(int id)
{
    this -> id = id;
}

string Uzytkownik::getLogin()
{
    return login;
}

void Uzytkownik::setLogin(string login)
{
    this -> login = login;
}

string Uzytkownik::getHaslo()
{
    return haslo;
}

void Uzytkownik::setHaslo(string haslo)
{
    this -> haslo = haslo;
}
