#include "file.h"

extern  char* fname;
extern Node * root; //raiz global (extern faz função reconhecer variavel global)
extern int quantidade;


 void ler() {
    FILE *txt;
    char linha[120]; 

    txt = fopen(fname, "r");
    if (txt == NULL) {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), txt) != NULL) {
        printf("%s", linha); 
    }

    fclose(txt);

}


char* ler_arquivo( char* arquivo){
     FILE *file = fopen(arquivo, "r");

     if (file == NULL) {
        printf("Falha para abrir file(ler_arquivo).\n");
        return NULL;
    }

    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    
    char *content = (char *)malloc(file_size + 1);

    if (content == NULL) {
        printf("falha na alocacao de memoria.\n");
        fclose(file);
        return NULL;
    }

    
    size_t result = fread(content, 1, file_size, file);
 
    content[file_size] = '\0'; 


    fclose(file);

    return content;
}

void LEITURA(){
//transformar auxiliar em txt(salvar)
    FILE *txt;
    
    
    // cria arquivo txt(se existente ele apaga)
    txt = fopen(fname, "w"); 
    if (txt == NULL) {
        printf("Não foi possível abrir o arquivo para escrita(LEITURA).\n");
        return;
    }

    
    char* filename = "auxiliar.txt"; 
    fprintf(txt, "%d\n", quantidade);
    TrieToFile(root, filename);
    char* leitura = ler_arquivo(filename);

    if (leitura != NULL) {
        fprintf(txt, "%s\n", leitura);
        free(leitura); 
    }

    
    fclose(txt);

}



void TrieToFileHelper(Node* node, FILE* file, char* buffer, int depth) {
    if (!node) {
        return;
    }

    if (node->flag) {
        buffer[depth] = '\0';
        fprintf(file, "%s %s %d\n", buffer, node->data->nome, node->data->idade);
    }

    for (int i = 0; i < ALFABETO; i++) {
        if (node->filho[i]) {
            buffer[depth] = 'a' + i;
            TrieToFileHelper(node->filho[i], file, buffer, depth + 1);
        }
    }
}

void TrieToFile(Node* root, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Falha ao abrir arquivo(TrieToFile).\n");
        return;
    }

    char buffer[100]; 
    TrieToFileHelper(root, file, buffer, 0);

    fclose(file);
}


