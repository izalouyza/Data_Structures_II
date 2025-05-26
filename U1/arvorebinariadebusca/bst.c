#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node* criarNo(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}


int main(){
    Node *raiz = criarNo(10);
    raiz->direita = criarNo(20);
    raiz->direita->esquerda = criarNo(15);
}


