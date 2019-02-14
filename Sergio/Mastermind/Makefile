PROGS := Mind

all: $(PROGS)

Mind: mastermind.o initialize.o game.o
	gcc -o Mind mastermind.o initialize.o game.o

Mind.exe: mastermind.o initialize.o game.o
	gcc-mingw-w64 -o Mind mastermind.o initialize.o game.o
	
mastermind.o: mastermind.c
	gcc -c mastermind.c 
	
initialize.o: initialize.c
	gcc -c initialize.c
	
game.o: game.c
	gcc -c game.c
	
clean:
	rm -f $(PROGS) *.o *~
