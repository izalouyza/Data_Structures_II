//g) Crie um algoritmo para calcular a altura da árvore.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int dado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL) return criarNo(dado);
    if (dado < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, dado);
    else if (dado > raiz->dado)
        raiz->direito = inserir(raiz->direito, dado);
    return raiz;
}

int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int alturaEsq = altura(raiz->esquerdo);
    int alturaDir = altura(raiz->direito);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int main() {
    No* raiz = NULL;
    int n, valor, i;

    printf("Quantos elementos deseja inserir na árvore? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
    }

    printf("A altura da árvore é: %d\n", altura(raiz));

    return 0;
}
