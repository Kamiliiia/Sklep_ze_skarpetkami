#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <cstring> 
#include <string>
#include <conio.h>
#include "funkcje.h"

using namespace std;

struct Skarpetka;

int wybor = 0;

int menu()
{
	cout << "SKLEP ZE SKARPETKAMI" << endl;
	cout << "---------------------" << endl;
	cout << "1. Dodaj produkt" << endl;
	cout << "2. Usun produkt" << endl;
	cout << "3. Zmien dane produktu" << endl;
	cout << "4. Dodaj dostawe produktu" << endl;
	cout << "5. Zmien dostawe produktu" << endl;
	cout << "6. Wyszukiwanie produktu po typie" << endl;
	cout << "7. Wyszukiwanie produktu po producencie" << endl;
	cout << "8. Wyswietlenie produktow" << endl;
	cout << "9. Wyjscie" << endl;

	cout << "Twoj wybor: ";
	cin >> wybor;

	return wybor;
}

void dodaj_edytuj_produkt(Skarpetka& skarpetki) //funkcja obslugujaca dodawanie, edytowanie produktu - interakcja z uzytkownikiem
{
	bool flaga = false; //flaga do sprawdzania czy zmienna spe³nia odpowiednie warunki

	//producent
	cout << "Producent: ";
	string producent;

	while (flaga == false)
	{
		cin >> producent;
		if (producent.length() <= 256) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! Maksymalna liczba znakow wynosi 256! " << endl;
			cout << "Producent: ";
		}
	}
	strcpy_s(skarpetki.producent, producent.c_str()); //konwersja ze stringa na char

	//typ skarpetki
	cout << "Typ skarpetki: " << endl;
	cout << "1 - stopki " << endl;
	cout << "2 - klasyczne" << endl;
	cout << "3 - podkolanowki" << endl;
	cout << "4 - sportowe" << endl;
	cout << "5 - balerinki" << endl;
	cout << "6 - zdrowotne" << endl;
	cout << "Podaj numer typu: ";
	string numer_typu;
	flaga = false;

	while (flaga == false)
	{
		cin >> numer_typu;
		if (numer_typu.length() == 1 && numer_typu[0] >= 49 && numer_typu[0] <= 54) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz!" << endl;
			cout << "Podaj numer typu: ";
		}
	}
	skarpetki.typ = numer_typu[0] - 48;

	//p³eæ
	cout << "Plec: 0 -> kobieta, 1 -> mezczyzna: ";
	string plec;
	flaga = false;
	while (flaga == false)
	{
		cin >> plec;
		if (plec.length() == 1 && (plec[0] == 48 || plec[0] == 49)) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz!" << endl;
			cout << "Plec: 0 -> kobieta, 1 -> mezczyzna: ";
		}
	}
	skarpetki.plec = plec[0] - 48;

	//wzór na skarpetce
	cout << "Wzor na skarpetce: ";
	string wzor;
	flaga = false;
	while (flaga == false)
	{
		cin >> wzor;
		if (wzor.length() <= 50) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! Maksymalna liczba znakow wynosi 50! " << endl;
			cout << "Wzor na skarpetce: ";
		}
	}
	strcpy_s(skarpetki.wzor, wzor.c_str()); //konwersja ze stringa na char

	//dominuj¹cy kolor skarpetki
	cout << "Dominujacy kolor: ";
	flaga = false;
	string kolor;
	while (flaga == false)
	{
		cin >> kolor;
		if (kolor.length() <= 50) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! Maksymalna liczba znakow wynosi 50! " << endl;
			cout << "Dominujacy kolor: ";
		}
	}
	strcpy_s(skarpetki.kolor, kolor.c_str()); //konwersja ze stringa na char

	//rozmiar z zakresu 35-46
	cout << "Rozmiar (zakres 35-46): ";
	string rozmiar;
	flaga = false;
	while (flaga == false)
	{
		cin >> rozmiar;
		if (rozmiar.length() == 2 && rozmiar[0] > 48 && rozmiar[0] <= 57 && rozmiar[1] >= 48 && rozmiar[1] <= 57) //je¿eli pierwszy i drugi znak to cyfry to wtedy wykonaj konwersjê
		{
			int rozm = stoi(rozmiar);
			if (rozm >= 35 && rozm <= 46) flaga = true;
			else
			{
				flaga = false;
				cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! " << endl;
				cout << "Rozmiar (zakres 35-46): ";
			}
		}
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! " << endl;
			cout << "Rozmiar (zakres 35-46): ";
		}
	}
	skarpetki.rozmiar = stoi(rozmiar);

	//dostepna liczba sztuk w magazynie
	cout << "Dostepna liczba sztuk: ";
	string liczba; //zmienna do sprawdzenia czy uzytkownik wprowadzil liczbe
	flaga = false;

	while (flaga == false)
	{
		cin >> liczba;
		for (int i = 0; i < liczba.length(); i++)
		{
			if (liczba[i] >= 48 && liczba[i] <= 57)  flaga = true;
			else
			{
				flaga = false;
				cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! " << endl;
				cout << "Dostepna liczba sztuk: ";
				break;
			}
		}
	}
	skarpetki.liczba_sztuk_magazyn = stoi(liczba);

	//cena produktu
	cout << "Cena (liczba z miejscami po przecinku lub kropce): ";
	string cena;
	flaga = false;

	while (flaga == false)
	{
		cin >> cena;
		for (int i = 0; i < cena.length(); i++)
		{
			if (cena[i] == '.' || cena[i] == ',' || (cena[i] >= '0' && cena[i] <= '9'))
			{
				if (cena[i] == ',') cena[i] = '.';
				flaga = true;
				continue;
			}
			else
			{
				flaga = false;
				cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! " << endl;
				cout << "Cena (liczba z miejscami po przecinku lub kropce): ";
				break;
			}
		}
	}
	skarpetki.cena = stod(cena);

	if (skarpetki.data == "")
	{
		skarpetki.data = 'X';
		skarpetki.liczba_sztuk_dostawa = 0;
	}
	cout << endl;
}

void dodaj_edytuj_dostawe(Skarpetka& skarpetki)
{
	system("cls");
	string dzien;
	string miesiac;
	string rok;
	cout << "DANE DOSTAWY:" << endl;
	//rok 
	cout << "Podaj rok dostawy: ";
	int r;
	int m;
	int d;
	bool flaga = false;
	flaga = false;

	while (flaga == false)
	{
		//zabezpieczenie zeby uzytkownik nie wprowadzi³ liter lub innych znaków niz liczby
		while (flaga == false)
		{
			cin >> rok;
			for (int i = 0; i < rok.length(); i++)
			{
				if (rok[i] < 48 || rok[i] > 57)
				{
					flaga = false;
					cout << "Nieprawidlowy typ danych! Sprobuj ponownie! " << endl;
					cout << "Podaj rok: ";
					break;
				}
				else
				{
					flaga = true;
				}
			}
		}
		r = stoi(rok); //rok w int

		if (rok.length() == 4 && r >= 2023 && r <= 2100)
		{
			flaga = true;
			//miesi¹c
			flaga = false;
			while (flaga == false)
			{
				cout << "Podaj miesiac: ";

				//zabezpieczenie zeby uzytkownik nie wprowadzi³ liter lub innych znaków niz liczby
				flaga = false;
				while (flaga == false)
				{
					cin >> miesiac;
					for (int i = 0; i < miesiac.length(); i++)
					{
						if (miesiac[i] < 48 || miesiac[i] > 57)
						{
							flaga = false;
							cout << "Nieprawidlowy typ danych! Sprobuj ponownie! " << endl;
							cout << "Podaj miesiac: ";
							break;
						}
						else
						{
							flaga = true;
						}
					}
				}
				m = stoi(miesiac);
				if (m >= 1 && m <= 12)
				{
					flaga = true;

					//dzien
					flaga = false;
					while (flaga == false)
					{
						cout << "Podaj dzien: ";

						//zabezpieczenie zeby uzytkownik nie wprowadzi³ liter lub innych znaków niz liczby
						while (flaga == false)
						{
							cin >> dzien;
							for (int i = 0; i < dzien.length(); i++)
							{
								if (dzien[i] < 48 || dzien[i] > 57)
								{
									flaga = false;
									cout << "Nieprawidlowy typ danych! Sprobuj ponownie! " << endl;
									cout << "Podaj dzien: ";
									break;
								}
								else
								{
									flaga = true;
								}
							}
						}
						d = stoi(dzien);

						//zabezpieczenie liczby dni w podanym miesiacu
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							if (d >= 1 && d <= 31)
							{
								flaga = true;
							}

							else
							{
								flaga = false;
								cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
								cout << "Podaj dzien dostawy: ";
							}
						}

						if (m == 2) //luty w latach przestêpnych i normalnych
						{
							if (r % 4 == 0)
							{
								if (r % 100 != 0 || r % 100 == 0 && r % 400 == 0)
								{
									if (d >= 1 && d <= 29)
									{
										flaga = true;
									}

									else
									{
										flaga = false;
										cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
										cout << "Podaj dzien dostawy: ";
									}
								}
								if (r % 100 == 0 && r % 400 != 0)
								{
									if (d >= 1 && d <= 28)
									{
										flaga = true;
									}

									else
									{
										flaga = false;
										cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
										cout << "Podaj dzien dostawy: ";
									}
								}
							}

							else
							{
								if (d >= 1 && d <= 28)
								{
									flaga = true;
								}

								else
								{
									flaga = false;
									cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
									cout << "Podaj dzien dostawy: ";
								}
							}
						}

						if (m == 4 || m == 6 || m == 9 || m == 11) // miesiace maj¹ce po 30 dni
						{
							if (d >= 1 && d <= 30)
							{
								flaga = true;
							}

							else
							{
								flaga = false;
								cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
								cout << "Podaj dzien dostawy: ";
							}
						}
					}
				}
				else
				{
					flaga = false;
					cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
					cout << "Podaj miesiac dostawy: ";
				}
			}
		}
		else
		{
			flaga = false;
			cout << "Nieprawidlowy typ danych! Sprobuj jeszcze raz!" << endl;
			cout << "Podaj rok dostawy: ";
		}
	}

	skarpetki.data = "";
	if (dzien.length() == 1) dzien = "0" + dzien;
	if (miesiac.length() == 1) miesiac = "0" + miesiac;
	skarpetki.data = dzien + "-" + miesiac + "-" + rok;

	//liczba sztuk w nastêpnej dostawie
	string liczba;
	flaga = false;
	cout << "Liczba sztuk w nastepnej dostawie: ";

	while (flaga == false)
	{
		cin >> liczba;
		for (int i = 0; i < liczba.length(); i++)
		{
			if (liczba[i] >= 48 && liczba[i] <= 57)  flaga = true;
			else
			{
				flaga = false;
				cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! " << endl;
				cout << "Dostepna liczba sztuk: ";
				break;
			}
		}
	}
	skarpetki.liczba_sztuk_dostawa = stoi(liczba);
}

//funkcja wyswietlajaca
void wyswietl(Skarpetka& skarpetki)
{
	cout << "Producent: " << skarpetki.producent << endl;
	cout << "Typ: ";
	if (skarpetki.typ == 1) cout << "stopki" << endl;
	if (skarpetki.typ == 2) cout << "klasyczne" << endl;
	if (skarpetki.typ == 3) cout << "podkolanowki" << endl;
	if (skarpetki.typ == 4) cout << "sportowe" << endl;
	if (skarpetki.typ == 5) cout << "balerinki" << endl;
	if (skarpetki.typ == 6) cout << "zdrowotne" << endl;
	cout << "Plec: ";
	if (skarpetki.plec == 0) cout << "kobieta" << endl;
	if (skarpetki.plec == 1) cout << "mezczyzna" << endl;
	cout << "Wzor: " << skarpetki.wzor << endl;
	cout << "Kolor: " << skarpetki.kolor << endl;
	cout << "Rzomiar: " << skarpetki.rozmiar << endl;
	cout << "Liczba sztuk w magazynie: " << skarpetki.liczba_sztuk_magazyn << endl;
	cout << "Cena: " << skarpetki.cena << endl << endl;

	//je¿eli dostawa istnieje to j¹ wyœwietl
	if (skarpetki.data != "X")
	{
		cout << "---DANE-DOSTAWY---" << endl;
		cout << "Data nastepnej dostawy: " << skarpetki.data << endl;
		cout << "Liczba sztuk w nastepnej dostawie: " << skarpetki.liczba_sztuk_dostawa << endl << endl;
	}

}

int typ = 0;
void wpisywanie_typu_do_wyszukiwania() //interakcja z u¿ytkownikiem - wpisywanie typu
{
	string numer_typu;
	bool flaga = false;

	cout << "Typ skarpetki: " << endl;
	cout << "1 - stopki " << endl;
	cout << "2 - klasyczne" << endl;
	cout << "3 - podkolanowki" << endl;
	cout << "4 - sportowe" << endl;
	cout << "5 - balerinki" << endl;
	cout << "6 - zdrowotne" << endl;
	cout << "Podaj numer typu: ";

	while (flaga == false)
	{
		cin >> numer_typu;
		if (numer_typu.length() == 1 && numer_typu[0] >= 49 && numer_typu[0] <= 54) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz!" << endl;
			cout << "Podaj numer typu: ";
		}
	}
	typ = numer_typu[0] - 48;
}

string producent = "";
void wpisywanie_producenta_do_wyszukiwania()
{
	bool flaga = false;
	cout << "Podaj nazwe producenta: ";
	while (flaga == false)
	{
		cin >> producent;
		if (producent.length() <= 256) flaga = true;
		else
		{
			flaga = false;
			cout << "Zle wprowadzony format danych! Sprobuj jeszcze raz! Maksymalna liczba znakow wynosi 256! " << endl;
			cout << "Producent: ";
		}
	}
}

//przed zapisem czysci plik
void czyszczenie_pliku()
{
	fstream plik;
	plik.open("skarpetki.txt", ios::out); //aby wyczyscic plik
	plik.close();
}

//zapisanie danych do pliku
void zapis_koncowy(Skarpetka& skarpetki)
{
	fstream plik;
	plik.open("skarpetki.txt", ios::app); //dopis do pliku
	plik << skarpetki.producent << endl;
	plik << skarpetki.typ << endl;
	plik << skarpetki.plec << endl;
	plik << skarpetki.wzor << endl;
	plik << skarpetki.kolor << endl;
	plik << skarpetki.rozmiar << endl;
	plik << skarpetki.liczba_sztuk_magazyn << endl;
	plik << skarpetki.cena << endl;
	plik << skarpetki.data << endl;
	plik << skarpetki.liczba_sztuk_dostawa << endl;
	plik.close();
}
