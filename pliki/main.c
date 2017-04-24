#include <ncurses.h>
#include <unistd.h>

#include "definicje.h"
#include "boisko.h"
#include "paletki.h"
#include "pilka.h"
#include "wynik.h"

/*
Kat odbicia pilki od paletki oraz przyrost wspolrzednych (x,y)
lewa paletka
45			(1,-1)
67,5		(1,-0.5)
90			(1,0)
67,5		(1,0.5)
45			(1,1)

prawa paletka
(-1,-1)		45
(-1,-0.5)	67,5
(-1,0)		90
(-1,0.5)		67,5
(-1,1)		45
*/

int main(int argc, char *argv[])
{
	int i, j, max_x, max_y, ch;
	int paletka_lewa, paletka_prawa;			// wspolrzedna y gornego wierzcholka paletki

	initscr();										// Inicjalizacja okna
	noecho();										// Nie wyswietlaj wciskanych przyciskow
	cbreak();										// Brak buforowania znakow
	curs_set(FALSE);								// Nie wyswietlaj	kursora
	keypad(stdscr, TRUE);						// Akceptuj wszystkie klawisze
	nodelay(stdscr, TRUE);						// Ustaw terminal w tryb nie-blokowania. getch() zwróci ERR jeżeli nie ma wejścia
	start_color();									// Inicjalizacja kolorow

	getmaxyx(stdscr, max_y, max_x);			// funkcja zwraca liczbe wierszy i kolumn
	if((max_y < WYSOKOSC) || (max_x < SZEROKOSC))
	{
		init_pair(1, COLOR_RED, COLOR_BLACK);
		mvaddstr(1, 2, "Aby uruchomic gre prosze zmaksymalizowac okno terminala");
		mvchgat(1, 2, -1, A_BLINK, 1, NULL);
		getch();
		refresh();
		endwin();			// Przywroc terminal

		return 0;
	}

	if(has_colors())
	{
		init_pair(1, COLOR_BLACK, COLOR_WHITE);	// do pierwszego trybu  przypisz czarny kolor czcionki i bialy kolor tla
		color_set(1, NULL);
		paletka_lewa = paletka_prawa = (WYSOKOSC / 2) - 3;		// ustaw paletki na srodku

		clear();													// czysc ekran
		rysuj_boisko();
		rysuj_paletki(paletka_lewa, paletka_prawa);
	
		pilka.x = (int)((SZEROKOSC / 2) - 15);
		pilka.y = (int)(WYSOKOSC / 2);
		pilka.przyrost_x = 1.0;
		pilka.przyrost_y = -0.5;
		pilka.opoznienie = 60000;
		pilka.licznik_odbic = 0;
		rysuj_pilke();
		wynik.p = wynik.l = 0;
		rysuj_wynik();
		refresh();												// odswiez ekran

		wynik.l = wynik.p	= 0;
		while(1)
		{
			ch = getch();
			if(ch != ERR)										// jeśli wejscie jest niepuste (jesli wcisnieto przycisk)
			{
				if(ch == 27) break;							// wykonuj dopoki pobrany znak rozny od ESC
				else if(ch == KEY_UP)						// jesli wcisnieto strzalke do gory
				{
					if(paletka_prawa > 1) --paletka_prawa;
				}
				else if(ch == KEY_DOWN)						// jesli wcisnieto strzalke do dolu
				{
					if((paletka_prawa + 6) < WYSOKOSC) ++paletka_prawa;
				}
				else if(ch == 'e')							// jesli wcisnieto klawisz e
				{
					if(paletka_lewa > 1) --paletka_lewa;
				}
				else if(ch == 'x')							// jesli wcisnieto klawisz x
				{
					if((paletka_lewa + 6) < WYSOKOSC) ++paletka_lewa;
				}
			}

			clear();												// czysc ekran
			rysuj_boisko();
			rysuj_paletki(paletka_lewa, paletka_prawa);
			pilka.x += pilka.przyrost_x;
			pilka.y += pilka.przyrost_y;
			rysuj_pilke();
			rysuj_wynik();

			if(((int)pilka.y == 1) || ((int)pilka.y == WYSOKOSC - 2)) pilka.przyrost_y *= -1; // odbij pilke od boiska
			if((int)pilka.x == 3)									// czy lewy gracz odbije pilke?
			{
				if((paletka_lewa <= (int)pilka.y) && ((paletka_lewa + 4) >= (int)pilka.y))		// tak
				{
					pilka.przyrost_x *= -1.0;						// zmien kierunek lotu pilki
					// ustal kat odbicia
					if((int)pilka.y == paletka_lewa) pilka.przyrost_y = -1.0;
					else if((int)pilka.y == paletka_lewa + 1) pilka.przyrost_y = -0.5;
					else if((int)pilka.y == paletka_lewa + 2) pilka.przyrost_y = 0.0;
					else if((int)pilka.y == paletka_lewa + 3) pilka.przyrost_y = 0.5;
					else if((int)pilka.y == paletka_lewa + 4) pilka.przyrost_y = 1.0;

					++pilka.licznik_odbic;
					if(pilka.opoznienie == 1000) 			pilka.opoznienie = 1000;		// maksymalna predkosc pilki
					else if(pilka.opoznienie <= 5000) 	pilka.opoznienie -= 50;
					else										 	pilka.opoznienie -= 1000;		// zwiekszenie predkosci pilki	
					//else if(pilka.licznik_odbic % 5 == 0) pilka.opoznienie -= 1000;	// co piate odbicie powoduje zwiekszenie predkosci pilki
				}	
			}
			else if((int)pilka.x == SZEROKOSC - 5)				// czy prawy gracz odbije pilke?
			{
				if((paletka_prawa <= (int)pilka.y) && ((paletka_prawa + 4) >= (int)pilka.y))		// tak
				{
					pilka.przyrost_x *= -1.0;						// zmien kierunek lotu pilki
					// ustal kat odbicia
					if((int)pilka.y == paletka_prawa) pilka.przyrost_y = -1.0;
					else if((int)pilka.y == paletka_prawa + 1) pilka.przyrost_y = -0.5;
					else if((int)pilka.y == paletka_prawa + 2) pilka.przyrost_y = 0.0;
					else if((int)pilka.y == paletka_prawa + 3) pilka.przyrost_y = 0.5;
					else if((int)pilka.y == paletka_prawa + 4) pilka.przyrost_y = 1.0;

					++pilka.licznik_odbic;
					if(pilka.opoznienie == 1000) 			pilka.opoznienie = 1000;		// maksymalna predkosc pilki
					else if(pilka.opoznienie <= 5000) 	pilka.opoznienie -= 50;
					else										 	pilka.opoznienie -= 1000;		// zwiekszenie predkosci pilki	
					//else if(pilka.licznik_odbic % 5 == 0) pilka.opoznienie -= 5000;	// co piate odbicie powoduje zwiekszenie predkosci pilki
					
				}	
			}
			else if((int)pilka.x == SZEROKOSC - 2)				// punkt dla lewego gracza
			{
				++wynik.l;

				clear();													// czysc ekran
				rysuj_boisko();
				rysuj_paletki(paletka_lewa, paletka_prawa);
				rysuj_pilke();
				rysuj_wynik();
				refresh();
			
				if(wynik.l == WYGRANA)
				{
					usleep(3000000);
					wynik.l = wynik.p = 0;
				}
				else usleep(100000);

				pilka.x = (int)((SZEROKOSC / 2) - 15);
				pilka.y = (int)(WYSOKOSC / 2);
				pilka.przyrost_x = 1.0;
				pilka.przyrost_y = -0.5;
				pilka.opoznienie = 60000;
				pilka.licznik_odbic = 0;
				rysuj_pilke();
			}
			else if((int)pilka.x == 0)								// punkt dla prawego gracza
			{
				++wynik.p;

				clear();													// czysc ekran
				rysuj_boisko();
				rysuj_paletki(paletka_lewa, paletka_prawa);
				rysuj_pilke();
				rysuj_wynik();
				refresh();
			
				if(wynik.p == WYGRANA)
				{
					usleep(3000000);
					wynik.l = wynik.p = 0;
				}
				else usleep(100000);

				pilka.x = (int)((SZEROKOSC / 2) + 15);
				pilka.y = (int)(WYSOKOSC / 2);
				pilka.przyrost_x = -1.0;
				pilka.przyrost_y = +0.5;
				pilka.opoznienie = 60000;
				pilka.licznik_odbic = 0;
				rysuj_pilke();
			}
			
			usleep(pilka.opoznienie);								// "Usypia" dzialanie programu

			refresh();													// odswiez ekran
		}
		
	}
	refresh();
	//sleep(1);
	endwin();															// Przywroc terminal
	return 0;
}
