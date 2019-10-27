#include <stdio.h>
#include <stdlib.h>
#include "eda2019_no.h"
#ifndef EDA2019_PILHA_DENC
#define EDA2019_PILHA_DENC
typedef struct s_pilha{
	no_padrao *topo; //topo da lista
}pilha;
pilha **criar_arr_pilha(int k);
int pilha_vazia(pilha *p);
no_padrao *add_no_pilha(pilha *p, no_padrao *n);
no_padrao *rem_no_pilha(pilha *p);
no_padrao *buscar_pilha(pilha* p, luint cpf);
pilha* clear_pilha(pilha *p);
int del_pilha(pilha *p);
#endif
