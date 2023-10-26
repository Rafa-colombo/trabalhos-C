#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

typedef struct fila{
int v[MAX];
int ini;
int fim;
} fila;

fila *cria_fila();
int fila_vazia (fila *f);
void push_fila (fila *f, int tamanho);
int pop_fila (fila *f);

#endif // FILA_ESTATICA_H_INCLUDED
