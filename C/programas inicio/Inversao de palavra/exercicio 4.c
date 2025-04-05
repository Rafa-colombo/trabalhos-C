#include <stdio.h>
#include <string.h>


void limpar ()
{
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

int main ()
{
    char str [20] [50];     //20 strings com 50 caracteres
    char ponto [] = ".";
    int i;




    printf("Bom dia, Boa tarde e Boa noite! Esse eh o programa de inversao da ordem das palavras.\n\n--Palavras limitadas: 50 letras, maximo de 20 palavras ou encerre com um ponto final--\n");
    printf("\n-So sera lido o valor ate 50 caracteres, lembre-se!\n");
    printf("\nInforme palavras a serem lidas(aperte enter para proxima):\n");

    for (i=0; i<20 ; i++)
    {
        printf ("%d: ", i+1);
        scanf ("%50s", str[i]);
        limpar ();
        if (strcmp(str[i], ponto) == 0 )   break;

    }

    printf("Saida: ");
    for (i--; i>=0; i--)  printf("%s ",str[i]); //i-- esta retirando ultimo(primeira string a ser mostrada) string, nesse caso tira o '.'



    return 0;
}

































