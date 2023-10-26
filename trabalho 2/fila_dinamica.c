#include "fila_dinamica.h"

fila *cria_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->ini = f->fim = NULL;
    return f;
    }

int fila_vazia(fila*f){
   if(f->ini==NULL)
     return 1;
   else
     return 0;
    }

void push_fila(fila *f, void *info){
    nodo_fila *novo= (nodo_fila*)malloc(sizeof(nodo_fila));
    novo->info = info;
    if(f-> fim!= NULL)
        f->fim->prox = novo;
    else f->ini = novo;
    novo->prox = NULL;
    f->fim = novo;
    }


void *pop_fila(fila *f){
    void *x = f->ini->info;
    nodo_fila *aux = f->ini->prox;
    if(f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux;
    return x;
    }

