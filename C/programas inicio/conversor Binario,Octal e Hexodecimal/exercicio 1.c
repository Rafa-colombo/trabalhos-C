#include <stdio.h>


int main()
{
   int entrada = 0, entrada1 = 0, entrada2 = 0;
   int b0 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0 , b6 = 0 , b7 = 0;
   int o0 = 0, o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0 , o6 = 0 , o7 = 0;


 printf ("Bom dia e ola mundo!\n");         //programa para valores separados
  printf ("Cole valor desejado(decimal) para Binario:");
   scanf ("%d", &entrada);
  printf ("Cole valor desejado(decimal) para Octal:");
   scanf ("%d", &entrada1);
  printf ("Cole valor desejado(decimal) para Hexodecimal:");
   scanf ("%d", &entrada2);



 b0 = entrada % 2;

   entrada = entrada / 2;
   b1 = entrada % 2;

   entrada = entrada / 2;
   b2 = entrada % 2;

   entrada = entrada / 2;
   b3 = entrada % 2;

   entrada = entrada / 2;
   b4 = entrada % 2;

   entrada = entrada / 2;
   b5 = entrada % 2;

   entrada = entrada / 2;
   b6 = entrada % 2;

   entrada = entrada / 2;
   b7 = entrada % 2;






o0 = entrada1 % 8;

 entrada1 = entrada1 / 8;
 o1 = entrada1 % 8;

 entrada1 = entrada1 / 8;
 o2 = entrada1 % 8;

 entrada1 = entrada1 / 8;
 o3 = entrada1 % 8;

  entrada1 = entrada1 / 8;
 o4 = entrada1 % 8;


  entrada1 = entrada1 / 8;
 o5 = entrada1 % 8;


  entrada1 = entrada1 / 8;
 o6 = entrada1 % 8;


  entrada1 = entrada1 / 8;
 o7 = entrada1 % 8;




   printf ("Valor em Binario:%d%d%d%d%d%d%d%d\n", b7,b6,b5,b4,b3,b2,b1,b0);
   printf ("Valor em Octal:%d%d%d%d%d%d%d%d\n", o7,o6,o5,o4,o3,o2,o1,o0);
   printf ("Valor em Hexodecimal:%X", entrada2);


return 0;



}

