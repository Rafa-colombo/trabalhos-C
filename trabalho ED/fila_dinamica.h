#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
int duracao;
struct nodo *prox;
} nodo;

typedef struct fila{
nodo *ini;
nodo *fim;
} fila;

fila *cria_fila();
int fila_vazia (fila *f);
void push_fila(fila *f, int tamanho);
int pop_fila(fila *f);

#endif // FILA_DINAMICA_H_INCLUDED
