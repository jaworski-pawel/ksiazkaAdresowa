#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

public:
    Uzytkownik(int id, string login, string haslo);
    int getId();
    void setId(int id);
    string getLogin();
    void setLogin(string login);
    string getHaslo();
    void setHaslo(string haslo);
};

#endif
