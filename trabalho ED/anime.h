#ifndef ANIME_H_INCLUDED
#define ANIME_H_INCLUDED
//#include "fila_dinamica.h"
#include "fila_estatica.h"
#include <string.h>



typedef struct anime {
char nome[100];
int qnt_eps;
int baixados;
int assistidos;
fila *eps;
} anime;



#endif // ANIME_H_INCLUDED
