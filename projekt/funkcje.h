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
	int plec; // p³eæ (0 - kobieta, 1 - mê¿czyzna)
	char wzor[50]; //wzór na skarpetce
	char kolor[50]; //dominuj¹cy kolor skarpetki
	int rozmiar; //liczba naturalna z zakresu: 35-46
	int liczba_sztuk_magazyn; //liczba dostêpnych sztuk na magazynie
	double cena; //koszt skarpetek
	string data; //data nastêpnej dostawy
	int liczba_sztuk_dostawa; //liczba sztuk w nastêpnej dostawie
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
