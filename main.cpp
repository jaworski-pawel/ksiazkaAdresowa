#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct Osoba
{
    int id;
    string imie, nazwisko, nrTel, email, adres;
};

int stringNaInt(string liczbaString)
{
    int liczbaInt = atoi(liczbaString.c_str());
    return liczbaInt;
}

int dodajOsobe(vector<Osoba> &osoby, int iloscOsob)
{
    int id;
    string imie, nazwisko, nrTel, email, adres;
    Osoba tymczasowaOsoba;

    system("cls");
    cout << "Dodawanie osoby" << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, nrTel);
    cout << "Podaj e-mail: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    id = iloscOsob+1;

    tymczasowaOsoba.id = id;
    tymczasowaOsoba.imie = imie;
    tymczasowaOsoba.nazwisko = nazwisko;
    tymczasowaOsoba.nrTel = nrTel;
    tymczasowaOsoba.email = email;
    tymczasowaOsoba.adres = adres;
    osoby.push_back(tymczasowaOsoba);


    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    if (plik.good())
    {
        plik << id << "|" << imie << "|" << nazwisko << "|" << nrTel << "|" << email << "|" << adres << endl;
        plik.close();

        cout << "Osoba zostala dodana.";
        Sleep(1000);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku KsiazkaAdresowa.txt" << endl;
    }
    iloscOsob++;
    osoby.erase(osoby.begin(), osoby.end());
    return iloscOsob;
}

int wcztajOsobyZPliku(vector<Osoba> &osoby)
{
    string wczytanaLinia;
    int iloscOsob = 0;

    Osoba tymczasowaOsoba;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);
    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, wczytanaLinia))
    {
        int dlugoscWczytanejLinii = wczytanaLinia.size();
        int nrPola = 0;
        vector<string> poleKontaktu(6);

        for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscWczytanejLinii; pozycjaZnaku++)
        {
            if (wczytanaLinia[pozycjaZnaku] != 124)
            {
                poleKontaktu[nrPola] +=wczytanaLinia[pozycjaZnaku];
            }
            else
            {
                nrPola++;
            }
        }
        tymczasowaOsoba.id = stringNaInt(poleKontaktu[0]);
        tymczasowaOsoba.imie = poleKontaktu[1];
        tymczasowaOsoba.nazwisko = poleKontaktu[2];
        tymczasowaOsoba.nrTel = poleKontaktu[3];
        tymczasowaOsoba.email = poleKontaktu[4];
        tymczasowaOsoba.adres = poleKontaktu[5];
        osoby.push_back(tymczasowaOsoba);
        poleKontaktu.erase(poleKontaktu.begin(), poleKontaktu.end());

        iloscOsob++;
    }

plik.close();

return iloscOsob;
}

void wyszukajPoImieniu(vector<Osoba> &osoby, string szukanaFraza)
{
    int iloscOsob;
    int znalezioneKontakty = 0;

    iloscOsob = wcztajOsobyZPliku(osoby);
    cout << "Kontakty o imieniu " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].imie == szukanaFraza)
        {
            cout << "ID: " << osoby[i].id << endl;
            cout << "Imie: " << osoby[i].imie << endl;
            cout << "Nazwisko: " << osoby[i].nazwisko << endl;
            cout << "Numer telefonu: " << osoby[i].nrTel << endl;
            cout << "E-mail: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl;
            cout << endl;
            znalezioneKontakty++;
        }
    }
    if (znalezioneKontakty == 0)
    {
        cout << "Nie znaleziono kontakow" << endl;
    }
    else
    {
        cout << "Znaleziono " << znalezioneKontakty << " kontaktow." << endl;
    }
    system("pause");
}

void wyszukajPoNazwisku(vector<Osoba> &osoby, string szukanaFraza)
{
    int iloscOsob;
    int znalezioneKontakty = 0;

    iloscOsob = wcztajOsobyZPliku(osoby);
    cout << "Kontakty o nazwisku " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].nazwisko == szukanaFraza)
        {
            cout << "ID: " << osoby[i].id << endl;
            cout << "Imie: " << osoby[i].imie << endl;
            cout << "Nazwisko: " << osoby[i].nazwisko << endl;
            cout << "Numer telefonu: " << osoby[i].nrTel << endl;
            cout << "E-mail: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl;
            cout << endl;
            znalezioneKontakty++;
        }
    }
    if (znalezioneKontakty == 0)
    {
        cout << "Nie znaleziono kontakow" << endl;
    }
    else
    {
        cout << "Znaleziono " << znalezioneKontakty << " kontaktow." << endl;
    }
    system("pause");
}

void wyswietlWszystkieOsoby(vector<Osoba> &osoby)
{
    int iloscOsob;
    int znalezioneKontakty = 0;

    iloscOsob = wcztajOsobyZPliku(osoby);
    cout << "Lista wszystkich kontaktow: " << endl;

    for (int i = 0; i < iloscOsob; i++)
    {
        cout << "ID: " << osoby[i].id << endl;
        cout << "Imie: " << osoby[i].imie << endl;
        cout << "Nazwisko: " << osoby[i].nazwisko << endl;
        cout << "Numer telefonu: " << osoby[i].nrTel << endl;
        cout << "E-mail: " << osoby[i].email << endl;
        cout << "Adres: " << osoby[i].adres << endl;
        cout << endl;
        znalezioneKontakty++;
    }

    if (znalezioneKontakty == 0)
    {
        cout << "Brak kontakow" << endl;
    }
    else
    {
        cout << "Znaleziono " << znalezioneKontakty << " kontaktow." << endl;
    }
    system("pause");
}
int main()
{
    vector<Osoba> osoby(0);
    int iloscOsob = 0;
    char wybor;
    string szukanaFraza;

    while (true)
    {
        system("cls");
        cout << "1. Dodaj nowa osobe" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkie kontakty" << endl;
        cout << "9. Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == '1')
        {
            iloscOsob = wcztajOsobyZPliku(osoby);
            iloscOsob = dodajOsobe(osoby, iloscOsob);
        }
        else if (wybor == '2')
        {
            cout << "Wyszukiwanie kontaktow po imieniu." << endl;
            cout << "Podaj imie: ";
            cin >> szukanaFraza;
            wyszukajPoImieniu(osoby, szukanaFraza);
        }
        else if (wybor == '3')
        {
            cout << "Wyszukiwanie kontaktow po nazwisku." << endl;
            cout << "Podaj nazwisko: ";
            cin >> szukanaFraza;
            wyszukajPoNazwisku(osoby, szukanaFraza);
        }
        else if (wybor == '4')
        {
            wyswietlWszystkieOsoby(osoby);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }
    return 0;
}
