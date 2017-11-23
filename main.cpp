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

int stringNaInt(string liczbaString);
void zapiszDaneDoPliku(vector<Osoba> &osoby, int iloscOsob);
int znajdzIteratorKontaktu(vector<Osoba> &osoby, int iloscOsob, int idKontaktu);
int dodajOsobe(vector<Osoba> &osoby, int iloscOsob);
int wczytajOsobyZPliku(vector<Osoba> &osoby);
void wyszukajPoImieniu(vector<Osoba> &osoby, string szukanaFraza);
void wyszukajPoNazwisku(vector<Osoba> &osoby, string szukanaFraza);
void wyswietlWszystkieOsoby(vector<Osoba> &osoby);
void edytujKontakt(vector<Osoba> &osoby);
void usunKontakt(vector<Osoba> &osoby);

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
        cout << "5. Edycja kontaktu" << endl;
        cout << "6. Usuwanie kontaktu" << endl;
        cout << "9. Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == '1')
        {
            iloscOsob = wczytajOsobyZPliku(osoby);
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
        else if (wybor == '5')
        {
            edytujKontakt(osoby);
        }
        else if (wybor == '6')
        {
            usunKontakt(osoby);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }
    return 0;
}

int stringNaInt(string liczbaString)
{
    int liczbaInt = atoi(liczbaString.c_str());
    return liczbaInt;
}

void zapiszDaneDoPliku(vector<Osoba> &osoby, int iloscOsob)
{
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out);
    if (plik.good())
    {
        plik << osoby[0].id << "|" << osoby[0].imie << "|" << osoby[0].nazwisko << "|" << osoby[0].nrTel << "|" << osoby[0].email << "|" << osoby[0].adres << endl;
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku KsiazkaAdresowa.txt" << endl;
    }

    for (int iteratorKontaktu = 1; iteratorKontaktu < iloscOsob; iteratorKontaktu++)
    {
        fstream plik;
        plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
        if (plik.good())
        {
            plik << osoby[iteratorKontaktu].id << "|" << osoby[iteratorKontaktu].imie << "|" << osoby[iteratorKontaktu].nazwisko << "|" << osoby[iteratorKontaktu].nrTel << "|" << osoby[iteratorKontaktu].email << "|" << osoby[iteratorKontaktu].adres << endl;
            plik.close();
        }
        else
        {
            cout << "Nie mozna otworzyc pliku KsiazkaAdresowa.txt" << endl;
        }
    }

}

int znajdzIteratorKontaktu(vector<Osoba> &osoby, int iloscOsob, int idKontaktu)
{
    bool czyZnalezionoId;
    int znalezionyiteratorKontaktu;

    for (int iteratorKontaktu = 0; iteratorKontaktu < iloscOsob; iteratorKontaktu++)
    {
        if (idKontaktu == osoby[iteratorKontaktu].id)
        {
            czyZnalezionoId = true;
            znalezionyiteratorKontaktu = iteratorKontaktu;
            break;
        }
        else
        {
            czyZnalezionoId = false;
        }
    }

    if (czyZnalezionoId)
    {
        return znalezionyiteratorKontaktu;
    }
    else
    {
        cout << "Nieprawidlowe ID" << endl;
            Sleep(2000);
            edytujKontakt(osoby);
    }
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

int wczytajOsobyZPliku(vector<Osoba> &osoby)
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

    iloscOsob = wczytajOsobyZPliku(osoby);
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

    iloscOsob = wczytajOsobyZPliku(osoby);
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

    iloscOsob = wczytajOsobyZPliku(osoby);
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

void edytujKontakt(vector<Osoba> &osoby)
{
    int szukaneId;
    int iteratorKontaktu;
    int iloscOsob;

    iloscOsob = wczytajOsobyZPliku(osoby);

    system("cls");
    cout << "Edycja kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(osoby, iloscOsob, szukaneId);

    system("cls");
    cout << "Edycja danych"<< endl;
    cout << "ID: " << osoby[iteratorKontaktu].id << endl;
    cout << "Imie: " << osoby[iteratorKontaktu].imie << endl;
    cout << "Nazwisko: " << osoby[iteratorKontaktu].nazwisko << endl;
    cout << "Numer telefonu: " << osoby[iteratorKontaktu].nrTel << endl;
    cout << "E-mail: " << osoby[iteratorKontaktu].email << endl;
    cout << "Adres: " << osoby[iteratorKontaktu].adres << endl;
    cout << endl;

    cout << "Podaj imie: ";
    cin >> osoby[iteratorKontaktu].imie;
    cout << "Podaj nazwisko: ";
    cin >> osoby[iteratorKontaktu].nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, osoby[iteratorKontaktu].nrTel);
    cout << "Podaj e-mail: ";
    cin >> osoby[iteratorKontaktu].email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, osoby[iteratorKontaktu].adres);
    zapiszDaneDoPliku(osoby, iloscOsob);
}

void usunKontakt(vector<Osoba> &osoby)
{
    int szukaneId;
    int iteratorKontaktu;
    int iloscOsob;
    char odpowiedz;

    iloscOsob = wczytajOsobyZPliku(osoby);

    system("cls");
    cout << "Usuwanie kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(osoby, iloscOsob, szukaneId);

    system("cls");
    cout << "Usun kontakt"<< endl;
    cout << "ID: " << osoby[iteratorKontaktu].id << endl;
    cout << "Imie: " << osoby[iteratorKontaktu].imie << endl;
    cout << "Nazwisko: " << osoby[iteratorKontaktu].nazwisko << endl;
    cout << "Numer telefonu: " << osoby[iteratorKontaktu].nrTel << endl;
    cout << "E-mail: " << osoby[iteratorKontaktu].email << endl;
    cout << "Adres: " << osoby[iteratorKontaktu].adres << endl;
    cout << endl;

    cout << "Czy na pewno usunac kontakt? (T/N)";
    cin >> odpowiedz;
    if (odpowiedz == 'T' || odpowiedz =='t')
    {
        osoby.erase(osoby.begin() + iteratorKontaktu);
    }
    iloscOsob--;
    zapiszDaneDoPliku(osoby, iloscOsob);
}
