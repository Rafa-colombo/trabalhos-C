#include <stdio.h>
#include <math.h>




int main(){
    
    float valor = 0;
    float aux = 1;
    printf("Digite valores, para fianlizar digite 0 \n");

    while (aux != 0){
     scanf("%f", &aux);
     valor += aux;
     printf("valor atual:%.3f\n", valor);     
    }
    
    printf("\nTotal: %.3f\nDividido pra 3: %.3f", valor, (valor/3));
    scanf("%s", aux);


    return 0;
}