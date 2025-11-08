#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerdo;
    struct No *direito;
} No;

No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));
    if(novo) {
        novo->direito = NULL;
        novo->esquerdo = NULL;
        novo->valor = valor;
    }
    return novo;
}

int main() {
    No *raiz = criarNo(10);
    raiz->direito = criarNo(20);
    raiz->direito->esquerdo = criarNo(15);

    return 0;
}
