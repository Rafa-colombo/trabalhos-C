

#include "pilha_estatica.h"



pilha *cria_pilha (){
pilha *p = (pilha*)malloc(sizeof(pilha));
p->topo = -1;
return p;
}

int pilha_vazia(pilha *p){
if (p->topo == -1) return 1;
else return 0;
}

void push_pilha(pilha *p, anime *a){
p->topo++;
p->v[p->topo] = a;
}

anime *pop_pilha(pilha *p){
anime *n = p->v[p->topo];
p->topo--;
return n;
}
