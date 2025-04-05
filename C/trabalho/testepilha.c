#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct pilha{
char v[MAX];
int topo;
};

typedef struct pilha Pilha;

Pilha *cria_pilha(){

  Pilha *p =(Pilha*)malloc(sizeof(Pilha));
  p->topo = -1;
  return p;
}


int vazia(Pilha*p){

  if(p->topo==-1)
    return 1;
  else 
    return 0;
  
}


void push(Pilha*p,char x[MAX]){
  p->topo++;
  p->v[p->topo] = x;
  
}

int pop(Pilha*p){
  int x = p->v[p->topo];  
  p->topo--;
  return x;            
}



int main(){

    Pilha *p = cria_pilha();

    push(p, 'Az');
    push(p, 'Z');
  for (int i = p->topo; i != -1 ; i--){
    printf("%c\n", p->v[i]); 
  }
  
    

    free(p);

    return 0;
}