all: freq


freq: freq.o dict.o
	gcc -g -o freq freq.o dict.o

freq.o: freq.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -g -c freq.c

dict: dict.o 
	gcc -o dict dict.o -g

dict.o: dict.c dict.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -g -c dict.c

debug: 
	gcc -Wall -Wextra -ansi -pedantic -g freq.c

test:
	gcc -Wall -Wextra -Werror -ansi -pedantic -g dict.c dicttests.c
	./a.out

clean: rm *.o
