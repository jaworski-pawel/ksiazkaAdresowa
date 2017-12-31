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

            if (wybor == '1')
            {
                ksiazkaUzytkownikow.rejestracja(uzytkownicy);
            }
            else if (wybor == '2')
            {
                ksiazkaAdresatow.setIdZalogowanegoUzytkownika(ksiazkaUzytkownikow.logowanie(uzytkownicy));
            }
            else if (wybor == '9')
            {
                exit(0);
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
            if (wybor == '1')
            {
                ksiazkaAdresatow.dodajAdresata(adresaci);
            }
            else if (wybor == '2')
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po imieniu." << endl;
                cout << "Podaj imie: ";
                cin >> szukanaFraza;
                ksiazkaAdresatow.wyszukajPoImieniu(adresaci, szukanaFraza);
            }
            else if (wybor == '3')
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po nazwisku." << endl;
                cout << "Podaj nazwisko: ";
                cin >> szukanaFraza;
                ksiazkaAdresatow.wyszukajPoNazwisku(adresaci, szukanaFraza);
            }
            else if (wybor == '4')
            {
                ksiazkaAdresatow.wyswietlWszystkichAdresatow(adresaci);
            }
            else if (wybor == '5')
            {
                ksiazkaAdresatow.usunAdresata(adresaci);
            }
            else if (wybor == '6')
            {
                ksiazkaAdresatow.edytujAdresata(adresaci);
            }
            else if (wybor == '7')
            {
                ksiazkaUzytkownikow.zmianaHasla(uzytkownicy, ksiazkaAdresatow.getIdZalogowanegoUzytkownika());
            }
            else if (wybor == '8')
            {
                ksiazkaAdresatow.setIdZalogowanegoUzytkownika(0);
            }
        }

    }
    return 0;
}
