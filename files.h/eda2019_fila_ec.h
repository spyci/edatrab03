#include <stdlib.h>
#include "eda2019_no.h"
#ifndef EDA2019_FILA_EC
#define EDA2019_FILA_EC
typedef struct s_fila{
	no_padrao **valores;
	luint inicio;
	luint fim;
	luint tam;
	luint qntelem;
}fila;



fila *criar_fila(luint tam);
int fila_vazia(fila *f);
int fila_cheia(fila *f);
int add_no_fila(fila *f, no_padrao *n);
no_padrao *rem_no_fila(fila *f);
int del_fila(fila *f);
#endif
