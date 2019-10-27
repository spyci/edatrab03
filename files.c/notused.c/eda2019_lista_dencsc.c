#include <stdlib.h>
#include "files.h/eda2019_no.h"
#include "files.h/eda2019_lista_dencsc.h"
//EMPLEMENTA LISTA DINAMICA ENCADEADA NAO CIRCULAR SEM CABEÇA PARA O TRABALHO EDA2019.2

int lista_vazia(lista *l){
	return (l->primeiro==NULL);
}

lista *criar_lista(){
	lista *l=(lista*)malloc(sizeof(lista));
	l->primeiro=NULL;
	return l;
}

no_lista *add_no_lista(lista *l, luint pos, no_lista *n){
	if(lista_vazia(l)|| pos==1){
		n->prox=l->primeiro;
		l->primeiro=n;
		return n;
	}
	else{
		luint i=1;
		no_lista* aux=l->primeiro;
		while(i!=pos-1 && aux->prox!=NULL){
			aux=aux->prox;
			i++;
		}
		n->prox=aux->prox;
		aux->prox=n;
	}
	return n;
}

no_lista *rem_no_lista(lista *l, no_lista *n){
	if(lista_vazia(l))return NULL;
	if(l->primeiro==n){
		l->primeiro=l->primeiro->prox;
		return n;
	}
	else{
		no_lista *aux=l->primeiro;
		while(aux->prox!=n){
			aux=aux->prox;
		}
		aux->prox=n->prox;
		n->prox=NULL;
		return n;
	}
}

no_lista *buscar_lista(lista *l, luint cpf){
	no_lista *aux=l->primeiro;
	while(aux!=NULL&&aux->cpf!=cpf){
		aux=aux->prox;
	}
	return aux;
}

int del_lista(lista *l){
	while(l->primeiro!=NULL){
		free(rem_no_lista(l, l->primeiro));
	}
	free(l);
	return 1;
}
