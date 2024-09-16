OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: Cjt_categorias.o Jugador.o Cjt_jugadores.o Torneo.o Cjt_torneos.o program.o
	g++ -o program.exe program.o Cjt_categorias.o Jugador.o Cjt_jugadores.o Torneo.o Cjt_torneos.o

Cjt_categorias.o: Cjt_categorias.hh Cjt_categorias.cc
	g++ -c Cjt_categorias.cc $(OPCIONS)

Jugador.o: Jugador.hh Jugador.cc
	g++ -c Jugador.cc $(OPCIONS)

Cjt_jugadores.o: Cjt_jugadores.hh Cjt_jugadores.cc
	g++ -c Cjt_jugadores.cc $(OPCIONS)

Torneo.o: Torneo.hh Torneo.cc
	g++ -c Torneo.cc $(OPCIONS)

Cjt_torneos.o: Cjt_torneos.hh Cjt_torneos.cc
	g++ -c Cjt_torneos.cc $(OPCIONS)
	
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
	
tar: Cjt_categorias.hh Cjt_categorias.cc Jugador.hh Jugador.cc Cjt_jugadores.hh Cjt_jugadores.cc Torneo.hh Torneo.cc Cjt_torneos.hh Cjt_torneos.cc program.cc BinTree.hh Makefile html.zip jp_luis.valverde.zip
	tar -cvf practica.tar Cjt_categorias.hh Cjt_categorias.cc Jugador.hh Jugador.cc Cjt_jugadores.hh Cjt_jugadores.cc Torneo.hh Torneo.cc Cjt_torneos.hh Cjt_torneos.cc program.cc BinTree.hh Makefile html.zip jp_luis.valverde.zip
clean:
	rm *.o
	rm *.exe
