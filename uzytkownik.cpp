#include <iostream>
#include "uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik(int _id, string _login, string _haslo)
{
    id = _id;
    login = _login;
    haslo = _haslo;
}

int Uzytkownik::getId()
{
    return id;
}

void Uzytkownik::setId(int _id)
{
    id = _id;
}

string Uzytkownik::getLogin()
{
    return login;
}

void Uzytkownik::setLogin(string _login)
{
    login = _login;
}

string Uzytkownik::getHaslo()
{
    return haslo;
}

void Uzytkownik::setHaslo(string _haslo)
{
    haslo = _haslo;
}
