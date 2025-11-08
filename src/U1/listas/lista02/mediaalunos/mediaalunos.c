//Crie um algoritmo para calcular a média das notas dos alunos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno *esquerdo;
    struct Aluno *direito;
} Aluno;

Aluno* criarAluno(char *nome, int matricula, float nota) {
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->nota = nota;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Aluno* inserir(Aluno *raiz, char *nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    if (matricula < raiz->matricula) {
        raiz->esquerdo = inserir(raiz->esquerdo, nome, matricula, nota);
    } else if (matricula > raiz->matricula) {
        raiz->direito = inserir(raiz->direito, nome, matricula, nota);
    }
    return raiz;
}

void calcularMedia(Aluno *raiz, float *soma, int *contador) {
    if (raiz == NULL) return;
    calcularMedia(raiz->esquerdo, soma, contador);
    *soma += raiz->nota;
    (*contador)++;
    calcularMedia(raiz->direito, soma, contador);
}

int main() {
    Aluno *raiz = NULL;
    int n, matricula;
    float nota, soma = 0;
    int contador = 0;
    char nome[50];

    printf("Quantos alunos deseja inserir? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do aluno: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        printf("Digite a nota: ");
        scanf("%f", &nota);
        getchar();

        raiz = inserir(raiz, nome, matricula, nota);
    }

    calcularMedia(raiz, &soma, &contador);

    if (contador > 0) {
        printf("Media das notas: %.2f\n", soma / contador);
    } else {
        printf("Nenhum aluno na arvore.\n");
    }

    return 0;
}
