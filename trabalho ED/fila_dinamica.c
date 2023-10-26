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

void push_fila(fila *f, int tamanho){
    nodo *novo= (nodo*)malloc(sizeof(nodo));
    novo->duracao = tamanho;
    if(f-> fim!= NULL)
        f->fim->prox = novo;
    else f->ini = novo;
    novo->prox = NULL;
    f->fim = novo;
    }


int pop_fila(fila *f){
    int x = f->ini->duracao;
    nodo *aux = f->ini->prox;
    if(f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux;
    return x;
    }

