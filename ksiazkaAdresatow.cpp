#include <iostream>
#include "ksiazkaAdresatow.h"

KsiazkaAdresatow::KsiazkaAdresatow()
{
    idZalogowanegoUzytkownika = 0;
    iloscUzytkownikow = 0;
    iloscKontaktow = 0;
}

int KsiazkaAdresatow::getIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresatow::setIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    this -> idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
}

int KsiazkaAdresatow::getIloscUzytkownikow()
{
    return iloscUzytkownikow;
}

void KsiazkaAdresatow::setIloscUzytkownikow(int iloscUzytkownikow)
{
    this -> iloscUzytkownikow = iloscUzytkownikow;
}

void KsiazkaAdresatow::dodajAdresata(vector<Adresat> &adresaci)
{
    wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");
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

    id = przypiszId();
    cout << "Przypisano id " << id << endl;

    Adresat tymczasowyAdresat(id, idZalogowanegoUzytkownika, imie, nazwisko, nrTel, email, adres);
    adresaci.push_back(tymczasowyAdresat);


    fstream plik;
    plik.open("Adresaci.txt", ios::out | ios::app);
    if (plik.good())
    {
        plik << id << "|" << idZalogowanegoUzytkownika << "|" << imie << "|" << nazwisko << "|" << nrTel << "|" << email << "|" << adres << endl;
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
}

void KsiazkaAdresatow::edytujAdresata(vector<Adresat> &adresaci)
{
    int szukaneId;
    int iteratorKontaktu;
    string tymczasoweImie;
    string tymczasoweNazwisko;
    string tymczasowyNrTel;
    string tymczasowyEmail;
    string tymczasowyAdres;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");

    system("cls");
    cout << "Edycja kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(adresaci, szukaneId);

    if (iteratorKontaktu == -1)
    {
        cout << "Nieprawidlowe ID" << endl;
        edytujAdresata(adresaci);
    }
    else
    {
        system("cls");
        cout << "Edycja danych"<< endl;
        cout << "ID: " << adresaci[iteratorKontaktu].getId() << endl;
        cout << "Imie: " << adresaci[iteratorKontaktu].getImie() << endl;
        cout << "Nazwisko: " << adresaci[iteratorKontaktu].getNazwisko() << endl;
        cout << "Numer telefonu: " << adresaci[iteratorKontaktu].getNumerTelefonu() << endl;
        cout << "E-mail: " << adresaci[iteratorKontaktu].getEmail() << endl;
        cout << "Adres: " << adresaci[iteratorKontaktu].getAdres() << endl;
        cout << endl;

        cout << "Podaj imie: ";
        cin >> tymczasoweImie;
        cout << "Podaj nazwisko: ";
        cin >> tymczasoweNazwisko;
        cout << "Podaj numer telefonu: ";
        cin.sync();
        getline(cin, tymczasowyNrTel);
        cout << "Podaj e-mail: ";
        cin >> tymczasowyEmail;
        cout << "Podaj adres: ";
        cin.sync();
        getline(cin, tymczasowyAdres);

        utworzKopieKontaktow(adresaci);

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
                if (adresaci[iteratorKontaktu].getId() == szukaneId)
                {
                    fstream plik;
                    plik.open("Adresaci.txt", ios::out | ios::app);
                    if (plik.good())
                    {
                        plik << adresaci[iteratorKontaktu].getId() << "|" << adresaci[iteratorKontaktu].getIdUzytkownika() << "|" << tymczasoweImie << "|" << tymczasoweNazwisko << "|" << tymczasowyNrTel << "|" << tymczasowyEmail << "|" << tymczasowyAdres << endl;
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
                        plik << adresaci[iteratorKontaktu].getId() << "|" << adresaci[iteratorKontaktu].getIdUzytkownika() << "|" << adresaci[iteratorKontaktu].getImie() << "|" << adresaci[iteratorKontaktu].getNazwisko() << "|" << adresaci[iteratorKontaktu].getNumerTelefonu() << "|" << adresaci[iteratorKontaktu].getEmail() << "|" << adresaci[iteratorKontaktu].getAdres() << endl;
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

void KsiazkaAdresatow::usunAdresata(vector<Adresat> &adresaci)
{
    int szukaneId;
    int iteratorKontaktu;
    char odpowiedz;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");

    system("cls");
    cout << "Usuwanie kontaktu" << endl;
    cout << "Podaj ID: ";
    cin >> szukaneId;
    iteratorKontaktu = znajdzIteratorKontaktu(adresaci, szukaneId);

    if (iteratorKontaktu == -1)
    {
        cout << "Nieprawidlowe ID" << endl;
        usunAdresata(adresaci);
    }
    else
    {
        system("cls");
        cout << "Usun kontakt"<< endl;
        cout << "ID: " << adresaci[iteratorKontaktu].getId() << endl;
        cout << "Imie: " << adresaci[iteratorKontaktu].getImie() << endl;
        cout << "Nazwisko: " << adresaci[iteratorKontaktu].getNazwisko() << endl;
        cout << "Numer telefonu: " << adresaci[iteratorKontaktu].getNumerTelefonu() << endl;
        cout << "E-mail: " << adresaci[iteratorKontaktu].getEmail() << endl;
        cout << "Adres: " << adresaci[iteratorKontaktu].getAdres() << endl;
        cout << endl;

        cout << "Czy na pewno usunac kontakt? (T/N)";
        cin >> odpowiedz;
        if (odpowiedz == 'T' || odpowiedz =='t')
        {
            utworzKopieKontaktow(adresaci);

            cout << "Zoba kopie" << endl;
            Sleep(30000);

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
                iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, i, "tempAdresaci.txt");

                for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
                {
                    if (adresaci[iteratorKontaktu].getId() != szukaneId)
                    {
                        fstream plik;
                        plik.open("Adresaci.txt", ios::out | ios::app);
                        if (plik.good())
                        {
                            plik << adresaci[iteratorKontaktu].getId() << "|" << adresaci[iteratorKontaktu].getIdUzytkownika() << "|" << adresaci[iteratorKontaktu].getImie() << "|" << adresaci[iteratorKontaktu].getNazwisko() << "|" << adresaci[iteratorKontaktu].getNumerTelefonu() << "|" << adresaci[iteratorKontaktu].getEmail() << "|" << adresaci[iteratorKontaktu].getAdres() << endl;
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
}

void KsiazkaAdresatow::wyszukajPoImieniu(vector<Adresat> &adresaci, string szukanaFraza)
{
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");

    cout << "Kontakty o imieniu " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if (adresaci[i].getImie() == szukanaFraza)
        {
            cout << "ID: " << adresaci[i].getId() << endl;
            cout << "Imie: " << adresaci[i].getImie() << endl;
            cout << "Nazwisko: " << adresaci[i].getNazwisko() << endl;
            cout << "Numer telefonu: " << adresaci[i].getNumerTelefonu() << endl;
            cout << "E-mail: " << adresaci[i].getEmail() << endl;
            cout << "Adres: " << adresaci[i].getAdres() << endl;
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

void KsiazkaAdresatow::wyszukajPoNazwisku(vector<Adresat> &adresaci, string szukanaFraza)
{
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");
    cout << "Kontakty o nazwisku " << szukanaFraza << ": " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if (adresaci[i].getNazwisko() == szukanaFraza)
        {
            cout << "ID: " << adresaci[i].getId() << endl;
            cout << "Imie: " << adresaci[i].getImie() << endl;
            cout << "Nazwisko: " << adresaci[i].getNazwisko() << endl;
            cout << "Numer telefonu: " << adresaci[i].getNumerTelefonu() << endl;
            cout << "E-mail: " << adresaci[i].getEmail() << endl;
            cout << "Adres: " << adresaci[i].getAdres() << endl;
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

void KsiazkaAdresatow::wyswietlWszystkichAdresatow(vector<Adresat> &adresaci)
{
    int znalezioneKontakty = 0;

    iloscKontaktow = wczytajAdresatowUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika, "Adresaci.txt");
    cout << "Lista wszystkich kontaktow: " << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        cout << "ID: " << adresaci[i].getId() << endl;
        cout << "Imie: " << adresaci[i].getImie() << endl;
        cout << "Nazwisko: " << adresaci[i].getNazwisko() << endl;
        cout << "Numer telefonu: " << adresaci[i].getNumerTelefonu() << endl;
        cout << "E-mail: " << adresaci[i].getEmail() << endl;
        cout << "Adres: " << adresaci[i].getAdres() << endl;
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

int KsiazkaAdresatow::przypiszId()
{
    int wolneId = 1;
    string wczytanaLinia;
    string wczytaneID;

    fstream plik;
    plik.open("Adresaci.txt", ios::in);
    if(plik.good())
    {
        while (getline(plik, wczytanaLinia))
        {
            int dlugoscWczytanejLinii = wczytanaLinia.size();

            for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscWczytanejLinii; pozycjaZnaku++)
            {
                if (wczytanaLinia[pozycjaZnaku] != 124)
                {
                    wczytaneID += wczytanaLinia[pozycjaZnaku];
                }
                else
                {
                    if (wolneId <= stringNaInt(wczytaneID))
                    {
                        wolneId = stringNaInt(wczytaneID) + 1;
                    }
                    wczytaneID = "";
                    break;
                }
            }
        }
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku!" << endl;

    }
    return wolneId;
}

int KsiazkaAdresatow::wczytajAdresatowUzytkownikaZPliku(vector<Adresat> &adresaci, int idUzytkownika, string nazwapliku)
{
    string wczytanaLinia;
    int iloscKontaktowUzytkownika = 0;

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

            if (stringNaInt(poleKontaktu[1]) == idUzytkownika)
            {
                Adresat tymczasowyAdresat(stringNaInt(poleKontaktu[0]), stringNaInt(poleKontaktu[1]), poleKontaktu[2], poleKontaktu[3], poleKontaktu[4], poleKontaktu[5], poleKontaktu[6]);
                adresaci.push_back(tymczasowyAdresat);
                poleKontaktu.erase(poleKontaktu.begin(), poleKontaktu.end());

                iloscKontaktowUzytkownika++;
            }
        }
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku!" << endl;

    }
    return iloscKontaktowUzytkownika;
}

int KsiazkaAdresatow::znajdzIteratorKontaktu(vector<Adresat> &adresaci, int idKontaktu)
{
    bool czyZnalezionoId = false;
    int znalezionyiteratorKontaktu;

    for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktow; iteratorKontaktu++)
    {
        if ((idKontaktu == adresaci[iteratorKontaktu].getId()) && (idZalogowanegoUzytkownika == adresaci[iteratorKontaktu].getIdUzytkownika()))
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

void KsiazkaAdresatow::utworzKopieKontaktow(vector<Adresat> adresaci)
{
    for (int i = 1; i <= iloscUzytkownikow; i++)
    {
        int iloscKontaktowUzytkownika;
        iloscKontaktowUzytkownika = wczytajAdresatowUzytkownikaZPliku(adresaci, i, "Adresaci.txt");

        for (int iteratorKontaktu = 0; iteratorKontaktu < iloscKontaktowUzytkownika; iteratorKontaktu++)
        {
            fstream plik;
            plik.open("tempAdresaci.txt", ios::out | ios::app);
            if (plik.good())
            {
                plik << adresaci[iteratorKontaktu].getId() << "|" << adresaci[iteratorKontaktu].getIdUzytkownika() << "|" << adresaci[iteratorKontaktu].getImie() << "|" << adresaci[iteratorKontaktu].getNazwisko() << "|" << adresaci[iteratorKontaktu].getNumerTelefonu() << "|" << adresaci[iteratorKontaktu].getEmail() << "|" << adresaci[iteratorKontaktu].getAdres() << endl;
                plik.close();
            }
            else
            {
                cout << "Nie mozna otworzyc pliku tempAdresaci.txt" << endl;
            }
        }
    }
}

int KsiazkaAdresatow::stringNaInt(string liczbaString)
{
    int liczbaInt = atoi(liczbaString.c_str());
    return liczbaInt;
}

