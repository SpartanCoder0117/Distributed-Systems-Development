run: asteroides
	./asteroides 10
asteroides: gfx.o asteroides.o
	g++ gfx.o asteroides.o -o asteroides -lX11 -lm
gfx.o: gfx.c
	gcc -Wall -c gfx.c
asteroides.o: asteroides.cpp
	g++ -Wall -c asteroides.cpp

clean:
	rm *.o ./asteroides
