#ifndef KSIAZKAUZYTKOWNIKOW_H
#define KSIAZKAUZYTKOWNIKOW_H

#include <iostream>
#include <vector>
#include "uzytkownik.h"

using namespace std;

class KsiazkaUzytkownikow
{
    int iloscUzytkownikow;

public:
    KsiazkaUzytkownikow();
    int getIloscUzytkownikow();
    int logowanie(vector<Uzytkownik> &uzytkownicy);
    void rejestracja(vector<Uzytkownik> &uzytkownicy);
    void zmianaHasla(vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika);

private:
    int stringNaInt(string liczbaString);
    void setIloscUzytkownikow(int iloscUzytkownikow);
    void wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy);
    void zapiszUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy);
};

#endif
