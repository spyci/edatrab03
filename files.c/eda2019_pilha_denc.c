#include <stdio.h>
#include <stdlib.h>
#include "../files.h/eda2019_no.h"
#include "../files.h/eda2019_pilha_denc.h"
//EMPLEMENTA PILHA DINAMICA ENCADEADA NAO CIRCULAR PARA O TRABALHO EDA2019.2
pilha **criar_arr_pilha(int k){
	pilha** p = (pilha**)malloc(sizeof(pilha*)*k);
  	for (int i = 0; i<k; i++){
    		p[i] = (pilha*)malloc(sizeof(pilha));
    		p[i]->topo = NULL;
   	}
	return p;
}

int pilha_vazia(pilha* p){
	return (p->topo==NULL);
}

no_padrao *add_no_pilha(pilha* p, no_padrao *n) {
  	n->prox = p->topo;
	p->topo = n;
	return n;
}

no_padrao *buscar_pilha(pilha* p, luint cpf){
	no_padrao* aux=p->topo;
	while(aux->cpfc!=cpf&&aux!=NULL){
		aux=aux->prox;
	}
	return aux;
}

no_padrao *rem_no_pilha(pilha* p){
	if(pilha_vazia(p))return NULL;
	else{
		no_padrao* aux;
		aux = p->topo;
		p->topo = aux->prox;
		aux->prox = NULL;
		return aux;
	}
}
pilha* clear_pilha(pilha *p){
	while(p->topo!=NULL){
		free(rem_no_pilha(p));
	}
	return p;
}

int del_pilha(pilha* p){		
	clear_pilha(p);
	free(p);
	return 1;
}


