#include <stdlib.h>
#include "../files.h/eda2019_no.h"
no_padrao *iniciar_no_padrao(luint v_cpfc, luint v_cpft, char v_op, lint v_valor){
	no_padrao* n;
	n = (no_padrao*)malloc(sizeof(no_padrao));
 	n->cpfc = v_cpfc;
  	n->op = v_op;
  	n->valor = v_valor;
  	n->cpft = v_cpft;
	return n;
}

no_lista *iniciar_no_lista(luint v_cpf){
	no_lista *n;
	n = (no_lista*)malloc(sizeof(no_lista));
 	n->cpf = v_cpf;
  	n->valor=0;
  	n->n_op=0;
	return n;
}
