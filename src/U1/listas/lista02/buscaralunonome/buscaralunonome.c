//Implemente um algoritmo para buscar um aluno pelo nome.

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

Aluno* buscarPorNome(Aluno *raiz, const char *nomeBusca) {
    if (raiz == NULL) return NULL;
    if (strcmp(raiz->nome, nomeBusca) == 0) return raiz;
    Aluno *resultado = buscarPorNome(raiz->esquerdo, nomeBusca);
    if (resultado != NULL) return resultado;
    return buscarPorNome(raiz->direito, nomeBusca);
}

int main() {
    Aluno *raiz = NULL;
    int n, matricula;
    float nota;
    char nome[50];
    printf("Quantos alunos deseja inserir? ");
    scanf("%d", &n);
    getchar(); // limpa o buffer do teclado

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

    printf("Digite o nome para buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;

    Aluno *encontrado = buscarPorNome(raiz, nome);

    if (encontrado != NULL) {
        printf("Aluno encontrado: %s, Matricula: %d, Nota: %.2f\n",
               encontrado->nome, encontrado->matricula, encontrado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    return 0;
}
