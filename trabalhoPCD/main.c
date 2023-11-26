#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node * root; //raiz global
char* fname = "banco.txt"; //arquivo principal
int quantidade; 



void FileToTrie(Node* root, char *name) {
    FILE* file = fopen(name, "r");
    if (file == NULL) {
        printf("Falha ao ler arquivo(fileToTrie).\n");
        return;
    }

    char word[10];
    char nome[100];
    int idade;

    fscanf(file, "%d", &quantidade);
    while (fscanf(file, "%s %[^0-9] %d", word, nome, &idade) != EOF) {
        insert(root, word, nome, idade);
    }

    fclose(file);
}



int main(){

    root = createNode();

    int rodar = 1;
    char ID[30];
    char nome[1000];
    int idade;
    


    FileToTrie(root, fname);

    while(rodar){
        char comando[2];
        scanf("%1s", comando);
        switch(comando[0]){

        case '+': //adicionar na trie
            scanf("%s %[^0-9] %d", ID, nome, &idade);
            if (idade > 99){
                printf("Idade invalida.\n");
                break;
            }
            insert(root, ID, nome, idade);    
            printf("Inserido (%s|%s|%d)\n", ID, nome, idade);
            quantidade++;
            break;
        case '-': //remoção na trie
            scanf("%s", ID);
            remover(root, ID);
            quantidade--;
            break;
        case '?': //busca na trie
            scanf("%s", ID); 
            Node* aux;
            aux = search(root, ID); // raiz e chave de busca(ID)
            if (aux !=NULL ){
                printf("(%s|%s|%d)\n", ID, aux->data->nome, aux->data->idade);
            } else {
                printf("ID %s nao encontrado.\n", ID);
            }
            break;
        case 'p': //printa trie
            printTrie(root);
            break;
        case 's': //salva arquivo
            printf("%s salvo\n", fname);
            LEITURA();//Pega auxiliar e salva em txt
            break;
        case 'f':
            freeTrie(root);
            rodar = 0;
            break;


        default:
                printf("Invalid command\n");

        }



    }


    return 0;
}
