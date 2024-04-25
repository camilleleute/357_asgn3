all: dict

dict: dict.o 
	gcc -o dict dict.o 

dict.o: dict.c dict.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c dict.c

debug: 
	gcc -Wall -Wextra -ansi -pedantic -g dict.c

test:
	gcc -Wall -Wextra -Werror -ansi -pedantic dict.c dicttests.c
	./a.out

clean: rm *.o
