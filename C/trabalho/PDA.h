#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED //como usa?
#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct transicao{
    int qi;
    char E;
    char Rpop[1];
    char Rpush[1];
    int qj; 
} transicao;


typedef struct estado{ 
    transicao salvo[100];//segurar transições
    int tam;
    int final; 
} estado;


int point = 0; //ponteiro de posição começa em Q[0]

estado salva_transicao(estado Q[50]);
bool verifica(pilha *p, char a[1], char *input, char b);
void Transi_pop(char a[1], pilha *p);
void Transi_push(char a[1], pilha *p);
bool recurcao(estado Q[point],char *input,pilha *p);
void Q_final(estado Q[50]);



 




#endif // PILHA_ESTATICA_H_INCLUDED