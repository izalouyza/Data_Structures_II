//a) Implemente a estrutura de dados para a árvore binária de busca. Por exemplo, em C:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;
