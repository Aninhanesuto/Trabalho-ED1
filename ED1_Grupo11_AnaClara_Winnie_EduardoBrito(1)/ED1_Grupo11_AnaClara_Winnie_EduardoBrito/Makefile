all: executar
 
executar: main.o code.o arvore.o
	gcc -o executar main.o code.o arvore.o
main.o: main.c code.h
	gcc -c main.c -Wall -Werror -Wextra
code.o: code.c code.h
	gcc -c code.c -Wall -Werror -Wextra
arvore.o: arvore.c code.h
	gcc -c arvore.c -Wall -Werror -Wextra
clean:
	rm -rf *.o executar