#ifndef PILHA_DINAMICA_H_INCLUDED
#define PILHA_DINAMICA_H_INCLUDED
#include "anime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoA{  //pilha de ponteiros
struct nodoA *prox;
anime *a;
} nodoA;

typedef struct Pilha{
nodoA *topo;
} pilha;

pilha *cria_pilha();
int pilha_vazia(pilha *p);
void push_pilha(pilha *p, anime *a);
anime *pop_pilha(pilha *p);

#endif // PILHA_DINAMICA_H_INCLUDED
