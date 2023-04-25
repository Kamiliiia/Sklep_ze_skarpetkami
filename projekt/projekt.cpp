#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <cstring> 
#include <string>
#include <conio.h>
#include "funkcje.h"

using namespace std;

int main()
{
	Skarpetka socks;
	vector <Skarpetka> skarpetki;
	int size = 0;

	//aktualizacja wektora - na początku działania programu
	fstream plik;
	plik.open("skarpetki.txt", ios::in);
	string dane;
	while (plik>>dane) 
	{
		skarpetki.push_back(socks);
		strcpy_s(skarpetki[size].producent, dane.c_str());
		plik >> dane;
		skarpetki[size].typ = dane[0] - 48;
		plik >> dane;
		skarpetki[size].plec = dane[0] - 48;
		plik >> dane;
		strcpy_s(skarpetki[size].wzor, dane.c_str());
		plik >> dane;
		strcpy_s(skarpetki[size].kolor, dane.c_str());
		plik >> dane;
		skarpetki[size].rozmiar = stoi(dane);
		plik >> dane;
		skarpetki[size].liczba_sztuk_magazyn = stoi(dane);
		plik >> dane;
		skarpetki[size].cena = stod(dane);
		plik >> dane;
		skarpetki[size].data = dane;
		plik >> dane;
		skarpetki[size].liczba_sztuk_dostawa = stoi(dane);
		size++;
	}
	plik.close();


	//menu
	int poz = 0; //zmienna do przemieszczania sie po tablicy (przy usuwaniu)
	char k='x'; //do sterowania zmienna (przy usuwaniu)
	bool czy_juz_ma_dostawe = false; //do sprawdzania czy dany produkt ma juz dostawe
	bool czy_znaleziono_pozycje = false; //do wyszukiwania po typie/producencie - jesli nie znaleziono pozycji - zbior pusty zwraca

	while (true)
	{
		menu();
		switch (wybor)
		{
		case 1:
			system("cls");
			cout << "DODAJ PRODUKT" << endl;
			skarpetki.push_back(socks);
			dodaj_edytuj_produkt(skarpetki[size]);
			size++;
			cout << endl << "Produkt pomyslnie zostal dodany! " << endl;
			Sleep(1500);
			system("cls");
			break;
		case 2:
			
			system("cls");
			
			poz = 0; //aktualna wyswietlana pozycja, zaczyna od 0

			//jesli rozmiar = 0 to wtedy jest brak pozycji do usuniecia
			if (size == 0)
			{
				cout << "BRAK POZYCJI DO USUNIECIA!" << endl;
				Sleep(1200);
				system("cls");
				break;
			}

			k = 'x'; // do zmiennej k przypisujemy znak inny niz spacja i A oraz D aby nie wpłyneło to na działanie programu 
			while (k != 32)
			{
				system("cls");
				wyswietl(skarpetki[poz]);
				cout << "Do przemieszczania sie pomiedzy tablica uzyj liter A (lewo) i D (prawo)" << endl;
				cout << "Aby usunac element nacisnij spacje" << endl;
				k = _getch();

				if (k == 97 || k == 65)
				{
					poz--;
					if (poz == -1) poz = 0;
					system("cls");
					wyswietl(skarpetki[poz]);
				}

				if (k == 100 || k == 68)
				{
					poz++;
					if (poz == size) poz = size-1;
					system("cls");
					wyswietl(skarpetki[poz]);
				}
			}

			if (k == 32) //jesli spacja została nacisnieta
			{
				skarpetki.erase(skarpetki.begin() + poz);
				size--;
				cout << "Produkt zostal pomyslnie usuniety!" << endl;
				Sleep(1200);
				system("cls");
			}
			
			break;
		case 3:
			system("cls");
			cout << "EDYTUJ PRODUKT" << endl;
			poz = 0; //pozycja do wyswietlenia
			if (size == 0)
			{
				cout << "BRAK POZYCJI DO EDYCJI!" << endl;
				Sleep(1200);
				system("cls");
				break;
			}

			k = 'x';
			//do przemieszczania sie
			while (k != 32)
			{
				system("cls");
				wyswietl(skarpetki[poz]);
				cout << "Do przemieszczania sie pomiedzy tablica uzyj liter A (lewo) i D (prawo)" << endl;
				cout << "Aby edytowac element, nacisnij spacje" << endl;
				k = _getch();

				if (k == 97 || k == 65)
				{
					poz--;
					if (poz == -1) poz = 0;
					system("cls");
					wyswietl(skarpetki[poz]);
				}

				if (k == 100 || k == 68)
				{
					poz++;
					if (poz == size) poz = size - 1;
					system("cls");
					wyswietl(skarpetki[poz]);
				}
			}
			if (k == 32) //jesli zatwierdzono wybor spacją, wtedy dodaje produkt i zamienia z istniejącym
			{
				cout << endl;
				cout << "===EDYCJA=DANYCH===" << endl;
				dodaj_edytuj_produkt(skarpetki[poz]);
			}
			cout << endl << "Produkt pomyslnie zostal zmieniony! " << endl;
			Sleep(1500);
			system("cls");
			break;
		case 4: //dodawanie dostawy do wybranego produktu
			 //pozycja do wyswietlenia
			if (size == 0)
			{
				cout << "BRAK POZYCJI DO DODANIA DOSTAWY!" << endl;
				Sleep(1200);
				system("cls");
				break;
			}
			poz = 0;
			k = 'x'; // przypisanie zmiennej k znaku ktory nie bedzie wykorzystywany do obslugi programu		
			//do przemieszczania sie
			while (k != 32)
			{
				system("cls");
				wyswietl(skarpetki[poz]);
				cout << "Do przemieszczania sie pomiedzy tablica uzyj liter A (lewo) i D (prawo)" << endl;
				cout << "Aby dodac dostawe, nacisnij spacje" << endl;
				cout << "Mozna dodawac tylko dostawy do produktow, ktore jej jeszcze nie maja" << endl;
				k = _getch();

				if (k == 97 || k == 65)
				{
					poz--;
					if (poz == -1) poz = 0;
					system("cls");
					wyswietl(skarpetki[poz]);
				}

				if (k == 100 || k == 68)
				{
					poz++;
					if (poz == size) poz = size-1;
					system("cls");
					wyswietl(skarpetki[poz]);
				}
			}
			if (k == 32) //jesli zatwierdzono wybor spacją, wtedy dodaje produkt 
			{
				if (skarpetki[poz].data == "X")
				{
					cout << endl;
					cout << "===DODAWANIE=DOSTAWY===" << endl;
					dodaj_edytuj_dostawe(skarpetki[poz]);
				}
				else
				{
					system("cls");
					cout << "WYBRANY PRODUKT MA JUZ DOSTAWE!" << endl;
					Sleep(1200);
					system("cls");
					break;
				}
			}
			cout << endl << "Dostawa pomyslnie zostala dodana! " << endl;
			Sleep(1500);
			system("cls");
			break;

		case 5: //edycja dostawy
			poz = 0; //pozycja do wyswietlenia
			if (size == 0)
			{
				cout << "BRAK POZYCJI DO EDYCJI DOSTAWY!" << endl;
				Sleep(1200);
				system("cls");
				break;
			}
			k = 'x'; // przypisanie zmiennej k znaku ktory nie bedzie wykorzystywany do obslugi programu		
			//do przemieszczania sie
			while (k != 32)
			{
				system("cls");
				wyswietl(skarpetki[poz]);
				cout << "Do przemieszczania sie pomiedzy tablica uzyj liter A (lewo) i D (prawo)" << endl;
				cout << "Aby dodac dostawe, nacisnij spacje" << endl;
				cout << "Mozna edytowac tylko istniejace dostawy" << endl;
				k = _getch();

				if (k == 97 || k == 65)
				{
					poz--;
					if (poz == -1) poz = 0;
					system("cls");
					wyswietl(skarpetki[poz]);
				}

				if (k == 100 || k == 68)
				{
					poz++;
					if (poz == size) poz = size - 1;
					system("cls");
					wyswietl(skarpetki[poz]);
				}
			}
			if (k == 32) //jesli zatwierdzono wybor spacją, wtedy dodaje produkt i zamienia z istniejącym
			{
				if (skarpetki[poz].data != "X")
				{
					cout << endl;
					cout << "===DODAWANIE=DOSTAWY===" << endl;
					dodaj_edytuj_dostawe(skarpetki[poz]);
				}
				else
				{
					system("cls");
					cout << "NIE MOZNA EDYTOWAC DOSTAWY, JESLI NIE MA JEJ DODANEJ!" << endl;
					Sleep(1200);
					system("cls");
					break;
				}
			}
			cout << endl << "Dostawa pomyslnie zostala zaktualizowana! " << endl;
			Sleep(1500);
			system("cls");
			break;
			break;
		case 6:
			system("cls");
			cout << "==WYSZUKIWANIE=PO=TYPIE==" << endl;
			wpisywanie_typu_do_wyszukiwania();
			system("cls");
			k = 'x';
			
			for (int i = 0; i < size; i++)
			{
				if (typ == skarpetki[i].typ)
				{
					czy_znaleziono_pozycje = true;
					wyswietl(skarpetki[i]);
					cout << "----------------------------------------------" << endl;
					cout << endl;
				}
			}
			if (czy_znaleziono_pozycje == false) cout << "BRAK DANYCH DO WYSWIETLENIA" << endl;
			
			cout<< "Aby kontynuowac, nacisnij dowolny klawisz ";
			k = _getch();
			
			system("cls");
			break;

		case 7:
			system("cls");
			cout << "==WYSZUKIWANIE=PO=PRODUCENCIE==" << endl;
			wpisywanie_producenta_do_wyszukiwania();
			system("cls");
			k = 'x';
			czy_znaleziono_pozycje = false;
			for (int i = 0; i < size; i++)
			{
				if (producent == skarpetki[i].producent)
				{
					czy_znaleziono_pozycje = true;
					wyswietl(skarpetki[i]);
					cout << "----------------------------------------------" << endl;
					cout << endl;
				}
			}
			if (czy_znaleziono_pozycje == false) cout << "BRAK DANYCH DO WYSWIETLENIA" << endl;

			cout << "Aby kontynuowac, nacisnij dowolny klawisz ";
			k = _getch();

			system("cls");
			break;
		case 8: //wyswietlanie
			for (int i = 0; i < size; i++)
			{
				cout << "----------------------------------" << endl;
				wyswietl(skarpetki[i]);
			}
		case 9:
			//zapis do pliku
			czyszczenie_pliku();
			for (int i = 0; i < size; i++)
			{
				zapis_koncowy(skarpetki[i]);
			}
			exit(0);
			break;
		default:
			system("cls");
			cout << "Bledny wybor! Sprobuj jeszcze raz!" << endl << endl;
			menu();
			break;
		}
	}
}