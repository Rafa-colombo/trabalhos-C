#ifndef trie_h
#define trie_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define ALFABETO 26


typedef struct dados {
    char nome[100];
    int idade;
} dados;

typedef struct TrieNode {
    struct TrieNode* filho[ALFABETO];
    int flag;
    dados* data; 
}Node;

typedef struct letra {
    int flag;
    struct trie * raiz; // raiz da trie(cabeça)
} letra;// CADA LETRA CORRESPONDE A UM PONTEIRO QUE APONTA COM NOME EX:'A'


#include "file.h"

Node* createNode();
Node* search(Node* root, char* chave);
void insert(Node* root, char* chave, const char* nome, int idade);
void remover(Node* root, char* chave);
void printTrie(Node* root);
void freeTrie(Node* node);

#endif