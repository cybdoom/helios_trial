my_shell.exe: my_shell.o 
	gcc -o my_shell.exe my_shell.o -L../Singly_linked_list -lsingly_linked_list

my_shell.o: my_shell.c
	gcc -c my_shell.c

clean:
	rm -f *.o my_shell.exe