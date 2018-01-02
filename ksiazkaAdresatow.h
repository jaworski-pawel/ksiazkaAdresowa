#ifndef KSIAZKAADRESATOW_H
#define KSIAZKAADRESATOW_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "adresat.h"

using namespace std;

class KsiazkaAdresatow
{
    int idZalogowanegoUzytkownika;
    int iloscUzytkownikow;
    int iloscKontaktow;

public:
    KsiazkaAdresatow();
    int getIdZalogowanegoUzytkownika();
    void setIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    int getIloscUzytkownikow();
    void setIloscUzytkownikow(int iloscUzytkownikow);
    void dodajAdresata(vector<Adresat> &adresaci);
    void edytujAdresata(vector<Adresat> &adresaci);
    void usunAdresata(vector<Adresat> &adresaci);
    void wyszukajPoImieniu(vector<Adresat> &adresaci, string szukanaFraza);
    void wyszukajPoNazwisku(vector<Adresat> &adresaci, string szukanaFraza);
    void wyswietlWszystkichAdresatow(vector<Adresat> &adresaci);

private:
    int przypiszId();
    int wczytajAdresatowUzytkownikaZPliku(vector<Adresat> &adresaci, int idUzytkownika, string nazwapliku);
    int znajdzIteratorKontaktu(vector<Adresat> &adresaci, int IdKontaktu);
    void utworzKopieKontaktow(vector<Adresat> adresaci);
    int stringNaInt(string liczbaString);
};

#endif
