#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_fila{
void * info;
struct nodo_fila *prox;
} nodo_fila;

typedef struct fila{
nodo_fila *ini;
nodo_fila *fim;
} fila;

fila *cria_fila();
int fila_vazia (fila *f);
void push_fila(fila *f, void *info);
void * pop_fila(fila *f);

#endif // FILA_DINAMICA_H_INCLUDED
