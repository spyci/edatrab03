#include <stdlib.h>
#include "../files.h/eda2019_no.h"
#include "../files.h/eda2019_lista_deccc.h"
//EMPLEMENTA LISTA DINAMICA ENCADEADA CIRCULAR COM CABEÇA PARA O TRABALHO EDA2019.2

int lista_vazia(lista *l){
	return (l->primeiro->prox==l->primeiro&&l->primeiro->ante==l->primeiro);
}

lista *criar_lista(){
	lista *l=(lista*)malloc(sizeof(lista));
	l->primeiro=iniciar_no_lista(0);
	l->primeiro->prox=l->primeiro;
	l->primeiro->ante=l->primeiro;
	return l;
}

no_lista *add_no_lista(lista *l, luint pos, no_lista *n){
	if(pos<=0)return NULL;
	luint i=1;
	no_lista* aux=l->primeiro;
	while(i!=pos && aux->prox!=l->primeiro){
		aux=aux->prox;
		i++;
	}
	n->prox=aux->prox;
	aux->prox->ante=n;
	aux->prox=n;
	n->ante=aux;
	return n;
}

no_lista *rem_no_lista(lista *l, no_lista *n){
	if(lista_vazia(l))return NULL;
	if(n==l->primeiro)return NULL;
	n->ante->prox=n->prox;
	n->prox->ante=n->ante;
	n->prox=NULL;
	n->ante=NULL;
	return n;
}

no_lista *buscar_lista(lista *l, luint cpf){
	no_lista *aux=l->primeiro;
	while(aux->prox!=l->primeiro&&aux->cpf!=cpf){
		aux=aux->prox;
	}
	if(aux->cpf!=cpf)return NULL;
	return aux;
}

int del_lista(lista *l){
	no_lista *aux=l->primeiro;
	no_lista *aux2;
	while(!lista_vazia(l)){
		aux2=aux;
		free(rem_no_lista(l, aux));
		aux=aux2;
	}
	free(l);
	return 1;
}
