#include <iostream>
#include <windows.h>
#include <fstream>
#include "ksiazkaUzytkownikow.h"

using namespace std;

KsiazkaUzytkownikow::KsiazkaUzytkownikow()
{
    iloscUzytkownikow = 0;
}

int KsiazkaUzytkownikow::getIloscUzytkownikow()
{
    return iloscUzytkownikow;
}

 int KsiazkaUzytkownikow::logowanie(vector<Uzytkownik> &uzytkownicy)
 {
    string nazwa, haslo;
    wczytajUzytkownikowZPliku(uzytkownicy);

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    int i = 0;
    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].getLogin() == nazwa)
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo: ";
                cin >> haslo;
                if (uzytkownicy[i].getHaslo() == haslo)
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(1000);
                    return uzytkownicy[i].getId();
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 5 sekund przed kolejna proba" << endl;
            Sleep(5000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem." << endl;
    Sleep(3000);
    return 0;
 }

 void KsiazkaUzytkownikow::rejestracja(vector<Uzytkownik> &uzytkownicy)
 {
    string nazwa, haslo;
    wczytajUzytkownikowZPliku(uzytkownicy);

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    int i = 0;

    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].getLogin() == nazwa)
        {
            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe: ";
            cin >> nazwa;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;
    iloscUzytkownikow++;
    Uzytkownik tymczasowyUzytkownik(iloscUzytkownikow, nazwa, haslo);
    uzytkownicy.push_back(tymczasowyUzytkownik);
    cout << "Konto zalozone" << endl;
    Sleep(1000);
    zapiszUzytkownikowDoPliku(uzytkownicy);
 }

 void KsiazkaUzytkownikow::zmianaHasla(vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
 {
     string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;
    for (int i = 0; i < iloscUzytkownikow; i++)
    {
        if (uzytkownicy[i].getId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].setHaslo(haslo);
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(1000);
        }
    }
    zapiszUzytkownikowDoPliku(uzytkownicy);
 }

 void KsiazkaUzytkownikow::wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy)
 {
    string wczytanaLinia;
    iloscUzytkownikow = 0;

    uzytkownicy.erase(uzytkownicy.begin(), uzytkownicy.end());

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);
    if(plik.good())
    {
        while (getline(plik, wczytanaLinia))
        {
            int dlugoscWczytanejLinii = wczytanaLinia.size();
            int nrPola = 0;
            vector<string> poleUzytkownika(3);

            for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscWczytanejLinii; pozycjaZnaku++)
            {
                if (wczytanaLinia[pozycjaZnaku] != 124)
                {
                    poleUzytkownika[nrPola] +=wczytanaLinia[pozycjaZnaku];
                }
                else
                {
                    nrPola++;
                }
            }
            Uzytkownik tymczasowyUzytkownik(stringNaInt(poleUzytkownika[0]), poleUzytkownika[1], poleUzytkownika[2]);
            uzytkownicy.push_back(tymczasowyUzytkownik);
            poleUzytkownika.erase(poleUzytkownika.begin(), poleUzytkownika.end());

            iloscUzytkownikow++;
        }
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku!" << endl;

    }
 }

 int KsiazkaUzytkownikow::stringNaInt(string liczbaString)
{
    int liczbaInt = atoi(liczbaString.c_str());
    return liczbaInt;
}

void KsiazkaUzytkownikow::setIloscUzytkownikow(int iloscUzytkownikow)
{
    this -> iloscUzytkownikow = iloscUzytkownikow;
}

 void KsiazkaUzytkownikow::zapiszUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy)
 {
     fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good())
    {
        plik << uzytkownicy[0].getId() << "|" << uzytkownicy[0].getLogin() << "|" << uzytkownicy[0].getHaslo() << endl;
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
    }

    for (int i = 1; i < iloscUzytkownikow; i++)
    {
        fstream plik;
        plik.open("Uzytkownicy.txt", ios::out | ios::app);
        if (plik.good())
        {
            plik << uzytkownicy[i].getId() << "|" << uzytkownicy[i].getLogin() << "|" << uzytkownicy[i].getHaslo() << endl;
            plik.close();
        }
        else
        {
            cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
        }
    }
 }
