#include "fila_estatica.h"


fila *cria_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->ini = f->fim = 0;
    return f;
    }

int fila_vazia (fila *f){
    if (f->ini == f->fim) return 1;
    else return 0;
    }


void push_fila (fila *f, int tamanho) {
    f->v[f->fim] = tamanho;
    f->fim++;
    }

int pop_fila (fila *f){
    int aux = f->v[f->ini];
    f->ini++;
    return aux;
    }
