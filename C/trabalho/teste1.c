
#include "PDA.h"



int main(){

    pilha *p = cria_pilha(); 
    estado Q[50];
    Q->tam = 0;
    
    
    salva_transicao(Q);
    Q_final(Q);
   
   char entrada[50];
   //uso for?
   for (int i = 0; i < sizeof(entrada); i++){
        scanf("%s", entrada);
        char *aponta_input = entrada;
        int verificar = recurcao(Q, aponta_input, p); 
    
        if (verificar == 1) printf("%s: sim\n", entrada[i]);
        else printf("%s: nao\n", entrada[i]);
   }  

    free(p);
    return 0;
}