all: my_fun.o my_assignment.o
	gcc -o my_exe my_fun.o my_assignment.o 
	./my_exe

my_assignment.o: my_assignment.c 
	gcc -c my_assignment.c

my_fun.o: my_library.h my_fun.c
	gcc -c my_fun.c
clean:
	rm -f *.o
