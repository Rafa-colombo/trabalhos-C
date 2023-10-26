#include "pilha_dinamica.h"


pilha *cria_pilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
    }

int pilha_vazia(pilha *p){
    if (p->topo == NULL) return 1;
    else return 0;
    }

void push_pilha(pilha *p, anime *ani){
    nodoA *novo = (nodoA*)malloc(sizeof(nodoA));
    novo->a = ani;
    novo->prox = p->topo;
    p->topo = novo;
    }

anime *pop_pilha(pilha *p){
    anime *n = p->topo->a;
    nodoA *aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    return n;
    }
