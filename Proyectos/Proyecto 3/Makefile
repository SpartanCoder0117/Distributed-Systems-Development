animacion: animacion.cpp gfx.o Gusano.o
	g++ -std=c++11 animacion.cpp -c 
	g++ -std=c++11 gfx.o animacion.o Gusano.o -o animacion -lX11
Gusano.o: Gusano.cpp Gusano.h
	g++ Gusano.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c	

