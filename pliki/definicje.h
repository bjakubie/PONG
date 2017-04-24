// definicje.h

#ifndef _DEFINNICJE_H
#define _DEFINNICJE_H

#define WYSOKOSC 		 36				// wysokosc planszy do gry
#define SZEROKOSC 	132				// szerokosc planszy do gry
#define WYGRANA		 21				// gra toczy sie do 21 punktow

// struktura pilka przechowuje aktualne wspolrzedne pilki
struct ball
{
	float x;
	float y;
	float przyrost_x;			// zmienna przesuwa pilke wzdluz osi OX o wartosc przyrost_x
	float przyrost_y;			// zmienna przesuwa pilke wzdluz osi OY o wartosc przyrost_y
	int opoznienie;			// predkosc poruszania sie pilki (czas w milisekundach)
	int licznik_odbic;		// zmienna przechowuje liczbe odbic pileczki paletkami
} pilka;

// aktualny stan punktowy rozgrywki
struct result
{
	int l;						// liczba punktow zdobyta przez lewego gracza
	int p;						// liczba punktow zdobyta przez prawego gracza
} wynik;

#endif