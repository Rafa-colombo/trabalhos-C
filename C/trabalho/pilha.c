#include "pilha.h"



pilha *cria_pilha (){
pilha *p = (pilha*)malloc(sizeof(pilha));
p->v[0] = 'Z'; 
p->topo = 0;
return p;
}

int pilha_vazia(pilha *p){
if (p->topo == -1) return 1;
else return 0;
}

void push_pilha(pilha *p, char a){
p->topo++;
p->v[p->topo] = a; 
printf("adicionado %s", a);
}

int *pop_pilha(pilha *p){
int aux = p->v[p->topo];
p->topo--;
printf("removido %s", aux);
return p->v[(p->topo)--];
}