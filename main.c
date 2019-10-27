#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "files.h/eda2019_no.h"
#include "files.h/eda2019_pilha_denc.h"
#include "files.h/eda2019_fila_ec.h"
#include "files.h/eda2019_lista_decsc.h"
#define MOD %



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void relatorio_parcial(pilha **p, int n_pilhas, luint n_dia){
  printf("-:| RELATORIO DIARIO %llu |:-\n", n_dia);
  printf("%d\n", n_pilhas);
  for (int i=0; i<n_pilhas; i++){
	luint l_pcont=0;
	no_padrao *aux=p[i]->topo;
  	while(aux!=NULL){l_pcont++; aux=aux->prox;}
	printf("Guiche %d: %llu\n", i+1, l_pcont);
  	aux=p[i]->topo;
	while(aux!=NULL){
		printf("[%llu,%llu,%c,%lld]\n", aux->cpfc, aux->cpft, aux->op, aux->valor);
		aux=aux->prox;
	}
  }
}

no_padrao *entradas(){
    	luint v_cpfc, v_cpft,v_valor;
    	char v_op;
    	scanf("%llu %llu %c %lld", &v_cpfc, &v_cpft, &v_op, &v_valor);
	no_padrao *no = iniciar_no_padrao(v_cpfc, v_cpft, v_op, v_valor);
	return no;
}

void relatorio_final(lista *l){
	luint i=1;
	no_lista *aux=l->primeiro;
	while(aux->prox!=l->primeiro){i++; aux=aux->prox;}
	printf("\n-:| RELATORIO FINAL |:-\n%llu\n", i);
	aux=l->primeiro;
	while(aux->prox!=l->primeiro){
		printf("-:[ %llu : %llu %lld\n", aux->cpf, aux->n_op, aux->valor);
		aux=aux->prox;
	}
	printf("-:[ %llu : %llu %lld\n", aux->cpf, aux->n_op, aux->valor);
}

no_lista *proc_no_lista(lista *l, luint cpf){
	if(buscar_lista(l, cpf)!=NULL){//BUSCAR O CPF PRA DEPOSITAR
		no_lista *noaux = buscar_lista(l, cpf);
		return noaux; 
	}
	else{
		no_lista *noaux = iniciar_no_lista(cpf);
		no_lista* auxl = l->primeiro;//auxliar pra percorrer a lista
		luint i=1;
		if(lista_vazia(l)){ 
			//printf("inserindo o no do cpf %llu na posição : %llu\n", noaux->cpf, i);			
			add_no_lista(l, 1, noaux);
			return noaux;
		}
		if(auxl->ante==l->primeiro&&auxl->prox==l->primeiro){//apenas um elemento
			luint i=1;			
			if(auxl->cpf<cpf)i++;
			add_no_lista(l, i, noaux);
			//printf("inserindo o no do cpf %llu na posição : %llu\n", noaux->cpf, i);
			return noaux;
		}
		while((cpf>auxl->cpf)&&(auxl->prox!=l->primeiro)){//Percorre a lista até achar cpf maior que o cpf do no
			auxl=auxl->prox;
			i++;
		}
		if(auxl->cpf<cpf)i++;
		//printf("inserindo o no do cpf %llu na posição : %llu\n", noaux->cpf, i);
		add_no_lista(l, i, noaux);
		return noaux;
	}
}

void processar_dados(pilha *p, fila *f, lista *l){
	no_padrao *no=rem_no_fila(f);
	add_no_pilha(p, no);
	switch(no->op){
		case('D'):{
			//printf("cpfc: %llu, cpft:%llu op:%c\n", no->cpfc, no->cpft, no->op); 
			proc_no_lista(l, no->cpft)->valor+=no->valor;
			proc_no_lista(l, no->cpft)->n_op++;
			proc_no_lista(l, no->cpfc)->n_op++;
			break;
		}
		case('S'):{
			//printf("cpfc: %llu, cpft:%llu op:%c\n", no->cpfc, no->cpft, no->op); 
			proc_no_lista(l, no->cpfc)->valor-=no->valor;
			proc_no_lista(l, no->cpfc)->n_op++;
			break;
		}
		case('T'):{
			//printf("cpfc: %llu, cpft:%llu op:%c\n", no->cpfc, no->cpft, no->op);  
			proc_no_lista(l, no->cpfc)->valor-=no->valor;
			proc_no_lista(l, no->cpft)->valor+=no->valor;
			proc_no_lista(l, no->cpfc)->n_op++;
			proc_no_lista(l, no->cpft)->n_op++;
			break;
		}
	}
}

int main(){
	luint n_clientes, n_pilhas, n_dias;
	scanf("%llu %llu %llu", &n_clientes, &n_pilhas, &n_dias);
	pilha** p;
	p = criar_arr_pilha(n_pilhas);
	fila* f = criar_fila((luint)(floor(sqrt(n_dias))));
	lista *l = criar_lista();
	luint j=0, dia=1;
	for(luint i=0; i<=n_clientes; i++){
		if((i!=0&&i%n_dias==0)||i==n_clientes){
			relatorio_parcial(p, n_pilhas, dia); 
			j=0; 
			dia++;
			for(luint s=0; s<n_pilhas; s++){
				clear_pilha(p[s]);
			} 	
		}
		luint n_guiche = j%n_pilhas;
		if(!(i==n_clientes)){
			no_padrao *no= entradas();
			add_no_fila(f, no);
			processar_dados(p[n_guiche], f, l);
		}
		j++;
	}
	relatorio_final(l);
	for(int k=0; k<n_pilhas; k++){
		del_pilha(p[k]);
	}
	free(p);
	del_lista(l);
	del_fila(f);
}
