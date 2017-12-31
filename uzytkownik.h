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
    Uzytkownik(int _id, string _login, string _haslo);
    int getId();
    void setId(int _id);
    string getLogin();
    void setLogin(string _login);
    string getHaslo();
    void setHaslo(string _haslo);
};

#endif
