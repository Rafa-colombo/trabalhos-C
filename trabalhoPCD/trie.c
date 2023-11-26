# include "trie.h"

Node* createNode() {
    Node* nodoNovo = (Node*)malloc(sizeof(Node));
    if (nodoNovo) {
        int i;
        for (i = 0; i < ALFABETO; i++) {
            nodoNovo->filho[i] = NULL;
        }
        nodoNovo->flag = 0;
    }
    return nodoNovo;
}


void insert(Node* root, char* chave, const char* nome, int idade) {
    Node* check = root;

    while (*chave) {
        int index = *chave - 'a';
        if (!check->filho[index]) {
            check->filho[index] = createNode();
        }
        check = check->filho[index];
        chave++;
    }

    check->flag = 1;

    check->data = (dados*)malloc(sizeof(dados));
    strcpy(check->data->nome, nome);
    check->data->idade = idade;
}


Node* search(Node* root, char* chave) {
    Node* check = root;

    while (*chave) {
        int index = *chave - 'a';
        if (!check->filho[index]) {
            return NULL; 
        }
        check = check->filho[index];
        chave++;
    }
    
    if (check && check->flag) {
        return check; // Se a chave completa está na Trie, retorna o ponteiro para o nó correspondente
    } else {
        return NULL; // Se a chave não está na Trie
    }
}


void freeTrie(Node* node) {
    if (!node) {
        return;
    }

    int i;
    for (i = 0; i < ALFABETO; i++) {
        freeTrie(node->filho[i]);
    }

    free(node);
}


void printAUX(struct TrieNode* node, char* buffer, int depth) {
    if (!node) {
        return;
    }

   
    if (node->flag) {
        buffer[depth] = '\0';
        printf("(%s|%s|%d)\n", buffer, node->data->nome, node->data->idade);
    }

    for (int i = 0; i < ALFABETO; i++) {
        if (node->filho[i]) {
            buffer[depth] = 'a' + i;
            printAUX(node->filho[i], buffer, depth + 1);
        }
    }
}

void printTrie(Node* root) {
    char buffer[100]; 
    printAUX(root, buffer, 0);
}


int vazio(Node* node) {
    for (int i = 0; i < ALFABETO; i++) {
        if (node->filho[i]) {
            return 0; 
        }
    }
    return 1; 
}

Node* removerAUX(Node* node, char* chave, int depth) {
    if (!node) {
        return NULL;
    }

    if (depth == 0) {
        if (node->flag) {
            node->flag = 0;

            if (vazio(node)) {
                free(node);
                node = NULL;
            }
        }
        return node;
    }

    int index = chave[0] - 'a';
    node->filho[index] = removerAUX(node->filho[index], chave + 1, depth - 1);

    if (vazio(node) && !node->flag) {
        free(node);
        node = NULL;
    }
    
    return node;
}

void remover(Node* root, char* chave) {
    Node* aux;
    aux = search(root, chave);
    if (!aux) {
        printf("ID %s nao encontrado.\n", chave);
        return;
    }
    else {
        printf("Removido (%s|%s|%d)\n", chave, aux->data->nome, aux->data->idade);
    }

    root = removerAUX(root, chave, strlen(chave));
    
}