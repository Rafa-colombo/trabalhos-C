#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anime.h"
//#include "pilha_estatica.h"
#include "pilha_dinamica.h"


anime *comeca(char str[], int qnt_eps){

    anime *novo = (anime*)malloc(sizeof(anime));
    strcpy(novo->nome,str);
    novo->qnt_eps = qnt_eps;
    novo->eps = cria_fila();
    novo->baixados = 0;
    novo->assistidos = 0;

printf("comecando %s\n", novo->nome);
return novo;
}

int download (anime *p, int baixar, int duracao){
    int i;
    for (i = 0; i<baixar; i++){
        if( p->baixados < p->qnt_eps) {
            push_fila(p->eps, duracao);
            p->baixados++;
        }
        else break;
    }
    printf("%d eps de %s baixados\n", baixar, p->nome);
    return i + 1;
}

void assistir(anime *p, int assistir){
    if (p->assistidos >= p->qnt_eps){
    printf("acabou %s\n", p->nome);
    return;
        }
    if (p->qnt_eps < p->baixados){
        printf("Nenhum anime a assistir no momento\n");
        return; // nao consegue assistir
        }
    int tempo = 0;
    int i = 0;
    for (i = 0; i<assistir; i++){
            if (fila_vazia(p->eps) == 1) break;
        tempo += pop_fila(p->eps);

        p->assistidos++;
        }

    if (assistir <= p->qnt_eps){
        printf("%d eps de %s(%d minutos)\n", i,p->nome, tempo);
        }
    if (p->qnt_eps == p->assistidos){
        printf("%s acabou\n", p->nome);
        }
}







int main()
{
    char primeiro[100];
    int rodar = 1;
    char NOME[100];
    int QNT_EPS;
    int BAIXAR;
    int TEMPO;
    int ASSISTE;

    pilha *pilha_anime= cria_pilha();


    while(rodar){
            scanf("%s",&primeiro);
            switch(primeiro[0]){
            case 'c':// comaça tal serie
                scanf("%s %d", &NOME, &QNT_EPS);
                push_pilha(pilha_anime, comeca(NOME, QNT_EPS));
                break;

            case 'd':
                if (pilha_vazia(pilha_anime) == 1){
                    printf("nenhum anime a baixar no momento\n");
                    break;
                    }
                else{
                scanf("%d %d",&BAIXAR,&TEMPO);     //download == PUSH
                anime *aux = pop_pilha(pilha_anime);
                download(aux, BAIXAR, TEMPO);
                push_pilha(pilha_anime, aux);
                    }
                break;

            case 'a':
                if (pilha_vazia(pilha_anime) == 1){
                    printf("nunhum anime a assistir no momento\n");
                    break;
                    }
                scanf("%d", &ASSISTE);       //assiste == POP
                anime *aux2 = pop_pilha(pilha_anime);
                assistir(aux2, ASSISTE);
                if(aux2->assistidos == aux2->qnt_eps) {
                    free(aux2->eps);
                    free(aux2);
                    }
                else push_pilha(pilha_anime, aux2);
                break;


            case 'F'://finaliza codigo
                rodar = 0;
                while(pilha_vazia(pilha_anime) != 1) {
                    anime *top = pop_pilha(pilha_anime);
                    printf("%s: faltam baixar %d eps e assistir %d eps\n",top->nome, (top->qnt_eps - top->baixados), (top->qnt_eps - top->assistidos));
                    while (fila_vazia(top->eps) != 1){
                        pop_fila(top->eps);
                        }
                    free(top->eps);
                    free(top);
                    }
                free(pilha_anime);
                break;
            }
    }

    return 0;
}
