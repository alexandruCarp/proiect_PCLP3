CC=gcc
DEPS=lista.h taskuri.h
build: tema1
tema1: tema1.o lista.o eliminare1.o eliminare23.o uniformizare.o completare.o statistici.o
	$(CC) -o tema1 tema1.o lista.o eliminare1.o eliminare23.o uniformizare.o completare.o statistici.o -g -lm
%.o: %.c $(DEPS)
	$(CC)  -c  $< -g
clean:
	rm -f *.o tema1
