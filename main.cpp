#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;

struct Uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

struct Adresat
{
    int idAdresata, idUzytkownika;
    string imie, nazwisko, nrTel, email, adres;
};

int rejestracja(vector<Uzytkownik> &uzytkownicy);
int logowanie(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow);
void zmianaHasla(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow, int idZalogowanegoUzytkownika);
int stringNaInt(string liczbaString);
int wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy);
void zapiszDaneLogowaniaDoPliku(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow);
int wczytajAdresatowUzytkownikaZPliku(vector<Adresat> &adresaci, int idUzytkownika, string nazwapliku);
int przypiszId(vector<Adresat> adresaci, int iloscKontaktow);
int dodajOsobe(vector<Adresat> &adresaci, int iloscKontaktow, int idUzytkownika);
void wyszukajPoImieniu(vector<Adresat> &adresaci, string szukanaFraza, int idUzytkownika);
void wyszukajPoNazwisku(vector<Adresat> &adresaci, string szukanaFraza, int idUzytkownika);
void wyswietlWszystkieOsoby(vector<Adresat> &adresaci, int idUzytkownika);
int znajdzIteratorKontaktu(vector<Adresat> &adresaci, int iloscKontaktow, int idKontaktu, int idUzytkownika);
int usunKontakt(vector<Adresat> &adresaci, int idUzytkownika, int iloscUzytkownikow);
void edytujKontakt(vector<Adresat> &adresaci, int idUzytkownika, int iloscUzytkownikow);
void utworzKopieKontaktow(vector<Adresat> adresaci, int iloscUzytkownikow);

int main()
{
    vector<Uzytkownik> uzytkownicy(0);
    vector<Adresat> adresaci(0);
    int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = 0;
    int iloscKontaktow = 0;
    char wybor;

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            system("cls");
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << "Wybor: ";
            cin >> wybor;

            if (wybor == '1')
            {
                iloscUzytkownikow = rejestracja(uzytkownicy);
            }
            else if (wybor == '2')
            {
                iloscUzytkownikow = wczytajUzytkownikowZPliku(uzytkownicy);
                idZalogowanegoUzytkownika = logowanie(uzytkownicy, iloscUzytkownikow);
            }
            else if (wybor == '9')
            {
                exit(0);
            }
        }
        else
        {
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
                iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");
                iloscKontaktow = dodajOsobe(adresaci, iloscKontaktow, idZalogowanegoUzytkownika);
            }
            else if (wybor == '2')
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po imieniu." << endl;
                cout << "Podaj imie: ";
                cin >> szukanaFraza;
                wyszukajPoImieniu(adresaci, szukanaFraza, idZalogowanegoUzytkownika);
            }
            else if (wybor == '3')
            {
                string szukanaFraza;
                cout << "Wyszukiwanie kontaktow po nazwisku." << endl;
                cout << "Podaj nazwisko: ";
                cin >> szukanaFraza;
                wyszukajPoNazwisku(adresaci, szukanaFraza, idZalogowanegoUzytkownika);
            }
            else if (wybor == '4')
            {
                wyswietlWszystkieOsoby(adresaci, idZalogowanegoUzytkownika);
            }
            else if (wybor == '5')
            {
                iloscKontaktow = usunKontakt(adresaci, idZalogowanegoUzytkownika, iloscUzytkownikow);
            }
            else if (wybor == '6')
            {
                edytujKontakt(adresaci, idZalogowanegoUzytkownika, iloscUzytkownikow);
            }
            else if (wybor == '7')
            {
                zmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowanegoUzytkownika);
            }
            else if (wybor == '8')
            {
                idZalogowanegoUzytkownika = 0;
            }
        }

    }
    return 0;
}

int rejestracja(vector<Uzytkownik> &uzytkownicy)
{
    Uzytkownik tymczasowyUzytkownik;
    string nazwa, haslo;
    int iloscUzytkownikow = wczytajUzytkownikowZPliku(uzytkownicy);

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    int i = 0;

    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
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
    tymczasowyUzytkownik.nazwa = nazwa;
    tymczasowyUzytkownik.haslo = haslo;
    tymczasowyUzytkownik.idUzytkownika = iloscUzytkownikow;
    uzytkownicy.push_back(tymczasowyUzytkownik);
    cout << "Konto zalozone" << endl;
    Sleep(1000);
    zapiszDaneLogowaniaDoPliku(uzytkownicy, iloscUzytkownikow);
    return iloscUzytkownikow;
}

int logowanie(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    int i = 0;
    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo: ";
                cin >> haslo;
                if (uzytkownicy[i].haslo == haslo)
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(1000);
                    return uzytkownicy[i].idUzytkownika;
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

void zmianaHasla(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow, int idZalogowanegoUzytkownika)
{
    string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;
    for (int i = 0; i < iloscUzytkownikow; i++)
    {
        if (uzytkownicy[i].idUzytkownika == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo = haslo;
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(1000);
        }
    }
    zapiszDaneLogowaniaDoPliku(uzytkownicy, iloscUzytkownikow);
}

int stringNaInt(string liczbaString)
{
    int liczbaInt = atoi(liczbaString.c_str());
    return liczbaInt;
}

int wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy)
{
    string wczytanaLinia;
    int iloscUzytkownikow = 0;

    Uzytkownik tymczasowyUzytkownik;

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
            tymczasowyUzytkownik.idUzytkownika = stringNaInt(poleUzytkownika[0]);
            tymczasowyUzytkownik.nazwa = poleUzytkownika[1];
            tymczasowyUzytkownik.haslo = poleUzytkownika[2];
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
    return iloscUzytkownikow;
}

void zapiszDaneLogowaniaDoPliku(vector<Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good())
    {
        plik << uzytkownicy[0].idUzytkownika << "|" << uzytkownicy[0].nazwa << "|" << uzytkownicy[0].haslo << endl;
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
            plik << uzytkownicy[i].idUzytkownika << "|" << uzytkownicy[i].nazwa << "|" << uzytkownicy[i].haslo << endl;
            plik.close();
        }
        else
        {
            cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
        }
    }
}

int wczytajAdresatowUzytkownikaZPliku(vector<Adresat> &adresaci, int idUzytkownika, string nazwapliku)
{
    string wczytanaLinia;
    int iloscKontaktow = 0;

    Adresat tymczasowyAdresat;

    adresaci.erase(adresaci.begin(), adresaci.end());

    fstream plik;
    plik.open(nazwapliku.c_str(), ios::in);
    if(plik.good())
    {
        while (getline(plik, wczytanaLinia))
        {
            int dlugoscWczytanejLinii = wczytanaLinia.size();
            int nrPola = 0;
            vector<string> poleKontaktu(7);

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
            tymczasowyAdresat.idUzytkownika = stringNaInt(poleKontaktu[1]);
            if (tymczasowyAdresat.idUzytkownika == idUzytkownika)
            {
                tymczasowyAdresat.idAdresata = stringNaInt(poleKontaktu[0]);
                tymczasowyAdresat.imie = poleKontaktu[2];
                tymczasowyAdresat.nazwisko = poleKontaktu[3];
                tymczasowyAdresat.nrTel = poleKontaktu[4];
                tymczasowyAdresat.email = poleKontaktu[5];
                tymczasowyAdresat.adres = poleKontaktu[6];
                adresaci.push_back(tymczasowyAdresat);
                poleKontaktu.erase(poleKontaktu.begin(), poleKontaktu.end());

                iloscKontaktow++;
            }
        }
        plik.close();
    }
    else
    {
        cout<<"Nie mozna otworzyc pliku!";

    }
    return iloscKontaktow;
}

int przypiszId(vector<Adresat> adresaci, int iloscKontaktow)
{
    int wolneId;

    if (iloscKontaktow == 0)
    {
        wolneId = 1;
    }
    else
    {
        wolneId = adresaci[iloscKontaktow-1].idAdresata + 1;
    }
    return wolneId;
}

int dodajOsobe(vector<Adresat> &adresaci, int iloscKontaktow, int idUzytkownika)
{
    int id;
    string imie, nazwisko, nrTel, email, adres;
    Adresat tymczasowyAdresat;

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

    id = przypiszId(adresaci, iloscKontaktow);
    cout << "Przypisano id " << id << endl;

    tymczasowyAdresat.idAdresata = id;
    tymczasowyAdresat.idUzytkownika = idUzytkownika;
    tymczasowyAdresat.imie = imie;
    tymczasowyAdresat.nazwisko = nazwisko;
    tymczasowyAdresat.nrTel = nrTel;
    tymczasowyAdresat.email = email;
    tymczasowyAdresat.adres = adres;
    adresaci.push_back(tymczasowyAdresat);


    fstream plik;
    plik.open("Adresaci.txt", ios::out | ios::app);
    if (plik.good())
    {
        plik << id << "|" << idUzytkownika << "|" << imie << "|" << nazwisko << "|" << nrTel << "|" << email << "|" << adres << endl;
        plik.close();

        cout << "Osoba zostala dodana.";
        Sleep(1000);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
    }
    iloscKontaktow++;
    adresaci.erase(adresaci.begin(), adresaci.end());
    return iloscKontaktow;
}

void wyszukajPoImieniu(vector<Adresat> &adresaci, string szukanaFraza, int idUzytkownika)
{
    int iloscKontaktow;
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idUzytkownika, "Adresaci.txt");
    cout << "Kontakty o imieniu " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if (adresaci[i].imie == szukanaFraza)
        {
            cout << "ID: " << adresaci[i].idAdresata << endl;
            cout << "Imie: " << adresaci[i].imie << endl;
            cout << "Nazwisko: " << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
            cout << "E-mail: " << adresaci[i].email << endl;
            cout << "Adres: " << adresaci[i].adres << endl;
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

void wyszukajPoNazwisku(vector<Adresat> &adresaci, string szukanaFraza, int idUzytkownika)
{
    int iloscKontaktow;
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idUzytkownika, "Adresaci.txt");
    cout << "Kontakty o nazwisku " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if (adresaci[i].nazwisko == szukanaFraza)
        {
            cout << "ID: " << adresaci[i].idAdresata << endl;
            cout << "Imie: " << adresaci[i].imie << endl;
            cout << "Nazwisko: " << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
            cout << "E-mail: " << adresaci[i].email << endl;
            cout << "Adres: " << adresaci[i].adres << endl;
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

void wyswietlWszystkieOsoby(vector<Adresat> &adresaci, int idUzytkownika)
{
    int iloscKontaktow;
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idUzytkownika, "Adresaci.txt");
    cout << "Lista wszystkich kontaktow: " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        cout << "ID: " << adresaci[i].idAdresata << endl;
        cout << "Imie: " << adresaci[i].imie << endl;
        cout << "Nazwisko: " << adresaci[i].nazwisko << endl;
        cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
        cout << "E-mail: " << adresaci[i].email << endl;
        cout << "Adres: " << adresaci[i].adres << endl;
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

int znajdzIteratorKontaktu(vector<Adresat> &adresaci, int iloscKontaktow, int idKontaktu, int idUzytkownika)
{
    bool czyZnalezionoId = false;
    int znalezionyiteratorKontaktu;

    for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
    {
        if ((idKontaktu == adresaci[iteratorKontaktu].idAdresata) && (idUzytkownika == adresaci[iteratorKontaktu].idUzytkownika))
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
        return(-1);
    }
}

int usunKontakt(vector<Adresat> &adresaci, int idUzytkownika, int iloscUzytkownikow)
{
    int szukaneId;
    int iteratorKontaktu;
    int iloscKontaktow;
    char odpowiedz;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idUzytkownika, "Adresaci.txt");

    system("cls");
    cout << "Usuwanie kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(adresaci, iloscKontaktow, szukaneId, idUzytkownika);

    if (iteratorKontaktu == -1)
    {
        cout << "Nieprawidlowe ID" << endl;
        usunKontakt(adresaci, szukaneId, iloscUzytkownikow);
    }
    else
    {
        system("cls");
        cout << "Usun kontakt"<< endl;
        cout << "ID: " << adresaci[iteratorKontaktu].idAdresata << endl;
        cout << "Imie: " << adresaci[iteratorKontaktu].imie << endl;
        cout << "Nazwisko: " << adresaci[iteratorKontaktu].nazwisko << endl;
        cout << "Numer telefonu: " << adresaci[iteratorKontaktu].nrTel << endl;
        cout << "E-mail: " << adresaci[iteratorKontaktu].email << endl;
        cout << "Adres: " << adresaci[iteratorKontaktu].adres << endl;
        cout << endl;

        cout << "Czy na pewno usunac kontakt? (T/N)";
        cin >> odpowiedz;
        if (odpowiedz == 'T' || odpowiedz =='t')
        {
            utworzKopieKontaktow(adresaci, iloscUzytkownikow);

            fstream plik;
            plik.open("Adresaci.txt", ios::out);
            if (plik.good())
            {
                plik << "";
                plik.close();
            }
            else
            {
                cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
            }

            for (int i = 1; i <= iloscUzytkownikow; i++)
            {
                int iloscKontaktow;
                iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, i, "tempAdresaci.txt");

                for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
                {
                    if (adresaci[iteratorKontaktu].idAdresata != szukaneId)
                    {
                        fstream plik;
                        plik.open("Adresaci.txt", ios::out | ios::app);
                        if (plik.good())
                        {
                            plik << adresaci[iteratorKontaktu].idAdresata << "|" << adresaci[iteratorKontaktu].idUzytkownika << "|" << adresaci[iteratorKontaktu].imie << "|" << adresaci[iteratorKontaktu].nazwisko << "|" << adresaci[iteratorKontaktu].nrTel << "|" << adresaci[iteratorKontaktu].email << "|" << adresaci[iteratorKontaktu].adres << endl;
                            plik.close();
                        }
                        else
                        {
                            cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
                        }

                    }
                }
            }

            fstream plikTemp;
            plikTemp.open("tempAdresaci.txt", ios::out);
            if (plikTemp.good())
            {
                plikTemp << "";
                plikTemp.close();
            }
            else
            {
                cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
            }
        }
        iloscKontaktow--;
    }
    return iloscKontaktow;
}

void edytujKontakt(vector<Adresat> &adresaci, int idUzytkownika, int iloscUzytkownikow)
{
    int szukaneId;
    int iteratorKontaktu;
    int iloscKontaktow;
    Adresat tymczasowyAdresat;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idUzytkownika, "Adresaci.txt");

    system("cls");
    cout << "Edycja kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(adresaci, iloscKontaktow, szukaneId, idUzytkownika);

    if (iteratorKontaktu == -1)
    {
        cout << "Nieprawidlowe ID" << endl;
        edytujKontakt(adresaci, idUzytkownika, iloscUzytkownikow);
    }
    else
    {
        system("cls");
        cout << "Edycja danych"<< endl;
        cout << "ID: " << adresaci[iteratorKontaktu].idAdresata << endl;
        cout << "Imie: " << adresaci[iteratorKontaktu].imie << endl;
        cout << "Nazwisko: " << adresaci[iteratorKontaktu].nazwisko << endl;
        cout << "Numer telefonu: " << adresaci[iteratorKontaktu].nrTel << endl;
        cout << "E-mail: " << adresaci[iteratorKontaktu].email << endl;
        cout << "Adres: " << adresaci[iteratorKontaktu].adres << endl;
        cout << endl;

        cout << "Podaj imie: ";
        cin >> tymczasowyAdresat.imie;
        cout << "Podaj nazwisko: ";
        cin >> tymczasowyAdresat.nazwisko;
        cout << "Podaj numer telefonu: ";
        cin.sync();
        getline(cin, tymczasowyAdresat.nrTel);
        cout << "Podaj e-mail: ";
        cin >> tymczasowyAdresat.email;
        cout << "Podaj adres: ";
        cin.sync();
        getline(cin, tymczasowyAdresat.adres);

        utworzKopieKontaktow(adresaci, iloscUzytkownikow);

        fstream plik;
        plik.open("Adresaci.txt", ios::out);
        if (plik.good())
        {
            plik << "";
            plik.close();
        }
        else
        {
            cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
        }

        for (int i = 1; i <= iloscUzytkownikow; i++)
        {
            int iloscKontaktow;
            iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, i, "tempAdresaci.txt");

            for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
            {
                if (adresaci[iteratorKontaktu].idAdresata == szukaneId)
                {
                    fstream plik;
                    plik.open("Adresaci.txt", ios::out | ios::app);
                    if (plik.good())
                    {
                        plik << adresaci[iteratorKontaktu].idAdresata << "|" << adresaci[iteratorKontaktu].idUzytkownika << "|" << tymczasowyAdresat.imie << "|" << tymczasowyAdresat.nazwisko << "|" << tymczasowyAdresat.nrTel << "|" << tymczasowyAdresat.email << "|" << tymczasowyAdresat.adres << endl;
                        plik.close();
                    }
                    else
                    {
                        cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
                    }
                }
                else
                {
                    fstream plik;
                    plik.open("Adresaci.txt", ios::out | ios::app);
                    if (plik.good())
                    {
                        plik << adresaci[iteratorKontaktu].idAdresata << "|" << adresaci[iteratorKontaktu].idUzytkownika << "|" << adresaci[iteratorKontaktu].imie << "|" << adresaci[iteratorKontaktu].nazwisko << "|" << adresaci[iteratorKontaktu].nrTel << "|" << adresaci[iteratorKontaktu].email << "|" << adresaci[iteratorKontaktu].adres << endl;
                        plik.close();
                    }
                    else
                    {
                        cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
                    }

                }
            }
        }

        fstream plikTemp;
        plikTemp.open("tempAdresaci.txt", ios::out);
        if (plikTemp.good())
        {
            plikTemp << "";
            plikTemp.close();
        }
        else
        {
            cout << "Nie mozna otworzyc pliku Adresaci.txt" << endl;
        }
    }
}

void utworzKopieKontaktow(vector<Adresat> adresaci, int iloscUzytkownikow)
{
    for (int i = 1; i <= iloscUzytkownikow; i++)
    {
        int iloscKontaktow;
        iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, i, "Adresaci.txt");

        for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
        {
            fstream plik;
            plik.open("tempAdresaci.txt", ios::out | ios::app);
            if (plik.good())
            {
                plik << adresaci[iteratorKontaktu].idAdresata << "|" << adresaci[iteratorKontaktu].idUzytkownika << "|" << adresaci[iteratorKontaktu].imie << "|" << adresaci[iteratorKontaktu].nazwisko << "|" << adresaci[iteratorKontaktu].nrTel << "|" << adresaci[iteratorKontaktu].email << "|" << adresaci[iteratorKontaktu].adres << endl;
                plik.close();
            }
            else
            {
                cout << "Nie mozna otworzyc pliku tempAdresaci.txt" << endl;
            }
        }
    }
}
