// wynik.c
 
#include "definicje.h"
#include "wynik.h" 
 
void rysuj_zero(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x, "  ");
	mvaddstr(WYSOKOSC + 3, x + 4, "  ");
	mvaddstr(WYSOKOSC + 4, x, "  ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");

}

void rysuj_jeden(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "  ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 3, x, "  ");
	mvaddstr(WYSOKOSC + 4, x, "  ");
	mvaddstr(WYSOKOSC + 5, x, "  ");
}

void rysuj_dwa(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

void rysuj_trzy(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

void rysuj_cztery(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "  ");
	mvaddstr(WYSOKOSC + 1, x + 4, "  ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x + 4, "  ");
}

void rysuj_piec(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

void rysuj_szesc(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 4, x, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

/*void rysuj_siedem(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x + 4, "  ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x + 4, "  ");
}
*/
void rysuj_siedem(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 3, x + 3, "  ");
	mvaddstr(WYSOKOSC + 4, x + 2, "  ");
	mvaddstr(WYSOKOSC + 5, x + 1, "  ");
}

void rysuj_osiem(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x, "  ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

void rysuj_dziewiec(int os, int odl)
{
	int x;

	x = ((SZEROKOSC / 2) + os) + odl;
	mvaddstr(WYSOKOSC + 1, x, "      ");
	mvaddstr(WYSOKOSC + 2, x + 4, "  ");
	mvaddstr(WYSOKOSC + 2, x, "  ");
	mvaddstr(WYSOKOSC + 3, x, "      ");
	mvaddstr(WYSOKOSC + 4, x + 4, "  ");
	mvaddstr(WYSOKOSC + 5, x, "      ");
}

// funkcja wyswietla aktualny stan punktowy gry
void rysuj_wynik()
{
	// dwukropek
	mvaddstr(WYSOKOSC + 2, SZEROKOSC / 2, "  ");
	mvaddstr(WYSOKOSC + 4, SZEROKOSC / 2, "  ");
		
	// wynik dzieciatek lewego gracza
	if((wynik.l / 10) == 1) rysuj_jeden(-7, -6);
	else if((wynik.l / 10) == 2) rysuj_dwa(-11, -6);
	else rysuj_zero(-11, -6);

	// wynik jednosci lewego gracza
	if((wynik.l % 10) == 0) 	  rysuj_zero(-3, -6);
	else if((wynik.l % 10) == 1) rysuj_jeden(1, -6);
	else if((wynik.l % 10) == 2) rysuj_dwa(-3, -6);
	else if((wynik.l % 10) == 3) rysuj_trzy(-3, -6);
	else if((wynik.l % 10) == 4) rysuj_cztery(-3, -6);
	else if((wynik.l % 10) == 5) rysuj_piec(-3, -6);
	else if((wynik.l % 10) == 6) rysuj_szesc(-3, -6);
	else if((wynik.l % 10) == 7) rysuj_siedem(-3, -6);
	else if((wynik.l % 10) == 8) rysuj_osiem(-3, -6);
	else 								  rysuj_dziewiec(-3, -6);

	// wynik dzieciatek prawego gracza
	if((wynik.p / 10) == 1) 		rysuj_jeden(9, 0);
	else if((wynik.p / 10) == 2) 	rysuj_dwa(5, 0);
	else 									rysuj_zero(5, 0);

	// wynik jednosci prawego gracza
	if((wynik.p % 10) == 0) 	  rysuj_zero(13, 0);
	else if((wynik.p % 10) == 1) rysuj_jeden(13, 0);
	else if((wynik.p % 10) == 2) rysuj_dwa(13, 0);
	else if((wynik.p % 10) == 3) rysuj_trzy(13, 0);
	else if((wynik.p % 10) == 4) rysuj_cztery(13, 0);
	else if((wynik.p % 10) == 5) rysuj_piec(13, 0);
	else if((wynik.p % 10) == 6) rysuj_szesc(13, 0);
	else if((wynik.p % 10) == 7) rysuj_siedem(13, 0);
	else if((wynik.p % 10) == 8) rysuj_osiem(13, 0);
	else 								  rysuj_dziewiec(13, 0);

}
