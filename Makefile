CC=gcc
DEPS=lista.h taskuri.h listaDiviziuni.h
build: tema1
tema1: tema1.o lista.o eliminare1.o eliminare23.o uniformizare.o completare.o statistici.o listaDiviziuni.o
	$(CC) -g -o tema1 tema1.o lista.o eliminare1.o eliminare23.o uniformizare.o completare.o statistici.o listaDiviziuni.o -lm
%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $<
clean:
	rm -f *.o tema1