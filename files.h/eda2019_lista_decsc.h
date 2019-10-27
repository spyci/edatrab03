#include <stdlib.h>
#include "eda2019_no.h"
#ifndef EDA2019_LISTA_DECSC
#define EDA2019_LISTA_DECSC
typedef struct s_lista{
	no_lista *primeiro;
}lista;

int lista_vazia(lista *l);
lista *criar_lista();
no_lista *add_no_lista(lista *l, luint pos, no_lista *n);
no_lista *rem_no_lista(lista *l, no_lista *n);
no_lista *buscar_lista(lista *l, luint cpf);
int del_lista(lista *l);
#endif
