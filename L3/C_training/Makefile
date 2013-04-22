# Makefile for Singly_linked_list project

program: main.o libworld.a
	gcc -o program main.o -L. -lworld

main.o: main.c
	gcc -c main.c

libworld.a: hworld.o gworld.o
	ar cr libworld.a hworld.o gworld.o

hworld.o: hworld.c
	gcc -c hworld.c

gworld.o: gworld.c
	gcc -c gworld.c

clean:
	rm -f *.o *.a program
