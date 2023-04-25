#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <cstring> 
#include <string>
#include <conio.h>

using namespace std;

struct Skarpetka
{
	char producent[256]; //producent skarpetek
	int typ; //typ skarpetki
	int plec; // p�e� (0 - kobieta, 1 - m�czyzna)
	char wzor[50]; //wz�r na skarpetce
	char kolor[50]; //dominuj�cy kolor skarpetki
	int rozmiar; //liczba naturalna z zakresu: 35-46
	int liczba_sztuk_magazyn; //liczba dost�pnych sztuk na magazynie
	double cena; //koszt skarpetek
	string data; //data nast�pnej dostawy
	int liczba_sztuk_dostawa; //liczba sztuk w nast�pnej dostawie
};

int menu();
void dodaj_edytuj_produkt(Skarpetka& skarpetki);
void dodaj_edytuj_dostawe(Skarpetka& skarpetki);
void wyswietl(Skarpetka& skarpetki);
void wpisywanie_typu_do_wyszukiwania();
void wpisywanie_producenta_do_wyszukiwania();
void czyszczenie_pliku();
void zapis_koncowy(Skarpetka& skarpetki);
extern int wybor;
extern int typ;
extern string producent;

#endif
