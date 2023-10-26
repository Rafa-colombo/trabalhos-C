#include <stdio.h>
#include "fila_dinamica.h"
#define MAX 101



typedef struct nodo{
struct nodo *vizinho;
struct nodo *prox;
} nodo;

nodo *grafo[MAX][MAX] = {0};

nodo *insere(nodo *lista, nodo *vizinho ){
nodo *novo = (nodo*)malloc(sizeof(nodo));
novo->vizinho = vizinho;
novo->prox = lista;
return novo;
}


nodo *remover (nodo *lista, nodo *vizinho){
if (lista == NULL) return NULL;
if (lista->vizinho == vizinho) {
    nodo *aux = lista->prox;
    free(lista);
    return aux;   
}
nodo *aux2 = remover(lista->prox, vizinho);
lista->prox = aux2;
return lista;
}

nodo *esvazia(nodo *lista){
    if(lista == NULL) return NULL;
    esvazia(lista->prox);
    free(lista);
    return NULL;
}

int DFS(int *visitados, int Vi, int Vj, int tam_linha){
    int css = 1;

    nodo **esquerda = &grafo[Vi][Vj-1];
    nodo **direita = &grafo[Vi][Vj+1];
    nodo **cima = &grafo[Vi-1][Vj];
    nodo **baixo = &grafo[Vi+1][Vj];

    nodo *aux = grafo[Vi][Vj];
    visitados[tam_linha * Vi + Vj] = 1;

    while (aux != NULL){
        if (aux->vizinho == *esquerda){
            css += DFS(visitados, Vi, Vj-1, tam_linha);
        }
        if (aux->vizinho == *direita){
            css += DFS(visitados, Vi, Vj+1, tam_linha);
        }
        if (aux->vizinho == *cima){
            css += DFS(visitados, Vi-1, Vj, tam_linha);
        }
        if (aux->vizinho == *baixo){
            css += DFS(visitados, Vi+1, Vj, tam_linha);
        }
        aux = aux->prox;
    }
    
    return css;
}

void BFS(nodo *posicao, nodo *visitado[MAX][MAX],int qnt_linhas, int tam_linha, int Vi, int Vj){
    fila *fila_visinhos = cria_fila();
    nodo *aux = posicao;
    visitado[Vi][Vj] = (nodo*)1;
    push_fila(fila_visinhos, aux);
    nodo *anterior = aux;
    
    while(!fila_vazia(fila_visinhos)){
        aux = pop_fila(fila_visinhos);
        anterior = aux;

        while (aux != NULL) {
            int Vi = 0;
            int Vj = 0;
            for(int linha = 0; linha<qnt_linhas; linha++){
                for(int coluna = 0; coluna<tam_linha; coluna++){                   
                    if (aux == grafo[linha][coluna]){
                        if (aux == grafo[linha][coluna]){
                            Vi = linha;
                            Vj = coluna;
                        }
                    }
                }
            }
            
            if(visitado[Vi][Vj] == 0 || visitado[Vi][Vj] == (nodo*)1){
                visitado[Vi][Vj] = anterior;
                push_fila(fila_visinhos, aux->vizinho);
            }
            aux = aux->prox;
        }
    }
    free(fila_visinhos);
}

int main(){

    int rodar = 1;
    char primeiro[20];
    int M = 0;
    int N = 0;
    int i, j;
    char aux;
    char mapa[MAX][MAX] = {0};

    scanf("%d %d", &N, &M);
    
  


     for(int linha = 0; linha<N; linha++){     //criar mapa (linhas)
        scanf("%s", mapa[linha]);  
        }
    
    
    for (int linha = 0; linha<N; linha++){  //mudar variavel i j
        for (int coluna = 0; coluna<M; coluna++){
            if (mapa[linha][coluna] == '.'){
                if(linha-1 >= 0){
                    if(mapa[linha-1][coluna] == '.'){
                        nodo *aux1;
                        if(grafo[linha-1][coluna] == NULL){
                            aux1 = malloc(sizeof(nodo));
                            aux1->vizinho = NULL;
                            aux1->prox = NULL;
                        }

                        nodo *aux2;
                        if(grafo[linha][coluna] == NULL){
                            aux2 = malloc(sizeof(nodo));
                            aux2->vizinho = NULL;
                            aux2->prox = NULL;
                        }

                        if (grafo[linha-1][coluna] != NULL && grafo[linha][coluna] == NULL){
                            aux2->vizinho = grafo[linha-1][coluna];
                            grafo[linha][coluna] = aux2;
                        }
                        else if(grafo[linha-1][coluna] == NULL && grafo[linha][coluna] != NULL){
                            aux1->vizinho = grafo[linha][coluna];
                            grafo[linha-1][coluna] = aux1;
                        }
                        else if(grafo[linha-1][coluna] == NULL && grafo[linha][coluna] == NULL){
                            grafo[linha-1][coluna] = aux1;
                            grafo[linha][coluna] = aux2;
                            grafo[linha-1][coluna]->vizinho = grafo[linha][coluna];
                            grafo[linha][coluna]->vizinho = grafo[linha-1][coluna];
                        }
                        else {
                            grafo[linha-1][coluna] = insere(grafo[linha-1][coluna], grafo[linha][coluna]);
                            grafo[linha][coluna] = insere(grafo[linha][coluna], grafo[linha-1][coluna]);
                        }
                    }
                }
                if(coluna-1 >= 0){
                    if(mapa[linha][coluna-1] == '.'){
                        nodo *aux1;
                        if(grafo[linha][coluna-1] == NULL){
                            aux1 = malloc(sizeof(nodo));
                            aux1->vizinho = NULL;
                            aux1->prox = NULL;
                        }

                        nodo *aux2;
                        if(grafo[linha][coluna] == NULL){
                            aux2 = malloc(sizeof(nodo));
                            aux2->vizinho = NULL;
                            aux2->prox = NULL;
                        }

                        if (grafo[linha][coluna-1] != NULL && grafo[linha][coluna] == NULL){
                            aux2->vizinho = grafo[linha][coluna-1];
                            grafo[linha][coluna] = aux2;
                        }
                        else if(grafo[linha][coluna-1] == NULL && grafo[linha][coluna] != NULL){
                            aux1->vizinho = grafo[linha][coluna];
                            grafo[linha][coluna-1] = aux1;
                        }
                        else if(grafo[linha][coluna-1] == NULL && grafo[linha][coluna] == NULL){
                            grafo[linha][coluna-1] = aux1;
                            grafo[linha][coluna] = aux2;
                            grafo[linha][coluna-1]->vizinho = grafo[linha][coluna];
                            grafo[linha][coluna]->vizinho = grafo[linha][coluna-1];
                        }
                        else {
                            grafo[linha][coluna-1] = insere(grafo[linha-1][coluna], grafo[linha][coluna]);
                            grafo[linha][coluna] = insere(grafo[linha][coluna], grafo[linha][coluna-1]);
                        }
                    }
                }
            }
        }
    }
    
    
    while(rodar){
        int visitados[MAX][MAX] = {0};
        nodo *visitadosBFS[MAX][MAX] = {0};
        int iInicial, jInicial, iFinal, jFinal;
        scanf("%s",&primeiro);
        switch (primeiro[0])
        {
            case 'r': //regiao
                {
                int regiao = 0;
                int maior = 0;
                int aux = 0;
                for (int linha = 0; linha<N; linha++){
                    for (int coluna = 0; coluna<M; coluna++){
                        if(mapa[linha][coluna] == '.' && (visitados[linha][coluna] == 0)){
                             aux = DFS((int*)&visitados, linha, coluna, N-1);
                             regiao++;
                             if (maior < aux){
                                maior = aux;
                             }
                        }
                    }
                }
                printf("%d regioes; a maior tem area %d\n", regiao, maior);
                }
                break;

            case 'c': //cam
                scanf("%d %d %d %d",&iInicial, &jInicial, &iFinal, &jFinal);
                int passos = 0;
                BFS(grafo[iInicial][jInicial], visitadosBFS, N, M, iInicial, jInicial);
                if(visitadosBFS[iFinal][jFinal] == 0){
                    printf("Nao ha caminho de (%d,%d) para (%d,%d)\n", iInicial, jInicial, iFinal, jFinal);
                    break;  
                }
                nodo *auxiliar = visitadosBFS[iFinal][jFinal];

                while(auxiliar != (nodo*)1){
                    for(int linha = 0; linha<N; linha++){
                        for(int coluna = 0; coluna<M; coluna++){
                            if(auxiliar == grafo[linha][coluna]){
                                auxiliar = visitadosBFS[linha][coluna];
                            }
                        }
                    }
                    passos++;
                }
                printf("De (%d,%d) para (%d,%d) em %d passos\n", iInicial, jInicial, iFinal, jFinal, passos);
                break;
            
            case 'x':
                scanf("%d %d",&i, &j);
                if(i-1>= 0){
                    if (mapa[i-1][j] == '.'){
                    grafo[i-1][j] = remover(grafo[i-1][j], grafo[i][j]);
                    }     
                }
                if(i+1 >=N-1){
                    if (mapa[i+1][j] == '.'){
                    grafo[i+1][j] = remover(grafo[i+1][j], grafo[i][j]);
                    }
                }
                if(j-1 >=0) {
                    if (mapa[i][j-1] == '.'){
                    grafo[i][j-1] = remover(grafo[i][j-1], grafo[i][j]);
                    }
                } 
                if(j+1 >= M-1){
                    if (mapa[i][j+1] == '.'){
                    grafo[i][j+1] = remover(grafo[i][j+1], grafo[i][j]);
                    }
                }
                grafo[i][j] = esvazia(grafo[i][j]);
                mapa[i][j] = 'x';
                printf("uma estalactite acabou de cair na posicao (%d, %d), e essa posicao agora esta bloqueada.\n\n", i, j);
                for(int linha = 0; linha<N; linha++){
                printf("%s\n", mapa[linha]);   
                }
                break;

            case '.':
                scanf("%d %d",&i, &j);
                if(i-1>= 0){
                    if (mapa[i-1][j] == '.'){
                    grafo[i-1][j] = insere(grafo[i-1][j], grafo[i][j]);
                    grafo[i][j] = insere(grafo[i][j], grafo[i-1][j]);
                    }     
                }
                if(i+1 >=N-1){
                    if (mapa[i+1][j] == '.'){
                    grafo[i+1][j] = insere(grafo[i+1][j], grafo[i][j]);
                    grafo[i][j] = insere(grafo[i][j], grafo[i+1][j]);
                    }
                }
                if(j-1 >=0) {
                    if (mapa[i][j-1] == '.'){
                    grafo[i][j-1] = insere(grafo[i][j-1], grafo[i][j]);
                    grafo[i][j] = insere(grafo[i][j], grafo[i][j-1]);
                    }
                } 
                if(j+1 >= M-1){
                    if (mapa[i][j+1] == '.'){
                    grafo[i][j+1] = insere(grafo[i][j+1], grafo[i][j]);
                    grafo[i][j] = insere(grafo[i][j], grafo[i][j+1]);
                    }
                }
                mapa[i][j] = '.';
                printf(" a estalactite na posicao (%d, %d) foi quebrada, e essa posicao agora esta livre.\n\n", i, j);
                for(int linha = 0; linha<N; linha++){
                printf("%s\n", mapa[linha]);   
                }
                break;

            case 'f':
                return 0; 
            }    
    }
    

}  