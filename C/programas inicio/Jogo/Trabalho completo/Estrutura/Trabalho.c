
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define ORANGE 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define YELLOW 14
#define WHITE 15


int valor(int n)
{
    switch(n)
    {
    case 0:
        return 1000;
    case 1:
        return 2000;
    case 2:
        return 3000;
    case 3:
        return 4000;
    case 4:
        return 5000;
    case 5:
        return 10000;
    case 6:
        return 20000;
    case 7:
        return 30000;
    case 8:
        return 40000;
    case 9:
        return 50000;
    case 10:
        return 100000;
    case 11:
        return 200000;
    case 12:
        return 300000;
    case 13:
        return 400000;
    case 14:
        return 500000;
    case 15:
        return 1000000;

    }
}
void setColor(int color)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int chamaPergunta(int n, int* p)
{
    const char * perguntas[] =
    {
        "Em que estado brasileiro nasceu a apresentadora Xuxa?",                                                                 //1
        "Qual eh o nome dado ao estado da agua em forma de gelo?",                                                                //2
        "Fidel Castro nasceu em que pais?",                                                                                      //3
        "Qual eh o personagem do folclore brasileiro que tem uma perna so?",                                                      //4
        "Quem proclamou a republica no Brasil em 1889?",                                                                         //5
        "Quem era o apresentador que reprovava os calouros tocando uma buzina?",                                                 //6
        "Quem e o patrono do exercito brasileiro?",                                                                              //7
        "O que era Frankenstein, de Mary Shelley?",                                                                              //8
        "Qual e o signo do zodiaco de quem nasce no dia do ano-novo?",                                                           //9
        "Quem fundou a fabrica de automoveis Ford?",                                                                             //10
        "A agua ferve a quantos graus centigrados?",                                                                             //11
        "Qual personagem da turma da Monica tem apenas cinco fios de cabelo?",                                                   //12
        "Qual cantora tinha o apelido de 'Ternurinha' na epoca da jovem guarda?",                                                //13
        "Qual e a pedra preciosa mais dura encontrada na natureza?",                                                             //14
        "Qual  materia do curso de engenharia da computacao eh considerado como a mais dinamica e interessante pelos alunos?",   //15
        "O rio Amazonas pertence a qual continente?",                                                                            //16
        "Quem esculpiu o boneco Pinoquio, no conto de Carlo Lorenzini?",                                                         //17
        "Qual ator do cinema brasileiro eh conhecido por ter unhas enormes??",                                                    //18
        "O violoncelo e um tipo de instrumento de?",                                                                             //19
        "Quantas denticcoes naturais tem o ser humano durante a vida?",                                                           //20
    };

    const char * alternativas[] =
    {
        "RIO DE JANEIRO",          /* 1 */
        "RIO GRANDE DO SUL",
        "SANTA CATARINA",
        "GOIAS",

        "LIQUIDO",                /* 2 */
        "SOLIDO",
        "GASOSO",
        "VAPOROSO",

        "JAMAICA",                /* 3 */
        "CUBA",
        "EL SALVADOR",
        "MEXICO",

        "CUCA",                   /* 4 */
        "NEGRINHO DO PASTOREIO",
        "BOITATA",
        "SACI-PERERE",

        "DUQUE DE CAXIAS",       /* 5 */
        "MARECHAL RONDON",
        "DOM PEDRO II",
        "MARECHAL DEODORO",

        "RAUL GIL",               /* 6 */
        "BOLINHA",
        "FLAVIO CAVALCANTI",
        "CHACRINHA",

        "MARECHAL DEODORO",       /* 7 */
        "BARAO DE MAUA",
        "DUQUE DE CAXIAS",
        "MARQUES DE POMBAL",

        "MONSTRO",                /* 8 */
        "GORILA",
        "PRINCIPE",
        "SAPO",

        "VIRGEM",                 /* 9 */
        "AQUARIO",
        "CAPRICORNIO",
        "ARIES",

        "HARRISON FORD",          /* 10 */
        "GERALD FORD",
        "HENRY FORD",
        "ANNA FORD",

        "200",                    /* 11 */
        "100",
        "170",
        "220",

        "MONICA",                 /* 12 */
        "CEBOLINHA",
        "CASCAO",
        "MAGALI",

        "SILVINHA",               /* 13 */
        "WANDERLEIA",
        "GRETCHEN",
        "MARTINHA",

        "ESMERALDA",               /* 14 */
        "RUBI",
        "PEROLA",
        "DIAMANTE",

        "CALCULO",                  /* 15 */
        "FISICA",
        "PROGRAMACAO",
        "LIBRAS",

        "AMERICANO",                    /* 16 */
        "AFRICANO",
        "EUROPEU",
        "ASIATICO",

        "GEPETO",                   /* 17 */
        "FADA",
        "BRUXA",
        "GIGANTE",

        "PENADINHO",                   /* 18 */
        "ZE DO CAIXAO",
        "ZE DO CASARAO",
        "TONINHO DO DIABO",

        "SOPRO",                   /* 19 */
        "CORDAS",
        "PERCUSSAO",
        "REPERCUSSAO",

        "UMA",                     /* 20 */
        "DUAS",
        "TRES",
        "QUATRO",
    };

    const int respostas[] =
    {
        2,  //RIO GRANDE DO SUL
        2,  //SOLIDO
        2,  //CUBA
        4,  //SACI
        4,  //MARECHAL DEODORO
        4,  //CHACRINHA
        3,  //DUQUE DE CAXIAS
        1,  //MONSTRO
        3,  //CAPRICORNIO
        3,  //HENRY FORD
        2,  //100
        2,  //CEBOLINHA
        2,  //WANDERLEIA
        4,  //DIAMANTE
        3,  //PROGRAMAÇÃO
        1,  //AMERICANO
        1,  //GEPETO
        2,  //ZÉ DO CAIXÃO
        2,  //CORDAS
        2,  // DUAS
    };

    setColor(LIGHT_GRAY);
    printf("========================");
    setColor(ORANGE);
    printf("\n       [Valendo]\n");
    setColor(LIGHT_GREEN);
    printf("      R$ ");
    setColor(YELLOW);
    printf("%d,00\n", valor(n - (3 - *p)));
    setColor(LIGHT_GRAY);
    printf("========================\n\n");
    setColor(LIGHT_GRAY);
    printf("%s\n",perguntas[n]);    //PRINT PERGUNTAS
    for(int i = 0; i < 4; i++)      //PRINT ALTERNATIVAS(NUMERO E OPÇOES)
    {
        setColor(LIGHT_BLUE);
        printf(" %d) ",i+1);
        setColor(LIGHT_GRAY);
        printf("%s\n", alternativas[4*n + i]); //4 * NUMERO DA PERGUNTA + ALTERNATIVA (SETAR POSIÇÃO DAS ALTERNATIVAS)
    }
    if (*p > 0)                    //PRINT DO PULO
        setColor(LIGHT_RED);
    printf("[5] ");
    setColor(LIGHT_GRAY);
    printf("Pular (");
    setColor(YELLOW);
    printf("%d", *p);
    setColor(LIGHT_GRAY);
    printf(")\n");



    if (n > 0)                        //PRINT DO PARAR
    {
        setColor(LIGHT_RED);
        printf("[6] ");
        setColor(LIGHT_GRAY);
        printf ("Parar R$ %d,00\n\n\n", (valor((n-1) - (3 - *p)))/2);     //EXIBIR VALOR GANHO AO PARAR
    }


    int o = 0;  //INTEIRO QUE RECEBE ALTERNATIVAS

    do
    {
        setColor(LIGHT_CYAN);
        printf("\n\n[Resposta]: ");

        scanf("%d", &o);
        if(*p == 0)        //NUMERO DE PULOS É 0
        {
            setColor(LIGHT_RED);
            printf("\n\nNao tem mais pulo\n");
            setColor(LIGHT_GRAY);
            continue;
        }
        setColor(LIGHT_RED);
        if( o > 6) printf("\n\nResposta invalida, digite novamente! 1 - 4");    //NAO POR RESPOSTA INVALIDA
        setColor(LIGHT_GRAY);
    }
    while (o > 6 || (*p == 0 && o == 5));    //SEMPRE EXECUTAR do ENQUANTO ATENDE AO WHILE (NAO TEM MAIS PULO OU RESPOSTA INVALIDA) VOLTA DO PARA ESCANEAR RESPOSTA


    if (o == 5 && *p > 0 )  //FUNÇAO PONTEIRO PULO
    {
        setColor(ORANGE);
        printf("\nPULOU!\n\n");
        setColor(LIGHT_GRAY);
        (*p)--;
        return 1;      //RETORNA UM PARA NAO FECHAR
    }



    if (o == 6 )  //FUNÇAO PARAR
    {

        setColor(ORANGE);
        printf("\n\nPremio:");
        setColor(GREEN);
        printf(" R$ ");
        setColor(YELLOW);
        printf("%d,00\n", (valor((n-1) - (3 - *p)))/2);
        setColor(LIGHT_GRAY);
        return 0;   //PARA O PROGRAMA
    }

    if(o == respostas[n])  //PEGA RESPOSTA DE ACORDO COM NUMERO DO]A PERGUNTA(N)
    {
        setColor(LIGHT_GREEN);
        printf("\n\nSua resposta esta EEEEEEE \nEXATA!!!\n\n");
        FILE *arq;
        char Linha[10];

        setColor(ORANGE);

        arq = fopen ("feliz.txt", "r");

        while(fgets(Linha,10,arq) !=NULL)
            printf("%s", Linha);

        setColor(LIGHT_GRAY);

        fclose(arq);

        printf("\n\n\n");

    }
    else
    {
        setColor(LIGHT_RED);
        printf("\n\nSua resposta esta EEEEEEE\nERRADA, BURRO!\n\n");
        printf("Premio: eh um grande chapeu de idiota s2!\n\n");
        setColor(LIGHT_GRAY);

        FILE *arq;
        char Linha[10];

        setColor(LIGHT_MAGENTA);

        arq = fopen ("triste.txt", "r");

        while(fgets(Linha,10,arq) !=NULL)
            printf("%s", Linha);

        setColor(LIGHT_GRAY);

        fclose(arq);

        printf("\n\n\n");

        return 0;
    }

    return 1;

}




int main()
{
    char nome[999];
    int recebe;
    int hub;
    int jogo = 0;
    char oi[1];
    int *pulo =  &(int)
    {
        3
    };

    setColor(ORANGE);
    printf("===============================================\n");
    setColor(YELLOW);
    printf("             SHOW DO GRANDE MILHO");
    setColor(ORANGE);
    printf("\n===============================================");
    setColor(LIGHT_CYAN);
    printf("\n\n[Escolha seu nome]: ");

    gets(nome);
    printf("\nDiverta-se %s\n", nome);
    system("cls");


    setColor(GREEN);
    printf("\n==========================================\n");
    setColor(ORANGE);
    printf("                   MENU");
    setColor(GREEN);
    printf("\n==========================================\n");
    setColor(LIGHT_CYAN);
    printf("\nOla");
    setColor(LIGHT_GRAY);
    printf(" %s", nome);
    setColor(LIGHT_CYAN);
    printf("! \n\nSelecione:");
    setColor(YELLOW);
    printf("\n\n[1] Para Iniciar \n[0] Para Fechar\n\n");
    setColor(LIGHT_CYAN);
    printf("Tela inicial, digite seu comando: ");
    scanf("%d", &hub);
    if (hub == 1)
    {

        system("cls");

        while (jogo == 0)
        {
            setColor(GREEN);
            printf("=========================================================\n");
            setColor(ORANGE);
            printf("                       Bem-vindo!\n");
            setColor(GREEN);
            printf("=========================================================\n");
            setColor(CYAN);
            printf("Acerte 16 perguntas para conquistar o GRANDE PREMIO!!!!\n");
            printf("IMPORTANTE!! \nUm erro e voce perde TUDO, jogue com sabedoria!\nVoce possui 3 pulos!\n\n ");
            printf("\nBoa sorte no jogo");
            setColor(LIGHT_CYAN);
            printf(" %s\n", nome);
            setColor(CYAN);
            printf("\nPressione");
            setColor(YELLOW);
            printf(" ENTER");
            setColor(CYAN);
            printf(" para seguir\n");
            setColor(LIGHT_GRAY);
            gets(oi);
            getchar();
            system("cls");

            for(int i = 0; i < 16 + (3-*pulo); i++)
            {
                recebe = chamaPergunta(i,pulo);
                if (recebe == 0) break;
                setColor(LIGHT_GREEN);
                printf("\n%s pressione [", nome);
                setColor(WHITE);
                printf("ENTER");
                setColor(LIGHT_GREEN);
                printf("] para seguir\n");
                setColor(LIGHT_GRAY);
                gets(oi);
                getchar();
                system("cls");

            }


            // Premio do Ganhador
            if (recebe == 1)
            {

                FILE *arq;
                char Linha[10];

                setColor(LIGHT_MAGENTA);

                arq = fopen ("premio.txt", "r");

                while(fgets(Linha,10,arq) !=NULL)
                    printf("%s", Linha);

                setColor(LIGHT_GRAY);

                fclose(arq);

                printf("\n\n\n");

                setColor(ORANGE);

                printf("\nParabens %s, para jogar novamente tecle 0 ou 1 para fechar.\n- ", nome);
                scanf("%d", &jogo);

            }
            else
            {
                setColor(LIGHT_CYAN);
                printf("\n\n\n\n%s, para jogar novamente tecle 0 ou 1 para fechar.\n ", nome);
                scanf("%d", &jogo);
            }

            *pulo = 3;
            system("cls");
        }
    }


    return 0;

}




