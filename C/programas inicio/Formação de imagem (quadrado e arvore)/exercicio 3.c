#include <stdio.h>
#include <math.h>


void repetechar (char c, int n)
{
    for (int contador = 0 && contador < 110; contador < n ; contador++)
    {
        printf ("%c", c);
    }

}


void mostraquadrado (int lado)
{
    repetechar ('*', lado ) ;       //cabe�a

    printf ("\n");

    for (int q = 0; q<lado -2; q++)      //lado
    {

        printf ("*");

        repetechar (' ', lado - 2) ;

        printf ("*\n");
    }
    repetechar ('*', lado ) ;       //p�
}

void mostrararvore(int galho)
{
    for (int x = 0; x < galho ; x++ )
    {

        repetechar (' ', galho - x - 1);
        repetechar ('*', x );
        printf ("|");
        repetechar ('*', x );

        printf ("\n");

    }

}


int main()
{
    int entrada = 25;
    int limite = 1; // 1 -> Ligado | 0 -> Desligado
    while (entrada != 0)
    {
        printf(" Ola humano!\nValores maximos de altura com limite ligado:64 \n\n-Legenda: \n1) Quadrado \n2) Arvore \n8) Liga/Desliga Limite \n9) Limpar \n0) Sair");
        printf("\nInforme comando a ser executado: ");
        scanf ("%d", &entrada);

        int a,b;

        if (entrada == 1)
        {
            printf ("\nSelecione tamanho do seu quadrado: ");
            scanf("\n%d", &a);
            if (a < 65 || limite == 0)
            {
                mostraquadrado(a);
            }
            else
            {
                printf ("\n\n  --Erro 111: Tamanho nao suportado--\n ");
            }

        }

        if (entrada == 2)
        {
            printf ("\nSelecione tamanho da sua arvore: ");
            scanf("\n%d", &b);
            if (b < 65 || limite == 0)
            {
                mostrararvore (b);
            }
            else
            {
                printf ("\n\n  --Erro 111: Tamanho nao suportado--\n ");
            }
        }

        if (entrada == 8)
        {
            if (limite == 1)
            {
                limite = 0;
                printf ("\n\n  --Limite desligado--\n ");
            }
            else
            {
                limite = 1;
                printf ("\n\n  --Limite ligado--\n ");
            }
        }

        if (entrada == 9)
        {
             system("CLS");
        }


        printf("\n\n\n");



    }
     system("CLS");
    return 0;
}








