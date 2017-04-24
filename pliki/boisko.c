// boisko.c
#include "definicje.h"
#include "boisko.h"

// funkcja rysuje gorna i dolna belke oraz linie srodkowa
void rysuj_boisko()
{
	int i, j;
	for(i = 0; i < SZEROKOSC; ++i) mvaddstr(0, i, " ");
	for(i = 0; i < SZEROKOSC; ++i) mvaddstr(WYSOKOSC - 1, i, " ");
	for(i = 1; i < WYSOKOSC; i += 2) mvaddstr(i, SZEROKOSC / 2, "  ");
}
