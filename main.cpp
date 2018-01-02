#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "uzytkownik.h"
#include "adresat.h"
#include "ksiazkaUzytkownikow.h"
#include "ksiazkaAdresatow.h"

using namespace std;

int main()
{
    vector<Uzytkownik> uzytkownicy;
    vector<Adresat> adresaci;
    KsiazkaUzytkownikow ksiazkaUzytkownikow;
    KsiazkaAdresatow ksiazkaAdresatow;
    char wybor;

    while (true)
    {
        if (ksiazkaAdresatow.getIdZalogowanegoUzytkownika() == 0)
        {
            system("cls");
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << "Wybor: ";
            cin >> wybor;

            switch(wybor)
            {
            case '1':
            {
                ksiazkaUzytkownikow.rejestracja(uzytkownicy);
                break;
            }
            case '2':
            {
                ksiazkaAdresatow.setIdZalogowanegoUzytkownika(ksiazkaUzytkownikow.logowanie(uzytkownicy));
                break;
            }
            case '9':
            {
                exit(0);
                break;
            }
            }
        }
        else
        {
            ksiazkaAdresatow.setIloscUzytkownikow(ksiazkaUzytkownikow.getIloscUzytkownikow());
            system("cls");
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cin >> wybor;

            switch(wybor)
            {
            case '1':
            {
                ksiazkaAdresatow.dodajAdresata(adresaci);
                break;
            }
            case '2':
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po imieniu." << endl;
                cout << "Podaj imie: ";
                cin >> szukanaFraza;
                ksiazkaAdresatow.wyszukajPoImieniu(adresaci, szukanaFraza);
                break;
            }
            case '3':
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po nazwisku." << endl;
                cout << "Podaj nazwisko: ";
                cin >> szukanaFraza;
                ksiazkaAdresatow.wyszukajPoNazwisku(adresaci, szukanaFraza);
                break;
            }
            case '4':
            {
                ksiazkaAdresatow.wyswietlWszystkichAdresatow(adresaci);
                break;
            }
            case '5':
            {
                ksiazkaAdresatow.usunAdresata(adresaci);
                break;
            }
            case '6':
            {
                ksiazkaAdresatow.edytujAdresata(adresaci);
                break;
            }
            case '7':
            {
                ksiazkaUzytkownikow.zmianaHasla(uzytkownicy, ksiazkaAdresatow.getIdZalogowanegoUzytkownika());
                break;
            }
            case '8':
            {
                ksiazkaAdresatow.setIdZalogowanegoUzytkownika(0);
                break;
            }
            }
        }

    }
    return 0;
}
