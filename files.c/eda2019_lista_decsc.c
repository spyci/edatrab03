#include <stdlib.h>
#include "../files.h/eda2019_no.h"
#include "../files.h/eda2019_lista_decsc.h"
//EMPLEMENTA LISTA DINAMICA ENCADEADA CIRCULAR SEM CABEÇA PARA O TRABALHO EDA2019.2

int lista_vazia(lista *l){
	return (l->primeiro==NULL);
}

lista *criar_lista(){
	lista *l=(lista*)malloc(sizeof(lista));
	l->primeiro=NULL;
	return l;
}

no_lista *add_no_lista(lista *l, luint pos, no_lista *n){
	if(pos<=0)return NULL;
	if(lista_vazia(l)){
		l->primeiro=n;
		n->ante=n;
		n->prox=n;
		return n;
	}
	if(pos==1){
		no_lista *aux=l->primeiro;
		n->prox=aux;
		n->ante=aux->ante;
		aux->ante->prox=n;
		aux->ante=n;
		l->primeiro=n;
		return n;
	}
	else{	
		luint i=1;
		no_lista *aux=l->primeiro;
		while(i!=pos-1 && aux->prox!=l->primeiro){
			aux=aux->prox;
			i++;
		}
		n->prox=aux->prox;
		aux->prox->ante=n;
		aux->prox=n;
		n->ante=aux;
		return n;
	}	
}

no_lista *rem_no_lista(lista *l, no_lista *n){
	if(lista_vazia(l))return NULL;
	if(l->primeiro->prox==l->primeiro&&l->primeiro->ante==l->primeiro){
		l->primeiro=NULL;
		n->ante=NULL;
		n->prox=NULL;
		return n;
	}
	if(n==l->primeiro){
		l->primeiro->prox->ante=l->primeiro->ante;
		l->primeiro->ante->prox=l->primeiro->prox;
		l->primeiro=l->primeiro->prox;
		n->prox=NULL;
		n->ante=NULL;
		return n;

	}
	else{
		n->ante->prox=n->prox;
		n->prox->ante=n->ante;
		n->prox=NULL;
		n->ante=NULL;
		return n;
	}
}

no_lista *buscar_lista(lista *l, luint cpf){
	if(lista_vazia(l))return NULL;
	no_lista *aux=l->primeiro;
	while(aux->cpf!=cpf&&aux->prox!=l->primeiro){
		aux=aux->prox;
	}
	if(aux->cpf!=cpf)return NULL;
	else return aux;
}

int del_lista(lista *l){
	while(!lista_vazia(l)){
		no_lista *aux=l->primeiro;
		free(rem_no_lista(l, aux));
	}
	free(l);
	return 1;
}
