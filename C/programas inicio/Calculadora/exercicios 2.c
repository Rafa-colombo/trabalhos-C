#include <stdio.h>
#include <math.h>

float potencia(float base,float potencia)
{
    /*float resultado; função da variavel
    resultado = pow(base,potencia)
    */
    return pow (base, potencia) ;

}



int main()
{
    int num = 25;
    while (num != 0)
    {
        printf("Legenda: \n1) Adicao \n2) Subtracao \n3) Multiplicacao \n4) Divisao \n5) Exponenciacao \n6) Bhaskara \n7) Conversor para Decimal\n8) Raio de uma circunferencia \n9) Limpar \n10) Modulo da parada\n0) Sair");
        printf("\nInforme operacao a ser executada:");
        scanf ("%d", &num);

        float a,b;

        if (num < 4 && num !=0)
        {

            printf ("\nInforme primeiro valor:");
            scanf ("%f",&a);
            printf ("\nInforme segundo valor:");
            scanf ("%f",&b);

        }



        if (num == 1)
        {
            system("cls");
            printf ("\n-Valor da soma:%.2f", a+b);
        }



        if (num == 2)
        {
            system("cls");
            printf ("\n-Valor da subtracao:%.2f", a-b);
        }



        if (num == 3)
        {
            system("cls");
            printf ("\n-Valor da multiplicacao:%.2f", a*b);
        }



        if (num == 4)
        {
            printf ("\nInforme valor do dividendo:");
            scanf ("%f",&a);
            printf ("\nInforme valor do divisor:");
            scanf ("%f",&b);
            if (b == 0)
            {
                system("cls");
                printf ("\n-Nao existe divisao por '0'.");
            }
            else
            {
                system("cls");
                printf ("\n-Valor da divisao:%.2f", a/b);
            }
        }



        if (num == 5)
        {
            printf ("\nInforme a base:");
            scanf ("%f",&a);
            printf ("\nInforme a potencia:");
            scanf ("%f",&b);

            system("cls");
            printf ("\n-Valor da potenciacao:%.2f", potencia(a,b));
        }



        if (num == 6)
        {
            float c;
            printf ("\nInforme 'a' da sua equacao:");
            scanf ("%f",&a);



            if (a == 0)
            {
                system("cls");
                printf ("\n-Nao existe valor real com 'a'= 0.");
            }
            else
            {

                printf ("\nInforme 'b' da sua equacao:");
                scanf ("%f",&b);
                printf ("\nInforme 'c' da sua equacao:");
                scanf ("%f",&c);

                float delta = (b*b)-(4*a*c);
                if (delta < 0 )
                {
                    system("cls");
                    printf ("\n-Nao existe valor real com delta menor que 0.");
                }
                else
                {

                    float r1= (-b + (sqrt(delta))) / (2*a);
                    float r2= (-b - (sqrt(delta))) / (2*a);

                    system("cls");
                    printf ("\n-Valor de x1:%.2f\n-Valor de x2:%.2f", r1,r2);
                }
            }

        }



        if (num == 7)
        {
            int decimal = 0;
            printf ("\n1) Decimal->Binario \n2) Decimal->Octal/Hexodecimal \n");
            printf ("Informe operacao desejada:");
            scanf ("%d",&decimal);




            if (decimal == 1)
            {
                printf ("\n--Em Processo--");

            }

            if (decimal == 2)
            {
                int b;
                printf ("\nInforme um numero decimal:");
                scanf ("%d", &b);
                printf ("\n-Valor em Octal:%o", b);
                printf ("\n-Valor em Hexodecimal:%X", b);

            }
            if (decimal > 2) printf ("\n-operacao invalida-");


        }

        if (num == 8)
        {
            float x,y,lx,ly;

            printf ("\n pontos do centro da circunferencia em:\n");
            printf ("\n X: ");
            scanf("%f", &x);
             printf ("\n Y: ");
            scanf("%f", &y);
            printf ("\n pontos do lado da circunferencia em:\n");
            printf ("\n X: ");
            scanf("%f", &lx);
             printf ("\n Y: ");
            scanf("%f", &ly);

           float r = (sqrt(((lx - x)*(lx - x)) + (ly - y)* (ly - y)));

            system("cls");
            printf("\n-Raio dessa circunferencia: %.2f", r);

        }



        if ( num > 10)
        {
            system("cls");
            printf ("\n-ERRO 123: Operacao invalida!-\n");
        }




        if (num == 9)
        {
            system("CLS");
        }



        if (num == 10)
        {
            float a, b, c;
            printf("valor 1: ");
            scanf ("%f", &a);
            printf("valor 2: ");
            scanf ("%f", &b);
            printf("valor 3: ");
            scanf ("%f", &c);

            float r = (sqrt(potencia(a,2) + potencia(b,2) + potencia(c,2)));

            system("cls");
                      printf ("\nResultado: %0.2f",  r);
        }

        printf("\n\n\n");


    }
    return 0;
}



