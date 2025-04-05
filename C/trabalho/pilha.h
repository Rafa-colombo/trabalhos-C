#ifndef PILHA_INCLUDED
#define PILHA_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pilha {
char v[100];
int topo;
} pilha;

pilha *cria_pilha ();
int pilha_vazia(pilha *p);
void push_pilha(pilha *p, char a);
int *pop_pilha(pilha *p);


#endif // PILHA_ESTATICA_H_INCLUDED