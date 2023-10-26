#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED
#include "anime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pilha {
anime *v[100];
int topo;
} pilha;

pilha *cria_pilha ();
int pilha_vazia(pilha *p);
void push_pilha(pilha *p, anime *a);
anime *pop_pilha(pilha *p);


#endif // PILHA_ESTATICA_H_INCLUDED
