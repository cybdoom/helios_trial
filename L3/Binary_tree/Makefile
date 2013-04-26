test_1.exe: test_1.o libbinary_tree.a
	gcc -o test_1.exe test_1.o -L. -lbinary_tree

test_1.o: test_1.c
	gcc -c test_1.c

libbinary_tree.a: binary_tree.o
	ar cr libbinary_tree.a binary_tree.o

binary_tree.o: binary_tree.c
	gcc -c binary_tree.c

clean:
	rm -f *.o *.a test_1.exe
