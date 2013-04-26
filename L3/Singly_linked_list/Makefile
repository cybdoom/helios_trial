test_1.exe: test_1.o libsingly_linked_list.a
	gcc -o test_1.exe test_1.o -L. -lsingly_linked_list

test_1.o: test_1.c
	gcc -c test_1.c

libsingly_linked_list.a: singly_linked_list.o
	ar cr libsingly_linked_list.a singly_linked_list.o

singly_linked_list.o: singly_linked_list.c
	gcc -c singly_linked_list.c

clean:
	rm -f *.o *.a test_1.exe
