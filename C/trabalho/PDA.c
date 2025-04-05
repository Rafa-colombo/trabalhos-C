#include "PDA.h"




// function salvar variavel
estado salva_transicao(estado Q[50]){
    int Qi, Qj, S, T;
    char c, c1, c2;
    printf("numero estados e transicoes: ");

    scanf("%d %d", S, T);

    for (int j = 0; j < S; j++)
    {
        int i = 0; 
        printf("Qi E Rpop Rpush Qj: ");
             
        scanf(" %d %c %c %c %d",Qi, c, c1, c2, Qj);
        Q[Qi].salvo[i].qi = Qi;
        Q[Qi].salvo[i].E = c;
        strcopy(Q[Qi].salvo[i].Rpop, c1);
        strcopy(Q[Qi].salvo[i].Rpush, c2);
        Q[Qi].salvo[i].qj = Qj;
        Q[Qi].tam++;

    }
    
    return Q[50];
    
}

bool verifica(pilha *p, char a[1], char *input, char b){

    if(input != b) return 0;//verificar se transicao aceita a(input) e vazio
    else return 1;
    if(input == '&') return 0;//verificar se transicao é vazio
    else return 1;
    if(p->topo != a) return 0;
    else return 1;

}

void Transi_pop(char a[1], pilha *p){

    if(a == '\0'){ }
    else pop_pilha(p);
    pop_pilha(p);

}

void Transi_push(char a[1], pilha *p){

    if(a == '\0'){ }
    else push_pilha(p, a[1]);
    push_pilha(p, a[0]);

}

bool recurcao(estado Q[point],char *input,pilha *p){
    if (Q[point].final == 1){ return 1;}
    
    for (int i = 0; i < Q[point].tam; i++){
        if(verifica(p, Q[point].salvo[i].Rpop, input, Q[point].salvo[i].E)) point = Q[point].salvo[i].qj; 
        else {
            Transi_pop(Q[point].salvo[i].Rpop, p);
            Transi_push(Q[point].salvo[i].Rpush, p); 
            point = Q[point].salvo[i].qj;
        }
        if (recurcao(Q[point], input++, p)){ }
    }    

}


void Q_final(estado Q[50]){

    int Marca = 0;
    int F = 0;
    scanf("%d", F);

    for (int i = 0; i < F; i++){
        scanf("%d", Marca);
        Q[Marca].final = 1;
    }
    
}



    


