pong: boisko.o paletki.o pilka.o wynik.o main.o
	gcc boisko.o paletki.o pilka.o wynik.o main.o -o pong -lcurses

main.o: ./pliki/main.c
	gcc -c ./pliki/main.c -o main.o -lcurses

wynik.o: ./pliki/wynik.c
	gcc -c ./pliki/wynik.c -o wynik.o

pilka.o: ./pliki/pilka.c
	gcc -c ./pliki/pilka.c -o pilka.o

paletki.o: ./pliki/paletki.c
	gcc -c ./pliki/paletki.c -o paletki.o

boisko.o: ./pliki/boisko.c
	gcc -c ./pliki/boisko.c -o boisko.o
	
clean:
	rm -f *.o