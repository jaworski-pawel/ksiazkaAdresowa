#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Osoba
{
    int id;
    string imie, nazwisko, nrTel, email, adres;
};

int dodajOsobe(vector<Osoba> &osoby, int iloscOsob)
{
    int id;
    string imie, nazwisko, nrTel, email, adres;

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

    osoby[iloscOsob].id = id;
    osoby[iloscOsob].imie = imie;
    osoby[iloscOsob].nazwisko = nazwisko;
    osoby[iloscOsob].nrTel = nrTel;
    osoby[iloscOsob].email = email;
    osoby[iloscOsob].adres = adres;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    if (plik.good())
    {
        plik << id << endl;
        plik << imie << endl;
        plik << nazwisko << endl;
        plik << nrTel << endl;
        plik << email << endl;
        plik << adres << endl;

        plik.close();

        cout << "Osoba zostala dodana.";
        Sleep(1000);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku KsiazkaAdresowa.txt" << endl;
    }
    iloscOsob++;
    return iloscOsob;
}

int wcztajOsobyZPliku(vector<Osoba> &osoby)
{
    string wczytanaLinia;
    int nrLinii=1;
    int iloscOsob = 0;
    int rodzajPola;

    Osoba tymczasowaOsoba;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);
    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, wczytanaLinia))
    {
        rodzajPola=nrLinii%6;
        switch (rodzajPola)
        {
        case 1:
            tymczasowaOsoba.id = iloscOsob+1;
            break;
        case 2:
            tymczasowaOsoba.imie = wczytanaLinia;
            break;
        case 3:
            tymczasowaOsoba.nazwisko = wczytanaLinia;
            break;
        case 4:
            tymczasowaOsoba.nrTel = wczytanaLinia;
            break;
        case 5:
            tymczasowaOsoba.email = wczytanaLinia;
            break;
        case 0:
            tymczasowaOsoba.adres = wczytanaLinia;
            iloscOsob++;
            break;
        }
        nrLinii++;
        osoby.push_back(tymczasowaOsoba);
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
