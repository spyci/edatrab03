output: main.o eda2019_fila_ec.o eda2019_lista_decsc.o eda2019_pilha_denc.o eda2019_no.o
	gcc main.o eda2019_fila_ec.o eda2019_lista_decsc.o eda2019_pilha_denc.o eda2019_no.o -Wall -Wextra -Werror -Wpedantic -lm
main.o: main.c
	gcc -c  main.c -lm
eda2019_fila_ec.o: files.c/eda2019_fila_ec.c
	gcc -c files.c/eda2019_fila_ec.c
eda2019_lista_decsc.o: files.c/eda2019_lista_decsc.c
	gcc -c files.c/eda2019_lista_decsc.c
eda2019_pilha_denc.o: files.c/eda2019_pilha_denc.c
	gcc -c files.c/eda2019_pilha_denc.c
eda2019_no.o: files.c/eda2019_no.c
	gcc -c files.c/eda2019_no.c
clear:
	rm *.o 
