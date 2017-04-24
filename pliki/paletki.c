// paletki.c

#include "definicje.h"
#include "paletki.h"

// funkcja rysuje paletki. Parametr l_y to gorny wierzcholek lewej paletki, p_x - prawej
// wysokosc paletek wynosi 5 wierszy 
void rysuj_paletki(int l_y, int p_y)
{
	int i;
	for(i = 0; i < 5; ++i) mvaddstr(l_y + i, 2, "  ");
	for(i = 0; i < 5; ++i) mvaddstr(p_y + i, SZEROKOSC - 4, "  ");
}