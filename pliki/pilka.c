// pilka.c

#include "definicje.h"
#include "pilka.h"

// funkcja rysuje pilke w punkcie o wspolrzednych (y, x)
void rysuj_pilke()
{
	mvaddstr((int)pilka.y, (int)pilka.x, "  ");
}